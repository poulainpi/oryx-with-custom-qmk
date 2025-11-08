# vrMEr Testing Quickstart

**Feature**: 002-minimize-layers  
**Date**: 2025-11-08  
**Purpose**: Quick testing guide for validating the 6-layer vrMEr implementation

## Prerequisites

Before testing:

- [ ] Firmware compiled successfully (GitHub Actions or Docker)
- [ ] Firmware flashed to ZSA Voyager using Keymapp
- [ ] Access to both macOS and Windows systems (physical or VM)
- [ ] Text editor available on both systems
- [ ] Review contracts/layer-structure.md for behavioral guarantees

## 5-Minute Smoke Test

**Objective**: Quick validation that core functionality works

### 1. Layer Switching
- [ ] Power on keyboard
- [ ] Press TO(5) to access LAYER_CONFIG
- [ ] Press TO(0) to return to LAYER_MAC_BASE
- [ ] Press TO(1) to switch to LAYER_WIN_BASE
- [ ] LED color changes: Blue (Mac) → Cyan (Windows)

### 2. Basic Typing
- [ ] Type: "The quick brown fox jumps over the lazy dog"
- [ ] All letters appear correctly on both OS bases
- [ ] No accidental modifier triggers

### 3. Layer Access
- [ ] Tap left thumb → LAYER_SYMBOLS activates → type @ → returns to base
- [ ] Tap right thumb → LAYER_FUNCTION activates → press F1 → returns to base
- [ ] Hold space → LAYER_NUMBERS activates → type 123 → release → returns to base

### 4. Home Row Mods
- [ ] Quick tap H → H letter
- [ ] Hold H (>200ms) → Ctrl (Mac) or Win (Windows) activates
- [ ] No false activations during normal typing

### 5. Clipboard Operations
- [ ] Select text, press OS_COPY on number layer
- [ ] Verify Cmd+C (Mac) or Ctrl+C (Windows) executes
- [ ] Press OS_PASTE → Text pastes correctly

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

## Layer-Specific Testing

### Test 1: macOS Base (LAYER_MAC_BASE)

**Setup**: Press TO(0), verify blue LED

**Typing**:
- [ ] Type full alphabet: a-z (all appear correctly)
- [ ] Type common punctuation: . , " ?
- [ ] No missed characters

**Home Row Mods** (Cmd-optimized):
- [ ] Hold H → Ctrl (test with Ctrl+C)
- [ ] Hold I → Alt (test with Alt+Tab)
- [ ] Hold E → Cmd (test with Cmd+Space) ← Primary on E
- [ ] Hold T → Cmd (test with Cmd+Tab) ← Primary on T
- [ ] Hold R → Alt
- [ ] Hold N → Ctrl

**Layer Access**:
- [ ] Tap left thumb → LAYER_SYMBOLS → type @ → returns to MAC_BASE
- [ ] Tap right thumb → LAYER_FUNCTION → press F1 → returns to MAC_BASE
- [ ] Hold space → LAYER_NUMBERS → type 1 → release → returns to MAC_BASE

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 2: Windows Base (LAYER_WIN_BASE)

**Setup**: Press TO(1), verify cyan LED

**Typing**:
- [ ] Type full alphabet: a-z (identical to Mac base)
- [ ] Type common punctuation: . , " ?

**Home Row Mods** (Ctrl-optimized):
- [ ] Hold H → Win (test with Win+E)
- [ ] Hold I → Alt (test with Alt+Tab)
- [ ] Hold E → Ctrl (test with Ctrl+C) ← Primary on E
- [ ] Hold T → Ctrl (test with Ctrl+V) ← Primary on T
- [ ] Hold R → Alt
- [ ] Hold N → Win

**Layer Access**:
- [ ] Tap left thumb → LAYER_SYMBOLS → type @ → returns to WIN_BASE
- [ ] Tap right thumb → LAYER_FUNCTION → press F1 → returns to WIN_BASE
- [ ] Hold space → LAYER_NUMBERS → type 1 → release → returns to WIN_BASE

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 3: Symbols Layer (LAYER_SYMBOLS)

**Access**: OSL (one-shot) from either base layer

**Symbols Available** (to be validated during implementation):
- [ ] Type programming snippet: `if (x == 0) { return true; }`
- [ ] Requires: (, ), {, }, ;, ==, if, return, true (alpha via transparent)
- [ ] No missed characters
- [ ] Typing feels fluid, no lag

**Layer Return**:
- [ ] After each symbol keypress → returns to originating base
- [ ] After ONESHOT_TIMEOUT (5s) with no keypress → returns to base
- [ ] Double-tap OSL → layer "locks" until OSL pressed again

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 4: Function/Navigation Layer (LAYER_FUNCTION)

**Access**: OSL (one-shot) from either base layer

**Function Keys**:
- [ ] F1 through F12 accessible
- [ ] All F-keys send correctly

**Navigation**:
- [ ] Arrow keys: Up, Down, Left, Right work correctly
- [ ] macOS: Cmd+Up, Cmd+Down, Opt+Left, Opt+Right (if mapped)
- [ ] Windows: Home, End, Page Up, Page Down (if mapped)

**German Umlauts**:
- [ ] ä (DE_ADIA) types correctly
- [ ] ö (DE_ODIA) types correctly
- [ ] ü (DE_UDIA) types correctly
- [ ] ß (DE_SS) types correctly
- [ ] € (DE_EURO) types correctly (if mapped)

**Layer Return**:
- [ ] After keypress → returns to originating base
- [ ] No stuck function layer

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 5: Numbers Layer (LAYER_NUMBERS)

**Access**: LT(4, Space) - hold space from either base

**Numpad Layout**:
- [ ] Numbers 0-9 arranged in numpad style
- [ ] Operators: +, -, *, / accessible
- [ ] Colon (:) available (if needed for time entry)

**OS-Aware Clipboard** (from this layer):
- [ ] OS_UNDO: Cmd+Z (Mac) / Ctrl+Z (Windows)
- [ ] OS_COPY: Cmd+C (Mac) / Ctrl+C (Windows)
- [ ] OS_PASTE: Cmd+V (Mac) / Ctrl+V (Windows)
- [ ] OS_CUT: Cmd+X (Mac) / Ctrl+X (Windows)

**Layer Return**:
- [ ] Release space → immediately returns to base
- [ ] No delay in return
- [ ] Tap space (<200ms) → sends space character, not number layer

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 6: Config Layer (LAYER_CONFIG)

**Access**: TO(5) - persistent layer

**RGB Controls**:
- [ ] RGB toggle (on/off)
- [ ] Brightness increase/decrease
- [ ] Hue change (cycle colors)
- [ ] Saturation change
- [ ] Animation mode toggle

**Layer Switching**:
- [ ] TO(0) → returns to LAYER_MAC_BASE (blue LED)
- [ ] TO(1) → switches to LAYER_WIN_BASE (cyan LED)
- [ ] No auto-return (layer persists until manual switch)

**Bootloader**:
- [ ] QK_BOOT immediately enters bootloader mode
- [ ] Keyboard ready for firmware flash

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

## Edge Case Testing

### Test 7: Layer Stacking
- [ ] From MAC_BASE, access LAYER_SYMBOLS → type @ → returns to MAC_BASE (not another layer)
- [ ] From WIN_BASE, access LAYER_FUNCTION → press F1 → returns to WIN_BASE
- [ ] While holding space (LAYER_NUMBERS), tap left thumb → LAYER_SYMBOLS activates on top
- [ ] Release space → both layers deactivate, returns to base

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 8: Rapid Switching
- [ ] Quickly alternate: OSL(SYMBOLS) → type @ → OSL(FUNCTION) → F1 → OSL(SYMBOLS) → type #
- [ ] All keys register correctly
- [ ] No layer confusion or stuck layers

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 9: Home Row Mod Timing
- [ ] Type "hi" quickly (<100ms between keys) → "hi" appears, no Ctrl activation
- [ ] Type "h" slowly (hold 250ms) then release → Ctrl modifier felt (no character)
- [ ] Type "h" at exactly 200ms (TAPPING_TERM boundary) → implementation-defined (acceptable)

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 10: OS Detection Switching
- [ ] Start on LAYER_MAC_BASE, use OS_COPY → Cmd+C executes
- [ ] Switch to LAYER_WIN_BASE via TO(1), use OS_COPY → Ctrl+C executes
- [ ] Switch back to LAYER_MAC_BASE via TO(0), use OS_COPY → Cmd+C executes again
- [ ] No OS detection errors

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

## Performance Validation

### Test 11: Typing Speed
- [ ] Type at normal speed (60-80 WPM) on both bases
- [ ] No lag, no missed characters
- [ ] Home row mods don't interfere with fast typing

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 12: Firmware Size
- [ ] Check compiled firmware size: **MUST BE < 230KB** (SC-008)
- [ ] Flash memory: 256KB total, target 90% (230KB)
- [ ] Command: Check GitHub Actions build log or Docker output

**Current Size**: _______ KB  
**Status**: ⏸️ PENDING / ✅ PASS (< 230KB) / ❌ FAIL (≥ 230KB)

---

### Test 13: Code Reduction
- [ ] Measure vrMEr/keymap.c line count after implementation
- [ ] Original: 930 lines
- [ ] Target: 465-550 lines (40-50% reduction, SC-009)
- [ ] Command: `(Get-Content vrMEr/keymap.c | Measure-Object -Line).Lines` (PowerShell)

**Original**: 930 lines  
**New**: _______ lines  
**Reduction**: _______ % (MUST BE 40-50%)  
**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 14: Tap Dance Elimination
- [ ] Search for remaining tap dances: `grep -c "TD(DANCE" vrMEr/keymap.c`
- [ ] Result MUST BE 0 (SC-002)

**Tap Dances Remaining**: _______  
**Status**: ⏸️ PENDING / ✅ PASS (0) / ❌ FAIL (> 0)

---

## Regression Testing

### Test 15: QMK Features Preserved
- [ ] Caps Word (CW_TOGG) toggles correctly
- [ ] Repeat Key (QK_REPEAT_KEY) repeats last character
- [ ] Leader Key (QK_LEAD) triggers leader sequences (if configured)
- [ ] One-Shot Shift (OSM(MOD_LSFT)) capitalizes next letter only
- [ ] Application Key (KC_APPLICATION) opens context menu

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

### Test 16: USB Stability
- [ ] Plug keyboard into USB port → immediately recognized
- [ ] Unplug and replug → no configuration lost
- [ ] Wake computer from sleep → keyboard responsive

**Status**: ⏸️ PENDING / ✅ PASS / ❌ FAIL

---

## Constitutional Compliance Check

### Test 17: Principle Validation

**Principle 1 - Minimal Firmware Size**:
- [ ] Firmware < 230KB (Test 12)
- [ ] Status: ⏸️ PENDING / ✅ PASS / ❌ FAIL

**Principle 2 - Layer Minimization**:
- [ ] Exactly 6 layers (0-5)
- [ ] Zero tap dances (Test 14)
- [ ] All MT() macros used correctly
- [ ] Status: ⏸️ PENDING / ✅ PASS / ❌ FAIL

**Principle 3 - OS-Specific Optimization**:
- [ ] macOS base uses Cmd-optimized home row mods (Test 1)
- [ ] Windows base uses Ctrl-optimized home row mods (Test 2)
- [ ] Shared utility layers work from both bases (Tests 3-5)
- [ ] OS_COPY/PASTE/CUT/UNDO use correct modifiers (Test 5, Test 10)
- [ ] Status: ⏸️ PENDING / ✅ PASS / ❌ FAIL

**Principle 4 - Oryx Integration**:
- [ ] GitHub Actions build workflow succeeds
- [ ] Firmware downloadable from artifacts
- [ ] Status: ⏸️ PENDING / ✅ PASS / ❌ FAIL

**Principle 5 - Code Maintainability**:
- [ ] Layer enum constants used (LAYER_MAC_BASE, etc.)
- [ ] Custom keycodes clearly defined (OS_COPY, etc.)
- [ ] Code reduction 40-50% (Test 13)
- [ ] Comments document layer purpose and custom logic
- [ ] Status: ⏸️ PENDING / ✅ PASS / ❌ FAIL

**Overall Constitutional Compliance**: ⏸️ PENDING / ✅ PASS ALL 5 / ❌ FAIL

---

## Bug Reporting Template

If test fails, document:

**Test ID**: [e.g., Test 5 - Numbers Layer]  
**Expected Behavior**: [what should happen]  
**Actual Behavior**: [what actually happened]  
**Steps to Reproduce**:
1. [step 1]
2. [step 2]
3. [step 3]

**System**: macOS / Windows  
**Layer Active**: [layer number/name]  
**Firmware Version**: [commit hash or build date]  

**Contract Violation**: [reference contract from layer-structure.md if applicable]

---

## Testing Completion Checklist

- [ ] All 17 tests executed (T001-T017)
- [ ] All tests PASS (no ❌ FAIL)
- [ ] Firmware size < 230KB (SC-008)
- [ ] Code reduction 40-50% (SC-009)
- [ ] Zero tap dances (SC-002)
- [ ] All 5 constitutional principles validated (SC-010)
- [ ] No bugs reported (or all bugs fixed)

**Final Status**: ⏸️ PENDING / ✅ READY FOR PRODUCTION / ❌ NEEDS FIXES

---

## Next Steps After Testing

1. If all tests PASS → Merge feature branch to main
2. If any test FAILS → Fix bugs, retest failed tests
3. If firmware size > 230KB → Optimize code, disable unused features
4. If code reduction < 40% → Review for additional consolidation opportunities
5. Document any workarounds or known limitations in README.md
