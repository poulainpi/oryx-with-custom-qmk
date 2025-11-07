# Quickstart: Testing the Minimized Layer Layout

**Feature**: Minimize Keyboard Layers  
**Created**: 2025-11-07  
**Purpose**: Comprehensive testing guide for validating the consolidated 5-layer keyboard layout

## Prerequisites

### Before Testing

- [x] Firmware compiled successfully (GitHub Actions or local build)
- [x] Firmware flashed to ZSA Voyager keyboard using Keymapp
- [x] Access to both Windows and macOS systems (or VM)
- [x] Oryx layout editor accessible (for visual reference)
- [x] Layer documentation reviewed (data-model.md, layer-structure.md)

### Testing Environment

**Windows System**:
- Windows 10 or 11
- Text editor (Notepad++, VS Code, or similar)
- Terminal/PowerShell for testing shortcuts

**macOS System**:
- macOS Sonoma, Sequoia, or later
- Text editor (TextEdit, VS Code, or similar)
- Terminal for testing shortcuts

**Tools**:
- [Keymapp](https://www.zsa.io/flash) for firmware flashing
- Oryx layout viewer for visual reference (optional)
- Clipboard test content (text to copy/paste)

## Quick Start (5-Minute Smoke Test)

### 1. Verify Layer Switching

**Goal**: Confirm base layer switching works

```
1. Power on keyboard → Should default to macOS or Windows base (set in config)
2. Hold top-right key → Access configuration layer (RGB controls visible)
3. Press TO(macOS) key → Switch to macOS base layer
4. Hold top-right key again → Access configuration layer
5. Press TO(Windows) key → Switch to Windows base layer

✅ PASS: Layers switch correctly, LED colors change per base layer
❌ FAIL: Cannot access config layer or layers don't switch
```

### 2. Verify Basic Typing

**Goal**: Confirm alpha keys work on both base layers

```
On macOS base:
Type: "The quick brown fox jumps over the lazy dog"

On Windows base:
Type: "The quick brown fox jumps over the lazy dog"

✅ PASS: All letters type correctly on both bases
❌ FAIL: Missing letters, wrong characters, or stuck keys
```

### 3. Verify Layer Access

**Goal**: Confirm thumb cluster layer access works

```
On either base layer:
1. Tap left inner thumb (OSL symbols) → Type a symbol (e.g., @) → Auto-return to base
2. Tap right inner thumb (OSL function) → Press F1 → Auto-return to base
3. Hold right outer thumb (LT numbers) → Type numbers 1-9 → Release → Returns to base

✅ PASS: All three utility layers accessible and return to base
❌ FAIL: Layer doesn't activate, stuck on layer, or wrong layer accessed
```

### 4. Verify Home Row Mods

**Goal**: Confirm mod-tap keys work correctly

```
On macOS base:
- Quick tap H → Sends H
- Hold H (>200ms) → Activates Ctrl modifier

On Windows base:
- Quick tap H → Sends H
- Hold H (>200ms) → Activates Win modifier

✅ PASS: Tap sends letter, hold activates modifier (correct per OS)
❌ FAIL: False activations, wrong modifier, or tap doesn't work
```

### 5. Verify OS-Specific Shortcuts

**Goal**: Confirm clipboard operations use correct modifiers

```
On macOS base (number layer):
- Copy text → Should use Cmd+C
- Paste text → Should use Cmd+V

On Windows base (number layer):
- Copy text → Should use Ctrl+C
- Paste text → Should use Ctrl+V

✅ PASS: Clipboard operations work with OS-appropriate shortcuts
❌ FAIL: Wrong modifier used or shortcuts don't work
```

## Comprehensive Test Scenarios

### Base Layer Testing

#### Test 1: Alpha Key Layout (macOS Base)

**Objective**: Verify all 26 letters in correct positions

**Steps**:
1. Switch to macOS base layer
2. Type complete alphabet: `a b c d e f g h i j k l m n o p q r s t u v w x y z`
3. Verify current layout positions: HIEA O (left home), DTRNS (right home)

**Expected**: All letters type correctly in expected positions

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 2: Alpha Key Layout (Windows Base)

**Objective**: Verify identical layout on Windows base

**Steps**:
1. Switch to Windows base layer
2. Type complete alphabet again
3. Verify positions match macOS base

**Expected**: Identical letter positions as macOS

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 3: Home Row Mods (macOS)

**Objective**: Verify mod-tap functionality on macOS base

**Steps**:
1. Tap H → Should type 'h'
2. Hold H + tap C → Should send Ctrl+C (copy shortcut but with Ctrl held via H)
3. Tap I → Should type 'i'
4. Hold I + tap Tab → Should send Alt+Tab
5. Tap E → Should type 'e'
6. Hold E + tap C → Should send Cmd+C (macOS copy)

**Expected**: Tap = letter, Hold = modifier (Ctrl/Alt/Cmd as specified)

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 4: Home Row Mods (Windows)

**Objective**: Verify swapped Ctrl/Cmd positions on Windows base

**Steps**:
1. Tap H → Should type 'h'
2. Hold H + tap L → Should send Win+L (lock screen)
3. Tap E → Should type 'e'
4. Hold E + tap C → Should send Ctrl+C (Windows copy)

**Expected**: Tap = letter, Hold = modifier (Ctrl/Cmd swapped vs macOS)

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Symbol Layer Testing

#### Test 5: Symbol Access (Both Bases)

**Objective**: Verify unified symbol layer accessible from both bases

**Steps**:
1. On macOS base, tap left inner thumb (OSL symbols)
2. Type symbols: `@ & [ ] { } ( ) < > = ! ? % $ # + - * /`
3. Verify auto-return to macOS base after each symbol
4. Switch to Windows base
5. Repeat symbol typing sequence
6. Verify identical symbol positions

**Expected**: All symbols accessible, same positions on both bases

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 6: Special Characters

**Objective**: Verify less-common symbols and German layout characters

**Steps**:
1. Access symbol layer
2. Type: `` § ` ~ ^ | \ _ : ; ``
3. Verify all characters display correctly

**Expected**: All special characters accessible

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Function/Navigation Layer Testing

#### Test 7: Function Keys (F1-F12)

**Objective**: Verify all function keys accessible

**Steps**:
1. Access function layer (right inner thumb OSL)
2. Press F1, F2, F3... through F12
3. Verify each F-key triggers expected action (browser refresh, etc.)

**Expected**: All 12 function keys accessible and functional

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 8: Navigation Keys

**Objective**: Verify arrow keys, Page Up/Down, Home/End

**Steps**:
1. Open text editor with multi-line content
2. Access function layer
3. Test arrow keys (←↓↑→) → Should move cursor
4. Test Page Up/Down → Should scroll page
5. Test Home/End → Should move to line start/end

**Expected**: All navigation keys work as expected

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 9: German Umlauts

**Objective**: Verify ä, ö, ü, ß, € accessible from function layer

**Steps**:
1. Access function layer
2. Type: `ä ö ü ß €`
3. Verify all umlauts and euro symbol display correctly

**Expected**: All German characters accessible

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 10: Tab, Escape, Enter

**Objective**: Verify editing keys on function layer

**Steps**:
1. Access function layer
2. Press Tab → Should indent or move focus
3. Press Escape → Should cancel action (e.g., close dialog)
4. Press Enter → Should create new line

**Expected**: All editing keys functional

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Number Layer Testing

#### Test 11: Number Pad Layout

**Objective**: Verify number entry and operators

**Steps**:
1. Hold right outer thumb (LT number layer)
2. While holding, type: `1 2 3 4 5 6 7 8 9 0`
3. Type operators: `+ - * / :`
4. Type decimal: `3.14`

**Expected**: All numbers and operators accessible while holding thumb

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 12: Space Key Tap Behavior

**Objective**: Verify LT tap sends space, hold activates layer

**Steps**:
1. Quick tap right outer thumb → Should type space
2. Hold right outer thumb → Should activate number layer (not type space)

**Expected**: Tap = space, Hold = number layer

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### OS-Specific Clipboard Testing

#### Test 13: macOS Clipboard Shortcuts

**Objective**: Verify Cmd+Z/C/V/X on macOS base

**Prerequisites**: Switch to macOS base layer, have test text ready

**Steps**:
1. Type some text: "Test content"
2. Access number layer → Press clipboard copy key → Text should copy
3. Delete text
4. Access number layer → Press clipboard paste key → Text should paste
5. Access number layer → Press clipboard cut key → Text should cut
6. Access number layer → Press clipboard undo key → Text should restore

**Expected**: All clipboard shortcuts use Cmd modifier, work correctly

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 14: Windows Clipboard Shortcuts

**Objective**: Verify Ctrl+Z/C/V/X on Windows base

**Prerequisites**: Switch to Windows base layer, have test text ready

**Steps**:
1. Type some text: "Test content"
2. Access number layer → Press clipboard copy key → Text should copy (Ctrl+C)
3. Delete text
4. Access number layer → Press clipboard paste key → Text should paste (Ctrl+V)
5. Access number layer → Press clipboard cut key → Text should cut (Ctrl+X)
6. Access number layer → Press clipboard undo key → Text should restore (Ctrl+Z)

**Expected**: All clipboard shortcuts use Ctrl modifier, work correctly

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Configuration Layer Testing

#### Test 15: RGB Controls

**Objective**: Verify RGB lighting adjustments

**Steps**:
1. Access config layer
2. Toggle RGB on/off
3. Change RGB mode
4. Adjust hue, saturation, brightness
5. Adjust animation speed

**Expected**: All RGB controls functional, visual feedback matches adjustments

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 16: Layer Switching from Config

**Objective**: Verify TO() keys switch base layers

**Steps**:
1. Access config layer
2. Press TO(macOS) → Should switch to macOS base (LED color changes)
3. Access config layer again
4. Press TO(Windows) → Should switch to Windows base (LED color changes)

**Expected**: Layer switches work, LED colors update correctly

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 17: Bootloader Access

**Objective**: Verify QK_BOOT enters bootloader mode

**Steps**:
1. Access config layer
2. Press QK_BOOT key (usually top-right area)
3. Keyboard should disconnect and enter bootloader mode
4. Reconnect or flash new firmware to exit

**Expected**: Keyboard enters bootloader mode (LED pattern changes, disconnects)

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Edge Case Testing

#### Test 18: Rapid Layer Switching

**Objective**: Verify no layer stacking or stuck layers

**Steps**:
1. Rapidly tap OSL(symbols) → type @ → tap OSL(symbols) → type & → repeat
2. Verify auto-return to base after each symbol
3. Hold LT(numbers) → type 1 → release → immediately hold again → type 2 → release
4. Verify returns to base each time

**Expected**: Clean layer transitions, no stuck layers

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 19: Dual-Function Timing Edge Cases

**Objective**: Verify tap vs hold threshold (200ms)

**Steps**:
1. Very quick tap (~50ms) of home row mod (e.g., H) → Should send letter
2. Medium tap (~150ms) of home row mod → Should send letter (below threshold)
3. Slow tap (~250ms) of home row mod → Should activate modifier (above threshold)
4. Test with multiple home row mods

**Expected**: Consistent tap/hold differentiation at 200ms threshold

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

#### Test 20: Layer Transparency Fallthrough

**Objective**: Verify undefined keys on utility layers fall through to base

**Steps**:
1. Access symbol layer
2. Press a key position that should be transparent (not a symbol)
3. Verify it sends the base layer key
4. Repeat on function and number layers

**Expected**: Transparent positions send base layer keys

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

## Performance Testing

### Test 21: Typing Speed Baseline

**Objective**: Verify no regression in typing speed

**Steps**:
1. Use typing test website (e.g., 10fastfingers.com)
2. Take typing test on macOS base → Record WPM
3. Take typing test on Windows base → Record WPM
4. Compare with pre-consolidation typing speed

**Expected**: <5% difference in typing speed (within normal variance)

**macOS WPM**: _____ | **Windows WPM**: _____ | **Previous WPM**: _____  
**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

### Test 22: Firmware Size Validation

**Objective**: Confirm firmware size within constraints

**Steps**:
1. Check compiled firmware size in GitHub Actions output or local build
2. Compare with 256KB flash limit
3. Verify <90% usage (target: <230KB)

**Expected**: Firmware size <230KB (ideally 20-30KB smaller than pre-consolidation)

**Firmware Size**: _____ KB | **Flash Usage**: _____ %  
**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

## Regression Testing

### Test 23: Preserved Features

**Objective**: Verify all original features still functional

**Checklist**:
- ☐ Caps Word (CW_TOGG) works
- ☐ Repeat Key (QK_REPEAT_KEY) works
- ☐ Leader Key (QK_LEAD) works
- ☐ Key overrides (Shift+dot=comma, Shift+quote=doublequote) work
- ☐ Combo keys (4 combos defined) work
- ☐ Media keys (if present) work

**Expected**: All features functional as before

**Actual**: ☐ Pass ☐ Fail  
**Notes**: _______________________________

## Test Summary

### Overall Results

**Total Tests**: 23  
**Tests Passed**: _____  
**Tests Failed**: _____  
**Pass Rate**: _____ %

### Critical Issues (Blocking)

_(List any failures that prevent normal keyboard usage)_

1. _______________________________
2. _______________________________

### Minor Issues (Non-Blocking)

_(List any failures that don't prevent usage but need fixing)_

1. _______________________________
2. _______________________________

### Recommendations

☐ **Ready for daily use** - All critical tests passed  
☐ **Ready with caveats** - Minor issues acceptable  
☐ **Not ready** - Critical issues must be fixed

---

**Tested By**: _____________________  
**Date**: _____________________  
**Firmware Version**: _____________________  
**Branch**: 001-minimize-layers
