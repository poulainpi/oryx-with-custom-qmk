# Current 10-Layer Keyboard Layout

**Documented**: 2025-11-07  
**Purpose**: Backup documentation of the existing 10-layer structure before consolidation  
**Source**: JRaem/keymap.c (before layer minimization implementation)

## Layer Structure Overview

The current keyboard layout uses **10 layers** (numbered 0-9):

- **Layer 0**: macOS Base Layer
- **Layer 1**: macOS Symbol Layer
- **Layer 2**: macOS Function/Navigation Layer
- **Layer 3**: macOS Number Pad Layer
- **Layer 4**: Windows Base Layer
- **Layer 5**: Windows Function/Navigation Layer
- **Layer 6**: Windows Symbol Layer
- **Layer 7**: Windows Number Pad Layer
- **Layer 8**: Function Keys Layer (cross-OS)
- **Layer 9**: Configuration/RGB Control Layer

## Layer Details

### Layer 0 - macOS Base Layer

**Purpose**: Primary typing layer for macOS  
**Home Row Mods**:
- Left hand: H(Ctrl), I(Alt), E(Cmd), A, O
- Right hand: D, T, R(Cmd), N(Alt), S(Ctrl)

**Thumb Cluster**:
- Left inner: OSL(1) - One-shot symbol layer
- Left outer: OSM(MOD_LSFT) - One-shot shift
- Right inner: OSL(2) - One-shot function/nav layer
- Right outer: LT(3, KC_SPACE) - Layer-tap numbers/space

**Special Keys**: CW_TOGG (caps word), QK_REPEAT_KEY, QK_LEAD (leader), TO(9) access to config layer

**LED Pattern**: Blue/teal indicators on specific keys

---

### Layer 1 - macOS Symbol Layer

**Purpose**: Programming symbols and special characters for macOS  
**Access**: OSL(1) from Layer 0 left thumb

**Key Categories**:
- Brackets: [ ] { } ( ) < >
- Operators: + - * / = ! ? % $ #
- Special: § & @ | \ _ ~ ^ ` 

**Dual-Functions**:
- DUAL_FUNC_0: LT(10, KC_U) at @ position
- DUAL_FUNC_1: LT(5, KC_F3) at / position
- DUAL_FUNC_2: LT(7, KC_F3) at { position
- DUAL_FUNC_3: LT(9, KC_3) at ) position
- DUAL_FUNC_4: LT(13, KC_U) at : position
- DUAL_FUNC_5: LT(2, KC_F20) in right thumb
- DUAL_FUNC_6: LT(3, KC_F16) in right thumb

---

### Layer 2 - macOS Function/Navigation Layer

**Purpose**: Function keys, navigation, German umlauts for macOS  
**Access**: OSL(2) from Layer 0 right inner thumb

**Key Categories**:
- Function keys: F1-F12 (F10-F12 on left edge, F1-F9 on bottom row)
- Navigation: Arrow keys (←↓↑→), window management (Cmd+arrows)
- Editing: Escape(Ctrl), Tab, Enter
- German characters: ü, ß, ä, ö, €

**Dual-Functions**:
- DUAL_FUNC_7: LT(8, KC_T) at € position

**Window Management**: Opt+Left, Cmd+Up, Opt+Right, Cmd+Down/Left/Right

---

### Layer 3 - macOS Number Pad Layer

**Purpose**: Number pad layout with macOS clipboard shortcuts  
**Access**: LT(3, KC_SPACE) from Layer 0 right outer thumb

**Layout**:
- Number pad: 7-8-9 (top), 1-2-3-0 (middle), 4-5-6 (bottom)
- Operators: - (DE_MINS), : (DE_COLN), + (DE_PLUS), * (DE_ASTR), / (DE_SLSH)
- Clipboard: KC_MAC_UNDO, KC_MAC_COPY, KC_MAC_PASTE, KC_MAC_CUT
- Utility: KC_APPLICATION, KC_PSCR (Print Screen)
- Decimal: KC_COMMA, KC_DOT (in thumbs)

---

### Layer 4 - Windows Base Layer

**Purpose**: Primary typing layer for Windows  
**Home Row Mods** (different from macOS):
- Left hand: H(Win/Cmd), I(Alt), E(Ctrl), A, O
- Right hand: D, T(Ctrl), R(Alt), N(Win/Cmd), S

**Thumb Cluster**:
- Left inner: OSL(6) - One-shot Windows symbol layer
- Left outer: OSM(MOD_LSFT) - One-shot shift
- Right inner: OSL(5) - One-shot Windows function/nav layer
- Right outer: LT(7, KC_SPACE) - Layer-tap Windows numbers/space

**Special Keys**: CW_TOGG, QK_REPEAT_KEY, QK_LEAD, TO(9) access to config, Alt+Tab navigation

**LED Pattern**: Green indicators on specific keys

**Dual-Functions**:
- DUAL_FUNC_8: LT(7, KC_U) at top-left position

---

### Layer 5 - Windows Function/Navigation Layer

**Purpose**: Function keys, navigation, German umlauts for Windows  
**Access**: OSL(5) from Layer 4 right inner thumb

**Key Categories**:
- Function keys: F1-F12 (same layout as Layer 2)
- Navigation: Arrow keys, Ctrl+Left/Right for word navigation, PgUp/PgDn, Home, End
- Editing: Escape(Win), Tab, Enter
- German characters: ü, ß, ä, ö, €

**Dual-Functions**:
- DUAL_FUNC_9: LT(8, KC_H) at € position

---

### Layer 6 - Windows Symbol Layer

**Purpose**: Programming symbols and special characters for Windows  
**Access**: OSL(6) from Layer 4 left thumb

**Layout**: Identical symbol positions to Layer 1 (macOS symbols)

**Dual-Functions**:
- DUAL_FUNC_10: LT(10, KC_1) at @ position
- DUAL_FUNC_1: LT(5, KC_F3) at / position (shared with macOS)
- DUAL_FUNC_11: LT(3, KC_N) at { position
- DUAL_FUNC_12: LT(14, KC_2) at ) position
- DUAL_FUNC_13: LT(6, KC_K) at : position
- DUAL_FUNC_14: LT(14, KC_F13) in right thumb
- DUAL_FUNC_15: LT(6, KC_0) in right thumb

---

### Layer 7 - Windows Number Pad Layer

**Purpose**: Number pad layout with Windows clipboard shortcuts  
**Access**: LT(7, KC_SPACE) from Layer 4 right outer thumb

**Layout**: Identical number positions to Layer 3 (macOS numbers)

**Clipboard Shortcuts**: KC_PC_UNDO, KC_PC_COPY, KC_PC_PASTE, KC_PC_CUT (Ctrl+Z/C/V/X instead of Cmd)

---

### Layer 8 - Function Keys Layer

**Purpose**: Alternative function key layout (cross-OS)  
**Access**: Via DUAL_FUNC_7 (macOS) or DUAL_FUNC_9 (Windows)

**Layout**:
- Top row: Tab, F7-F8-F9-F12
- Middle row: Escape, F1-F2-F3-F11
- Bottom row: Enter, F4-F5-F6-F10

**Note**: This layer provides an alternate F-key arrangement, appears to be less frequently used

---

### Layer 9 - Configuration/RGB Control Layer

**Purpose**: RGB lighting control, layer switching, system functions  
**Access**: TO(9) from Layers 0 and 4 (top-right key)

**RGB Controls**:
- RGB_TOG (toggle), TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD
- RGB_VAD/RGB_VAI (brightness down/up)
- RGB_SAD/RGB_SAI (saturation down/up)
- RGB_SPD/RGB_SPI (speed down/up)
- RGB_HUD/RGB_HUI (hue down/up)
- HSV presets: HSV_0_255_255, HSV_74_255_255, HSV_169_255_255

**Layer Switching**:
- TO(4): Switch to Windows base layer
- TO(0): Switch to macOS base layer

**System Functions**:
- QK_BOOT: Enter bootloader mode for firmware flashing

**Navigation** (seems out of place):
- Arrow keys, PgUp/PgDn, Home, End
- Ctrl+Tab, Ctrl+Shift+Tab

**LED Pattern**: Custom indicators for config mode

---

## Dual-Function Key Summary

**Total**: 16 dual-function implementations (DUAL_FUNC_0 through DUAL_FUNC_15)

| ID | Definition | Tap | Hold | Used On |
|----|------------|-----|------|---------|
| DUAL_FUNC_0 | LT(10, KC_U) | U | Layer 10 | Layer 1 (@) |
| DUAL_FUNC_1 | LT(5, KC_F3) | F3 | Layer 5 | Layers 1, 6 (/) |
| DUAL_FUNC_2 | LT(7, KC_F3) | F3 | Layer 7 | Layer 1 ({) |
| DUAL_FUNC_3 | LT(9, KC_3) | 3 | Layer 9 | Layer 1 ()) |
| DUAL_FUNC_4 | LT(13, KC_U) | U | Layer 13 | Layer 1 (:) |
| DUAL_FUNC_5 | LT(2, KC_F20) | F20 | Layer 2 | Layer 1 thumb |
| DUAL_FUNC_6 | LT(3, KC_F16) | F16 | Layer 3 | Layer 1 thumb |
| DUAL_FUNC_7 | LT(8, KC_T) | T | Layer 8 | Layer 2 (€) |
| DUAL_FUNC_8 | LT(7, KC_U) | U | Layer 7 | Layer 4 top-left |
| DUAL_FUNC_9 | LT(8, KC_H) | H | Layer 8 | Layer 5 (€) |
| DUAL_FUNC_10 | LT(10, KC_1) | 1 | Layer 10 | Layer 6 (@) |
| DUAL_FUNC_11 | LT(3, KC_N) | N | Layer 3 | Layer 6 ({) |
| DUAL_FUNC_12 | LT(14, KC_2) | 2 | Layer 14 | Layer 6 ()) |
| DUAL_FUNC_13 | LT(6, KC_K) | K | Layer 6 | Layer 6 (:) |
| DUAL_FUNC_14 | LT(14, KC_F13) | F13 | Layer 14 | Layer 6 thumb |
| DUAL_FUNC_15 | LT(6, KC_0) | 0 | Layer 6 | Layer 6 thumb |

**Note**: Some dual-functions reference layers beyond 9 (layers 10, 13, 14), which may be errors or unused layer references.

---

## QMK Features Enabled

- **CAPS_WORD_ENABLE**: CW_TOGG toggle
- **COMBO_ENABLE**: 4 combos defined
- **KEY_OVERRIDE_ENABLE**: 2 overrides (shift+dot=comma, shift+quote=doublequote)
- **LEADER_ENABLE**: QK_LEAD key
- **REPEAT_KEY_ENABLE**: QK_REPEAT_KEY
- **RGB_MATRIX_ENABLE**: Custom LED patterns per layer

---

## LED Configurations

**Layers with custom LEDs**: 0 (macOS base), 4 (Windows base), 9 (config)

**Layer 0 (macOS)**: Blue/teal pattern on specific positions (positions 18-21, 45, 47)  
**Layer 4 (Windows)**: Green pattern on similar positions (positions 21, 45, 47)  
**Layer 9 (Config)**: Yellow/cyan indicators (positions 26, 28)

---

## Key Overrides

1. **Shift + Dot → Comma**: `ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM)`
2. **Shift + Quote → Double Quote**: `ko_make_basic(MOD_MASK_SHIFT, DE_DQOT, DE_QUOT)`

---

## Combos

1. **Dot + Shift → Comma**: `combo0`
2. **Shift + Quote → Double Quote**: `combo1`
3. **Dot + Shift → Comma**: `combo2` (duplicate?)
4. **Quote + Shift → Double Quote**: `combo3` (duplicate?)

---

## Analysis: Duplication & Consolidation Opportunities

### Duplicate Layers

**macOS vs Windows Parallel Structure**:
- Layers 1 (macOS symbols) ≈ Layer 6 (Windows symbols) - **NEARLY IDENTICAL**
- Layers 2 (macOS func/nav) ≈ Layer 5 (Windows func/nav) - **SIMILAR with modifier differences**
- Layers 3 (macOS numbers) ≈ Layer 7 (Windows numbers) - **IDENTICAL except clipboard shortcuts**

**Function Key Duplication**:
- Layer 2 (F1-F12) vs Layer 5 (F1-F12) vs Layer 8 (F1-F12 alt layout) - **3 layers with F-keys**

### Consolidation Strategy (Target: 5 Layers)

1. **Keep separate base layers** (Layers 0, 4) → **New Layers 0, 1**
   - Rationale: Home row mods differ significantly (Ctrl/Cmd positioning)
   
2. **Merge symbol layers** (Layers 1, 6) → **New Layer 2**
   - Rationale: Symbol positions identical, dual-functions can be OS-aware
   
3. **Merge function/nav layers** (Layers 2, 5, 8) → **New Layer 3**
   - Rationale: F-keys identical, navigation differs only in modifiers (Cmd vs Ctrl)
   
4. **Merge number layers** (Layers 3, 7) → **New Layer 4**
   - Rationale: Number positions identical, clipboard shortcuts use OS detection
   
5. **Keep config layer** (Layer 9) → **New Layer 5**
   - Rationale: RGB controls and system functions are OS-independent

**Result**: 10 layers → 5 layers (50% reduction)

---

## File Size Metrics

**Current keymap.c**: 471 lines total
- Layer definitions: Lines 33-108 (~75 lines)
- Dual-function definitions: Lines 17-32 (16 definitions)
- LED maps: Lines 145-154 (3 layer LED configs)
- RGB indicators: Lines 184-201 (switch statement with 3 cases)

**Estimated savings from consolidation**:
- Remove 5 duplicate layer definitions: ~37 lines
- Reduce dual-functions from 16 to ~13: ~10 lines
- Optimize LED indicators: ~5 lines
- **Total estimated reduction**: ~50-60 lines (~10-12% code size reduction)

---

## Backup Information

**Backup Branch**: `backup-10-layer-layout`  
**Created**: 2025-11-07  
**Purpose**: Rollback point if layer consolidation needs to be reverted

To restore original 10-layer layout:
```bash
git checkout backup-10-layer-layout
git checkout 001-minimize-layers  # Return to feature branch
git reset --hard backup-10-layer-layout  # Reset to backup (CAUTION: destroys changes)
```
