# Dual-Function Key Mappings Contract

**Feature**: Minimize Keyboard Layers  
**Created**: 2025-11-07  
**Purpose**: Define the consolidated dual-function key implementation strategy and mapping contracts

## Overview

Dual-function keys provide two behaviors: a **tap** action (quick press & release) and a **hold** action (press & hold beyond threshold). This consolidation reduces the current 16 dual-function implementations to 12-14 by merging duplicates across OS layers.

## Dual-Function Types

### Type 1: Mod-Tap (MT)

**Purpose**: Tap for character, hold for modifier  
**Syntax**: `MT(modifier, keycode)`  
**Primary Use**: Home row mods on base layers

### Type 2: Layer-Tap (LT)

**Purpose**: Tap for character, hold for layer access  
**Syntax**: `LT(layer, keycode)`  
**Primary Use**: Layer access from base layers, symbols/functions accessible while holding specific keys

### Type 3: Custom Dual-Function

**Purpose**: Complex dual-function behavior requiring custom process_record_user logic  
**Syntax**: Custom keycode with switch case in process_record_user  
**Primary Use**: OS-specific behaviors, conditional keypresses

## Current vs. Target Mapping

### Current Implementation (16 Dual-Functions)

| ID | Tap Behavior | Hold Behavior | Layer Context | OS |
|----|--------------|---------------|---------------|-----|
| DUAL_FUNC_0 | @ (DE_AT) | Left Ctrl | macOS symbols | Mac |
| DUAL_FUNC_1 | / (DE_SLSH) | Left Alt | macOS symbols | Mac |
| DUAL_FUNC_2 | { (DE_LCBR) | Left Cmd | macOS symbols | Mac |
| DUAL_FUNC_3 | ) (DE_RPRN) | Right Cmd | macOS symbols | Mac |
| DUAL_FUNC_4 | : (DE_COLN) | Right Ctrl | macOS symbols | Mac |
| DUAL_FUNC_5 | Backspace | Ctrl+Backspace | macOS func/nav | Mac |
| DUAL_FUNC_6 | Delete | Ctrl+Delete | macOS func/nav | Mac |
| DUAL_FUNC_7 | € (DE_EURO) | Left Cmd | macOS func/nav | Mac |
| DUAL_FUNC_8 | = (KC_EQUAL) | Escape | Windows base | Win |
| DUAL_FUNC_9 | € (DE_EURO) | Left Ctrl | Windows func/nav | Win |
| DUAL_FUNC_10 | @ (DE_AT) | Left Cmd | Windows symbols | Win |
| DUAL_FUNC_11 | { (DE_LCBR) | Left Ctrl | Windows symbols | Win |
| DUAL_FUNC_12 | ) (DE_RPRN) | Right Ctrl | Windows symbols | Win |
| DUAL_FUNC_13 | : (DE_COLN) | Right Cmd | Windows symbols | Win |
| DUAL_FUNC_14 | Backspace | Alt+Backspace | Windows func/nav | Win |
| DUAL_FUNC_15 | Delete | Alt+Delete | Windows func/nav | Win |

**Analysis**:
- **Duplicate Patterns**: DUAL_FUNC_1/similar, DUAL_FUNC_2/11, DUAL_FUNC_3/12, DUAL_FUNC_4/13
- **OS-Specific**: DUAL_FUNC_5/6 vs DUAL_FUNC_14/15 (different hold modifiers)
- **Consolidation Opportunities**: Symbols layer dual-functions can be unified; func/nav dual-functions need OS distinction

### Target Implementation (12-14 Dual-Functions)

#### Consolidated Dual-Functions (Shared Across OS Layers)

| New ID | Tap Behavior | Hold Behavior | Used On | Notes |
|--------|--------------|---------------|---------|-------|
| DF_AT_CTRL | @ (DE_AT) | Left Ctrl | Symbol layer | Replaces DUAL_FUNC_0, usable from both bases |
| DF_SLASH_ALT | / (DE_SLSH) | Left Alt | Symbol layer | Replaces DUAL_FUNC_1 |
| DF_RPRN_CMD | ) (DE_RPRN) | Right Cmd | Symbol layer | Replaces DUAL_FUNC_3 (Mac) / 12 (Win) |
| DF_COLN_CTRL | : (DE_COLN) | Right Ctrl | Symbol layer | Replaces DUAL_FUNC_4 / 13 (if mods compatible) |
| DF_EURO_CMD | € (DE_EURO) | Left Cmd | Function layer | Replaces DUAL_FUNC_7 (macOS context) |

#### OS-Specific Dual-Functions (Separate for macOS/Windows)

| New ID | Tap Behavior | Hold Behavior | Used On | OS | Notes |
|--------|--------------|---------------|---------|-----|-------|
| DF_LCBR_MAC | { (DE_LCBR) | Left Cmd | Symbol (Mac) | Mac | macOS: Cmd modifier |
| DF_LCBR_WIN | { (DE_LCBR) | Left Ctrl | Symbol (Win) | Win | Windows: Ctrl modifier |
| DF_BSPC_MAC | Backspace | Ctrl+Backspace | Func (Mac) | Mac | macOS word delete |
| DF_BSPC_WIN | Backspace | Alt+Backspace | Func (Win) | Win | Windows word delete |
| DF_DEL_MAC | Delete | Ctrl+Delete | Func (Mac) | Mac | macOS word delete forward |
| DF_DEL_WIN | Delete | Alt+Delete | Func (Win) | Win | Windows word delete forward |
| DF_EURO_WIN | € (DE_EURO) | Left Ctrl | Func (Win) | Win | Windows: Ctrl modifier |
| DF_EQL_ESC | = (KC_EQUAL) | Escape | Win Base | Win | Windows-specific base layer |

**Total Count**: 13 dual-functions (5 shared + 8 OS-specific)

## Dual-Function Contracts

### Contract 1: Home Row Mods (Base Layers)

**macOS Base Layer**:
```c
// Left hand home row
MT(MOD_LCTL, KC_H)   // H / Ctrl
MT(MOD_LALT, KC_I)   // I / Alt  
MT(MOD_LGUI, KC_E)   // E / Cmd
KC_A                 // A (no mod)
KC_O                 // O (no mod)

// Right hand home row
KC_D                 // D (no mod)
MT(MOD_RGUI, KC_T)   // T / Cmd
MT(MOD_RALT, KC_R)   // R / Alt
MT(MOD_RCTL, KC_N)   // N / Ctrl
KC_S                 // S (no mod)
```

**Windows Base Layer**:
```c
// Left hand home row (Ctrl/Cmd swapped vs macOS)
MT(MOD_LGUI, KC_H)   // H / Win
MT(MOD_LALT, KC_I)   // I / Alt
MT(MOD_LCTL, KC_E)   // E / Ctrl
KC_A                 // A (no mod)
KC_O                 // O (no mod)

// Right hand home row (Ctrl/Cmd swapped vs macOS)
KC_D                 // D (no mod)
MT(MOD_RCTL, KC_T)   // T / Ctrl
MT(MOD_RALT, KC_R)   // R / Alt  
MT(MOD_RGUI, KC_N)   // N / Win
KC_S                 // S (no mod)
```

**Contract Requirements**:
- MUST maintain HIEA O / DTRNS letter positions across both bases
- MUST swap Ctrl/Cmd positions between macOS and Windows
- MUST keep Alt in same position on both bases
- MUST use MT() for modifiers, not custom DUAL_FUNC implementations

### Contract 2: Symbol Layer Dual-Functions

**Consolidated Implementations** (work from both base layers):

```c
#define DF_AT_CTRL   LT(LAYER_FUNCTION, KC_U)  // Tap @, Hold Ctrl (if needed for layer access)
#define DF_SLASH_ALT LT(LAYER_SYMBOLS, KC_F3)  // Tap /, Hold Alt (example pattern)
// ... additional consolidated definitions
```

**Placement on Symbol Layer**:
- Use DF_* macros in symbol layer keymap where dual-function needed
- Tap behavior provides symbol character
- Hold behavior provides modifier or layer access for combined workflows

**Contract Requirements**:
- MUST work identically when accessed from macOS or Windows base
- SHOULD minimize dual-functions on symbol layer (prioritize simple symbol keycodes)
- MAY use dual-functions for less-common symbols with useful hold behaviors

### Contract 3: Function/Navigation Layer Dual-Functions

**OS-Specific Implementations** (different per base):

```c
// macOS function layer
#define DF_BSPC_MAC  /* custom: tap BSPC, hold Ctrl+BSPC */
#define DF_DEL_MAC   /* custom: tap DEL, hold Ctrl+DEL */
#define DF_EURO_MAC  LT(LAYER_FUNCTION, KC_T)  // Tap €, Hold Cmd

// Windows function layer  
#define DF_BSPC_WIN  /* custom: tap BSPC, hold Alt+BSPC */
#define DF_DEL_WIN   /* custom: tap DEL, hold Alt+DEL */
#define DF_EURO_WIN  LT(LAYER_FUNCTION, KC_H)  // Tap €, Hold Ctrl
```

**Conditional Usage in Keymap**:
```c
// In function layer definition, use OS-appropriate dual-function based on context
// Option 1: Duplicate layer definitions (one for Mac, one for Win) - NOT RECOMMENDED
// Option 2: Single layer with conditional keycodes - RECOMMENDED

// Use shared layer, conditionally apply in process_record_user
[LAYER_FUNCTION] = LAYOUT_voyager(
    // ...
    KC_CUSTOM_BSPC,  // Custom keycode, handler checks active base layer
    KC_CUSTOM_DEL,   // Custom keycode, handler checks active base layer
    // ...
)

// In process_record_user:
case KC_CUSTOM_BSPC:
    if (record->tap.count > 0) {
        send_keycode(KC_BSPC);  // Tap: backspace on both OSes
    } else {
        if (is_macos_active()) {
            send_keycode(LCTL(KC_BSPC));  // Hold: Ctrl+Bspc on macOS
        } else {
            send_keycode(LALT(KC_BSPC));  // Hold: Alt+Bspc on Windows
        }
    }
    break;
```

**Contract Requirements**:
- MUST detect active base layer to apply correct hold behavior
- MUST use custom keycodes with process_record_user for OS-conditional logic
- SHOULD minimize OS-specific dual-functions (use only where necessary)

### Contract 4: Number Layer Dual-Functions

**Thumb Cluster Access**:
```c
// On both base layers
LT(LAYER_NUMBERS, KC_SPACE)  // Tap space, hold for number layer
```

**Within Number Layer**:
- Minimal dual-functions needed
- Focus on number entry and operators (tap behavior)
- Clipboard shortcuts use simple keycodes with OS-conditional send logic

**Contract Requirements**:
- MUST use LT for layer access from base
- SHOULD NOT add dual-functions within number layer (keep simple)
- Clipboard operations handled via custom keycodes in process_record_user

## Custom Dual-Function Implementation Pattern

### Template for Custom Dual-Function

```c
// In keymap.c, custom keycodes enum
enum custom_keycodes {
    KC_CUSTOM_BSPC = SAFE_RANGE,  // Custom backspace dual-function
    KC_CUSTOM_DEL,                 // Custom delete dual-function
    KC_CUSTOM_EURO,                // Custom euro dual-function (if needed)
    // ... other custom keycodes
};

// In process_record_user
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CUSTOM_BSPC:
            if (record->tap.count > 0) {
                // Tap behavior
                if (record->event.pressed) {
                    register_code16(KC_BSPC);
                } else {
                    unregister_code16(KC_BSPC);
                }
            } else {
                // Hold behavior (OS-conditional)
                if (record->event.pressed) {
                    if (is_macos_active()) {
                        register_code16(LCTL(KC_BSPC));  // Ctrl+Bspc
                    } else {
                        register_code16(LALT(KC_BSPC));  // Alt+Bspc
                    }
                } else {
                    if (is_macos_active()) {
                        unregister_code16(LCTL(KC_BSPC));
                    } else {
                        unregister_code16(LALT(KC_BSPC));
                    }
                }
            }
            return false;  // Skip further processing
            
        // ... other cases
    }
    return true;  // Continue processing if not handled
}
```

**Contract Requirements**:
- MUST check `record->tap.count` to differentiate tap (>0) vs hold (0)
- MUST check `record->event.pressed` for key down vs key up
- MUST register keycode on press, unregister on release
- MUST return false to skip QMK's default handling
- SHOULD use descriptive custom keycode names (not DUAL_FUNC_N)

## OS Detection Helper

### Active Base Layer Detection

```c
// Helper function to determine active OS
bool is_macos_active(void) {
    return (get_highest_layer(default_layer_state) == LAYER_MAC_BASE);
}

// Usage in dual-function logic
if (is_macos_active()) {
    // macOS-specific behavior
} else {
    // Windows-specific behavior  
}
```

**Contract Requirements**:
- MUST use `get_highest_layer(default_layer_state)` not `layer_state`
- `default_layer_state` reflects TO() layer switches (persistent base)
- `layer_state` reflects momentary layers (OSL, LT) - not suitable for OS detection

## Testing Contracts

### Dual-Function Tap Test

**Scenario**: Quick tap (<200ms) of dual-function key

**Expected**:
- Sends tap keycode (e.g., KC_H, KC_BSPC, DE_AT)
- Does NOT activate hold behavior (modifier or layer)

**Acceptance**:
- ✅ Tap behavior 100% reliable at normal typing speed
- ✅ No false hold activations during rapid typing

### Dual-Function Hold Test

**Scenario**: Press and hold (>200ms) dual-function key

**Expected**:
- Activates hold behavior (modifier or layer)
- Does NOT send tap keycode

**Acceptance**:
- ✅ Hold behavior activates after TAPPING_TERM (200ms)
- ✅ Modifier or layer remains active while held
- ✅ Deactivates on release

### OS-Conditional Dual-Function Test

**Scenario**: Use custom dual-function on macOS base vs Windows base

**Expected**:
- On macOS base: Hold sends Ctrl+Bspc (or appropriate Mac modifier)
- On Windows base: Hold sends Alt+Bspc (or appropriate Win modifier)

**Acceptance**:
- ✅ Correct OS-specific behavior on both bases
- ✅ OS detection reliable via `is_macos_active()`
- ✅ No crosstalk between OS behaviors

## Migration Path from Current to Target

### Step 1: Identify Duplicate Implementations

Review DUAL_FUNC_0 through DUAL_FUNC_15, identify:
- Identical tap+hold behaviors across OS layers → consolidate
- Different hold modifiers per OS → keep separate, rename descriptively

### Step 2: Create Consolidated Definitions

```c
// Replace numbered macros with descriptive names
#define DF_AT_CTRL   /* consolidated implementation */
#define DF_SLASH_ALT /* consolidated implementation */
// ...
```

### Step 3: Update Keymap Arrays

Replace old DUAL_FUNC_N references with new DF_* or KC_CUSTOM_* names in keymaps

### Step 4: Implement Custom Keycodes

Move complex dual-functions to process_record_user with OS detection

### Step 5: Test Each Dual-Function

Verify tap and hold behaviors on both macOS and Windows bases

### Step 6: Remove Old Definitions

Delete DUAL_FUNC_0 through DUAL_FUNC_15 after migration complete

## Code Size Impact

**Current**:
- 16 dual-function implementations × ~45 bytes each = ~720 bytes

**Target**:
- 13 dual-function implementations × ~45 bytes each = ~585 bytes
- **Savings**: ~135 bytes from dual-function consolidation

**Additional Savings**:
- Removed duplicate layer definitions: ~300-400 bytes
- **Total Estimated Savings**: ~435-535 bytes

---

**Version**: 1.0.0  
**Last Updated**: 2025-11-07  
**Status**: Design Complete - Ready for Implementation
