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

## Placeholder Mappings (To Be Completed During Implementation)

### DANCE_0

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_1

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_2

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_3

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_4

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_5

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_6

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_7

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_8

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_9

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_10

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_11

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_12

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_13

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_14

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_15

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

---

### DANCE_16

**Current Function**: [TO BE ANALYZED from vrMEr/keymap.c]  
**Usage**: [TO BE DETERMINED]  
**Replacement**: [TO BE DESIGNED based on function analysis]  
**Code Change**: [TO BE IMPLEMENTED]  
**Testing**: [TO BE DEFINED]

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
