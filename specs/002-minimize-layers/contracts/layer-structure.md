# Contract: Layer Structure & Access Patterns

**Feature**: 002-minimize-layers  
**Date**: 2025-11-08  
**Purpose**: Define guaranteed behavior contracts for layer access, transitions, and state management

## Layer Access Contracts

### Contract 1: Base Layer Independence

**Guarantee**: macOS base (LAYER_MAC_BASE) and Windows base (LAYER_WIN_BASE) operate independently with identical utility layer access patterns

**Behavior**:
- Both bases MUST access LAYER_SYMBOLS via OSL(2)
- Both bases MUST access LAYER_FUNCTION via OSL(3)
- Both bases MUST access LAYER_NUMBERS via LT(4, Space)
- Both bases MUST access LAYER_CONFIG via TO(5)
- Alpha key layout MUST be identical (HIEA O / DTRNS)
- Only home row modifiers MAY differ (Cmd vs Ctrl positioning)

**Testing**: Verify symbol/function/number access works identically from both base layers

**Violations**: If utility layers behave differently depending on which base is active → BUG

---

### Contract 2: One-Shot Layer Auto-Return

**Guarantee**: Layers accessed via OSL (LAYER_SYMBOLS, LAYER_FUNCTION) automatically return to the originating base layer after one keypress

**Behavior**:
- Press OSL(2) from LAYER_MAC_BASE → LAYER_SYMBOLS activates
- Press any key on LAYER_SYMBOLS → key registers, layer returns to LAYER_MAC_BASE
- Press OSL(3) from LAYER_WIN_BASE → LAYER_FUNCTION activates
- Press any key on LAYER_FUNCTION → key registers, layer returns to LAYER_WIN_BASE
- Timeout: If no key pressed within ONESHOT_TIMEOUT (5000ms), layer returns automatically

**Edge Cases**:
- Pressing OSL key twice before timeout → layer "locks" (stays active until OSL pressed again)
- Pressing modifier while OSL active → modifier sticks, layer remains until non-modifier pressed

**Testing**: Verify layer returns after single symbol/function keypress from both bases

**Violations**: If layer remains active after keypress → BUG  
**Violations**: If layer returns to wrong base → BUG

---

### Contract 3: Layer-Tap Space Behavior

**Guarantee**: LT(4, Space) activates LAYER_NUMBERS when held, sends space when tapped

**Behavior**:
- Hold space > TAPPING_TERM (200ms) → LAYER_NUMBERS activates
- Tap space < TAPPING_TERM (200ms) → Space character sends
- Release space → LAYER_NUMBERS deactivates, returns to originating base
- While held, number/operator keys from LAYER_NUMBERS are available
- While held, OS-aware clipboard shortcuts use correct OS modifiers

**Edge Cases**:
- Holding space at exactly TAPPING_TERM boundary → implementation-defined (prefer hold)
- Pressing multiple number keys while holding space → all register correctly
- Releasing space mid-keystroke → layer deactivates, subsequent keypress uses base layer

**Testing**: Verify tap sends space, hold activates numbers, both from MAC_BASE and WIN_BASE

**Violations**: If tap sends nothing → BUG  
**Violations**: If hold doesn't activate LAYER_NUMBERS → BUG  
**Violations**: If returns to wrong base → BUG

---

### Contract 4: Persistent Config Layer

**Guarantee**: LAYER_CONFIG accessed via TO(5) remains active until explicitly switched to another layer via TO(0) or TO(1)

**Behavior**:
- Press TO(5) from any layer → LAYER_CONFIG becomes active
- LAYER_CONFIG remains active indefinitely (no auto-return)
- Press TO(0) from LAYER_CONFIG → LAYER_MAC_BASE becomes active
- Press TO(1) from LAYER_CONFIG → LAYER_WIN_BASE becomes active
- RGB controls only affect LEDs, do not change active layer
- QK_BOOT immediately enters bootloader (no layer change)

**Edge Cases**:
- Activating RGB toggle while on config layer → LED state changes, layer remains LAYER_CONFIG
- Pressing TO(0) or TO(1) while not on config layer → still works, switches to specified base
- Entering bootloader → keyboard resets, default layer (LAYER_MAC_BASE) activates on reboot

**Testing**: Verify config layer persists, manual return required, RGB works, bootloader accessible

**Violations**: If config layer auto-returns → BUG  
**Violations**: If cannot return to base layers → CRITICAL BUG

---

## OS Detection Contracts

### Contract 5: OS Detection Accuracy

**Guarantee**: is_macos_base() helper accurately detects which base layer is currently the default layer

**Behavior**:
```c
static inline bool is_macos_base(void) {
    return get_highest_layer(default_layer_state) == LAYER_MAC_BASE;
}
```

- When LAYER_MAC_BASE is default layer → is_macos_base() returns true
- When LAYER_WIN_BASE is default layer → is_macos_base() returns false
- Detection works regardless of currently active temporary layer (OSL/LT)
- Detection persists across layer switches (TO commands update default_layer_state)

**Testing**: Verify clipboard operations use Cmd on macOS base, Ctrl on Windows base

**Violations**: If wrong modifier used for clipboard operations → BUG  
**Violations**: If detection changes when temporary layers accessed → BUG

---

### Contract 6: OS-Aware Clipboard Operations

**Guarantee**: OS_UNDO, OS_COPY, OS_PASTE, OS_CUT send correct modifier key combination based on is_macos_base() detection

**Behavior**:
| Keycode | When is_macos_base() == true | When is_macos_base() == false |
|---------|------------------------------|-------------------------------|
| OS_UNDO | Sends Cmd+Z | Sends Ctrl+Z |
| OS_COPY | Sends Cmd+C | Sends Ctrl+C |
| OS_PASTE | Sends Cmd+V | Sends Ctrl+V |
| OS_CUT | Sends Cmd+X | Sends Ctrl+X |

**Testing**: Switch between base layers, verify clipboard shortcuts match OS expectations

**Violations**: If Cmd used on Windows base → BUG  
**Violations**: If Ctrl used on macOS base → BUG

---

## Home Row Mod Contracts

### Contract 7: Mod-Tap Timing

**Guarantee**: MT() macros distinguish between tap (character) and hold (modifier) based on TAPPING_TERM (200ms)

**Behavior**:
- Key pressed and released within 200ms → character sends (e.g., H, I, E, T, R, N)
- Key held beyond 200ms → modifier activates (e.g., Ctrl, Alt, Cmd/Win)
- Modifier remains active while key held
- Modifier releases when key released
- PERMISSIVE_HOLD enabled → if another key pressed before TAPPING_TERM, prefer hold

**Edge Cases**:
- Rapid typing (key pressed/released in <50ms) → always sends character
- Slow typing (key held 150ms) → depends on PERMISSIVE_HOLD and next key timing
- Rolling keystrokes (next key pressed before current released) → PERMISSIVE_HOLD applies

**Testing**: Verify normal typing sends characters, deliberate holds activate modifiers

**Violations**: If tap sends modifier → BUG  
**Violations**: If hold doesn't activate modifier → BUG  
**Violations**: If accidental modifiers trigger during fast typing → tuning issue (adjust TAPPING_TERM)

---

### Contract 8: Home Row Mod Symmetry

**Guarantee**: Left and right home row mods provide symmetric modifier coverage

**macOS Base**:
- Left side: Ctrl (H), Alt (I), Cmd (E)
- Right side: Cmd (T), Alt (R), Ctrl (N)
- Symmetry: Both sides have Ctrl, Alt, Cmd available

**Windows Base**:
- Left side: Win (H), Alt (I), Ctrl (E)
- Right side: Ctrl (T), Alt (R), Win (N)
- Symmetry: Both sides have Win, Alt, Ctrl available

**Testing**: Verify all modifiers accessible from both hands on both bases

**Violations**: If modifier only available on one side → BUG  
**Violations**: If Cmd/Win not swapped between bases → BUG

---

## RGB LED Contracts

### Contract 9: Layer Indication Colors

**Guarantee**: RGB LEDs indicate active base layer and config layer with distinct colors

**Behavior**:
| Layer | Color | RGB Value |
|-------|-------|-----------|
| LAYER_MAC_BASE | Blue | #0000FF |
| LAYER_WIN_BASE | Cyan | #00FFFF |
| LAYER_CONFIG | Red | #FF0000 |
| LAYER_SYMBOLS | Inherit base | No change |
| LAYER_FUNCTION | Inherit base | No change |
| LAYER_NUMBERS | Inherit base | No change |

- Utility layers (OSL/LT accessed) do not change LED color (too rapid)
- Config layer immediately shows red when TO(5) pressed
- Returning to base layer (TO(0)/TO(1)) restores base color (blue/cyan)

**Testing**: Verify LED color matches active base, changes to red on config, no flicker on utility access

**Violations**: If wrong color displayed → BUG  
**Violations**: If LEDs flicker during OSL/LT access → design flaw (accept as-is)

---

## Transparent Key Contracts

### Contract 10: Transparent Key Fallthrough

**Guarantee**: KC_TRANSPARENT on utility layers falls through to the key defined on the base layer

**Behavior**:
- If LAYER_SYMBOLS position has KC_TRANSPARENT
- And LAYER_SYMBOLS is active (via OSL)
- And user presses that position
- Then key defined at same position on LAYER_MAC_BASE or LAYER_WIN_BASE sends

**Usage**: Allows utility layers to expose base layer alphas without duplication

**Testing**: Verify transparent positions send base layer keys when accessed from utility layers

**Violations**: If transparent sends nothing → BUG  
**Violations**: If transparent doesn't fallthrough to base → BUG

---

## State Transition Guarantees

### Contract 11: Layer Transition Atomicity

**Guarantee**: Layer transitions complete atomically (no intermediate states visible)

**Behavior**:
- Pressing OSL(2) → layer switches immediately to LAYER_SYMBOLS (no delay)
- Pressing TO(5) → layer switches immediately to LAYER_CONFIG (no delay)
- Releasing LT(4, Space) → layer switches immediately back to base (no delay)
- No "in-between" layer state exists
- Layer transitions do not drop keypresses

**Testing**: Verify no missed keypresses during rapid layer switching

**Violations**: If keypress lost during transition → CRITICAL BUG  
**Violations**: If intermediate layer state causes wrong key to send → BUG

---

### Contract 12: Default Layer Persistence

**Guarantee**: Default layer (set by TO command) persists across temporary layer accesses

**Behavior**:
- Set default layer to LAYER_MAC_BASE via TO(0)
- Access LAYER_SYMBOLS via OSL(2) → default layer remains LAYER_MAC_BASE
- Return from LAYER_SYMBOLS → returns to LAYER_MAC_BASE (not some other layer)
- Change default layer to LAYER_WIN_BASE via TO(1)
- Subsequent temporary layer accesses return to LAYER_WIN_BASE

**Testing**: Verify default layer doesn't change unless TO command used

**Violations**: If temporary layer access changes default layer → CRITICAL BUG  
**Violations**: If default layer reverts unexpectedly → CRITICAL BUG

---

## Failure Modes

**Failure Mode 1**: OSL layer doesn't return after keypress  
**Recovery**: Press OSL key again to "unlock" layer, then press again to return  
**Prevention**: Ensure ONESHOT_TIMEOUT set correctly in config.h

**Failure Mode 2**: LT(Space) doesn't send space on tap  
**Recovery**: Use another space key position (if available) or adjust TAPPING_TERM  
**Prevention**: Test timing threshold with user's typing speed

**Failure Mode 3**: Home row mods trigger accidentally during fast typing  
**Recovery**: Increase TAPPING_TERM or enable IGNORE_MOD_TAP_INTERRUPT  
**Prevention**: Tune TAPPING_TERM to user's typing rhythm

**Failure Mode 4**: Wrong OS modifiers used for clipboard  
**Recovery**: Switch to correct base layer (TO(0) for macOS, TO(1) for Windows)  
**Prevention**: Ensure is_macos_base() detection uses correct layer constant

**Failure Mode 5**: Stuck on config layer  
**Recovery**: Press TO(0) or TO(1) to return to base  
**Prevention**: Document config layer requires manual return in quickstart.md

---

## Contract Validation Checklist

- [ ] Both bases access utilities identically (Contract 1)
- [ ] OSL layers auto-return after keypress (Contract 2)
- [ ] LT(Space) taps send space, holds activate numbers (Contract 3)
- [ ] Config layer persists until TO(0)/TO(1) (Contract 4)
- [ ] is_macos_base() detects correct base layer (Contract 5)
- [ ] Clipboard operations use correct OS modifiers (Contract 6)
- [ ] MT() macros respect TAPPING_TERM timing (Contract 7)
- [ ] Home row mods symmetric on both hands (Contract 8)
- [ ] RGB LEDs show correct layer colors (Contract 9)
- [ ] Transparent keys fall through to base (Contract 10)
- [ ] Layer transitions atomic and immediate (Contract 11)
- [ ] Default layer persists across temporary accesses (Contract 12)

**All contracts must pass before implementation is considered complete.**
