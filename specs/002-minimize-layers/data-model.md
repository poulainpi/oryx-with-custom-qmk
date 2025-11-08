# Data Model: vrMEr Layer Architecture

**Feature**: 002-minimize-layers  
**Date**: 2025-11-08  
**Purpose**: Define keyboard layer entities, relationships, and key mappings for the optimized 6-layer vrMEr layout

## Layer Entities

### Layer 0: LAYER_MAC_BASE (macOS Base)

**Purpose**: Primary typing layer for macOS with Cmd-optimized home row modifiers

**Access Method**: Default layer, or TO(0) from config layer

**Key Characteristics**:
- Home row mods: H=Ctrl, I=Alt, E=Cmd, A=none | D=none, T=Cmd, R=Alt, N=none, S=Ctrl
- Alpha layout: HIEA O / DTRNS (identical to Windows base)
- Thumb cluster: OSL(2) left, OSM(Shift) | OSL(3) right, LT(4, Space)

**Relationships**:
- Accesses LAYER_SYMBOLS via OSL(2)
- Accesses LAYER_FUNCTION via OSL(3)
- Accesses LAYER_NUMBERS via LT(4, Space)
- Accesses LAYER_CONFIG via TO(5)

**LED Color**: Blue (#0000FF)

---

### Layer 1: LAYER_WIN_BASE (Windows Base)

**Purpose**: Primary typing layer for Windows with Ctrl-optimized home row modifiers

**Access Method**: TO(1) from config layer

**Key Characteristics**:
- Home row mods: H=Win, I=Alt, E=Ctrl, A=none | D=none, T=Ctrl, R=Alt, N=Win, S=none
- Alpha layout: HIEA O / DTRNS (identical to macOS base)
- Thumb cluster: OSL(2) left, OSM(Shift) | OSL(3) right, LT(4, Space)

**Relationships**:
- Accesses LAYER_SYMBOLS via OSL(2)
- Accesses LAYER_FUNCTION via OSL(3)
- Accesses LAYER_NUMBERS via LT(4, Space)
- Accesses LAYER_CONFIG via TO(5)

**LED Color**: Cyan (#00FFFF)

**Key Difference from MAC_BASE**: Swapped Cmd/Ctrl and Win/Ctrl positions on home row for OS-appropriate workflow

---

### Layer 2: LAYER_SYMBOLS (Unified Symbols)

**Purpose**: Programming symbols, brackets, operators accessible from both OS bases

**Access Method**: OSL(2) from either base layer (one-shot layer)

**Key Characteristics**:
- Consolidates layers 1 and 6 from original layout
- Contains: §, &, [, ], ^, !, <, >, =, ~, @, €, {, }, *, ?, (, ), _, \, |, `, +, %, $, #, ;, ', "
- Auto-returns to base layer after one keypress (OSL behavior)

**Relationships**:
- Accessed from LAYER_MAC_BASE or LAYER_WIN_BASE
- Returns to originating base layer automatically

**LED Color**: Inherits from base layer (momentary access)

---

### Layer 3: LAYER_FUNCTION (Unified Function/Navigation)

**Purpose**: F-keys, navigation (arrows, page up/down, home/end), German umlauts, window management

**Access Method**: OSL(3) from either base layer (one-shot layer)

**Key Characteristics**:
- Consolidates layers 2, 5, and 8 from original layout
- Contains: F1-F12, arrows (↑↓←→), Tab, Escape, Enter, Esc, ä, ö, ü, ß, €
- macOS window nav: Cmd+Up, Opt+Left, Opt+Right, Cmd+Down, Cmd+Left, Cmd+Right
- Windows window nav: Page Up, Ctrl+Left, Ctrl+Right, Page Down, Home, End
- Auto-returns to base layer after one keypress (OSL behavior)

**Relationships**:
- Accessed from LAYER_MAC_BASE or LAYER_WIN_BASE
- Returns to originating base layer automatically

**LED Color**: Inherits from base layer (momentary access)

---

### Layer 4: LAYER_NUMBERS (Unified Numpad)

**Purpose**: Number pad layout with operators and OS-aware clipboard shortcuts

**Access Method**: LT(4, Space) from either base layer (layer-tap with space bar)

**Key Characteristics**:
- Consolidates layers 3 and 7 from original layout
- Numpad layout: 7 8 9, 1 2 3, 4 5 6, 0
- Operators: -, :, +, *, /, comma, period
- OS-aware clipboard: OS_UNDO, OS_COPY, OS_PASTE, OS_CUT (uses is_macos_base() detection)
- Hold space for layer access, tap space for space character

**Relationships**:
- Accessed from LAYER_MAC_BASE or LAYER_WIN_BASE
- Returns to originating base layer on release

**LED Color**: Inherits from base layer (momentary access)

**OS-Aware Keycodes**:
- OS_UNDO: Cmd+Z (macOS) or Ctrl+Z (Windows)
- OS_COPY: Cmd+C (macOS) or Ctrl+C (Windows)
- OS_PASTE: Cmd+V (macOS) or Ctrl+V (Windows)
- OS_CUT: Cmd+X (macOS) or Ctrl+X (Windows)

---

### Layer 5: LAYER_CONFIG (Configuration)

**Purpose**: RGB controls, layer switching, bootloader access, system functions

**Access Method**: TO(5) toggle from any layer

**Key Characteristics**:
- Preserves layer 9 functionality from original layout
- RGB controls: RGB_TOG, RGB_MOD, RGB_VAL+, RGB_VAL-, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD
- Layer switching: TO(0) for macOS base, TO(1) for Windows base
- System: QK_BOOT (bootloader), system reset
- Must manually return to base layer via TO(0) or TO(1)

**Relationships**:
- Independent layer, no automatic returns
- Provides access to LAYER_MAC_BASE and LAYER_WIN_BASE

**LED Color**: Red (#FF0000) - warning color for system changes

---

## Custom Keycodes

### OS_UNDO, OS_COPY, OS_PASTE, OS_CUT

**Purpose**: OS-aware clipboard operations that adapt modifiers based on active base layer

**Implementation**:
```c
enum custom_keycodes {
    OS_UNDO = SAFE_RANGE,
    OS_COPY,
    OS_PASTE,
    OS_CUT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_UNDO:
            if (record->event.pressed) {
                if (is_macos_base()) {
                    SEND_STRING(SS_LGUI("z"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return false;
        // ... similar for OS_COPY, OS_PASTE, OS_CUT
    }
    return true;
}
```

**Mapping**:
| Keycode | macOS | Windows |
|---------|-------|---------|
| OS_UNDO | Cmd+Z | Ctrl+Z |
| OS_COPY | Cmd+C | Ctrl+C |
| OS_PASTE | Cmd+V | Ctrl+V |
| OS_CUT | Cmd+X | Ctrl+X |

---

## Home Row Mod Entities

### MT() Macros (Mod-Tap)

**Purpose**: Dual-function keys that act as modifiers when held, normal keys when tapped

**Implementation Pattern**: `MT(MOD_<modifier>, KC_<key>)`

**Timing**: TAPPING_TERM = 200ms (configured in config.h)

**macOS Base Mappings**:
| Key Position | Tap | Hold | Macro |
|--------------|-----|------|-------|
| Left home H | H | Ctrl | MT(MOD_LCTL, KC_H) |
| Left home I | I | Alt | MT(MOD_LALT, KC_I) |
| Left home E | E | Cmd | MT(MOD_LGUI, KC_E) |
| Right home T | T | Cmd | MT(MOD_RGUI, KC_T) |
| Right home R | R | Alt | MT(MOD_LALT, KC_R) |
| Right home N | N | Ctrl | MT(MOD_RCTL, KC_N) |

**Windows Base Mappings**:
| Key Position | Tap | Hold | Macro |
|--------------|-----|------|-------|
| Left home H | H | Win | MT(MOD_LGUI, KC_H) |
| Left home I | I | Alt | MT(MOD_LALT, KC_I) |
| Left home E | E | Ctrl | MT(MOD_LCTL, KC_E) |
| Right home T | T | Ctrl | MT(MOD_RCTL, KC_T) |
| Right home R | R | Alt | MT(MOD_LALT, KC_R) |
| Right home N | N | Win | MT(MOD_RGUI, KC_N) |

**Key Difference**: macOS uses Cmd (GUI) as primary modifier on E/T, Windows uses Ctrl as primary modifier on E/T

---

## German Layout Entities

### DE_* Keycodes (from keymap_german.h)

**Purpose**: German keyboard characters (umlauts, special symbols)

**Location**: Primarily in LAYER_FUNCTION and LAYER_SYMBOLS

**Mappings**:
| Visual | QMK Keycode | Layer | Position |
|--------|-------------|-------|----------|
| ä | DE_ADIA or DE_AE | LAYER_FUNCTION | Available in umlaut section |
| ö | DE_ODIA or DE_OE | LAYER_FUNCTION | Available in umlaut section |
| ü | DE_UDIA or DE_UE | LAYER_FUNCTION | Available in umlaut section |
| ß | DE_SS | LAYER_FUNCTION | Available in umlaut section |
| € | DE_EURO | LAYER_FUNCTION or LAYER_SYMBOLS | Available for currency |
| @ | DE_AT | LAYER_SYMBOLS | Programming symbol |
| § | DE_SECT | LAYER_SYMBOLS | Special character |

---

## Layer Access Methods

### OSL (One-Shot Layer)

**Purpose**: Temporarily activate layer for next keypress only

**Behavior**: Press OSL key → layer activates → press any key → layer deactivates automatically

**Usage**: LAYER_SYMBOLS (OSL(2)), LAYER_FUNCTION (OSL(3))

**Timeout**: ONESHOT_TIMEOUT = 5000ms (configured in config.h)

### LT (Layer-Tap)

**Purpose**: Dual-function key that activates layer when held, sends keycode when tapped

**Behavior**: 
- Hold > TAPPING_TERM: Layer activates
- Tap < TAPPING_TERM: Keycode sends
- Release: Layer deactivates

**Usage**: LAYER_NUMBERS accessed via LT(4, KC_SPACE)

### TO (To Layer)

**Purpose**: Persistent layer switch (remains active until another TO command)

**Behavior**: Press TO key → layer switches → remains active indefinitely

**Usage**: LAYER_CONFIG accessed via TO(5), return via TO(0) or TO(1)

---

## Entity Relationships

```text
LAYER_MAC_BASE (0) ←──────────────┐
    │                              │
    ├─ OSL(2) ──→ LAYER_SYMBOLS    │
    ├─ OSL(3) ──→ LAYER_FUNCTION   │ TO(0) / TO(1)
    ├─ LT(4, Space) ──→ LAYER_NUMBERS   │
    └─ TO(5) ──→ LAYER_CONFIG (5) ─┘
                      │
LAYER_WIN_BASE (1) ←──┘
    │
    ├─ OSL(2) ──→ LAYER_SYMBOLS (2)
    ├─ OSL(3) ──→ LAYER_FUNCTION (3)
    ├─ LT(4, Space) ──→ LAYER_NUMBERS (4)
    └─ TO(5) ──→ LAYER_CONFIG (5)
```

**Key Principles**:
1. Two base layers provide OS-specific optimizations
2. Three utility layers are shared across both bases (code reuse)
3. One config layer provides system functions and layer switching
4. Utility layers auto-return to originating base layer
5. Config layer requires manual return (TO command)

---

## Size Impact Analysis

**Original vrMEr**:
- 10 layers (0-9)
- ~930 lines of keymap.c
- 17 tap dance implementations (~850-1020 lines of tap dance code)

**Target vrMEr**:
- 6 layers (0-5)
- ~465-550 lines of keymap.c (40-50% reduction)
- 0 tap dance implementations (all replaced with MT() or direct keycodes)

**Consolidation Savings**:
- Layer definitions: 4 fewer layers × ~50 lines = ~200 lines saved
- Tap dance elimination: 17 implementations × ~50-60 lines = ~850-1020 lines saved
- LED mappings: Reduced from scattered to 3 layers = ~50 lines saved
- Total estimated savings: ~1100-1270 lines → net result ~465-550 lines

**Constitutional Compliance**:
- ✅ Minimal Firmware Size: 40-50% code reduction directly supports this principle
- ✅ Layer Minimization: 10 → 6 layers (40% reduction) implements this principle
- ✅ OS-Specific Optimization: 2 bases + 3 shared utilities balances OS differentiation with code reuse
- ✅ Oryx Integration: All entities use standard QMK features (OSL, LT, MT, TO)
- ✅ Code Maintainability: Clear entity definitions and relationships improve understanding
