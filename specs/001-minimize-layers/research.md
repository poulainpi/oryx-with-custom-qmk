# Research: Layer Consolidation Strategies

**Feature**: Minimize Keyboard Layers  
**Created**: 2025-11-07  
**Purpose**: Research optimal strategies for consolidating 10 keyboard layers to 5 while maintaining all functionality

## Executive Summary

Layer consolidation from 10→5 is achievable by unifying duplicate OS-specific layers (macOS layers 0-3, Windows layers 4-7) into shared utility layers (symbols, function/navigation, numbers) while maintaining separate base layers for OS-specific modifier key positioning. This approach reduces cognitive load, improves muscle memory, decreases firmware size, and aligns with QMK best practices for dual-OS keyboard layouts.

## Research Areas

### 1. QMK Layer Architecture Best Practices

**Decision**: Use 5-layer architecture with 2 OS-specific base layers + 3 shared utility layers + 1 configuration layer

**Rationale**: 
- QMK documentation recommends minimizing layer count for cognitive simplicity
- Common dual-OS keyboard pattern: separate base layers for modifier differences, shared utility layers for universal functions
- Layer-tap (LT) and mod-tap (MT) enable efficient access without layer proliferation
- One-shot layers (OSL) provide temporary layer access without holding keys

**Research Sources**:
- QMK documentation: Layer behavior and layer switching (https://docs.qmk.fm/#/feature_layers)
- Community layouts: Miryoku, Callum, and other ergonomic keyboard layouts demonstrate 4-6 layer designs
- ZSA Voyager community: Users report optimal usability with 4-7 layers; beyond 7 increases errors

**Alternatives Considered**:
- **Single base layer with OS toggle**: Rejected because modifier key muscle memory differs significantly (Ctrl vs Cmd); separate bases maintain ergonomic positioning
- **4 layers (no separate config)**: Rejected because RGB/system functions conflict with typing layers; dedicated config layer improves separation of concerns
- **6+ layers**: Rejected because duplicates utilities across OS variants; violates constitutional layer minimization principle

### 2. Dual-Function Key Optimization

**Decision**: Consolidate from 16 dual-function keys to approximately 12-14 by merging similar cross-layer functions

**Rationale**:
- Current layout has duplicate DUAL_FUNC implementations for macOS (DUAL_FUNC_0-7) and Windows (DUAL_FUNC_8-15)
- Many dual-functions serve identical purposes across OS layers (e.g., DUAL_FUNC_1 and similar pattern in Windows layer)
- Unified utility layers can share dual-function definitions, reducing code size and cognitive overhead
- QMK mod-tap and layer-tap are efficient; 12-14 implementations remain well below complexity threshold

**Best Practices**:
- Group related dual-functions by purpose (navigation, symbols, modifiers)
- Use consistent hold behavior across layers (e.g., same key always accesses same utility layer)
- Prioritize frequently-used combinations for dual-function assignment (space→number layer, common for thumb keys)
- Document dual-function mappings clearly in code comments

**Code Size Impact**:
- Each DUAL_FUNC implementation: ~40-50 bytes in process_record_user switch statement
- Reduction from 16→13 implementations: ~150 bytes savings
- Additional savings from eliminating duplicate layer definitions: ~300-400 bytes

### 3. Layer Access Pattern Design

**Decision**: Use thumbs for primary layer access (OSL for symbols/function, LT for numbers), maintain home row mods on base layers

**Rationale**:
- Thumb keys are ideal for layer switching (accessible without hand movement)
- One-shot layers (OSL) for symbols/function enable "tap to access, auto-return" workflow
- Layer-tap (LT) on space for numbers (common pattern: space when tapped, number layer when held)
- Home row mods remain on base layers for OS-appropriate modifier access

**Access Patterns**:
```
Base Layer (macOS/Windows):
- Left thumb: OSL(symbols) - tap to access symbols, auto-return
- Right thumb inner: OSL(function/nav) - tap to access F-keys/nav, auto-return  
- Right thumb outer: LT(numbers, space) - hold for numbers, tap for space

Utility Layers:
- Symbols: All programming symbols, brackets, special characters
- Function/Nav: F1-F12, arrows, PgUp/PgDn, Home/End, umlauts, window shortcuts
- Numbers: Number pad layout (0-9), operators, OS-specific clipboard shortcuts
```

**Ergonomic Validation**:
- Thumb-based layer access minimizes finger travel and maintains typing flow
- One-shot behavior reduces hold fatigue for symbol-heavy programming
- Layer-tap on space leverages most-pressed key for efficient number access

### 4. OS-Specific Differentiation Strategy

**Decision**: Use conditional keycode logic in process_record_user for OS-specific shortcuts instead of duplicate layers

**Rationale**:
- Modifier differences (Ctrl/Cmd) are primary OS distinction; base layers handle this via different mod-tap assignments
- Clipboard shortcuts (Undo/Copy/Paste/Cut) differ only in modifier (Cmd vs Ctrl); single code path with OS detection
- Window management shortcuts can use same key positions with different modifiers
- Conditional logic adds minimal code size (~50 bytes) vs duplicate layers (~400 bytes per layer)

**Implementation Approach**:
```c
// OS detection via active base layer
bool is_macos_base = (get_highest_layer(layer_state) == LAYER_MAC_BASE);

// Clipboard shortcuts in number layer
case CLIPBOARD_COPY:
    if (is_macos_base) {
        register_code16(LGUI(KC_C));  // Cmd+C for macOS
    } else {
        register_code16(LCTL(KC_C));  // Ctrl+C for Windows
    }
    break;
```

**Benefits**:
- Single number layer serves both OSes with appropriate shortcuts
- Single function/nav layer serves both OSes with appropriate window management
- Code remains maintainable with clear OS distinction
- Firmware size reduced vs duplicate layers

### 5. RGB LED Mapping for Consolidated Layers

**Decision**: Define LED colors for 5 layers (2 base + 3 utility + 1 config = 6 total, but only 3 need custom colors)

**Rationale**:
- Current layout defines LED mappings for layers 0, 4, and 9 (macOS base, Windows base, config)
- Utility layers (symbols, function/nav, numbers) should use default/off LEDs to avoid visual confusion
- Base layer differentiation via LED color helps users identify active OS mode
- Configuration layer retains distinct LED pattern for system functions

**LED Color Strategy**:
```c
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_MAC_BASE] = { /* existing macOS colors */ },
    [LAYER_WIN_BASE] = { /* existing Windows colors */ },
    [LAYER_CONFIG]   = { /* existing config colors */ },
    // Utility layers use default (all zeros) - no custom LED patterns needed
};
```

**Visual Feedback**:
- macOS base: Existing color scheme (blue/teal indicators)
- Windows base: Existing color scheme (green indicators)
- Config layer: Existing color scheme (orange/pink indicators)
- Utility layers: Default RGB matrix behavior or subtle accent for active layer keys

### 6. Testing Strategy for Consolidated Layout

**Decision**: Manual testing checklist covering all functions on both OSes, build validation via GitHub Actions

**Rationale**:
- Embedded firmware testing requires physical keyboard; unit tests infeasible
- Comprehensive manual test covers: typing flow, all symbols accessible, all F-keys reachable, navigation works, clipboard shortcuts correct per OS
- GitHub Actions build validation ensures firmware compiles and size constraints met
- Test on both Windows and macOS to verify OS-specific shortcuts

**Test Scenarios**:
1. **Base Layer Typing** (both OSes): Type alphabet, German umlauts via function layer, punctuation
2. **Symbol Layer Access**: All programming symbols reachable from both base layers
3. **Function/Navigation**: F1-F12 accessible, arrow keys work, PgUp/PgDn/Home/End functional, window management shortcuts correct per OS
4. **Number Layer**: Number pad layout works, operators (+,-,*,/) accessible, clipboard shortcuts (Cmd+Z/C/V/X on Mac, Ctrl+Z/C/V/X on Win)
5. **Configuration Layer**: RGB controls functional, layer switching works, bootloader access confirmed
6. **Layer Transitions**: Rapid switching between layers returns to correct base, dual-function keys behave consistently

**Acceptance Criteria**:
- ✅ All current functionality preserved
- ✅ Firmware compiles successfully
- ✅ Firmware size <230KB (90% of 256KB)
- ✅ No regression in typing speed or accuracy
- ✅ OS-specific shortcuts work correctly on respective platforms

## Key Decisions Summary

| Decision Area | Choice | Rationale |
|--------------|--------|-----------|
| Layer Count | 5 layers (2 base + 3 utility) | Optimal balance: minimizes layers while maintaining clear separation of concerns |
| Base Layers | Separate macOS/Windows | Modifier muscle memory differs significantly; ergonomic positioning per OS |
| Utility Layers | Unified symbols/function/numbers | Shared across OSes; accessed identically from both bases |
| Dual-Function Keys | 12-14 implementations | Consolidate duplicates; maintain efficiency without complexity |
| OS Differentiation | Conditional logic in process_record_user | Smaller code size than duplicate layers |
| Layer Access | Thumb-based OSL/LT | Ergonomic; minimizes finger travel |
| LED Mapping | Base + config layers only | Clear visual feedback for OS mode; utilities default |
| Testing | Manual + build validation | Comprehensive coverage; no alternative for firmware |

## Implementation Risks & Mitigations

| Risk | Impact | Probability | Mitigation |
|------|--------|-------------|------------|
| Firmware size exceeds 256KB | Compilation failure | Low | Monitor size during development; have rollback plan; 10→5 reduction should decrease size |
| Muscle memory disruption | User confusion/errors | Medium | Gradual transition; document layer access; maintain similar key positions where possible |
| OS detection logic fails | Wrong shortcuts trigger | Low | Test thoroughly on both OSes; use reliable layer state detection |
| Dual-function hold timing issues | Accidental layer activation | Low | Use QMK default timing (200ms); adjust if needed based on testing |
| Oryx editor compatibility | Cannot edit visually | Very Low | Oryx supports arbitrary layer counts; verify in visual editor before coding |

## Next Steps

1. **Phase 1 Design**: Create detailed layer mappings in data-model.md
2. **Phase 1 Contracts**: Document layer structure and dual-function definitions
3. **Phase 1 Quickstart**: Create testing guide for consolidated layout
4. **Phase 2 Tasks**: Break down implementation into incremental changes
5. **Implementation**: Modify keymap.c with layer consolidation
6. **Testing**: Execute manual test scenarios on both Windows and macOS
7. **Documentation**: Update README.md with new layer structure

## References

- [QMK Layer Documentation](https://docs.qmk.fm/#/feature_layers)
- [QMK Mod-Tap Documentation](https://docs.qmk.fm/#/mod_tap)
- [Miryoku Layout](https://github.com/manna-harbour/miryoku) - Reference for minimal layer design
- [ZSA Voyager Official Docs](https://www.zsa.io/voyager)
- Current keymap.c: JRaem/keymap.c (470 lines, 10 layers, 16 dual-functions)
