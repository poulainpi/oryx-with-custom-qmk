# Implementation Plan: Minimize Keyboard Layers (vrMEr)

**Branch**: `002-minimize-layers` | **Date**: 2025-11-08 | **Spec**: [spec.md](./spec.md)
**Input**: Feature specification from `/specs/002-minimize-layers/spec.md`

**Note**: This plan follows the proven approach from feature 001-minimize-layers (JRaem folder) and adapts it for the vrMEr keyboard layout.

## Summary

Optimize the vrMEr ZSA Voyager keyboard layout to reduce layer count from 10 to 5-6 while preserving all functionality. This involves consolidating duplicate OS-specific layers (Windows/macOS) into unified shared layers for symbols, numbers, and function/navigation, while maintaining separate base layers with appropriate modifier key positioning for each operating system. The consolidation will reduce cognitive load, improve muscle memory development, and decrease firmware size (target 40-50% reduction) while maintaining full typing, navigation, RGB configuration, and all QMK features (Caps Word, combos, leader key, repeat key).

## Technical Context

**Language/Version**: C (QMK Firmware compatible with AVR-GCC compiler)  
**Primary Dependencies**: QMK Firmware (qmk_firmware submodule), Oryx layout API, German keyboard layout definitions (keymap_german.h)  
**Storage**: N/A (keyboard firmware stored in flash memory)  
**Testing**: Manual testing on Windows 10/11 and macOS (Sonoma/Sequoia), GitHub Actions build validation, hardware testing checklist  
**Target Platform**: ZSA Voyager keyboard (ARM STM32 microcontroller, 256KB flash)  
**Project Type**: Embedded firmware (single project structure with vrMEr custom code folder)  
**Performance Goals**: Compilation within 5 minutes, firmware size <230KB (90% of 256KB flash), keystroke response <10ms  
**Constraints**: Must maintain <256KB firmware size, preserve Oryx integration workflow, limit dual-function implementations for code size, maintain German keyboard layout support  
**Scale/Scope**: 10 layers → 5-6 layers consolidation, ~930 lines of keymap.c (target ~465-550 lines after 40-50% reduction), 17 tap dance implementations to eliminate/simplify, 52 physical keys

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

### I. Minimal Firmware Size (NON-NEGOTIABLE) ✅ PASS

- **Requirement**: Firmware must maintain smallest possible binary size
- **Assessment**: Layer consolidation from 10→5-6 will REDUCE firmware size by eliminating duplicate layer definitions, tap dance implementations, and LED mappings
- **Evidence**: Current ~930 lines of keymap.c contains duplicate layers (0/4 bases, 1/6 symbols, 2/5 function, 3/7 numbers); consolidation removes ~370-465 lines of duplication (40-50%)
- **Compliance**: Feature directly supports this principle by reducing code redundancy

### II. Layer Minimization (PRINCIPLE ALIGNMENT) ✅ PASS

- **Requirement**: Achieve full functionality with minimum number of layers
- **Assessment**: This feature implements this principle - reduces from 10 to 5-6 layers (40-50% reduction)
- **Evidence**: Current vrMEr layout has 10 layers (0-9) with duplicated functionality across OS-specific layers; target has 2 base + 3 utility + 1 config layers
- **Compliance**: Feature directly implements constitutional requirement, following proven 001-minimize-layers approach

### III. OS-Specific Optimization ✅ PASS

- **Requirement**: Maximize code reuse while maintaining OS-specific functionality
- **Assessment**: Consolidation strategy maintains separate base layers (macOS/Windows) for modifier differences, unifies all shared functionality (symbols, numbers, navigation)
- **Evidence**: Spec defines unified symbol, function/navigation, and number layers accessible from both base layers; OS-specific clipboard shortcuts handled via conditional logic (is_macos_base() helper)
- **Compliance**: Feature implements optimal balance between OS differentiation and code reuse, proven effective in JRaem optimization

### IV. Oryx Integration (NON-NEGOTIABLE) ✅ PASS

- **Requirement**: Maintain seamless Oryx visual editor integration
- **Assessment**: Layer consolidation can be implemented in Oryx visual editor; workflow unchanged (edit in Oryx → GitHub Action merge → build)
- **Evidence**: Oryx supports arbitrary layer counts and layer-tap definitions; consolidation uses standard QMK features (LT, MT, OSL, TO)
- **Compliance**: No impact on Oryx integration workflow; all changes implementable in visual editor, as demonstrated in 001-minimize-layers

### V. Code Maintainability ✅ PASS

- **Requirement**: Clear structure, documented code, centralized configuration
- **Assessment**: Consolidation IMPROVES maintainability by reducing layer count complexity and eliminating duplicate tap dance implementations
- **Evidence**: Reduction from 10→5-6 layers simplifies mental model; 17 tap dance implementations replaced with simpler MT() home row mods and direct keycodes
- **Compliance**: Feature enhances maintainability through simplification, following proven JRaem patterns

### Technical Constraints Compliance ✅ PASS

- ✅ Hardware: ZSA Voyager 52-key layout preserved
- ✅ Firmware: QMK features maintained (CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER, RGB_MATRIX)
- ✅ Key Layout: German keyboard layout (DE_*) preserved in consolidated layers
- ✅ Build System: GitHub Actions workflow unchanged
- ✅ Flash Size: Reduction in code size supports <230KB constraint (90% of 256KB)

### Development Workflow Compliance ✅ PASS

- ✅ Oryx Editing: Layer consolidation implementable in visual editor
- ✅ Custom Code: Changes primarily in vrMEr/keymap.c layer definitions and tap dance elimination
- ✅ Layer Design: Follows documented process (purpose → verification → implementation → testing)
- ✅ Size Optimization: Consolidation reduces size, supporting <90% flash target

**GATE STATUS**: ✅ **PASSED** - All constitutional principles satisfied; feature directly implements layer minimization principle while maintaining all other requirements

---

## Post-Design Constitution Re-Check

*GATE: Re-evaluated after Phase 1 design completion*

[To be filled after Phase 1 design is complete]

## Project Structure

### Documentation (this feature)

```text
specs/002-minimize-layers/
├── plan.md              # This file (/speckit.plan command output)
├── research.md          # Phase 0 output (reference JRaem approach, vrMEr analysis)
├── data-model.md        # Phase 1 output (layer architecture and key mappings for vrMEr)
├── quickstart.md        # Phase 1 output (testing guide for consolidated vrMEr layout)
├── contracts/           # Phase 1 output (layer definitions and access patterns)
│   ├── layer-structure.md
│   └── tap-dance-elimination.md
├── checklists/
│   └── requirements.md  # Specification quality validation (completed)
└── CURRENT_LAYOUT.md    # Backup of original 10-layer vrMEr layout (Phase 1 output)
```

### Source Code (repository root)

```text
vrMEr/
├── keymap.c             # Main implementation file (10 layers → 5-6 layers)
├── config.h             # Configuration (TAPPING_TERM, ONESHOT_TIMEOUT, RGB)
├── rules.mk             # QMK feature flags (unchanged - already optimal)
└── i18n.h               # German layout aliases (unchanged)

.github/
└── workflows/
    └── fetch-and-build-layout.yml  # Build workflow (unchanged)

qmk_firmware/            # QMK base (submodule, unchanged)

specs/002-minimize-layers/  # Documentation (see above)
```

**Structure Decision**: Single embedded firmware project with vrMEr custom code folder. Implementation follows identical structure to 001-minimize-layers (JRaem) for consistency and knowledge reuse. Build infrastructure (GitHub Actions, Docker scripts) already supports both JRaem and vrMEr folders.

## Complexity Tracking

> **No violations** - Feature fully compliant with all constitutional principles. Layer consolidation actively supports constitutional goals.
