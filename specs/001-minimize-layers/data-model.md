# Data Model: Layer Architecture and Key Mappings

**Feature**: Minimize Keyboard Layers  
**Created**: 2025-11-07  
**Purpose**: Define the consolidated 5-layer architecture with detailed key mappings and relationships

## Layer Architecture Overview

### Layer Hierarchy (5 Layers Total)

```
Layer 0: LAYER_MAC_BASE (macOS Base Layer)
Layer 1: LAYER_WIN_BASE (Windows Base Layer)
Layer 2: LAYER_SYMBOLS (Unified Symbol Layer)
Layer 3: LAYER_FUNCTION (Unified Function/Navigation Layer)
Layer 4: LAYER_NUMBERS (Unified Number Pad Layer)
Layer 5: LAYER_CONFIG (Configuration/RGB Layer) [Optional 6th if needed]
```

**Note**: Configuration layer can be renumbered to 5 or kept at current position 9 for minimal disruption. Design assumes 5-layer core with config as utility layer.

## Layer Entities

### Entity: Base Layer (macOS)

**Layer Number**: 0  
**Purpose**: Primary typing layer for macOS with Cmd-based modifier positioning  
**Access Method**: Default layer on keyboard startup (if macOS selected in config)  
**Parent Layers**: None (root layer)  
**Child Layers**: LAYER_SYMBOLS, LAYER_FUNCTION, LAYER_NUMBERS

**Key Categories**:
- **Alpha Keys**: Letters A-Z in optimized layout (current: HIEA O on home row left, DTRNS on home row right)
- **Home Row Mods** (macOS-specific):
  - Left: H(Ctrl), I(Alt), E(Cmd), A, O
  - Right: D, T(Cmd), R(Alt), N(Ctrl), S
- **Thumb Cluster**:
  - Left inner: OSL(LAYER_SYMBOLS) - one-shot symbol layer
  - Left outer: OSM(MOD_LSFT) - one-shot shift modifier
  - Right inner: OSL(LAYER_FUNCTION) - one-shot function/nav layer
  - Right outer: LT(LAYER_NUMBERS, KC_SPACE) - hold for numbers, tap for space
- **Navigation/Utility**: CW_TOGG (caps word), QK_REPEAT_KEY, QK_LEAD (leader key)

**LED Configuration**: Custom RGB pattern (existing blue/teal indicators)

**Relationships**:
- Accessed from: LAYER_CONFIG (via TO(0) switching)
- Accesses: LAYER_SYMBOLS (via OSL), LAYER_FUNCTION (via OSL), LAYER_NUMBERS (via LT)
- Alternative to: LAYER_WIN_BASE (mutually exclusive base layers)

### Entity: Base Layer (Windows)

**Layer Number**: 1  
**Purpose**: Primary typing layer for Windows with Ctrl-based modifier positioning  
**Access Method**: Switched from config layer via TO(1) or set as default on startup  
**Parent Layers**: None (root layer)  
**Child Layers**: LAYER_SYMBOLS, LAYER_FUNCTION, LAYER_NUMBERS (same as macOS)

**Key Categories**:
- **Alpha Keys**: Identical letter layout to macOS base (muscle memory consistency)
- **Home Row Mods** (Windows-specific):
  - Left: H(Cmd/Win), I(Alt), E(Ctrl), A, O
  - Right: D, T(Ctrl), R(Alt), N(Cmd/Win), S
  - *Note*: Ctrl/Cmd swapped compared to macOS for OS-appropriate shortcuts
- **Thumb Cluster**: Identical to macOS (same layer access patterns)
- **Navigation/Utility**: Identical to macOS base

**LED Configuration**: Custom RGB pattern (existing green indicators)

**Relationships**:
- Accessed from: LAYER_CONFIG (via TO(1) switching)
- Accesses: Same utility layers as macOS (LAYER_SYMBOLS, LAYER_FUNCTION, LAYER_NUMBERS)
- Alternative to: LAYER_MAC_BASE (mutually exclusive base layers)

### Entity: Symbol Layer (Unified)

**Layer Number**: 2  
**Purpose**: Programming symbols, special characters, and brackets accessible from both base layers  
**Access Method**: OSL(2) from either base layer's left thumb  
**Parent Layers**: LAYER_MAC_BASE, LAYER_WIN_BASE  
**Child Layers**: None (leaf layer)

**Key Categories**:
- **Brackets/Grouping**: [ ] { } ( ) < >
- **Operators**: + - * / = ! ? % $ #
- **Special Characters**: @ & | \ _ ~ ^ § ¶
- **Programming Symbols**: Backtick (`), grave, pipe, slash, backslash, colon, semicolon

**Example Layout** (consolidates current layers 1 and 6):
```
Row 1:  §    &    [    ]    ^    |    !    <    >    =    ~
Row 2:  @    /    {    }    *    |    ?    (    )    -    :
Row 3:  _    \    |    ~    `    |    +    %    $    #    ;
Thumbs: (transparent/pass-through to base layer thumbs)
```

**Dual-Function Keys on Symbol Layer**:
- Position-based access to additional symbols via hold behavior where appropriate
- Example: Hold certain keys to access layer-tap to LAYER_FUNCTION for combined workflows

**LED Configuration**: Default/off (no custom LED pattern; rely on base layer colors)

**Relationships**:
- Accessed from: Both base layers via OSL(2)
- Provides: All symbols needed for programming, writing, and special character entry
- Consolidates: Previous layers 1 (macOS symbols) and 6 (Windows symbols)

### Entity: Function/Navigation Layer (Unified)

**Layer Number**: 3  
**Purpose**: Function keys (F1-F12), navigation (arrows, PgUp/PgDn, Home/End), umlauts, window management  
**Access Method**: OSL(3) from either base layer's right inner thumb  
**Parent Layers**: LAYER_MAC_BASE, LAYER_WIN_BASE  
**Child Layers**: None (leaf layer)

**Key Categories**:
- **Function Keys**: F1-F12 arranged ergonomically
- **Navigation**: Arrow keys (←↓↑→), Page Up/Down, Home, End
- **German Umlauts**: ä (ae), ö (oe), ü (ue), ß (ss), € (euro)
- **Editing**: Escape, Tab, Enter
- **Window Management**: OS-specific shortcuts (Cmd+arrow on Mac, Ctrl+arrow on Win)

**Example Layout** (consolidates current layers 2, 5, and 8):
```
Row 1:  F12  Tab   ü    -     -    |  [nav] [nav]  -   [nav]  -     -
Row 2:  F11  Esc   ß    €     ä    ö |   ←     ↓    ↑     →    -     -
Row 3:  F10  Enter -    -     -    - |   -   PgDn Home  End   -     -
Row 4:  -    F1    F2   F3    F4   F5|   F6   F7   F8   F9    -     -
Thumbs: (transparent)
```

**OS-Specific Window Management**:
- macOS: Cmd+arrow keys for window positioning (implemented via Cmd mod in base layer)
- Windows: Ctrl+arrow keys for word navigation (implemented via Ctrl mod in base layer)
- Conditional logic handles different shortcuts per active base layer

**LED Configuration**: Default/off (no custom LED pattern)

**Relationships**:
- Accessed from: Both base layers via OSL(3)
- Provides: Function keys, navigation, umlauts, system navigation
- Consolidates: Previous layers 2 (macOS func/nav), 5 (Windows func/nav), 8 (function keys)

### Entity: Number Layer (Unified)

**Layer Number**: 4  
**Purpose**: Number pad layout with operators and OS-specific clipboard shortcuts  
**Access Method**: LT(4, KC_SPACE) from either base layer's right outer thumb (hold for layer, tap for space)  
**Parent Layers**: LAYER_MAC_BASE, LAYER_WIN_BASE  
**Child Layers**: None (leaf layer)

**Key Categories**:
- **Number Pad**: 0-9 in numpad arrangement
- **Operators**: + - * / :
- **Clipboard Shortcuts**: Undo, Copy, Paste, Cut (OS-specific modifiers)
- **Utility**: Comma, period (for decimal entry), Print Screen

**Example Layout** (consolidates current layers 3 and 7):
```
Row 1:  -    -     7    8    9    *  |   -     -     -     -    -   -
Row 2:  :    1     2    3    0    -  | [undo][copy][paste][cut] -   App
Row 3:  +    4     5    6    /    -  |   -     -     -     -    -   -
Row 4:  -    -     -    -    -    -  |   -     -   PrtSc   -    -   -
Thumbs: ,    .     -    -            |   -     -     -     -
```

**OS-Specific Clipboard Operations**:
- **Undo**: Cmd+Z (macOS) / Ctrl+Z (Windows)
- **Copy**: Cmd+C (macOS) / Ctrl+C (Windows)
- **Paste**: Cmd+V (macOS) / Ctrl+V (Windows)
- **Cut**: Cmd+X (macOS) / Ctrl+X (Windows)

**Implementation**: Use conditional keycode logic based on active base layer:
```c
bool is_macos = (get_highest_layer(default_layer_state) == LAYER_MAC_BASE);
// Then send appropriate modifier (LGUI vs LCTL) with action key
```

**LED Configuration**: Default/off (no custom LED pattern)

**Relationships**:
- Accessed from: Both base layers via LT(4, KC_SPACE)
- Provides: Number entry, arithmetic operators, clipboard operations
- Consolidates: Previous layers 3 (macOS numbers) and 7 (Windows numbers)

### Entity: Configuration Layer

**Layer Number**: 5 (or preserve at 9)  
**Purpose**: RGB lighting control, layer switching, system functions (bootloader access)  
**Access Method**: Explicit TO(5) or TO(9) from designated keys on base layers  
**Parent Layers**: All layers (accessible globally)  
**Child Layers**: None (utility layer)

**Key Categories**:
- **RGB Controls**: Toggle, mode, hue, saturation, brightness, speed adjustments
- **Layer Switching**: TO(LAYER_MAC_BASE), TO(LAYER_WIN_BASE)
- **System**: QK_BOOT (enter bootloader for firmware flashing)
- **Media**: Track previous/next, stop (optional)

**Example Layout** (preserves current layer 9):
```
Row 1:  RGB_TOG  LAYER_COLOR  MODE   SLD   VAD   VAI  | TO(WIN) -  TO(MAC) -   BOOT  -
Row 2:  -        -            SAD    SAI   SPD   SPI  | PgUp    Home  ↑   End   -     -
Row 3:  -        PREV_TRK     NEXT   STOP  HUD   HUI  | PgDn    ←     ↓   →     -     -
Row 4:  -        -            -      HSV1  HSV2  HSV3 | -       CTRL+SHIFT+TAB CTRL+TAB - - -
Thumbs: -        -                                    | -       -
```

**LED Configuration**: Custom RGB pattern (existing orange/pink indicators)

**Relationships**:
- Accessed from: Designated key on base layers (e.g., top-right corner TO(CONFIG))
- Provides: System-level functions independent of typing workflow
- Returns to: User manually selects base layer (TO(0) or TO(1))
- Preserves: Current layer 9 functionality with minimal changes

## State Transitions

### Layer Activation Flow

```
┌─────────────────┐
│  Power On       │
│  Default: MAC   │ or │ Default: WIN  │
└────────┬────────┘
         │
         ▼
    ┌────────────────────┐
    │   Base Layer       │
    │  (MAC or WIN)      │
    └────────────────────┘
         │
         ├─ OSL(SYMBOLS) ──→ [Symbol Layer] ──→ Auto-return to Base
         │
         ├─ OSL(FUNCTION) ─→ [Function Layer] ─→ Auto-return to Base
         │
         ├─ LT(NUMBERS) ───→ [Number Layer] ───→ Release returns to Base
         │
         └─ TO(CONFIG) ────→ [Config Layer]
                                     │
                                     ├─ TO(0) → [MAC Base]
                                     └─ TO(1) → [WIN Base]
```

### Dual-Function Key States

**Tap Behavior**: Executes primary key function (e.g., U, F3, space)  
**Hold Behavior**: Activates modifier or layer (e.g., Ctrl, layer access)  
**Timeout**: 200ms default (QMK TAPPING_TERM)

**Examples**:
- `MT(MOD_LCTL, KC_H)`: Tap = H, Hold = Left Ctrl
- `LT(LAYER_NUMBERS, KC_SPACE)`: Tap = Space, Hold = Numbers layer
- `OSL(LAYER_SYMBOLS)`: Tap = Activate symbols for next key, then auto-return

## Validation Rules

### Layer Consistency Rules

1. **Alpha key positions** MUST be identical across both base layers (LAYER_MAC_BASE and LAYER_WIN_BASE)
2. **Utility layer access** MUST use same thumb positions from both base layers
3. **Symbol/Function/Number layouts** MUST be identical when accessed from either base
4. **OS-specific differences** MUST be limited to: home row mods, clipboard shortcuts, window management
5. **LED mappings** MUST clearly distinguish base layers; utility layers use default

### Key Count Validation

- Total physical keys: 52 (26 per hand on Voyager)
- Keys per layer: 52 (full coverage)
- Dual-function keys: Target 12-14 (reduced from 16)
- Transparent keys: Used on utility layers to pass-through to base layer

### Firmware Size Validation

- Current keymap.c: ~470 lines, 10 layers
- Target keymap.c: ~350-400 lines, 5 layers
- Estimated savings: 100-150 lines (~20-30% reduction)
- Binary size target: <230KB (90% of 256KB flash)

## Relationships Between Layers

### Access Hierarchy

```
LAYER_CONFIG (5 or 9)
    ├─ TO(0) ──→ LAYER_MAC_BASE
    │              ├─ OSL(2) ──→ LAYER_SYMBOLS
    │              ├─ OSL(3) ──→ LAYER_FUNCTION
    │              └─ LT(4) ───→ LAYER_NUMBERS
    │
    └─ TO(1) ──→ LAYER_WIN_BASE
                   ├─ OSL(2) ──→ LAYER_SYMBOLS (same layer)
                   ├─ OSL(3) ──→ LAYER_FUNCTION (same layer)
                   └─ LT(4) ───→ LAYER_NUMBERS (same layer)
```

### Key Sharing Matrix

| Layer          | Shares Keys With        | Differentiation Method |
|----------------|-------------------------|------------------------|
| MAC_BASE       | WIN_BASE                | Home row mods only     |
| WIN_BASE       | MAC_BASE                | Home row mods only     |
| SYMBOLS        | (none - unique)         | Accessed from both bases |
| FUNCTION       | (none - unique)         | OS shortcuts via active base detection |
| NUMBERS        | (none - unique)         | Clipboard via active base detection |
| CONFIG         | (none - unique)         | Independent utility layer |

## Implementation Notes

### Dual-Function Key Consolidation

**Current** (16 dual-functions):
- DUAL_FUNC_0 to DUAL_FUNC_7: macOS variants
- DUAL_FUNC_8 to DUAL_FUNC_15: Windows variants

**Target** (12-14 dual-functions):
- Consolidate identical functions across OS layers
- Example: DUAL_FUNC_1 (macOS: tap /, hold Alt) = DUAL_FUNC_11 (Windows: same) → merge to single DUAL_FUNC_SLASH_ALT
- Maintain OS-specific ones where needed (e.g., different mod assignments)

### OS Detection Strategy

```c
// Determine active OS base layer
uint8_t get_active_base_layer(void) {
    uint8_t base = get_highest_layer(default_layer_state);
    return (base == LAYER_WIN_BASE) ? LAYER_WIN_BASE : LAYER_MAC_BASE;
}

// Use in clipboard shortcuts
bool is_macos_active(void) {
    return (get_active_base_layer() == LAYER_MAC_BASE);
}

// Apply in keycode handling
if (is_macos_active()) {
    register_code16(LGUI(KC_C));  // Cmd+C
} else {
    register_code16(LCTL(KC_C));  // Ctrl+C
}
```

### LED Mapping Optimization

**Layers needing custom LED patterns**: 3 (MAC_BASE, WIN_BASE, CONFIG)  
**Layers using default**: 3 (SYMBOLS, FUNCTION, NUMBERS)

**Storage savings**:
- Current: LED data for layers 0, 4, 9 (3 layers defined, 7 empty)
- Target: LED data for layers 0, 1, 5 (3 layers defined, 2-3 empty)
- Minimal change in LED data size; primary savings from layer consolidation

---

**Summary**: The 5-layer architecture consolidates 10 layers into a streamlined, maintainable structure with clear separation of concerns. Base layers handle OS-specific typing, utility layers provide universal access to symbols/functions/numbers, and the configuration layer manages system functions. This design reduces cognitive load, improves muscle memory, and decreases firmware size while maintaining full functionality.
