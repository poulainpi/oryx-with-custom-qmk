#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// Layer definitions for 6-layer architecture
enum layer_names {
  LAYER_MAC_BASE = 0,    // macOS base layer with Cmd-optimized home row mods
  LAYER_WIN_BASE = 1,    // Windows base layer with Ctrl/Win-optimized home row mods
  LAYER_SYMBOLS = 2,     // Unified symbols layer (consolidates old layers 1 and 6)
  LAYER_FUNCTION = 3,    // Function/navigation layer (consolidates old layers 2, 5, 8)
  LAYER_NUMBERS = 4,     // Numbers/numpad layer (consolidates old layers 3 and 7)
  LAYER_CONFIG = 5,      // Configuration layer (RGB, layer switching, bootloader)
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  // OS-aware clipboard operations (auto-detect macOS vs Windows base layer)
  OS_UNDO,    // Cmd+Z on macOS, Ctrl+Z on Windows
  OS_COPY,    // Cmd+C on macOS, Ctrl+C on Windows
  OS_PASTE,   // Cmd+V on macOS, Ctrl+V on Windows
  OS_CUT,     // Cmd+X on macOS, Ctrl+X on Windows
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: LAYER_MAC_BASE - macOS base layer with Cmd-optimized home row mods
  [LAYER_MAC_BASE] = LAYOUT_voyager(
    LGUI(DE_MINS),  LGUI(KC_0),     LGUI(DE_PLUS),  KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(LAYER_CONFIG),
    KC_TRANSPARENT, KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT,
    CW_TOGG,        MT(MOD_LCTL, KC_H), MT(MOD_LALT, KC_I), MT(MOD_LGUI, KC_E), KC_A,     KC_O,                                     KC_D,           MT(MOD_RGUI, KC_T), MT(MOD_LALT, KC_R), MT(MOD_RCTL, KC_N), KC_S,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT,
                                                    OSL(LAYER_SYMBOLS), OSM(MOD_LSFT),                                              OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),

  // Layer 1: LAYER_WIN_BASE - Windows base layer with Ctrl/Win-optimized home row mods
  [LAYER_WIN_BASE] = LAYOUT_voyager(
    LCTL(DE_MINS),  LCTL(KC_0),     LCTL(DE_PLUS),  KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(LAYER_CONFIG),
    KC_TRANSPARENT, KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT,
    CW_TOGG,        MT(MOD_LGUI, KC_H), MT(MOD_LALT, KC_I), MT(MOD_LCTL, KC_E), KC_A,     KC_O,                                     KC_D,           MT(MOD_RCTL, KC_T), MT(MOD_LALT, KC_R), MT(MOD_RGUI, KC_N), KC_S,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT,
                                                    OSL(LAYER_SYMBOLS), OSM(MOD_LSFT),                                              OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),

  // Layer 2: LAYER_SYMBOLS - Unified symbols layer (consolidates old layers 1 and 6)
  [LAYER_SYMBOLS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_SECT,        DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_AT,          DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_UNDS,        DE_BSLS,        DE_PIPE,        DE_DQOT,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_SCLN,        KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_BSPC,        KC_DEL
  ),

  // Layer 3: LAYER_FUNCTION - Unified function/navigation layer (consolidates old layers 2, 5, 8)
  [LAYER_FUNCTION] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_F12,         KC_TAB,         DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PGUP,        KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F11,         KC_ESCAPE,      DE_SS,          DE_EURO,        DE_AE,          DE_OE,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PGDN,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // Layer 4: LAYER_NUMBERS - Unified numpad layer (consolidates old layers 3 and 7)
  [LAYER_NUMBERS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_MINS,        KC_7,           KC_8,           KC_9,           DE_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_COLN,        KC_1,           KC_2,           KC_3,           KC_0,                                           OS_UNDO,        OS_COPY,        OS_PASTE,       OS_CUT,         KC_TRANSPARENT, KC_APPLICATION,
    KC_TRANSPARENT, DE_PLUS,        KC_4,           KC_5,           KC_6,           DE_SLSH,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_COMMA,       KC_DOT,                                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // Layer 5: LAYER_CONFIG - Configuration layer (RGB, layer switching, bootloader)
  [LAYER_CONFIG] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD,    RGB_VAD,        RGB_VAI,                                        TO(LAYER_WIN_BASE), KC_TRANSPARENT, TO(LAYER_MAC_BASE), KC_TRANSPARENT, QK_BOOT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_SPD,        RGB_SPI,                                        KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP, RGB_HUD,    RGB_HUI,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const key_override_t dot_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);
const key_override_t quote_doublequote_override = ko_make_basic(MOD_MASK_SHIFT, DE_DQOT, DE_QUOT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &dot_comma_override,
    &quote_doublequote_override,
    NULL
};


const uint16_t PROGMEM combo0[] = { OSM(MOD_LSFT), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { OSM(MOD_LSFT), DE_QUOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { OSM(MOD_LSFT), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo3[] = { OSM(MOD_LSFT), DE_QUOT, COMBO_END};
/*
const uint16_t PROGMEM combo0[] = { OSL(1), OSL(2), COMBO_END};
const uint16_t PROGMEM combo1[] = { OSL(6), OSL(5), COMBO_END};
*/
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_COMMA),
    COMBO(combo1, DE_DQOT),
    COMBO(combo2, KC_COMMA),
    COMBO(combo3, DE_DQOT),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {139,78,233}, {139,149,221}, {139,210,188}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {68,239,219}, {0,0,0}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,238,159}, {0,0,0}, {68,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case LAYER_MAC_BASE:  // Layer 0: Blue
      set_layer_color(0);
      break;
    case LAYER_WIN_BASE:  // Layer 1: Cyan
      set_layer_color(1);
      break;
    case LAYER_CONFIG:    // Layer 5: Red
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
  /*
  if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    }
  */
 if (leader_sequence_two_keys(LSFT(KC_2), KC_A)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_AE | S(KC_NO)); // Ä
        } else {
            tap_code16(DE_AE); // ä
        }
    } else if (leader_sequence_two_keys(LSFT(KC_2), KC_O)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_OE | S(KC_NO)); // Ö
        } else {
            tap_code16(DE_OE); // ö
        }
    } else if (leader_sequence_two_keys(LSFT(KC_2), KC_U)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_UE | S(KC_NO)); // Ü
        } else {
            tap_code16(DE_UE); // ü
        }
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(DE_SS); // ß
   } else if (leader_sequence_one_key(KC_A)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_AE | S(KC_NO)); // Ä
        } else {
            tap_code16(DE_AE); // ä
        }
   } else if (leader_sequence_one_key(KC_U)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_UE | S(KC_NO)); // Ü
        } else {
            tap_code16(DE_UE); // ü
        }
   } else if (leader_sequence_one_key(KC_O)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_OE | S(KC_NO)); // Ö
        } else {
            tap_code16(DE_OE); // ö
        }
   } else if (leader_sequence_two_keys(KC_S, KC_S)) {
      tap_code16(DE_SS); // ß
    } else if (leader_sequence_two_keys(KC_C, KC_E)) {
      tap_code16(DE_EURO); // €
    }

    /*
    else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    }
    */
}

// Helper function to detect if currently on macOS base layer
// Returns true if on LAYER_MAC_BASE (layer 0), false otherwise
bool is_macos_base(void) {
    return get_highest_layer(layer_state) == LAYER_MAC_BASE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;

    // OS-aware clipboard operations
    case OS_UNDO:
      if (record->event.pressed) {
        if (is_macos_base()) {
          tap_code16(LGUI(KC_Z));  // Cmd+Z on macOS
        } else {
          tap_code16(LCTL(KC_Z));  // Ctrl+Z on Windows
        }
      }
      return false;
    case OS_COPY:
      if (record->event.pressed) {
        if (is_macos_base()) {
          tap_code16(LGUI(KC_C));  // Cmd+C on macOS
        } else {
          tap_code16(LCTL(KC_C));  // Ctrl+C on Windows
        }
      }
      return false;
    case OS_PASTE:
      if (record->event.pressed) {
        if (is_macos_base()) {
          tap_code16(LGUI(KC_V));  // Cmd+V on macOS
        } else {
          tap_code16(LCTL(KC_V));  // Ctrl+V on Windows
        }
      }
      return false;
    case OS_CUT:
      if (record->event.pressed) {
        if (is_macos_base()) {
          tap_code16(LGUI(KC_X));  // Cmd+X on macOS
        } else {
          tap_code16(LCTL(KC_X));  // Ctrl+X on Windows
        }
      }
      return false;
  }
  return true;
}
