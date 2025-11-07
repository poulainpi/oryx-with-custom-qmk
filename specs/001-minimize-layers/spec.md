# Feature Specification: Minimize Keyboard Layers

**Feature Branch**: `001-minimize-layers`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Optimize the current layout with the same functions but a minimized number of layers"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Unified OS Base Layers (Priority: P1)

As a keyboard user who switches between Windows and macOS, I need a streamlined layer structure that provides OS-specific functionality without duplicating common features, so that I can maintain consistent muscle memory while having appropriate OS shortcuts available.

**Why this priority**: This is the foundational change that enables all other optimizations. Currently, layers 0 (macOS) and 4 (Windows) are nearly identical base layers with only modifier key differences. Consolidating shared functionality while maintaining OS-specific shortcuts is the primary goal.

**Independent Test**: Can be fully tested by typing text, using symbols, navigating with arrow keys, and executing OS-specific shortcuts on both Windows and macOS, and delivers a functional typing experience with reduced cognitive load.

**Acceptance Scenarios**:

1. **Given** I am on the macOS base layer, **When** I type letters and use modifier keys, **Then** I can access all standard typing functions with macOS-appropriate modifiers (Cmd for shortcuts)
2. **Given** I am on the Windows base layer, **When** I type letters and use modifier keys, **Then** I can access all standard typing functions with Windows-appropriate modifiers (Ctrl for shortcuts)
3. **Given** I switch between macOS and Windows base layers, **When** I use common keys (letters, numbers, navigation), **Then** their positions remain identical across both layers

---

### User Story 2 - Consolidated Symbol/Function Layers (Priority: P1)

As a keyboard user, I need symbols, numbers, function keys, and navigation keys accessible from a minimal set of shared layers that work consistently across both operating systems, so that I don't need to remember different layer access patterns for Windows vs macOS.

**Why this priority**: Currently, layers 1/6 (symbols), 2/5 (function/navigation), 3/7 (numbers), and 8 (function keys) contain significant duplication. Users must remember separate layer access patterns for each OS. Consolidating these layers reduces complexity without sacrificing functionality.

**Independent Test**: Can be tested by accessing all symbols, numbers, function keys, umlauts, and navigation features from both base layers, verifying consistent access patterns.

**Acceptance Scenarios**:

1. **Given** I am on either base layer, **When** I activate the symbol layer, **Then** I can access all programming symbols and special characters
2. **Given** I am on either base layer, **When** I activate the function/navigation layer, **Then** I can access F1-F12, arrow keys, Page Up/Down, Home/End, and umlauts
3. **Given** I am on either base layer, **When** I activate the number layer, **Then** I can access number pad layout with operators, along with OS-specific clipboard shortcuts
4. **Given** I need function keys while in another layer, **When** I use dual-function keys or layer combinations, **Then** function keys remain accessible without returning to base

---

### User Story 3 - Preserved RGB Configuration Layer (Priority: P2)

As a keyboard user who customizes lighting, I need a dedicated configuration layer for RGB settings and system functions that remains independent of OS choice, so that I can adjust lighting and access system features (reboot, layer switching) without interference from typing layers.

**Why this priority**: The RGB/configuration layer (9) serves a distinct purpose and has minimal overlap with typing/productivity layers. It can remain as a separate utility layer accessed explicitly via TO(9) without adding cognitive load to normal typing workflows.

**Independent Test**: Can be tested by accessing the configuration layer from any other layer, adjusting RGB settings, switching between OS base layers, and rebooting the keyboard.

**Acceptance Scenarios**:

1. **Given** I am on any layer, **When** I activate the configuration layer (layer 9 or new number), **Then** I can adjust RGB settings (toggle, mode, saturation, hue, brightness, speed)
2. **Given** I am on the configuration layer, **When** I select an OS base layer option, **Then** the keyboard switches to the appropriate Windows or macOS base layer
3. **Given** I am on the configuration layer, **When** I trigger the boot command, **Then** the keyboard enters bootloader mode for firmware flashing

---

### Edge Cases

- What happens when a dual-function key is held while switching layers? The hold function should remain active during layer transition.
- How does the layout handle rapid layer switching (e.g., accessing symbols while navigating)? Layer deactivation should return to the appropriate base layer.
- What if a user needs function keys accessible from the symbol layer? Function keys should be accessible via dual-function implementations or secondary layer combinations.
- How are German umlauts accessed when already in a non-base layer? Umlauts should be accessible from the function/navigation layer consistently.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Layout MUST reduce total number of layers from current 10 layers (0-9) to target of 5 layers or fewer
- **FR-002**: Layout MUST maintain all existing functionality: base typing, symbols, numbers, function keys, navigation, umlauts, RGB configuration, clipboard operations
- **FR-003**: Layout MUST preserve dual-function key behaviors (mod-tap, layer-tap) with at least 16 dual-function keys for efficient access
- **FR-004**: Layout MUST provide OS-specific base layers for Windows and macOS with appropriate modifier key positioning (Ctrl/Cmd, Alt/Option)
- **FR-005**: Layout MUST unify symbol access (layers 1 and 6 consolidated into single symbol layer)
- **FR-006**: Layout MUST unify function/navigation access (layers 2, 5, and 8 consolidated into single function/navigation layer)
- **FR-007**: Layout MUST unify number pad access (layers 3 and 7 consolidated into single number layer) with OS-specific clipboard shortcuts
- **FR-008**: Layout MUST maintain RGB configuration layer as dedicated utility layer with system functions (layer switching, bootloader access)
- **FR-009**: Layout MUST preserve German keyboard layout support (umlauts: ä, ö, ü, ß)
- **FR-010**: Layout MUST maintain key overrides (shift+dot=comma, shift+quote=doublequote)
- **FR-011**: Layout MUST maintain combo keys (4 combos defined)
- **FR-012**: Layout MUST preserve LED color mappings for active layers
- **FR-013**: Layout MUST maintain QMK feature set: CAPS_WORD, COMBO, REPEAT_KEY, KEY_OVERRIDE, LEADER
- **FR-014**: Clipboard operations (undo, copy, paste, cut) MUST differentiate between macOS shortcuts (Cmd+Z/C/V/X) and Windows shortcuts (Ctrl+Z/C/V/X)

### Key Entities

- **Base Layer (macOS)**: Primary typing layer with letters, modifiers positioned for macOS workflows (Cmd-based shortcuts)
- **Base Layer (Windows)**: Primary typing layer with letters, modifiers positioned for Windows workflows (Ctrl-based shortcuts)
- **Symbol Layer**: Unified layer providing all programming symbols, special characters, and brackets (consolidates layers 1 and 6)
- **Function/Navigation Layer**: Unified layer providing F1-F12, arrow keys, Page Up/Down, Home/End, Tab, Escape, German umlauts, and window management shortcuts (consolidates layers 2, 5, and 8)
- **Number Layer**: Unified layer providing number pad layout (0-9), operators (+, -, *, /), and OS-specific clipboard shortcuts (consolidates layers 3 and 7)
- **Configuration Layer**: Dedicated RGB control and system functions (preserved layer 9 or renumbered)

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Total layer count reduced from 10 to 5 layers (50% reduction)
- **SC-002**: All existing key functions remain accessible within same or fewer keystrokes as current layout
- **SC-003**: User can switch between Windows and macOS base layers and access all shared functionality (symbols, numbers, navigation) without relearning layer access patterns
- **SC-004**: Firmware binary size remains within acceptable limits (<90% flash capacity) after layer consolidation
- **SC-005**: User can access any symbol, number, function key, or navigation key from either base layer within 2 keypresses maximum
- **SC-006**: Layer structure can be visually documented with clear purpose for each layer, eliminating confusion about which layer to use for specific functions
- **SC-007**: Dual-function key count remains at 16 or fewer to maintain usability and avoid excessive hold-tap confusion
- **SC-008**: RGB LED patterns correctly reflect active layer after consolidation (3 layers with custom colors: both base layers and configuration layer)

## Assumptions

- **Assumption 1**: The current layout separation between Windows (layer 4-7) and macOS (layer 0-3) exists primarily for modifier key differences, not fundamentally different typing patterns
- **Assumption 2**: Users are willing to use dual-function keys and layer combinations to access function keys rather than having a dedicated function key layer accessible via layer-tap
- **Assumption 3**: The layer 8 function key arrangement (F1-F12 accessible via Esc/Tab/Enter positions) can be merged into the unified function/navigation layer without usability loss
- **Assumption 4**: Navigation shortcuts (window management with Cmd/Ctrl+arrows, Cmd/Ctrl+Tab) can use conditional logic or dual implementations rather than separate layers
- **Assumption 5**: The target of 5 layers represents the optimal balance between minimalism and usability; further reduction may compromise functionality

## Dependencies

- Requires Oryx layout editor to support the new consolidated layer structure
- Requires QMK firmware features: layer-tap (LT), mod-tap (MT), one-shot layers (OSL), one-shot mods (OSM)
- Requires testing on both Windows and macOS operating systems to verify OS-specific shortcuts
- Build system (GitHub Actions) must successfully compile optimized layout without errors

## Constraints

- Must maintain firmware size within ZSA Voyager flash memory limits
- Must preserve Oryx integration workflow (visual editing → GitHub Action → custom code merge)
- Cannot exceed 16 dual-function key implementations to avoid code complexity and size bloat
- Must maintain German keyboard layout keycodes (DE_*) for umlauts and special characters
- Layer numbering in QMK is zero-indexed and sequential; consolidated layers must use numbers 0-4 or similar compact range
