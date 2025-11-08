# Contract: Tap Dance Elimination Strategy

**Feature**: 002-minimize-layers  
**Date**: 2025-11-08  
**Purpose**: Migration mapping for all 17 tap dance implementations → MT() macros or direct keycodes

## Overview

**Current State**: vrMEr/keymap.c contains 17 tap dance implementations (DANCE_0 through DANCE_16)  
**Target State**: Zero tap dances - all replaced with QMK built-in MT() macros or direct keycodes  
**Rationale**: Tap dances add complexity, increase firmware size, and duplicate QMK functionality

**Proven Approach**: JRaem eliminated 16 dual-functions using this strategy with 48% code reduction and full constitutional compliance

---

## Tap Dance Analysis Results

```bash
# Analysis command used:
grep -E "DANCE_\d+|TD\(DANCE" vrMEr/keymap.c

# Results: 50+ matches found
# Implementations: DANCE_0, DANCE_1, DANCE_2, DANCE_3, DANCE_4, DANCE_5, DANCE_6, DANCE_7, DANCE_8, DANCE_9, DANCE_10, DANCE_11, DANCE_12, DANCE_13, DANCE_14, DANCE_15, DANCE_16
```

**Note**: Detailed tap dance function analysis pending - will be performed during implementation phase by reading vrMEr/keymap.c tap dance definitions section

---

## Migration Strategy by Category

### Category 1: Modifier + Character → MT() Macro

**Pattern**: Tap sends character, hold activates modifier  
**Replacement**: Use `MT(MOD_xxx, KC_xxx)` macro  
**Examples from expected usage**:
- Tap sends letter, hold sends Ctrl → `MT(MOD_LCTL, KC_X)`
- Tap sends letter, hold sends Alt → `MT(MOD_LALT, KC_X)`
- Tap sends letter, hold sends Cmd/Win → `MT(MOD_LGUI, KC_X)`

**Configuration**:
```c
#define TAPPING_TERM 200        // 200ms threshold (proven from JRaem)
#define PERMISSIVE_HOLD         // Prefer hold when rolling keystrokes
```

**Contract Reference**: See layer-structure.md Contract 7 (Mod-Tap Timing)

---

### Category 2: Layer Access + Character → LT() Macro

**Pattern**: Tap sends character, hold activates layer  
**Replacement**: Use `LT(layer, keycode)` macro  
**Examples from current usage**:
- Tap sends space, hold activates LAYER_NUMBERS → `LT(4, KC_SPC)`
- Tap sends backspace, hold activates layer → `LT(layer, KC_BSPC)`

**Configuration**:
```c
#define TAPPING_TERM 200        // Same threshold for consistency
```

**Contract Reference**: See layer-structure.md Contract 3 (Layer-Tap Space Behavior)

---

### Category 3: Multi-Function Keys → Direct Keycode

**Pattern**: Tap once = action A, tap twice = action B, hold = action C  
**Replacement**: Choose primary function, move secondary to explicit layer position  
**Decision Criteria**:
- If used frequently → place on base layer
- If used rarely → place on utility layer (symbols/function)
- If duplicates existing functionality → eliminate entirely

**Example Migration**:
```c
// BEFORE: Triple-function tap dance
// Tap once = X, Tap twice = Y, Hold = Ctrl

// AFTER: Separate into explicit keys
// Position 1: X (direct character on base layer)
// Position 2: Y (on LAYER_SYMBOLS if needed)
// Position 3: MT(MOD_LCTL, KC_X) (Ctrl+tap on base layer if frequently used)
```

---

### Category 4: OS-Specific Operations → Custom Keycode

**Pattern**: Tap dance switches behavior based on OS  
**Replacement**: Use custom keycode with is_macos_base() detection  
**Examples**:
- Copy (Cmd+C on macOS, Ctrl+C on Windows) → `OS_COPY`
- Paste (Cmd+V on macOS, Ctrl+V on Windows) → `OS_PASTE`
- Undo (Cmd+Z on macOS, Ctrl+Z on Windows) → `OS_UNDO`

**Implementation**: See data-model.md custom keycode definitions (already designed)

**Contract Reference**: See layer-structure.md Contract 6 (OS-Aware Clipboard Operations)

---

## Migration Mapping Template

For each DANCE_X, document:

1. **Current Function**: What does the tap dance do today?
   - Tap once: [key/action]
   - Tap twice: [key/action] (if applicable)
   - Hold: [modifier/layer] (if applicable)

2. **Usage Frequency**: Where is TD(DANCE_X) used?
   - Layer 0 positions: [list]
   - Layer 1 positions: [list]
   - Other layer positions: [list]

3. **Replacement Strategy**: How to replace?
   - Primary function → [MT()/LT()/direct keycode/custom keycode]
   - Secondary function → [new position on layer X / eliminate]
   - Rationale: [why this approach]

4. **Code Changes**:
   ```c
   // BEFORE
   [TD(DANCE_X)]
   
   // AFTER
   [MT(...) or LT(...) or OS_XXX or KC_XXX]
   ```

5. **Testing**: How to verify?
   - Test case 1: [verify primary function works]
   - Test case 2: [verify secondary function accessible]
   - Test case 3: [verify no accidental triggers]

---

## Complete Tap Dance Analysis and Replacement Strategy

### DANCE_0 (Layer 1 - macOS Symbols)

**Current Function**: Tap=@ (DE_AT), Hold=Ctrl, Double-Tap=@@  
**Usage**: Layer 1 (macOS symbols layer), home row position  
**Replacement**: Direct keycode `DE_AT` or `MT(MOD_LCTL, DE_AT)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_0)
// AFTER: DE_AT (direct symbol) or MT(MOD_LCTL, DE_AT) if Ctrl needed on hold
```
**Testing**: Type @ symbol on symbol layer, verify no accidental modifiers

---

### DANCE_1 (Layer 1 - macOS Symbols)

**Current Function**: Tap=/ (DE_SLSH), Hold=Alt, Double-Tap=//  
**Usage**: Layer 1 (macOS symbols layer), home row position  
**Replacement**: Direct keycode `DE_SLSH` or `MT(MOD_LALT, DE_SLSH)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_1)
// AFTER: DE_SLSH (direct symbol) or MT(MOD_LALT, DE_SLSH) if Alt needed
```
**Testing**: Type / symbol on symbol layer

---

### DANCE_2 (Layer 1 - macOS Symbols)

**Current Function**: Tap={ (DE_LCBR), Hold=Cmd, Double-Tap={{  
**Usage**: Layer 1 (macOS symbols layer), home row position  
**Replacement**: Direct keycode `DE_LCBR` or `MT(MOD_LGUI, DE_LCBR)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_2)
// AFTER: DE_LCBR (direct symbol) or MT(MOD_LGUI, DE_LCBR) if Cmd needed
```
**Testing**: Type { symbol on symbol layer

---

### DANCE_3 (Layer 1 - macOS Symbols)

**Current Function**: Tap=) (DE_RPRN), Hold=Cmd, Double-Tap=))  
**Usage**: Layer 1 (macOS symbols layer), home row position  
**Replacement**: Direct keycode `DE_RPRN` or `MT(MOD_RGUI, DE_RPRN)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_3)
// AFTER: DE_RPRN (direct symbol) or MT(MOD_RGUI, DE_RPRN) if Cmd needed
```
**Testing**: Type ) symbol on symbol layer

---

### DANCE_4 (Layer 1 - macOS Symbols)

**Current Function**: Tap=: (DE_COLN), Hold=Ctrl, Double-Tap=::  
**Usage**: Layer 1 (macOS symbols layer), home row position  
**Replacement**: Direct keycode `DE_COLN` or `MT(MOD_RCTL, DE_COLN)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_4)
// AFTER: DE_COLN (direct symbol) or MT(MOD_RCTL, DE_COLN) if Ctrl needed
```
**Testing**: Type : symbol on symbol layer

---

### DANCE_5 (Layer 1 - macOS Symbols, Thumb)

**Current Function**: Tap=Backspace, Hold=Ctrl+Backspace (delete word), Double-Tap=Backspace×2  
**Usage**: Layer 1 thumb cluster  
**Replacement**: `KC_BSPC` (direct) - word deletion moved to explicit key or eliminated  
**Code Change**:
```c
// BEFORE: TD(DANCE_5)
// AFTER: KC_BSPC (simple backspace on symbol layer)
```
**Testing**: Backspace on symbol layer deletes one character

---

### DANCE_6 (Layer 1 - macOS Symbols, Thumb)

**Current Function**: Tap=Delete, Hold=Ctrl+Delete (delete word forward), Double-Tap=Delete×2  
**Usage**: Layer 1 thumb cluster  
**Replacement**: `KC_DEL` (direct) - word deletion moved to explicit key or eliminated  
**Code Change**:
```c
// BEFORE: TD(DANCE_6)
// AFTER: KC_DEL (simple delete on symbol layer)
```
**Testing**: Delete on symbol layer deletes one character

---

### DANCE_7 (Layer 2 - macOS Function)

**Current Function**: Tap=€ (DE_EURO), Hold=Cmd, Double-Tap=€€  
**Usage**: Layer 2 (macOS function layer), home row position  
**Replacement**: Direct keycode `DE_EURO` (modifier not needed on function layer)  
**Code Change**:
```c
// BEFORE: TD(DANCE_7)
// AFTER: DE_EURO (direct € symbol)
```
**Testing**: Type € on function layer

---

### DANCE_8 (Layer 4 - Windows Base)

**Current Function**: Tap== (KC_EQUAL), Hold=Escape, Double-Tap===  
**Usage**: Layer 4 (Windows base layer), top row position  
**Replacement**: Direct keycode `KC_ESC` moved to dedicated position, = to appropriate layer  
**Code Change**:
```c
// BEFORE: TD(DANCE_8)
// AFTER: KC_TRANSPARENT or dedicated Escape key position
```
**Testing**: Verify Escape accessible on Windows base

---

### DANCE_9 (Layer 5 - Windows Function)

**Current Function**: Tap=€ (DE_EURO), Hold=Ctrl, Double-Tap=€€  
**Usage**: Layer 5 (Windows function layer), home row position  
**Replacement**: Direct keycode `DE_EURO` (modifier not needed on function layer)  
**Code Change**:
```c
// BEFORE: TD(DANCE_9)
// AFTER: DE_EURO (direct € symbol)
```
**Testing**: Type € on function layer

---

### DANCE_10 (Layer 6 - Windows Symbols)

**Current Function**: Tap=@ (DE_AT), Hold=Win, Double-Tap=@@  
**Usage**: Layer 6 (Windows symbols layer), home row position  
**Replacement**: Direct keycode `DE_AT` or `MT(MOD_LGUI, DE_AT)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_10)
// AFTER: DE_AT (direct symbol) or MT(MOD_LGUI, DE_AT) if Win needed
```
**Testing**: Type @ symbol on symbol layer

---

### DANCE_11 (Layer 6 - Windows Symbols)

**Current Function**: Tap=/ (DE_SLSH), Hold=Alt, Double-Tap=//  
**Usage**: Layer 6 (Windows symbols layer), home row position  
**Replacement**: Direct keycode `DE_SLSH` or `MT(MOD_LALT, DE_SLSH)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_11)
// AFTER: DE_SLSH (direct symbol) or MT(MOD_LALT, DE_SLSH) if Alt needed
```
**Testing**: Type / symbol on symbol layer

---

### DANCE_12 (Layer 6 - Windows Symbols)

**Current Function**: Tap={ (DE_LCBR), Hold=Ctrl, Double-Tap={{  
**Usage**: Layer 6 (Windows symbols layer), home row position  
**Replacement**: Direct keycode `DE_LCBR` or `MT(MOD_LCTL, DE_LCBR)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_12)
// AFTER: DE_LCBR (direct symbol) or MT(MOD_LCTL, DE_LCBR) if Ctrl needed
```
**Testing**: Type { symbol on symbol layer

---

### DANCE_13 (Layer 6 - Windows Symbols)

**Current Function**: Tap=) (DE_RPRN), Hold=Ctrl, Double-Tap=))  
**Usage**: Layer 6 (Windows symbols layer), home row position  
**Replacement**: Direct keycode `DE_RPRN` or `MT(MOD_RCTL, DE_RPRN)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_13)
// AFTER: DE_RPRN (direct symbol) or MT(MOD_RCTL, DE_RPRN) if Ctrl needed
```
**Testing**: Type ) symbol on symbol layer

---

### DANCE_14 (Layer 6 - Windows Symbols)

**Current Function**: Tap=: (DE_COLN), Hold=Win, Double-Tap=::  
**Usage**: Layer 6 (Windows symbols layer), home row position  
**Replacement**: Direct keycode `DE_COLN` or `MT(MOD_RGUI, DE_COLN)` if modifier needed  
**Code Change**:
```c
// BEFORE: TD(DANCE_14)
// AFTER: DE_COLN (direct symbol) or MT(MOD_RGUI, DE_COLN) if Win needed
```
**Testing**: Type : symbol on symbol layer

---

### DANCE_15 (Layer 6 - Windows Symbols, Thumb)

**Current Function**: Tap=Backspace, Hold=Alt+Backspace (delete word macOS-style on Windows), Double-Tap=Backspace×2  
**Usage**: Layer 6 thumb cluster  
**Replacement**: `KC_BSPC` (direct) - word deletion moved to explicit key or eliminated  
**Code Change**:
```c
// BEFORE: TD(DANCE_15)
// AFTER: KC_BSPC (simple backspace on symbol layer)
```
**Testing**: Backspace on symbol layer deletes one character

---

### DANCE_16 (Layer 6 - Windows Symbols, Thumb)

**Current Function**: Tap=Delete, Hold=Alt+Delete (delete word forward), Double-Tap=Delete×2  
**Usage**: Layer 6 thumb cluster  
**Replacement**: `KC_DEL` (direct) - word deletion moved to explicit key or eliminated  
**Code Change**:
```c
// BEFORE: TD(DANCE_16)
// AFTER: KC_DEL (simple delete on symbol layer)
```
**Testing**: Delete on symbol layer deletes one character

---

## Implementation Checklist

**Phase 1 - Analysis** (to be performed during task implementation):
- [ ] Read vrMEr/keymap.c tap dance definitions section (search for `tap_dance_action_t`)
- [ ] Document each DANCE_X function (tap/double-tap/hold behaviors)
- [ ] Map each DANCE_X to layer positions (which layers use which dances)
- [ ] Categorize each dance (modifier+char, layer+char, multi-function, OS-specific)
- [ ] Update this contract with complete analysis

**Phase 2 - Design**:
- [ ] For each DANCE_X, choose replacement strategy (MT/LT/direct/custom)
- [ ] For multi-function dances, decide primary vs secondary function placement
- [ ] Verify no functionality lost in migration (all functions accessible somewhere)
- [ ] Update this contract with specific replacement keycodes

**Phase 3 - Implementation**:
- [ ] Replace all TD(DANCE_X) references in keymaps with chosen replacements
- [ ] Remove tap dance definitions from keymap.c
- [ ] Remove `TAP_DANCE_ENABLE = yes` from rules.mk
- [ ] Verify firmware compiles without tap dance code

**Phase 4 - Validation**:
- [ ] Test each replaced function on hardware (see quickstart.md)
- [ ] Verify timing feels natural (adjust TAPPING_TERM if needed)
- [ ] Confirm no accidental modifier triggers during fast typing
- [ ] Measure firmware size reduction (expect ~100-200 lines removed)

---

## Success Criteria

**SC-002**: Eliminate all tap dance implementations (0 remaining)  
**SC-008**: Firmware size < 230KB (256KB flash limit)  
**SC-009**: Code reduction of 40-50% (930 lines → 465-550 lines)  
**SC-010**: Constitutional compliance (all 5 principles validated)

**From Constitution Principle 2**: "Minimize Layers & Dual-Functions: Target ≤6 layers with minimal dual-function keys (prefer QMK's built-in MT() over custom tap dances)"

**Validation**: Run `grep -c "TD(DANCE" vrMEr/keymap.c` → must return 0 after migration

---

## Risks & Mitigation

**Risk 1**: Some tap dances may have complex logic not easily replaceable  
**Mitigation**: Document complex cases here, consider custom keycode implementation if truly needed, or move function to explicit layer position

**Risk 2**: Users may prefer tap dance behavior over MT() timing  
**Mitigation**: Tune TAPPING_TERM, PERMISSIVE_HOLD, and IGNORE_MOD_TAP_INTERRUPT to match user preference (proven values: 200ms from JRaem)

**Risk 3**: Firmware size may not reduce as much as expected  
**Mitigation**: If SC-008 or SC-009 not met, consider additional optimizations (disable unused features, optimize data structures)

**Risk 4**: Functionality may be lost if secondary functions not placed elsewhere  
**Mitigation**: During Phase 2 design, explicitly map every secondary function to new layer position or validate elimination is acceptable

---

## References

- **JRaem Implementation**: See specs/001-minimize-layers/ for proven tap dance elimination approach (16 dual-functions → 0)
- **QMK Documentation**: [Mod-Tap](https://docs.qmk.fm/#/mod_tap), [Layer-Tap](https://docs.qmk.fm/#/feature_layers)
- **Constitution**: See .specify/memory/constitution.md Principle 2 (Layer Minimization)
- **Contract Reference**: See layer-structure.md Contract 7 (Mod-Tap Timing)

---

**Note**: This contract will be updated during implementation with specific analysis results for each DANCE_X. Current version establishes migration framework and strategy.
