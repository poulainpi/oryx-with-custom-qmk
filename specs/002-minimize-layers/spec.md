# Feature Specification: Minimize Layers (vrMEr Keyboard)

**Feature Branch**: `002-minimize-layers`  
**Created**: November 8, 2025  
**Status**: Draft  
**Input**: User description: "Optimize the vrMEr layout with the same functions but a minimized number of layers, following the same approach used for JRaem folder (reduce from 10 to 5-6 layers)"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Access All Keyboard Functions with Fewer Layers (Priority: P1)

As a keyboard user, I want to access all my current keyboard functions (typing, symbols, numbers, function keys, navigation) through a simplified 5-6 layer structure instead of the current 10 layers, so that I can build stronger muscle memory and reduce cognitive load when switching between layers.

**Why this priority**: This is the core value proposition - maintaining full functionality while reducing complexity. All other improvements depend on this foundation.

**Independent Test**: Can be fully tested by verifying that every key function from the original 10-layer layout is accessible in the new 5-6 layer structure, and measuring layer switch frequency during typical typing tasks.

**Acceptance Scenarios**:

1. **Given** I am typing on the base layer, **When** I need to access a programming symbol, **Then** I can reach it within the same number of keystrokes as before
2. **Given** I am working on macOS, **When** I switch to Windows, **Then** all keyboard functions remain accessible through the same key positions
3. **Given** I need to type German umlauts (ä, ö, ü, ß, €), **When** I access the appropriate layer, **Then** all special characters are available in intuitive positions
4. **Given** I am using any layer, **When** I need to return to base typing, **Then** the layer automatically returns or I can manually switch with a single key press

---

### User Story 2 - Maintain OS-Specific Optimizations (Priority: P2)

As a keyboard user who switches between macOS and Windows, I want separate base layers optimized for each operating system's modifier key conventions (Cmd vs Ctrl), while sharing all other layers, so that I can work efficiently on both platforms without relearning key combinations.

**Why this priority**: Critical for users who work across multiple operating systems. Enables consistent experience while respecting platform conventions.

**Independent Test**: Can be independently tested by switching between macOS base and Windows base layers, verifying that clipboard operations (undo, copy, paste, cut) use the correct OS modifiers, and confirming that navigation and symbol layers work identically from both bases.

**Acceptance Scenarios**:

1. **Given** I am on macOS base layer, **When** I perform clipboard operations, **Then** Cmd+Z/C/V/X modifiers are used
2. **Given** I am on Windows base layer, **When** I perform clipboard operations, **Then** Ctrl+Z/C/V/X modifiers are used
3. **Given** I am on either base layer, **When** I access symbols/numbers/function layers, **Then** they behave identically regardless of which base I came from
4. **Given** I switch from macOS to Windows computer, **When** I toggle to the appropriate base layer, **Then** home row modifiers and shortcuts adapt to the new OS conventions

---

### User Story 3 - Preserve Advanced QMK Features (Priority: P3)

As a power user, I want all existing QMK features (Caps Word, combos, key overrides, leader key, repeat key, RGB matrix) to continue working after the layer optimization, so that I don't lose any custom functionality I've configured.

**Why this priority**: Preserves user investment in custom configurations. Important for power users but doesn't affect basic functionality.

**Independent Test**: Can be independently tested by triggering each QMK feature (Caps Word toggle, combos, leader sequences, repeat key, RGB controls) and verifying they produce the same results as in the original layout.

**Acceptance Scenarios**:

1. **Given** I have enabled Caps Word, **When** I type text, **Then** capitalization behavior matches the original layout
2. **Given** I trigger a combo key sequence, **When** the combo activates, **Then** the configured action executes correctly
3. **Given** I press the repeat key, **When** triggered, **Then** the last key press repeats as expected
4. **Given** I access RGB controls, **When** I adjust settings, **Then** LED colors and patterns change as configured
5. **Given** I use the leader key, **When** I complete a leader sequence, **Then** the mapped action executes

---

### User Story 4 - Reduce Firmware Size (Priority: P3)

As a keyboard maintainer, I want the optimized layout to use significantly less code (target: <230KB, ideally 40-50% reduction) while maintaining all functionality, so that firmware builds faster, flashes faster, and leaves room for future enhancements.

**Why this priority**: Technical optimization that enables future development. Benefits are indirect but important for maintainability.

**Independent Test**: Can be independently tested by compiling the firmware before and after optimization, comparing binary sizes, and verifying the size meets the <230KB constitutional target (90% of 256KB flash).

**Acceptance Scenarios**:

1. **Given** the firmware is compiled, **When** I check the binary size, **Then** it is under 230KB (90% of flash capacity)
2. **Given** I compare old and new implementations, **When** I measure code lines and complexity, **Then** the new code shows 40-50% reduction
3. **Given** the optimized firmware is flashed, **When** I test all functions, **Then** everything works identically to the 10-layer version

---

### Edge Cases

- What happens when the user rapidly switches between layers before auto-return completes?
- How does the keyboard handle holding a layer-tap key at the exact TAPPING_TERM boundary?
- What occurs if the user presses a combo while already holding a home row modifier?
- How does RGB layer indication work when temporarily accessing a one-shot layer?
- What happens if the user tries to access a config function while a leader sequence is in progress?
- How does the keyboard behave when switching OS base layers while a utility layer (symbols/numbers) is active?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST reduce layer count from 10 to 5-6 layers while preserving all keyboard functions
- **FR-002**: System MUST provide two separate OS-specific base layers (macOS and Windows) with identical alpha key layouts but adapted home row modifiers
- **FR-003**: System MUST provide shared utility layers (symbols, function/navigation, numbers) accessible from both OS base layers
- **FR-004**: System MUST implement OS-aware clipboard operations that automatically use correct modifiers (Cmd on macOS, Ctrl on Windows)
- **FR-005**: System MUST preserve all German keyboard layout support (ä, ö, ü, ß, €) in the optimized structure
- **FR-006**: System MUST maintain all existing QMK features: CAPS_WORD, COMBO, KEY_OVERRIDE, LEADER, QK_REPEAT_KEY, RGB_MATRIX
- **FR-007**: System MUST use home row mods via QMK MT() macro instead of custom dual-function implementations
- **FR-008**: System MUST provide a config layer with RGB controls, layer switching, and bootloader access
- **FR-009**: System MUST implement one-shot layer (OSL) access for symbols and function layers
- **FR-010**: System MUST implement layer-tap (LT) access for numbers layer with space as the tap key
- **FR-011**: System MUST eliminate all custom dual-function implementations (tap dance) that can be replaced with simpler solutions
- **FR-012**: System MUST provide clear LED color indicators for different layers (base layers and config layer minimum)
- **FR-013**: System MUST maintain identical key positions for alpha characters across both OS base layers for consistent muscle memory
- **FR-014**: System MUST preserve all existing key positions for frequently used functions (tab, escape, enter, backspace)
- **FR-015**: System MUST compile to firmware size under 230KB (90% of 256KB flash capacity)

### Key Entities *(data-related)*

- **Layer**: Represents a keyboard layer with a numeric ID (0-5 or 0-6), name constant, keymap definition, and optional RGB color
  - Relationships: Base layers (0-1) can access utility layers (2-4) and config layer (5); utility layers return to most recent base
- **Home Row Mod**: Represents a dual-purpose key using MT() macro with a modifier (Ctrl/Alt/Cmd/Win) and base key (letter)
  - Attributes: modifier type (left/right), base keycode, timing threshold (TAPPING_TERM)
- **Custom Keycode**: Represents OS-aware operations with a unique enum value and behavior function
  - Attributes: keycode name (OS_UNDO, OS_COPY, OS_PASTE, OS_CUT), OS detection logic, modifier mapping
- **German Layout Alias**: Represents German keyboard character with QMK keycode (DE_*) and visual representation
  - Examples: DE_ADIA (ä), DE_ODIA (ö), DE_UDIA (ü), DE_SS (ß), DE_EURO (€)

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Firmware compiles to binary size under 230KB (90% of 256KB flash target)
- **SC-002**: Code size reduces by 40-50% compared to original 10-layer implementation (measured in lines of keymap.c)
- **SC-003**: Layer count reduces from 10 to 5-6 layers (40-50% reduction) while maintaining 100% feature parity
- **SC-004**: All 23 hardware test scenarios from original implementation pass successfully (typing, symbols, numbers, navigation, function keys, OS-specific operations, RGB controls, layer switching)
- **SC-005**: Zero custom dual-function implementations remain (all replaced with MT() macros or eliminated)
- **SC-006**: Build time for firmware reduces by at least 20% due to smaller codebase
- **SC-007**: All existing German keyboard characters (ä, ö, ü, ß, €) remain accessible in identical or fewer keystrokes
- **SC-008**: Home row modifier activation feels consistent across macOS and Windows base layers (TAPPING_TERM of 200ms maintained)
- **SC-009**: Constitution compliance validation passes for all 5 principles (minimal size, layer minimization, OS optimization, Oryx integration, maintainability)
- **SC-010**: Layer switching operations complete instantly (<50ms perceived latency) as measured by LED color changes

## Assumptions

- The vrMEr layout uses the same HIEA O / DTRNS alpha layout as JRaem (or similar ergonomic layout)
- The target keyboard is ZSA Voyager with 52 keys and 256KB flash memory
- The user needs both macOS and Windows support with OS-specific optimizations
- Tap dance features currently in vrMEr can be replaced with simpler MT() home row mods or eliminated
- The existing GitHub Actions build workflow will continue to work without modifications
- The user prefers one-shot layers (OSL) for temporary layer access over toggle layers
- Layer-tap with space bar (LT) is an acceptable pattern for numbers layer access
- The TAPPING_TERM of 200ms and ONESHOT_TIMEOUT of 5000ms from JRaem optimization are good defaults
- RGB matrix LED indication is desired for at least base layers and config layer
- The constitutional principles from feature 001-minimize-layers apply equally to this feature

## Dependencies

- Existing QMK firmware codebase (qmk_firmware submodule)
- German keyboard layout definitions (keymap_german.h)
- GitHub Actions workflow for firmware building
- Docker-based local build environment (build-local.ps1/sh scripts)
- ZSA Voyager keyboard hardware for testing
- Access to both macOS and Windows systems for OS-specific testing
- Keymapp application for firmware flashing
- Successful completion and learnings from feature 001-minimize-layers (JRaem optimization)
- Constitution compliance framework (.specify/memory/constitution.md)

## Out of Scope

- Changes to QMK firmware core functionality
- Modifications to Oryx layout editor or API
- Support for keyboards other than ZSA Voyager
- Support for operating systems other than macOS and Windows
- Custom PCB modifications or hardware changes
- Changes to USB communication protocol
- Implementation of new QMK features not already enabled
- Modification of GitHub Actions workflow structure
- Changes to Docker build configuration
- Support for layouts other than German keyboard (QWERTZ)
- Migration of Oryx layout to new structure (manual sync deferred)
- Real-time collaboration features
- Cloud synchronization of layouts
- Mobile device support or configuration
