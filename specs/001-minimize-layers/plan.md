# Implementation Plan: Minimize Keyboard Layers

**Branch**: `001-minimize-layers` | **Date**: 2025-11-07 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `/specs/001-minimize-layers/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Optimize the ZSA Voyager keyboard layout to reduce layer count from 10 to 5 while preserving all functionality. This involves consolidating duplicate OS-specific layers (Windows/macOS) into unified shared layers for symbols, numbers, and function/navigation, while maintaining separate base layers with appropriate modifier key positioning for each operating system. The consolidation will reduce cognitive load, improve muscle memory development, and decrease firmware size while maintaining full typing, navigation, and RGB configuration capabilities.

## Technical Context

**Language/Version**: C (QMK Firmware compatible with AVR-GCC compiler)  
**Primary Dependencies**: QMK Firmware (qmk_firmware submodule), Oryx layout API, German keyboard layout definitions (keymap_german.h)  
**Storage**: N/A (keyboard firmware stored in flash memory)  
**Testing**: Manual testing on Windows 10/11 and macOS (Sonoma/Sequoia), GitHub Actions build validation  
**Target Platform**: ZSA Voyager keyboard (ARM STM32 microcontroller, 256KB flash)  
**Project Type**: Embedded firmware (single project structure with JRaem custom code folder)  
**Performance Goals**: Compilation within 5 minutes, firmware size <230KB (90% of 256KB flash), keystroke response <10ms  
**Constraints**: Must maintain <256KB firmware size, preserve Oryx integration workflow, limit to 16 dual-function keys for code size, maintain German keyboard layout support  
**Scale/Scope**: 10 layers → 5 layers consolidation, ~470 lines of keymap.c, 16 dual-function key implementations, 52 physical keys, 4 combo keys, 2 key overrides

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

### I. Minimal Firmware Size (NON-NEGOTIABLE) ✅ PASS

- **Requirement**: Firmware must maintain smallest possible binary size
- **Assessment**: Layer consolidation from 10→5 will REDUCE firmware size by eliminating duplicate layer definitions, LED mappings, and layer-tap references
- **Evidence**: Current ~470 lines of keymap.c contains duplicate symbol/function/number layers (1/6, 2/5, 3/7, 8); consolidation removes ~200 lines of duplication
- **Compliance**: Feature directly supports this principle by reducing code redundancy

### II. Layer Minimization (PRINCIPLE ALIGNMENT) ✅ PASS

- **Requirement**: Achieve full functionality with minimum number of layers
- **Assessment**: This feature IS the implementation of this principle - reduces from 10 to 5 layers (50% reduction)
- **Evidence**: Current layout has 4 layers for macOS (0-3), 4 for Windows (4-7), function keys (8), config (9); target has 2 base + 3 shared + 1 config
- **Compliance**: Feature directly implements constitutional requirement

### III. OS-Specific Optimization ✅ PASS

- **Requirement**: Maximize code reuse while maintaining OS-specific functionality
- **Assessment**: Consolidation strategy maintains separate base layers (macOS/Windows) for modifier differences, unifies all shared functionality (symbols, numbers, navigation)
- **Evidence**: Spec defines unified symbol, function/navigation, and number layers accessible from both base layers; OS-specific clipboard shortcuts handled via conditional logic
- **Compliance**: Feature implements optimal balance between OS differentiation and code reuse

### IV. Oryx Integration (NON-NEGOTIABLE) ✅ PASS

- **Requirement**: Maintain seamless Oryx visual editor integration
- **Assessment**: Layer consolidation can be implemented in Oryx visual editor; workflow unchanged (edit in Oryx → GitHub Action merge → build)
- **Evidence**: Oryx supports arbitrary layer counts and layer-tap definitions; consolidation uses standard QMK features (LT, MT, OSL)
- **Compliance**: No impact on Oryx integration workflow; all changes implementable in visual editor

### V. Code Maintainability ✅ PASS

- **Requirement**: Clear structure, documented code, centralized configuration
- **Assessment**: Consolidation IMPROVES maintainability by reducing layer count complexity and eliminating duplicate definitions
- **Evidence**: Reduction from 10→5 layers simplifies mental model; fewer DUAL_FUNC implementations needed (consolidate similar functions)
- **Compliance**: Feature enhances maintainability through simplification

### Technical Constraints Compliance ✅ PASS

- ✅ Hardware: ZSA Voyager 52-key layout preserved
- ✅ Firmware: QMK features maintained (CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER)
- ✅ Key Layout: German keyboard layout (DE_*) preserved in consolidated layers
- ✅ Build System: GitHub Actions workflow unchanged
- ✅ Flash Size: Reduction in code size supports <256KB constraint

### Development Workflow Compliance ✅ PASS

- ✅ Oryx Editing: Layer consolidation implementable in visual editor
- ✅ Custom Code: Changes primarily in keymap.c layer definitions and DUAL_FUNC macros
- ✅ Layer Design: Follows documented process (purpose → verification → implementation → testing)
- ✅ Size Optimization: Consolidation reduces size, supporting <90% flash target

**GATE STATUS**: ✅ **PASSED** - All constitutional principles satisfied; feature directly implements layer minimization principle while maintaining all other requirements

---

## Post-Design Constitution Re-Check

*GATE: Re-evaluated after Phase 1 design completion*

### I. Minimal Firmware Size (NON-NEGOTIABLE) ✅ PASS

**Post-Design Assessment**:
- Layer consolidation design complete: 10 → 5 layers reduces keymap array size
- Dual-function consolidation: 16 → 13 implementations saves ~135 bytes
- LED mapping optimization: 3 layers with custom colors (down from scattered definitions)
- Estimated total firmware size reduction: ~435-535 bytes

**Design Evidence**:
- data-model.md specifies 5-layer architecture with clear entity definitions
- dual-function-mappings.md consolidates duplicate implementations
- layer-structure.md defines transparent key contracts to minimize layer definition overhead

**Compliance Verified**: ✅ Design actively reduces firmware size through consolidation

### II. Layer Minimization (PRINCIPLE ALIGNMENT) ✅ PASS

**Post-Design Assessment**:
- Design achieves 50% layer reduction (10 → 5)
- Each layer has single, clear purpose documented in data-model.md
- No redundant layers or duplicate functionality across layers

**Design Evidence**:
- LAYER_MAC_BASE (0): macOS typing with Cmd-based mods
- LAYER_WIN_BASE (1): Windows typing with Ctrl-based mods
- LAYER_SYMBOLS (2): Unified programming symbols (consolidates 1 & 6)
- LAYER_FUNCTION (3): Unified function/nav/umlauts (consolidates 2, 5, 8)
- LAYER_NUMBERS (4): Unified numpad with OS-conditional clipboard (consolidates 3 & 7)
- LAYER_CONFIG (5): Independent RGB/system functions (preserved from 9)

**Compliance Verified**: ✅ Design meets constitutional layer minimization target

### III. OS-Specific Optimization ✅ PASS

**Post-Design Assessment**:
- Design maintains separate base layers for OS-specific modifier positioning
- Unified utility layers shared across both OSes (maximum code reuse)
- OS differentiation via conditional logic in process_record_user (minimal code size)

**Design Evidence**:
- Home row mods differ between bases (Ctrl/Cmd swapped) - documented in dual-function-mappings.md
- Clipboard shortcuts use `is_macos_active()` helper for OS detection - detailed in layer-structure.md
- Symbols, functions, numbers layers identical when accessed from either base - specified in data-model.md

**Compliance Verified**: ✅ Design optimally balances OS differentiation with code reuse

### IV. Oryx Integration (NON-NEGOTIABLE) ✅ PASS

**Post-Design Assessment**:
- 5-layer design fully compatible with Oryx visual editor (supports arbitrary layer counts)
- All consolidation uses standard QMK features (OSL, LT, MT, TO) - Oryx supports all
- No custom C code required that would break Oryx editing workflow
- Layer structure can be fully represented in Oryx UI

**Design Evidence**:
- layer-structure.md specifies standard QMK layer access methods (OSL, LT, TO)
- dual-function-mappings.md uses standard MT/LT plus custom keycodes (Oryx-compatible)
- No architectural changes to JRaem folder structure or GitHub Actions workflow

**Compliance Verified**: ✅ Design preserves full Oryx integration capability

### V. Code Maintainability ✅ PASS

**Post-Design Assessment**:
- Design improves maintainability through clear layer hierarchy and purpose
- Dual-function naming changed from numbers (DUAL_FUNC_0-15) to descriptive (DF_AT_CTRL, DF_SLASH_ALT)
- OS detection helper (`is_macos_active()`) centralizes OS logic
- Comprehensive documentation in data-model.md, layer-structure.md, dual-function-mappings.md

**Design Evidence**:
- Layer entities clearly defined with purpose, access methods, relationships (data-model.md)
- Layer access contracts specify behavior guarantees (layer-structure.md)
- Dual-function migration path documented from current to target (dual-function-mappings.md)
- Testing guide provides validation scenarios (quickstart.md)

**Compliance Verified**: ✅ Design enhances maintainability through simplification and documentation

### Technical Constraints Compliance (Post-Design) ✅ PASS

- ✅ Hardware: ZSA Voyager 52-key layout preserved in all layer definitions
- ✅ Firmware: QMK features maintained (CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER)
- ✅ Key Layout: German keyboard (DE_*) supported in symbol and function layers
- ✅ Build System: No changes to GitHub Actions workflow required
- ✅ Flash Size: Design targets <230KB (90% of 256KB) with ~435-535 byte savings

### Development Workflow Compliance (Post-Design) ✅ PASS

- ✅ Oryx Editing: 5-layer structure editable in Oryx visual interface
- ✅ Custom Code: Changes scoped to JRaem/keymap.c (layer definitions, dual-functions)
- ✅ Layer Design: Follows documented process (data-model → contracts → quickstart testing)
- ✅ Size Optimization: Design actively reduces firmware size

**FINAL GATE STATUS**: ✅ **PASSED** - Design phase complete, all constitutional requirements satisfied, ready for task breakdown and implementation

## Project Structure

### Documentation (this feature)

```text
specs/001-minimize-layers/
├── plan.md              # This file (/speckit.plan command output)
├── research.md          # Phase 0 output (layer consolidation strategies)
├── data-model.md        # Phase 1 output (layer architecture and key mappings)
├── quickstart.md        # Phase 1 output (testing guide for consolidated layout)
├── contracts/           # Phase 1 output (layer definitions and access patterns)
│   ├── layer-structure.md
│   └── dual-function-mappings.md
└── checklists/
    └── requirements.md  # Specification quality validation (completed)
```

### Source Code (repository root)

```text
JRaem/
├── config.h             # USB config, serial number, layer state size, RGB settings
├── keymap.c             # ⚠️ PRIMARY CHANGE: Layer definitions, DUAL_FUNC macros, process_record_user
├── rules.mk             # QMK feature flags (no changes expected)
├── i18n.h               # Internationalization helpers (no changes expected)
└── keymap.json          # Oryx-generated layout (modified via Oryx editor)

qmk_firmware/            # QMK base code (submodule, no changes)

.github/workflows/
└── fetch-and-build-layout.yml  # Build automation (no changes expected)

README.md                # ⚠️ UPDATE: Document new layer structure

.specify/
└── memory/
    └── constitution.md  # Project governance (reference only)
```

**Structure Decision**: Single embedded firmware project structure. All custom code modifications occur in the `JRaem/` folder, specifically `keymap.c` for layer consolidation logic. The project follows QMK firmware conventions with custom keymap overlaying the base firmware. Changes are tested via GitHub Actions build process and manual keyboard testing on Windows/macOS.

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

**No violations detected** - All constitutional principles are satisfied by this feature. Layer consolidation directly implements Principle II (Layer Minimization) while supporting Principles I (Minimal Firmware Size), III (OS-Specific Optimization), IV (Oryx Integration), and V (Code Maintainability).
