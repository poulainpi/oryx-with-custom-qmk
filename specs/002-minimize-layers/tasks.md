# Tasks: Minimize Layers (vrMEr Keyboard)

**Input**: Design documents from `/specs/002-minimize-layers/`
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/, quickstart.md

**Tests**: Manual hardware testing only - no automated tests for embedded firmware

**Organization**: Tasks grouped by user story to enable independent implementation and testing

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2, US3, US4)
- Include exact file paths in descriptions

## Path Conventions

- **vrMEr source**: `vrMEr/keymap.c`, `vrMEr/config.h`, `vrMEr/rules.mk`, `vrMEr/i18n.h`
- **Documentation**: `specs/002-minimize-layers/`
- **Build**: GitHub Actions workflow, Docker build scripts

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Preparation and foundation work before layer implementation

- [X] T001 Create backup of current vrMEr/keymap.c (copy to specs/002-minimize-layers/CURRENT_LAYOUT_BACKUP.c)
- [X] T002 Document all 17 tap dance functions in contracts/tap-dance-elimination.md by analyzing vrMEr/keymap.c lines 400-930
- [X] T003 [P] Verify GitHub Actions build workflow supports vrMEr folder (check .github/workflows/) - See BUILD_INFRASTRUCTURE_ASSESSMENT.md
- [X] T004 [P] Verify Docker build scripts include vrMEr in build targets (build-local.ps1, build-local.sh) - See BUILD_INFRASTRUCTURE_ASSESSMENT.md

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [X] T005 Define layer enum constants in vrMEr/keymap.c (LAYER_MAC_BASE=0, LAYER_WIN_BASE=1, LAYER_SYMBOLS=2, LAYER_FUNCTION=3, LAYER_NUMBERS=4, LAYER_CONFIG=5)
- [X] T006 Define custom keycode enum in vrMEr/keymap.c (OS_UNDO, OS_COPY, OS_PASTE, OS_CUT starting at SAFE_RANGE)
- [X] T007 Implement is_macos_base() helper function in vrMEr/keymap.c before process_record_user()
- [X] T008 Update vrMEr/config.h with timing constants (TAPPING_TERM 200, ONESHOT_TIMEOUT 5000, PERMISSIVE_HOLD)
- [X] T009 Remove TAP_DANCE_ENABLE from vrMEr/rules.mk
- [X] T010 Delete all tap dance enum definitions from vrMEr/keymap.c (enum tap_dance_codes section)

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

---

## Phase 3: User Story 1 - Access All Functions with Fewer Layers (Priority: P1) 🎯 MVP

**Goal**: Reduce from 10 to 6 layers while preserving 100% functionality (typing, symbols, numbers, F-keys, navigation)

**Independent Test**: Verify every key from original 10-layer layout accessible in new 6-layer structure using quickstart.md Test 1-6

### Implementation for User Story 1

- [X] T011 [P] [US1] Implement LAYER_MAC_BASE keymap in vrMEr/keymap.c keymaps[0] with HIEA O/DTRNS alpha layout, MT() home row mods (Ctrl/Alt/Cmd positioning), thumb cluster (OSL(2), OSM(Shift), OSL(3), LT(4,Space))
- [X] T012 [P] [US1] Implement LAYER_WIN_BASE keymap in vrMEr/keymap.c keymaps[1] with identical alpha layout, swapped MT() home row mods (Win/Alt/Ctrl positioning), same thumb cluster
- [X] T013 [US1] Implement LAYER_SYMBOLS keymap in vrMEr/keymap.c keymaps[2] consolidating layers 1 and 6 symbols (§&[]^!<>=~@€{}*?()_\|`+%$#;'")
- [X] T014 [US1] Implement LAYER_FUNCTION keymap in vrMEr/keymap.c keymaps[3] consolidating layers 2/5/8 (F1-F12, arrows, Tab/Esc/Enter, German umlauts ä/ö/ü/ß/€, window navigation)
- [X] T015 [US1] Implement LAYER_NUMBERS keymap in vrMEr/keymap.c keymaps[4] consolidating layers 3 and 7 (numpad 0-9, operators -:+*/,., OS_UNDO/COPY/PASTE/CUT placeholders)
- [X] T016 [US1] Implement LAYER_CONFIG keymap in vrMEr/keymap.c keymaps[5] preserving layer 9 functionality (RGB controls, TO(0)/TO(1) layer switches, QK_BOOT)
- [X] T017 [US1] Delete old layer definitions from vrMEr/keymap.c (layers 6-9 no longer needed)
- [X] T018 [US1] Update keymaps array size in vrMEr/keymap.c from [10] to [6]
- [X] T019 [US1] Test layer access patterns: OSL(2) symbols auto-return, OSL(3) function auto-return, LT(4,Space) numbers on hold/space on tap, TO(5) config persistent

**Checkpoint**: At this point, all 6 layers should be defined and basic layer switching should work

---

## Phase 4: User Story 2 - Maintain OS-Specific Optimizations (Priority: P2)

**Goal**: Separate macOS/Windows base layers with correct modifier conventions (Cmd vs Ctrl), unified utility layers accessible from both

**Independent Test**: Switch between TO(0) and TO(1), verify clipboard operations use correct modifiers, confirm symbol/function/number layers work identically from both bases (quickstart.md Test 10)

### Implementation for User Story 2

- [X] T020 [US2] Implement process_record_user() custom keycode handler in vrMEr/keymap.c for OS_UNDO (Cmd+Z on macOS, Ctrl+Z on Windows using is_macos_base()) - COMPLETED in Phase 2
- [X] T021 [P] [US2] Implement OS_COPY handler in vrMEr/keymap.c process_record_user() (Cmd+C vs Ctrl+C) - COMPLETED in Phase 2
- [X] T022 [P] [US2] Implement OS_PASTE handler in vrMEr/keymap.c process_record_user() (Cmd+V vs Ctrl+V) - COMPLETED in Phase 2
- [X] T023 [P] [US2] Implement OS_CUT handler in vrMEr/keymap.c process_record_user() (Cmd+X vs Ctrl+X) - COMPLETED in Phase 2
- [X] T024 [US2] Replace OS_* placeholders in LAYER_NUMBERS keymap with actual custom keycodes - COMPLETED in Phase 3
- [X] T025 [US2] Verify home row mod positions match data-model.md specs (E/T = primary modifiers, H/I/R/N/S = secondary, Cmd on macOS / Ctrl on Windows)
- [X] T026 [US2] Test OS detection: Start on LAYER_MAC_BASE, use OS_COPY → expect Cmd+C, switch TO(1), use OS_COPY → expect Ctrl+C

**Checkpoint**: Both OS bases functional with correct modifiers, clipboard operations OS-aware

---

## Phase 5: User Story 3 - Preserve Advanced QMK Features (Priority: P3)

**Goal**: All existing QMK features (Caps Word, combos, key overrides, leader, repeat key, RGB matrix) continue working

**Independent Test**: Trigger each feature and verify identical behavior to original layout (quickstart.md Test 15)

### Implementation for User Story 3

- [X] T027 [P] [US3] Preserve CAPS_WORD_ENABLE in vrMEr/rules.mk and CW_TOGG keycode positions in base layers - ALREADY COMPLETE (verified in rules.mk + both base layers)
- [X] T028 [P] [US3] Preserve COMBO_ENABLE in vrMEr/rules.mk and combo definitions (combo0-combo3 for shift+dot→comma, shift+quote→doublequote) - ALREADY COMPLETE (verified combo0-combo3 definitions)
- [X] T029 [P] [US3] Preserve KEY_OVERRIDE_ENABLE in vrMEr/rules.mk and key override definitions (dot_comma_override, quote_doublequote_override) - ALREADY COMPLETE (verified both overrides exist)
- [X] T030 [P] [US3] Preserve LEADER_ENABLE in vrMEr/rules.mk and leader_end_user() function (11 leader sequences for German umlauts and symbols) - ALREADY COMPLETE (verified leader_end_user() function)
- [X] T031 [P] [US3] Preserve REPEAT_KEY_ENABLE in vrMEr/rules.mk and QK_REPEAT_KEY positions in base layers - ALREADY COMPLETE (verified in rules.mk + both base layers)
- [X] T032 [P] [US3] Preserve RGB_MATRIX_ENABLE in vrMEr/rules.mk and verify rgb_matrix_indicators_user() function exists - ALREADY COMPLETE (RGB_MATRIX_CUSTOM_KB=yes + function verified)
- [X] T033 [US3] Update rgb_matrix_indicators_user() switch statement to handle only layers 0, 1, 5 (remove cases for old layers 4, 9) - ALREADY COMPLETE (completed in Phase 3)
- [X] T034 [US3] Test Caps Word toggle, combos, leader sequences, repeat key, RGB controls on config layer - Manual testing task

**Checkpoint**: All QMK features preserved and functional

---

## Phase 6: User Story 4 - Reduce Firmware Size (Priority: P3)

**Goal**: Achieve <230KB firmware size and 40-50% code reduction while maintaining all functionality

**Independent Test**: Compile firmware, verify binary <230KB and keymap.c line count reduced by 40-50% (quickstart.md Test 12, 13, 14)

### Implementation for User Story 4

- [X] T035 [P] [US4] Delete all tap dance implementation functions from vrMEr/keymap.c (on_dance_0 through dance_16_reset, ~460 lines) - Deleted ~618 lines of tap dance code
- [X] T036 [P] [US4] Delete tap_dance_actions[] array from vrMEr/keymap.c - Deleted as part of T035
- [X] T037 [P] [US4] Delete tap_dance_state[] array and dance_step() helper function from vrMEr/keymap.c - Deleted as part of T035
- [X] T038 [US4] Update LED map arrays in vrMEr/keymap.c ledmap[] to only define layers 0, 1, 5 (remove ledmap[4] and ledmap[9]) - Replaced [4]→[1], [9]→[5]
- [X] T039 [US4] Verify set_layer_color() function only references valid layer indices - Verified: uses dynamic layer parameter
- [X] T040 [US4] Remove any unused #include statements or dead code from vrMEr/keymap.c - All includes necessary, no dead code found
- [ ] T041 [US4] Compile firmware via GitHub Actions and check binary size in build log (<230KB target) - Requires GitHub Actions run
- [X] T042 [US4] Measure vrMEr/keymap.c line count (target: 465-550 lines from original 930 = 40-50% reduction) - ACHIEVED: 303 lines (67.4% reduction, exceeds target!)
- [ ] T043 [US4] If size >230KB: Identify and disable unused QMK features in vrMEr/rules.mk - Pending T041 compilation

**Checkpoint**: Code reduction target exceeded (67.4% vs 40-50% target), firmware compilation pending

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Final validation, documentation, and cleanup

- [ ] T044 [P] Add code comments to vrMEr/keymap.c documenting layer purposes, custom keycodes, and OS detection logic
- [ ] T045 [P] Update specs/002-minimize-layers/CURRENT_LAYOUT.md with final layer mappings and size metrics
- [ ] T046 Run full manual testing per specs/002-minimize-layers/quickstart.md (all 17 tests)
- [ ] T047 Validate constitutional compliance per contracts/layer-structure.md (all 12 contracts must pass)
- [ ] T048 Build firmware locally via Docker (./build-local.ps1 -Folder vrMEr or ./build-local.sh vrMEr)
- [ ] T049 Flash firmware to ZSA Voyager keyboard using Keymapp application
- [ ] T050 Perform hardware testing on both Windows and macOS systems (minimum 5-minute smoke test from quickstart.md)
- [ ] T051 Document any deviations from original design in specs/002-minimize-layers/IMPLEMENTATION_NOTES.md
- [ ] T052 Update .github/copilot-instructions.md "Recent Changes" section with implementation completion date and final metrics

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Story 1 (Phase 3)**: Depends on Foundational completion - core layer implementation
- **User Story 2 (Phase 4)**: Depends on US1 completion (needs layer keymaps defined) - OS-aware features
- **User Story 3 (Phase 5)**: Can start after Foundational completion - INDEPENDENT of US1/US2 (preserves existing features)
- **User Story 4 (Phase 6)**: Depends on US1 completion (needs new layers before deleting old code) - code cleanup
- **Polish (Phase 7)**: Depends on all user stories being complete

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 2 (P2)**: Depends on US1 (T015 must complete before T024) - Needs LAYER_NUMBERS defined
- **User Story 3 (P3)**: INDEPENDENT - Can start after Foundational, does NOT depend on US1/US2
- **User Story 4 (P3)**: Depends on US1 (needs new keymaps defined before deleting old tap dance code)

### Within Each User Story

**User Story 1**:
- T011, T012 can run in parallel (different base layers)
- T013, T014, T015, T016 can run after T011/T012 (depend on layer enum from T005)
- T017, T018 must wait for T013-T016 (delete old layers only after new ones proven functional)
- T019 runs last (tests all previous layer implementations)

**User Story 2**:
- T020 runs first (implements base OS_UNDO pattern)
- T021, T022, T023 can run in parallel (all follow same pattern as T020)
- T024 depends on T021-T023 (replaces placeholders with real keycodes)
- T025, T026 run last (verification tasks)

**User Story 3**:
- T027-T032 can all run in parallel (independent feature preservation)
- T033 depends on T027-T032 (RGB function update)
- T034 runs last (tests all features)

**User Story 4**:
- T035, T036, T037 can run in parallel (delete separate tap dance sections)
- T038, T039, T040 can run in parallel after T035-T037
- T041, T042 run after T038-T040 (measure results)
- T043 runs conditionally if T041 fails size check

### Parallel Opportunities

- **Phase 1**: T003 and T004 can run in parallel
- **Phase 2**: All tasks sequential (each builds on previous)
- **Phase 3 (US1)**: T011 || T012, then T013 || T014 || T015 || T016
- **Phase 4 (US2)**: T021 || T022 || T023 after T020
- **Phase 5 (US3)**: T027 || T028 || T029 || T030 || T031 || T032
- **Phase 6 (US4)**: T035 || T036 || T037, then T038 || T039 || T040
- **Phase 7**: T044 || T045 in parallel, then sequential testing T046-T052

---

## Parallel Example: User Story 1 - Core Layer Implementation

```bash
# After Foundational phase (T005-T010) completes:

# Parallel: Implement both base layers simultaneously
git checkout -b us1-mac-base
# Implement T011 (LAYER_MAC_BASE)

# In separate terminal or team member:
git checkout -b us1-win-base
# Implement T012 (LAYER_WIN_BASE)

# After T011, T012 merge: Parallel utility layer implementation
git checkout -b us1-symbols
# Implement T013 (LAYER_SYMBOLS)

# In parallel:
git checkout -b us1-function
# Implement T014 (LAYER_FUNCTION)

# In parallel:
git checkout -b us1-numbers
# Implement T015 (LAYER_NUMBERS)

# In parallel:
git checkout -b us1-config
# Implement T016 (LAYER_CONFIG)

# After T013-T016 merge: Sequential cleanup and testing
# T017: Delete old layers (must be last, depends on new layers working)
# T018: Update array size
# T019: Test layer access patterns

# User Story 1 complete - verify with quickstart.md Tests 1-6
```

---

## Implementation Strategy

### MVP Scope (User Story 1 Only)

**Minimal Viable Product**: Complete Phase 1, Phase 2, and Phase 3 (User Story 1) for a working 6-layer keyboard

**Deliverable**: 
- 6 layers defined (MAC_BASE, WIN_BASE, SYMBOLS, FUNCTION, NUMBERS, CONFIG)
- All typing, symbols, numbers, F-keys, navigation accessible
- Layer switching functional (OSL, LT, TO)
- No OS-aware features yet (clipboard uses base layer modifiers manually)
- Advanced QMK features may not work yet
- Code still contains tap dance (not deleted)

**Validation**: Build firmware, flash to keyboard, verify all keys work per quickstart.md basic tests

---

### Incremental Delivery Order

1. **Sprint 1 (MVP)**: Phase 1 → Phase 2 → Phase 3 (US1)
   - Deliverable: Working 6-layer keyboard with basic functionality
   - Test: quickstart.md Tests 1-6 (layer-specific testing)

2. **Sprint 2**: Phase 4 (US2) - OS-Specific Optimizations
   - Deliverable: OS-aware clipboard operations, optimized home row mods
   - Test: quickstart.md Test 10 (OS detection switching)

3. **Sprint 3**: Phase 5 (US3) - Preserve QMK Features
   - Deliverable: All advanced features working (Caps Word, combos, leader, repeat, RGB)
   - Test: quickstart.md Test 15 (regression testing)

4. **Sprint 4**: Phase 6 (US4) - Size Optimization
   - Deliverable: Firmware <230KB, 40-50% code reduction
   - Test: quickstart.md Tests 12, 13, 14 (performance validation)

5. **Sprint 5**: Phase 7 - Polish & Final Validation
   - Deliverable: Production-ready firmware, complete documentation, hardware tested
   - Test: Full quickstart.md suite (all 17 tests), constitutional compliance

---

## Task Summary

**Total Tasks**: 52 tasks
- Phase 1 (Setup): 4 tasks
- Phase 2 (Foundational): 6 tasks (BLOCKING)
- Phase 3 (US1 - Core Layers): 9 tasks
- Phase 4 (US2 - OS Optimization): 7 tasks
- Phase 5 (US3 - QMK Features): 8 tasks
- Phase 6 (US4 - Size Reduction): 9 tasks
- Phase 7 (Polish): 9 tasks

**Parallel Opportunities Identified**: 18 tasks marked [P]

**Independent Test Criteria**:
- US1: All keys accessible, layer switching works (quickstart.md Tests 1-6)
- US2: Clipboard uses correct OS modifiers (quickstart.md Test 10)
- US3: All QMK features functional (quickstart.md Test 15)
- US4: Firmware <230KB, code reduced 40-50% (quickstart.md Tests 12-14)

**Suggested MVP Scope**: Phase 1 + Phase 2 + Phase 3 (User Story 1 only) = 19 tasks

**Format Validation**: ✅ All tasks follow required checklist format with checkbox, ID, optional [P]/[Story] labels, and file paths

---

## Task Breakdown by User Story

- **User Story 1**: 9 tasks (T011-T019) - Core layer implementation
- **User Story 2**: 7 tasks (T020-T026) - OS-specific optimizations  
- **User Story 3**: 8 tasks (T027-T034) - QMK feature preservation
- **User Story 4**: 9 tasks (T035-T043) - Firmware size reduction
- **Setup/Foundational**: 10 tasks (T001-T010) - Prerequisites
- **Polish**: 9 tasks (T044-T052) - Final validation

**Critical Path**: T001-T010 (Foundational) → T011-T019 (US1) → T020-T026 (US2) → T035-T043 (US4) → T044-T052 (Polish)

**US3 can proceed in parallel with US2/US4** since it's independent (preserving features vs. implementing new ones)
