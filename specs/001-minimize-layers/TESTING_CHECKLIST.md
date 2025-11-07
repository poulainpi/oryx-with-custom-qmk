# Testing Checklist - Layer Consolidation Feature

**Status**: ⏸️ Awaiting Hardware  
**Created**: 2025-11-07  
**Purpose**: Manual testing checklist for validating the 6-layer keyboard implementation

## Testing Prerequisites

Before starting tests, ensure:

- [ ] Firmware compiled successfully via GitHub Actions
- [ ] Firmware downloaded from GitHub Actions artifacts
- [ ] Firmware flashed to ZSA Voyager using Keymapp
- [ ] Access to macOS system (physical or VM)
- [ ] Access to Windows system (physical or VM)
- [ ] Text editor available on both systems
- [ ] Terminal/command prompt available
- [ ] Reviewed quickstart.md for detailed test procedures

## Quick Reference: Test Summary

| Test ID | Category | Description | Status |
|---------|----------|-------------|--------|
| T045 | Smoke Test | 5-minute quick validation | ⏸️ Pending |
| T046 | Base Layers | macOS/Windows typing, home row mods | ⏸️ Pending |
| T047 | Symbols | Symbol layer access and entry | ⏸️ Pending |
| T048 | Function/Nav | F-keys, arrows, umlauts | ⏸️ Pending |
| T049 | Numbers | Numpad layout and operators | ⏸️ Pending |
| T050 | Clipboard | OS-aware copy/paste/cut/undo | ⏸️ Pending |
| T051 | Config | RGB controls, layer switching | ⏸️ Pending |
| T052 | Edge Cases | Layer stacking, rapid switching | ⏸️ Pending |
| T053 | Performance | Typing speed, firmware size | ⏸️ Pending |
| T054 | Regression | Preserved QMK features | ⏸️ Pending |

## T045: 5-Minute Smoke Test

**Objective**: Quick validation that basic functionality works

### Test Steps:

1. **Layer Switching**
   - [ ] Power on keyboard
   - [ ] Press TO(LAYER_CONFIG) (top-right key)
   - [ ] Verify RGB controls visible
   - [ ] Switch to macOS base layer
   - [ ] Switch to Windows base layer
   - [ ] LED colors change per base layer

2. **Basic Typing**
   - [ ] Type: "The quick brown fox jumps over the lazy dog" on macOS
   - [ ] Type: "The quick brown fox jumps over the lazy dog" on Windows
   - [ ] All letters appear correctly

3. **Layer Access**
   - [ ] Tap left inner thumb → Symbol layer activates
   - [ ] Type @ symbol → Returns to base
   - [ ] Tap right inner thumb → Function layer activates
   - [ ] Press F1 → Returns to base
   - [ ] Hold right outer thumb → Number layer activates
   - [ ] Type 123 → Release → Returns to base

4. **Home Row Mods**
   - [ ] Quick tap H → Sends H letter
   - [ ] Hold H (>200ms) → Activates Ctrl (Mac) or Win (Windows)
   - [ ] No false activations during typing

5. **Clipboard Shortcuts**
   - [ ] Select text, press OS_COPY (number layer)
   - [ ] Verify Cmd+C (Mac) or Ctrl+C (Windows) executes
   - [ ] Press OS_PASTE → Text pastes correctly

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T046: Base Layer Testing

**Objective**: Validate both OS base layers function correctly

### Test 1: macOS Typing
- [ ] Switch to LAYER_MAC_BASE
- [ ] Type full alphabet: a-z
- [ ] Type numbers: 0-9 (if accessible on base)
- [ ] Type common punctuation: . , " ?
- [ ] All characters appear correctly

### Test 2: Windows Typing
- [ ] Switch to LAYER_WIN_BASE
- [ ] Type full alphabet: a-z
- [ ] Type numbers: 0-9
- [ ] Type common punctuation: . , " ?
- [ ] All characters appear correctly

### Test 3: Layer Returns
- [ ] From base, access symbol layer → Returns to base after tap
- [ ] From base, access function layer → Returns to base after tap
- [ ] From base, access number layer → Returns to base after release
- [ ] No stuck layers

### Test 4: Home Row Mods (macOS)
- [ ] Tap H → H letter
- [ ] Hold H → Ctrl modifier (test with Ctrl+C)
- [ ] Tap I → I letter
- [ ] Hold I → Alt modifier (test with Alt+Tab)
- [ ] Tap E → E letter
- [ ] Hold E → Cmd modifier (test with Cmd+Space)
- [ ] Tap T → T letter
- [ ] Hold T → Cmd modifier
- [ ] Tap R → R letter
- [ ] Hold R → Alt modifier
- [ ] Tap N → N letter
- [ ] Hold N → Ctrl modifier

### Test 4b: Home Row Mods (Windows)
- [ ] Tap H → H letter
- [ ] Hold H → Win modifier (test with Win+E)
- [ ] Tap I → I letter
- [ ] Hold I → Alt modifier (test with Alt+Tab)
- [ ] Tap E → E letter
- [ ] Hold E → Ctrl modifier (test with Ctrl+C)
- [ ] Tap T → T letter
- [ ] Hold T → Ctrl modifier
- [ ] Tap R → R letter
- [ ] Hold R → Alt modifier
- [ ] Tap N → N letter
- [ ] Hold N → Win modifier

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T047: Symbol Layer Testing

**Objective**: Verify unified symbol layer works from both bases

### Test 5: Symbol Access
- [ ] From macOS base, access LAYER_SYMBOLS
- [ ] Type: @, /, {, }, (, ), :
- [ ] All symbols appear correctly
- [ ] Layer returns to base after each symbol
- [ ] From Windows base, access LAYER_SYMBOLS
- [ ] Type same symbols → Identical behavior

### Test 6: Rapid Symbol Entry
- [ ] Type programming snippet: `if (x == 0) { return true; }`
- [ ] Requires: (, ), {, }, ;, ==
- [ ] No missed characters
- [ ] Typing feels fluid, no lag

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T048: Function/Navigation Testing

**Objective**: Validate F-keys, arrows, and German umlauts

### Test 7: Function Keys
- [ ] Access LAYER_FUNCTION
- [ ] Press F1 through F12
- [ ] Each F-key registers correctly
- [ ] Test F5 (refresh), F11 (fullscreen) in browser

### Test 8: Navigation Keys
- [ ] Access LAYER_FUNCTION
- [ ] Test arrow keys: ↑ ↓ ← →
- [ ] Test PgDn, Home, End
- [ ] Cursor moves correctly in text editor

### Test 9: German Umlauts
- [ ] Access LAYER_FUNCTION
- [ ] Type: ü, ß, ä, ö, €
- [ ] All special characters appear correctly
- [ ] Test in text editor with German input support

### Test 10: Window Management (if shortcuts configured)
- [ ] Test Cmd+arrow (Mac) or Win+arrow (Windows)
- [ ] Windows snap to screen edges
- [ ] Shortcuts use correct modifiers per OS

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T049: Number Layer Testing

**Objective**: Validate numpad layout and operators

### Test 11: Number Entry
- [ ] Access LAYER_NUMBERS (hold space)
- [ ] Type: 1234567890
- [ ] Numbers appear correctly
- [ ] Numpad layout feels natural (789 top row, 456 middle, 123 bottom)

### Test 12: Operators
- [ ] Access LAYER_NUMBERS
- [ ] Type: + - * / :
- [ ] Test decimal: comma, period
- [ ] Calculate: 123 + 456 = 579
- [ ] All operators work correctly

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T050: Clipboard Operations Testing

**Objective**: Verify OS-aware clipboard shortcuts

### Test 13: macOS Clipboard
- [ ] Switch to LAYER_MAC_BASE
- [ ] Type test text: "Hello from macOS"
- [ ] Select text
- [ ] Access LAYER_NUMBERS, press OS_COPY
- [ ] Verify Cmd+C executed (text copied)
- [ ] Press OS_PASTE → Text pastes
- [ ] Press OS_CUT → Text cuts
- [ ] Press OS_UNDO → Text restored

### Test 14: Windows Clipboard
- [ ] Switch to LAYER_WIN_BASE
- [ ] Type test text: "Hello from Windows"
- [ ] Select text
- [ ] Access LAYER_NUMBERS, press OS_COPY
- [ ] Verify Ctrl+C executed (text copied)
- [ ] Press OS_PASTE → Text pastes
- [ ] Press OS_CUT → Text cuts
- [ ] Press OS_UNDO → Text restored

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T051: Configuration Layer Testing

**Objective**: Verify RGB controls and system functions

### Test 15: RGB Controls
- [ ] Access LAYER_CONFIG (top-right key)
- [ ] Press RGB_TOG → LEDs toggle on/off
- [ ] Press RGB_MODE_FORWARD → Animation changes
- [ ] Adjust brightness (RGB_VAI/VAD) → LEDs brighten/dim
- [ ] Adjust hue (RGB_HUI/HUD) → Colors shift
- [ ] Adjust saturation (RGB_SAI/SAD) → Color intensity changes
- [ ] Test HSV presets → Specific colors activate

### Test 16: Layer Switching
- [ ] Access LAYER_CONFIG
- [ ] Press TO(LAYER_MAC_BASE) → Switches to macOS base
- [ ] Access LAYER_CONFIG again
- [ ] Press TO(LAYER_WIN_BASE) → Switches to Windows base
- [ ] LED colors change to indicate active base

### Test 17: Bootloader Access
- [ ] Access LAYER_CONFIG
- [ ] Press QK_BOOT (top-right key)
- [ ] Keyboard enters bootloader mode
- [ ] Keymapp detects keyboard in flash mode
- [ ] ⚠️ Do not flash firmware during test - just verify access

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T052: Edge Cases Testing

**Objective**: Stress test layer switching and timing

### Test 18: Layer Stacking
- [ ] Access symbol layer (OSL)
- [ ] While holding, try to access function layer → Should not stack
- [ ] Release → Returns to base correctly
- [ ] Access number layer (LT with space)
- [ ] While holding, access config layer → Should not interfere
- [ ] Release → Returns correctly

### Test 19: Dual-Function During Layer Switch
- [ ] Access number layer
- [ ] While active, quickly tap then hold H key
- [ ] Verify tap sends character, hold activates mod
- [ ] No interference between layer tap and mod tap

### Test 20: Rapid Layer Switching
- [ ] Quickly toggle: Base → Symbol → Base → Function → Base → Numbers → Base
- [ ] Repeat 5 times rapidly
- [ ] No stuck layers
- [ ] No missed layer activations
- [ ] Keyboard remains responsive

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T053: Performance Testing

**Objective**: Validate typing performance and firmware size

### Test 21: Typing Speed Consistency
- [ ] Type at normal speed for 1 minute (40-60 WPM typical)
- [ ] No input lag detected
- [ ] No missed keystrokes
- [ ] Home row mods don't false-trigger during fast typing
- [ ] Optional: Use typing test website (e.g., monkeytype.com)

### Test 22: Firmware Size Verification
- [ ] Check GitHub Actions build log for firmware size
- [ ] Verify size < 230KB (90% of 256KB flash)
- [ ] Record actual size: _______ KB
- [ ] Compare to original 10-layer firmware (if available)

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## T054: Regression Testing

**Objective**: Verify preserved QMK features still work

### Test 23: QMK Feature Verification

**CAPS_WORD**:
- [ ] Press CW_TOGG (on base layer)
- [ ] Type: hello world
- [ ] Expect: HELLO_WORLD (caps, underscore for space)
- [ ] Auto-disables after period or exclamation

**COMBO** (4 combos - need combo definitions from keymap.c):
- [ ] Execute combo 1: _______ → Result: _______
- [ ] Execute combo 2: _______ → Result: _______
- [ ] Execute combo 3: _______ → Result: _______
- [ ] Execute combo 4: _______ → Result: _______

**KEY_OVERRIDE** (2 overrides):
- [ ] Override 1: Shift+. → , (dot_comma_override)
- [ ] Override 2: Shift+" → ' (quote_doublequote_override)

**LEADER**:
- [ ] Press QK_LEAD key
- [ ] Execute leader sequence (if configured)
- [ ] Verify leader action executes

**QK_REPEAT_KEY**:
- [ ] Type a letter (e.g., x)
- [ ] Press QK_REPEAT_KEY
- [ ] Letter repeats (xx)

**RGB_MATRIX**:
- [ ] RGB LEDs illuminate
- [ ] Layer-specific colors display
- [ ] Brightness/colors adjustable from config layer

**Result**: ✅ PASS / ❌ FAIL  
**Notes**:

---

## Final Validation

### Implementation Completeness

- [ ] All 6 layers functional (0-5)
- [ ] Both OS base layers working correctly
- [ ] All 3 shared utility layers accessible from both bases
- [ ] OS-aware operations use correct modifiers
- [ ] RGB configuration layer fully functional
- [ ] No obsolete code from old 10-layer structure
- [ ] Firmware size meets constitutional requirements (<230KB)

### Test Summary

- Tests Passed: ____ / 23
- Tests Failed: ____ / 23
- Tests Skipped: ____ / 23

### Critical Issues Found

1. 
2. 
3. 

### Non-Critical Issues Found

1. 
2. 
3. 

### Overall Status

- [ ] ✅ ALL TESTS PASSED - Ready for production use
- [ ] ⚠️ MINOR ISSUES - Usable with noted limitations
- [ ] ❌ CRITICAL ISSUES - Requires fixes before use

---

## Next Steps

If all tests pass:
- [ ] Mark Phase 8 tasks as complete in tasks.md
- [ ] Proceed to Phase 9 (Polish & Documentation)
- [ ] Consider merging feature branch to main

If issues found:
- [ ] Document issues in GitHub Issues
- [ ] Prioritize fixes (critical vs. nice-to-have)
- [ ] Create bugfix commits
- [ ] Re-test after fixes
