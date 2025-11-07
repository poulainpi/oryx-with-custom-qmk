<!--
Sync Impact Report
==================
Version Change: 0.0.0 → 1.0.0
Created: 2025-11-07

Modified Principles: Initial creation with 5 core principles
Added Sections: Core Principles, Technical Constraints, Development Workflow, Governance
Removed Sections: None

Templates Status:
✅ plan-template.md - Validated (constitution check section compatible)
✅ spec-template.md - Validated (user story structure aligns)
✅ tasks-template.md - Validated (phase organization aligns)

Follow-up TODOs: None
-->

# Oryx with Custom QMK Constitution

## Core Principles

### I. Minimal Firmware Size (NON-NEGOTIABLE)
The firmware MUST maintain the smallest possible binary size while providing full functionality. Every feature inclusion MUST be justified against the firmware size constraint. Unused QMK features MUST be explicitly disabled in `config.h` (RGB matrix effects, unused capabilities). Only essential QMK features are enabled in `rules.mk` (CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER). Code MUST be optimized for size: avoid redundant logic, use macros efficiently, minimize dual-function key implementations where possible.

**Rationale**: The ZSA Voyager has limited flash memory. Exceeding the size limit prevents firmware compilation and deployment. Size optimization ensures headroom for future enhancements and maintains fast flash times.

### II. Layer Minimization
The keyboard layout MUST achieve full functionality with the minimum number of layers. Target architecture: Windows layer (base), macOS layer (variant), symbol/function layers (shared utilities), configuration layer (RGB/system). MUST NOT create redundant layers or duplicate functionality across layers. Each layer MUST have a clear, single purpose that cannot be achieved through layer combinations or dual-function keys.

**Rationale**: Cognitive load increases exponentially with layer count. Users must remember layer locations and access patterns. Minimal layers improve muscle memory development, reduce mental overhead, and simplify the keymap structure. This directly supports usability and maintainability.

### III. OS-Specific Optimization
Windows and macOS layers MUST be independently optimized for their respective operating systems while maximizing code reuse. Modifier keys (Ctrl/Cmd, Alt/Option) MUST be positioned for OS-specific workflows. Shared functionality (symbols, numbers, navigation) MUST be unified across OS layers using identical layouts. OS-specific shortcuts (Cmd+C vs Ctrl+C, window management) MUST be implemented with minimal code duplication using conditional logic where possible.

**Rationale**: Users switching between operating systems require consistent muscle memory but OS-appropriate keyboard behavior. Duplicating entire layers wastes firmware space; strategic differentiation with unified shared layers optimizes both usability and size.

### IV. Oryx Integration (NON-NEGOTIABLE)
The build system MUST support seamless integration with ZSA Oryx graphical layout editor. Workflow requirement: Oryx layout edits → Compile in Oryx → GitHub Action fetches changes → Merges with custom QMK code → Builds unified firmware. Custom code in JRaem folder MUST NOT conflict with Oryx-generated base keymap structure. Manual code in `config.h`, `keymap.c`, `rules.mk` MUST extend, not replace, Oryx functionality. GitHub Actions MUST automate: fetch latest Oryx layout, merge custom features, compile firmware, provide downloadable artifact.

**Rationale**: Oryx provides intuitive visual layout editing without code knowledge. Custom QMK features (Achordion, advanced macros) require code. Integration workflow preserves both benefits: visual editing convenience and advanced programmability, eliminating manual merge conflicts.

### V. Code Maintainability
Custom QMK code MUST be clearly structured and documented. Configuration options MUST be centralized in `config.h`. Feature flags MUST be managed in `rules.mk`. Keymap logic MUST be readable with descriptive comments for non-obvious dual-function keys, layer purposes, and custom keycodes. Dual-function implementations MUST use the DUAL_FUNC naming convention with sequential numbering. LED mappings and layer colors MUST be clearly defined in dedicated sections.

**Rationale**: Keyboard layouts evolve over time. Future modifications (adding keys, adjusting layers, enabling features) require understanding existing code. Clear structure reduces debugging time, prevents introduction of errors, and enables confident iteration. This is critical for solo-maintained projects.

## Technical Constraints

**Hardware**: ZSA Voyager 52-key split ortholinear keyboard  
**Firmware Base**: QMK Firmware (qmk_firmware folder contains base code)  
**Custom Code Location**: JRaem folder (user-editable: config.h, keymap.c, rules.mk, i18n.h)  
**Key Layout**: German keyboard layout (DE_* keycodes for umlauts, special characters)  
**Build System**: GitHub Actions workflow (`.github/workflows/fetch-and-build-layout.yml`)  
**Required QMK Features**: CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER, RGB_MATRIX  
**Disabled QMK Features**: CONSOLE, COMMAND, MOUSEKEY, TAP_DANCE, SPACE_CADET (disabled in rules.mk for size)  
**RGB Matrix**: Custom animations disabled in config.h (33 effects undefined to save space)  
**Flash Tool**: Keymapp by ZSA

## Development Workflow

### Oryx Editing Workflow
1. Edit layout visually in Oryx web interface (layout must be public)
2. Click "Compile this layout" in Oryx to confirm changes
3. Run GitHub Action "Fetch and build layout" with layout ID and keyboard type
4. Action automatically fetches Oryx changes, merges with custom code, builds firmware
5. Download firmware artifact from GitHub Action results
6. Flash firmware using Keymapp application

### Custom Code Editing Workflow
1. Edit files in JRaem folder: `config.h` (configuration), `keymap.c` (keymap logic), `rules.mk` (feature flags)
2. Commit and push changes to main branch
3. Run GitHub Action "Fetch and build layout" to rebuild firmware
4. Download and flash firmware artifact

### Layer Design Process
1. Document layer purpose and key functionality requirements
2. Verify layer cannot be eliminated through dual-function keys or layer combinations
3. Implement layer in Oryx with clear visual structure
4. Test functionality on both Windows and macOS (if applicable)
5. Document layer access method and purpose in README.md

### Size Optimization Process
1. Check compiled firmware size after each feature addition
2. If approaching size limit: audit enabled features in rules.mk, review disabled RGB effects in config.h, optimize dual-function key implementations, eliminate redundant layer definitions
3. Justify any size increase against functional benefit in commit message
4. Maintain headroom for future features (target: <90% flash capacity)

## Governance

This constitution defines the non-negotiable principles and workflows for the Oryx with Custom QMK project. All modifications to layout, code, or build process MUST comply with these principles. Amendments to this constitution require:
- Clear justification for the change
- Documentation of impact on existing principles
- Update of dependent documentation (README.md, workflow files)
- Version increment following semantic versioning

**Semantic Versioning for Constitution**:
- MAJOR: Breaking changes to core principles (e.g., removing layer minimization requirement)
- MINOR: New principle added or section materially expanded (e.g., adding security requirements)
- PATCH: Clarifications, wording improvements, non-semantic refinements

All commits MUST verify compliance with principles. Feature additions MUST be justified against firmware size and layer count constraints. Complexity introduced MUST provide proportional usability or functionality benefit.

**Version**: 1.0.0 | **Ratified**: 2025-11-07 | **Last Amended**: 2025-11-07
