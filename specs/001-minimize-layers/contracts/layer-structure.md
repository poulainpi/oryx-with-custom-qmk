# Layer Structure Contract

**Feature**: Minimize Keyboard Layers  
**Created**: 2025-11-07  
**Purpose**: Define the formal contract for layer organization, access patterns, and inter-layer communication

## Layer Definitions

### Layer Numbering Schema

```c
// Layer indices (0-based, sequential)
enum custom_layers {
    LAYER_MAC_BASE = 0,   // macOS base typing layer
    LAYER_WIN_BASE = 1,   // Windows base typing layer
    LAYER_SYMBOLS  = 2,   // Unified programming symbols
    LAYER_FUNCTION = 3,   // Unified function keys, navigation, umlauts
    LAYER_NUMBERS  = 4,   // Unified number pad with OS-specific clipboard
    LAYER_CONFIG   = 5    // RGB configuration and system functions
};
```

**Contract Requirements**:
- Layer indices MUST be sequential (0, 1, 2, 3, 4, 5)
- Layer names MUST use descriptive enum constants (not magic numbers in keymap)
- Base layers MUST occupy positions 0 and 1 for default layer switching efficiency
- Configuration layer MAY be renumbered from current 9 to 5, or remain at 9 if minimizing disruption is preferred

### Layer Access Methods

#### One-Shot Layer (OSL)

**Purpose**: Activate layer for next keypress only, then auto-return to base  
**Use Cases**: Symbol layer, function/navigation layer

**Contract**:
```c
// Syntax: OSL(layer)
OSL(LAYER_SYMBOLS)    // Activate symbols for one keypress
OSL(LAYER_FUNCTION)   // Activate function/nav for one keypress
```

**Behavior**:
- **Tap**: Activate target layer
- **Next Key**: Process key from target layer, then return to base
- **Timeout**: If no key pressed within ONESHOT_TIMEOUT (5000ms default), auto-return
- **Cancellation**: Tap OSL again to cancel activation

**Guarantees**:
- MUST return to originating base layer (MAC or WIN) after one keypress
- MUST NOT persist layer activation beyond single key
- MUST support rapid sequence entry (e.g., symbol, symbol, symbol via repeated taps)

#### Layer-Tap (LT)

**Purpose**: Dual-function key - tap for character, hold for layer access  
**Use Cases**: Space key (tap space, hold for numbers layer)

**Contract**:
```c
// Syntax: LT(layer, keycode)
LT(LAYER_NUMBERS, KC_SPACE)  // Tap = space, Hold = numbers layer
```

**Behavior**:
- **Tap** (press & release < TAPPING_TERM): Send keycode (KC_SPACE)
- **Hold** (press & hold >= TAPPING_TERM): Activate layer (LAYER_NUMBERS)
- **Release**: Deactivate layer, return to base

**Guarantees**:
- MUST differentiate tap vs hold based on TAPPING_TERM (200ms default)
- MUST send keycode on tap
- MUST activate layer while held
- MUST NOT send keycode if hold threshold exceeded

#### Layer Toggle (TO)

**Purpose**: Permanently switch to target layer (set as default layer)  
**Use Cases**: Switching between macOS/Windows base layers, accessing config layer

**Contract**:
```c
// Syntax: TO(layer)
TO(LAYER_MAC_BASE)   // Switch to macOS base
TO(LAYER_WIN_BASE)   // Switch to Windows base  
TO(LAYER_CONFIG)     // Switch to configuration layer
```

**Behavior**:
- **Press**: Immediately switch default layer to target
- **Persistence**: Remains on target layer until another TO() command
- **Base Layer Context**: Sets the "home" layer for OSL/LT returns

**Guarantees**:
- MUST set default_layer_state to target layer
- MUST persist until explicit layer change via another TO()
- MUST serve as return destination for OSL/LT operations

## Layer Access Patterns

### From macOS Base Layer (LAYER_MAC_BASE)

| Thumb Position | Key Function | Access Method | Target Layer | Return Behavior |
|----------------|--------------|---------------|--------------|-----------------|
| Left Inner     | Symbol Layer | OSL(2)        | LAYER_SYMBOLS | Auto-return after one key |
| Left Outer     | Shift Mod    | OSM(MOD_LSFT) | N/A (modifier) | One-shot shift |
| Right Inner    | Func/Nav Layer | OSL(3)      | LAYER_FUNCTION | Auto-return after one key |
| Right Outer    | Space/Numbers | LT(4, SPACE) | LAYER_NUMBERS | Return on release |

**Contract**:
- Access patterns MUST be identical for both base layers (MAC and WIN)
- Thumb cluster MUST provide all layer access (no hand movement required)
- Layer access keys MUST be transparent (KC_TRANSPARENT) on utility layers to prevent layer stacking issues

### From Windows Base Layer (LAYER_WIN_BASE)

| Thumb Position | Key Function | Access Method | Target Layer | Return Behavior |
|----------------|--------------|---------------|--------------|-----------------|
| Left Inner     | Symbol Layer | OSL(2)        | LAYER_SYMBOLS | Auto-return after one key |
| Left Outer     | Shift Mod    | OSM(MOD_LSFT) | N/A (modifier) | One-shot shift |
| Right Inner    | Func/Nav Layer | OSL(3)      | LAYER_FUNCTION | Auto-return after one key |
| Right Outer    | Space/Numbers | LT(4, SPACE) | LAYER_NUMBERS | Return on release |

**Contract**:
- MUST use identical thumb assignments to macOS base (muscle memory consistency)
- Home row mods MUST differ (Ctrl/Cmd positions swapped) for OS-appropriate shortcuts
- All other keys MUST match macOS base positions (letters, navigation, etc.)

### From Configuration Layer (LAYER_CONFIG)

| Key Position | Key Function | Access Method | Target Layer | Notes |
|--------------|--------------|---------------|--------------|-------|
| Designated   | To macOS     | TO(0)         | LAYER_MAC_BASE | Permanent switch |
| Designated   | To Windows   | TO(1)         | LAYER_WIN_BASE | Permanent switch |
| Designated   | Bootloader   | QK_BOOT       | N/A | System reset for flashing |

**Contract**:
- MUST provide explicit TO() keys for both base layers
- User MUST manually select base layer (no auto-detection)
- Config layer SHOULD be accessible via TO(5) or TO(9) from base layers (top-right key)

## OS-Specific Behavior Contracts

### Clipboard Operations (Number Layer)

**Requirement**: Single number layer MUST provide correct clipboard shortcuts for active base layer

**Contract**:
```c
// Pseudo-code contract
on_key_press(CLIPBOARD_COPY) {
    if (active_base == LAYER_MAC_BASE) {
        send_keycode(LGUI(KC_C));  // Cmd+C
    } else if (active_base == LAYER_WIN_BASE) {
        send_keycode(LCTL(KC_C));  // Ctrl+C
    }
}
```

**Supported Operations**:
- **Undo**: LGUI(KC_Z) [Mac] / LCTL(KC_Z) [Win]
- **Copy**: LGUI(KC_C) [Mac] / LCTL(KC_C) [Win]
- **Paste**: LGUI(KC_V) [Mac] / LCTL(KC_V) [Win]
- **Cut**: LGUI(KC_X) [Mac] / LCTL(KC_X) [Win]

**Guarantees**:
- MUST detect active base layer via `get_highest_layer(default_layer_state)`
- MUST send OS-appropriate modifier (LGUI for macOS, LCTL for Windows)
- MUST work consistently regardless of how base layer was set

### Window Management (Function Layer)

**Requirement**: Navigation shortcuts MUST use OS-appropriate modifiers

**Contract**:
```c
// Window positioning on macOS: Cmd+arrows
// Word navigation on Windows: Ctrl+arrows

on_key_press(NAV_SHORTCUT) {
    if (active_base == LAYER_MAC_BASE) {
        // macOS window management uses Cmd
        apply_modifier(MOD_LGUI);
    } else {
        // Windows navigation uses Ctrl  
        apply_modifier(MOD_LCTL);
    }
    send_navigation_key();
}
```

**Supported Shortcuts**:
- **macOS**: Cmd+Left/Right/Up/Down for window positioning
- **Windows**: Ctrl+Left/Right for word navigation, Win+arrows for window snap

**Guarantees**:
- MUST apply correct modifier based on active base layer
- MAY use home row mods from base layer (inherited when function layer active)
- MUST document shortcuts in quickstart.md for user reference

## Layer Transparency Contract

### Transparent Key Behavior

**Definition**: `KC_TRANSPARENT` (or `_______`) passes keypress through to lower layer

**Contract**:
```c
// On utility layers (symbols, function, numbers):
// Undefined positions use KC_TRANSPARENT to pass through to base layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_SYMBOLS] = LAYOUT_voyager(
        // Row with defined symbols
        DE_SECT, DE_AMPR, DE_LBRC, ...,
        
        // Thumb cluster: pass through to base layer
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
};
```

**Guarantees**:
- Transparent keys on utility layers MUST pass through to base layer
- Base layers MUST define all 52 keys (no transparent keys on bases)
- Layer stacking MUST resolve to highest active layer with defined key, or fall through to base

### Layer Stacking Rules

**Priority Order** (highest to lowest):
1. Currently active momentary layer (OSL, LT)
2. Default base layer (set via TO)
3. Layer 0 (fallback if default layer undefined)

**Contract**:
- QMK resolves key by checking layers top-down until non-transparent key found
- Multiple OSL activations SHOULD NOT stack (QMK limits to one one-shot layer at a time)
- LT hold activation takes priority over OSL

## Dual-Function Key Contracts

### Mod-Tap (MT) Contract

**Purpose**: Tap for key, hold for modifier  
**Use Cases**: Home row mods on base layers

**Syntax**:
```c
MT(mod, keycode)
// Examples:
MT(MOD_LCTL, KC_H)    // Tap = H, Hold = Left Ctrl
MT(MOD_LGUI, KC_E)    // Tap = E, Hold = Left Cmd/Win
```

**Behavior Contract**:
- **Tap** (<200ms): Send keycode
- **Hold** (>=200ms): Apply modifier
- **Overlap**: If another key pressed during hold, treat as modifier
- **Release**: Remove modifier

**Guarantees**:
- MUST differentiate tap vs hold based on TAPPING_TERM (200ms)
- MUST work with QMK's permissive hold or other tapping settings if configured
- MUST NOT interfere with typing flow (false modifier activations <1%)

### Layer-Tap (LT) Contract

**Purpose**: Tap for key, hold for layer access  
**Use Cases**: Space key on base layers

**Syntax**:
```c
LT(layer, keycode)
// Example:
LT(LAYER_NUMBERS, KC_SPACE)  // Tap = space, Hold = numbers layer
```

**Behavior Contract**: (same as MT but activates layer instead of modifier)

### Dual-Function Implementation Count

**Current**: 16 dual-functions (DUAL_FUNC_0 to DUAL_FUNC_15)  
**Target**: 12-14 dual-functions

**Consolidation Contract**:
- MUST merge duplicate implementations across OS layers
- MUST preserve unique functionality (OS-specific mods remain separate)
- MUST maintain all user-accessible functions
- SHOULD use descriptive names (DUAL_FUNC_SLASH_ALT) instead of numbers

**Example Consolidation**:
```c
// Before: Separate macOS and Windows implementations
#define DUAL_FUNC_1 LT(5, KC_F3)   // macOS: tap /, hold Alt
#define DUAL_FUNC_11 LT(3, KC_N)   // Windows: tap {, hold Ctrl

// After: Unified where possible, separate where needed
#define DF_SLASH_ALT LT(LAYER_FUNCTION, KC_F3)  // Unified across both
#define DF_LCBR_MAC LT(LAYER_FUNCTION, KC_F3)   // macOS-specific if modifiers differ
#define DF_LCBR_WIN LT(LAYER_FUNCTION, KC_N)    // Windows-specific if modifiers differ
```

## Testing Contracts

### Layer Access Validation

**Test Scenarios**:
1. From LAYER_MAC_BASE, tap OSL(LAYER_SYMBOLS) → next key reads from symbols → auto-return to MAC base
2. From LAYER_WIN_BASE, hold LT(LAYER_NUMBERS, SPACE) → keys read from numbers while held → release returns to WIN base
3. From any base, press TO(LAYER_CONFIG) → switches to config → press TO(LAYER_MAC_BASE) → switches to MAC base

**Acceptance Criteria**:
- ✅ All layer access methods function as specified
- ✅ Returns to correct base layer (MAC or WIN depending on origin)
- ✅ No layer stacking issues (stuck on wrong layer)
- ✅ Transparent keys properly pass through to base

### OS-Specific Function Validation

**Test Scenarios**:
1. On LAYER_MAC_BASE, access number layer, press clipboard copy → sends Cmd+C
2. On LAYER_WIN_BASE, access number layer, press clipboard copy → sends Ctrl+C
3. On LAYER_MAC_BASE, access function layer, press window management shortcut → uses Cmd modifier
4. On LAYER_WIN_BASE, access function layer, press navigation shortcut → uses Ctrl modifier

**Acceptance Criteria**:
- ✅ macOS clipboard shortcuts use Cmd modifier
- ✅ Windows clipboard shortcuts use Ctrl modifier
- ✅ OS detection correctly identifies active base layer
- ✅ All four clipboard operations work on both OSes

### Dual-Function Key Validation

**Test Scenarios**:
1. Quick tap (<200ms) MT(MOD_LCTL, KC_H) → sends H (no modifier)
2. Hold (>200ms) MT(MOD_LCTL, KC_H) → applies Ctrl modifier
3. Quick tap LT(LAYER_NUMBERS, KC_SPACE) → sends space
4. Hold LT(LAYER_NUMBERS, KC_SPACE) → activates number layer

**Acceptance Criteria**:
- ✅ Tap behavior sends keycode without modifier
- ✅ Hold behavior activates modifier or layer
- ✅ Timing threshold (200ms) is comfortable for typing
- ✅ <1% false positives (unintended holds during normal typing)

## Error Handling Contracts

### Invalid Layer Access

**Scenario**: Attempt to access non-existent layer (e.g., old layer 6, 7, 8)

**Contract**:
- MUST NOT compile if invalid layer referenced in keymap
- QMK compiler SHOULD error on undefined layer constants
- LED mapping SHOULD handle missing layers gracefully (default color)

### Layer Stacking Overflow

**Scenario**: Multiple OSL activations or complex layer combinations

**Contract**:
- QMK layer stack depth: Limited to reasonable count (typically <10)
- SHOULD prevent infinite layer loops
- MAY fall back to layer 0 if stack corrupted

### Modifier Conflicts

**Scenario**: Home row mod conflicts with intentional modifier key usage

**Contract**:
- QMK tapping settings (IGNORE_MOD_TAP_INTERRUPT, PERMISSIVE_HOLD) determine behavior
- MUST document active tapping configuration in config.h
- SHOULD test common conflict scenarios (e.g., Shift+H on home row mod)

---

**Version**: 1.0.0  
**Last Updated**: 2025-11-07  
**Status**: Design Complete - Ready for Implementation
