# Original vrMEr Layout - 10 Layers

**Date Captured**: 2025-11-08  
**Purpose**: Backup of original vrMEr layout before 002-minimize-layers optimization  
**Source**: vrMEr/keymap.c (930 lines, 17 tap dances)

---

## Layer Structure (Original 10 Layers)

### Layer 0 - macOS Base
- **Alpha Layout**: HIEA O / DTRNS (P U repeat-key leader Q | G C L M F)
- **Home Row Mods**: Ctrl(H), Alt(I), Cmd(E) | Cmd(T), Alt(R), Ctrl(S)
- **Layer Access**: OSL(1) Symbols, OSM(Shift), OSL(2) Function, LT(3, Space) Numbers
- **Top Row**: Cmd+Minus, Cmd+0, Cmd+Plus, Cmd key | Shift+Tab, Tab, TO(9) Config
- **Features**: CW_TOGG (Caps Word), QK_REPEAT_KEY, QK_LEAD (Leader Key)

### Layer 1 - macOS Symbols
- **Symbols**: §, &, [, ], ^ | !, <, >, =, ~
- **Home Row**: TD(0)=@/Ctrl, TD(1)=/Alt, TD(2)={/Cmd, }, * | ?, (, TD(3)=)/Cmd, Alt(-), TD(4)=:/Ctrl
- **Bottom Row**: _, \, |, transparent, ` | +, %, $, #, ;
- **Layer Access**: TD(5)=Bspc/Ctrl+Bspc, TD(6)=Del/Ctrl+Del
- **Dual-Functions**: 6 tap dances (TD_0 to TD_6)

### Layer 2 - macOS Function/Navigation
- **Function Keys**: F1-F5 (top), F12 (left), F11, F10 (left col)
- **German Umlauts**: Ü, ẞ (TD_7=€/Cmd), Ä, Ö
- **Navigation**: Opt+Left, Cmd+Up, Opt+Right | Left, Down, Up, Right | Cmd+Down, Cmd+Left, Cmd+Right
- **Home Row**: Ctrl(Esc), Alt(ẞ), TD(7)=€/Cmd, Ä, Ö | arrows
- **Dual-Functions**: 1 tap dance (TD_7)

### Layer 3 - macOS Numbers
- **Numpad Layout**: Minus, 7-9, * | Colon, 1-3, 0 | Plus, 4-6, /
- **macOS Clipboard**: KC_MAC_UNDO, KC_MAC_COPY, KC_MAC_PASTE, KC_MAC_CUT, KC_APPLICATION
- **Layer Access**: Comma, Dot (thumbs)
- **No Dual-Functions**: Direct keycodes only

### Layer 4 - Windows Base
- **Alpha Layout**: Identical to Layer 0 (P U repeat-key leader Q | G C L M F)
- **Home Row Mods**: Win(H), Alt(I), Ctrl(E) | Ctrl(T), Alt(R), Win(S) ← SWAPPED from macOS
- **Layer Access**: OSL(6) Symbols, OSM(Shift), OSL(5) Function, LT(7, Space) Numbers
- **Top Row**: TD(8)==/Esc, Alt key | Shift+Tab, Tab, TO(9) Config
- **Right Thumb**: Alt+Tab, Alt+Shift+Tab (app switcher)
- **Features**: CW_TOGG, QK_REPEAT_KEY, QK_LEAD
- **Dual-Functions**: 1 tap dance (TD_8)

### Layer 5 - Windows Function/Navigation
- **Function Keys**: F1-F5 (top), F12, F11, F10 (left)
- **German Umlauts**: Ü, ẞ, TD(9)=€/Ctrl, Ä, Ö
- **Navigation**: Ctrl+Left, PageUp, Ctrl+Right | Left, Down, Up, Right | PageDown, Home, End
- **Home Row**: Win(Esc), Alt(ẞ), TD(9)=€/Ctrl | arrows
- **Dual-Functions**: 1 tap dance (TD_9)

### Layer 6 - Windows Symbols
- **Symbols**: §, &, [, ], ^ | !, <, >, =, ~
- **Home Row**: TD(10)=@/Win, TD(11)=/Alt, TD(12)={/Ctrl, }, * | ?, (, TD(13)=)/Ctrl, Alt(-), TD(14)=:/Win
- **Bottom Row**: _, \, |, ~, ` | +, %, $, #, ;
- **Layer Access**: TD(15)=Bspc/Alt+Bspc, TD(16)=Del/Alt+Del
- **Dual-Functions**: 7 tap dances (TD_10 to TD_16)

### Layer 7 - Windows Numbers
- **Numpad Layout**: Minus, 7-9, * | Colon, 1-3, 0 | Plus, 4-6, /
- **Windows Clipboard**: KC_PC_UNDO, KC_PC_COPY, KC_PC_PASTE, KC_PC_CUT, KC_APPLICATION
- **Layer Access**: Comma, Dot (thumbs)
- **No Dual-Functions**: Direct keycodes only

### Layer 8 - F-Key Row (Alternative)
- **Function Keys**: Tab, F7-F9, F12 | Esc, F1-F3, F11 | Enter, F4-F6, F10
- **Purpose**: Alternative F-key access (rarely used)
- **All Other Keys**: KC_TRANSPARENT (fallthrough to base)
- **No Dual-Functions**

### Layer 9 - Config/RGB
- **RGB Controls**: RGB_TOG, TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD, RGB_VAD, RGB_VAI | RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI | RGB_HUD, RGB_HUI
- **Layer Switching**: TO(4) Windows Base, TO(0) macOS Base, QK_BOOT bootloader
- **Media**: KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP
- **Navigation**: PageUp, Home, Up, End | PageDown, Left, Down, Right
- **Window Switching**: Ctrl+Shift+Tab, Ctrl+Tab
- **Preset Colors**: HSV_0_255_255 (red), HSV_74_255_255 (green), HSV_169_255_255 (blue)
- **No Dual-Functions**

---

## Tap Dance Inventory (17 Total)

### Layer 1 Tap Dances (macOS Symbols)
- **DANCE_0**: Tap=@ (DE_AT), Hold=Ctrl, Double-Tap=@@
- **DANCE_1**: Tap=/ (DE_SLSH), Hold=Alt, Double-Tap=//
- **DANCE_2**: Tap={ (DE_LCBR), Hold=Cmd, Double-Tap={{
- **DANCE_3**: Tap=) (DE_RPRN), Hold=Cmd, Double-Tap=))
- **DANCE_4**: Tap=: (DE_COLN), Hold=Ctrl, Double-Tap=::
- **DANCE_5**: Tap=Backspace, Hold=Ctrl+Backspace (delete word), Double-Tap=Backspace×2
- **DANCE_6**: Tap=Delete, Hold=Ctrl+Delete (delete word forward), Double-Tap=Delete×2

### Layer 2 Tap Dances (macOS Function)
- **DANCE_7**: Tap=€ (DE_EURO), Hold=Cmd, Double-Tap=€€

### Layer 4 Tap Dances (Windows Base)
- **DANCE_8**: Tap== (KC_EQUAL), Hold=Escape, Double-Tap===

### Layer 5 Tap Dances (Windows Function)
- **DANCE_9**: Tap=€ (DE_EURO), Hold=Ctrl, Double-Tap=€€

### Layer 6 Tap Dances (Windows Symbols)
- **DANCE_10**: Tap=@ (DE_AT), Hold=Win, Double-Tap=@@
- **DANCE_11**: Tap=/ (DE_SLSH), Hold=Alt, Double-Tap=//
- **DANCE_12**: Tap={ (DE_LCBR), Hold=Ctrl, Double-Tap={{
- **DANCE_13**: Tap=) (DE_RPRN), Hold=Ctrl, Double-Tap=))
- **DANCE_14**: Tap=: (DE_COLN), Hold=Win, Double-Tap=::
- **DANCE_15**: Tap=Backspace, Hold=Alt+Backspace (delete word macOS-style on Windows), Double-Tap=Backspace×2
- **DANCE_16**: Tap=Delete, Hold=Alt+Delete (delete word forward), Double-Tap=Delete×2

---

## Additional Features

### Key Overrides (2)
- **Shift+Dot → Comma**: `key_override_t dot_comma_override` (MOD_MASK_SHIFT + KC_DOT → KC_COMM)
- **Shift+DoubleQuote → SingleQuote**: `key_override_t quote_doublequote_override` (MOD_MASK_SHIFT + DE_DQOT → DE_QUOT)

### Combos (4)
- **OSM(Shift) + Dot → Comma**: Combo on both base layers (layers 0 and 4)
- **OSM(Shift) + SingleQuote → DoubleQuote**: Combo on both base layers
- **Note**: Combos duplicate key override functionality (redundant)

### Leader Key Sequences (11)
Triggered by QK_LEAD key:
1. **Leader + @ + A**: Types ä (shift → Ä)
2. **Leader + @ + O**: Types ö (shift → Ö)
3. **Leader + @ + U**: Types ü (shift → Ü)
4. **Leader + S**: Types ß
5. **Leader + A**: Types ä (shift → Ä)
6. **Leader + U**: Types ü (shift → Ü)
7. **Leader + O**: Types ö (shift → Ö)
8. **Leader + S + S**: Types ß
9. **Leader + C + E**: Types € (Euro)
10. **Leader + F**: (commented out) Would type "QMK is awesome."
11. **Leader + D + D + S**: (commented out) Would type "https://start.duckduckgo.com\n"

### RGB LED Layer Indication
- **Layer 0 (macOS Base)**: Custom LED map (ledmap[0]) with specific colors per key
- **Layer 4 (Windows Base)**: Custom LED map (ledmap[4]) with specific colors per key
- **Layer 9 (Config)**: Custom LED map (ledmap[9]) with TO(4), TO(0), QK_BOOT highlighted
- **All Other Layers**: LEDs off (inherit from base or turn off)

### Custom Keycodes (3)
- **RGB_SLD**: RGB solid color mode
- **HSV_0_255_255**: Red preset (H=0, S=255, V=255)
- **HSV_74_255_255**: Green preset (H=74, S=255, V=255)
- **HSV_169_255_255**: Blue preset (H=169, S=255, V=255)

---

## Code Statistics (Before Optimization)

- **Total Lines**: 930
- **Tap Dance Implementations**: 17 (DANCE_0 to DANCE_16)
- **Tap Dance Code**: ~460 lines (50% of total)
- **Layers**: 10 (0-9)
- **Custom Keycodes**: 4 (RGB_SLD, 3 HSV presets)
- **Key Overrides**: 2
- **Combos**: 4
- **Leader Sequences**: 11 (9 active, 2 commented)
- **LED Layers**: 3 (layers 0, 4, 9)

---

## Issues Identified (Rationale for Optimization)

1. **Dual OS Layouts Duplicated**: Layers 1-3 (macOS) and 6-8 (Windows) nearly identical, only modifiers differ
2. **Excessive Tap Dances**: 17 implementations add ~460 lines of code, increase firmware size, complicate maintenance
3. **Redundant Features**: Combos duplicate key override functionality
4. **Layer Sprawl**: 10 layers exceed target of ≤6 layers (Constitutional Principle 2)
5. **Firmware Size Risk**: 930 lines with tap dance logic may approach 256KB flash limit
6. **Maintenance Complexity**: Tap dance state machines harder to debug than QMK MT() macros
7. **Inconsistent OS Detection**: Two separate layer sets instead of shared utilities with OS-aware helpers

---

## Target Optimization (002-minimize-layers)

**Goals**:
- Reduce 10 layers → 6 layers (MAC_BASE, WIN_BASE, SYMBOLS, FUNCTION, NUMBERS, CONFIG)
- Eliminate 17 tap dances → 0 (use MT() macros or direct keycodes)
- Consolidate duplicate symbol/function layers → shared utilities
- Add OS-aware clipboard helpers (OS_COPY, OS_PASTE, OS_CUT, OS_UNDO)
- Preserve all functionality (German umlauts, F-keys, navigation, RGB controls)
- Reduce code by 40-50% (930 → 465-550 lines)
- Maintain firmware size < 230KB (90% of 256KB flash)
- Constitutional compliance (all 5 principles validated)

**See**: specs/002-minimize-layers/spec.md for complete requirements
