#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// Layer indices for consolidated 5-layer structure
enum custom_layers {
  LAYER_MAC_BASE = 0,   // macOS base typing layer
  LAYER_WIN_BASE = 1,   // Windows base typing layer
  LAYER_SYMBOLS  = 2,   // Unified programming symbols
  LAYER_FUNCTION = 3,   // Unified function keys, navigation, umlauts
  LAYER_NUMBERS  = 4,   // Unified number pad with OS-specific clipboard
  LAYER_CONFIG   = 5    // RGB configuration and system functions
};

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  // OS-aware clipboard operations
  OS_UNDO,
  OS_COPY,
  OS_PASTE,
  OS_CUT,
};

// OS detection helper function
// Returns true if currently on macOS base layer, false if on Windows base layer
bool is_macos_base(void) {
    return (get_highest_layer(default_layer_state) == LAYER_MAC_BASE);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: macOS Base Layer
  [LAYER_MAC_BASE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           TO(LAYER_CONFIG),          
    CW_TOGG,        MT(MOD_LCTL, KC_H),MT(MOD_LALT, KC_I),MT(MOD_LGUI, KC_E),KC_A,           KC_O,                                           KC_D,           MT(MOD_RGUI, KC_T),MT(MOD_LALT, KC_R),MT(MOD_RCTL, KC_N),KC_S,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT, 
    LGUI(DE_MINS),  LGUI(KC_0),     LGUI(DE_PLUS),  KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    OSL(LAYER_SYMBOLS), OSM(MOD_LSFT),                                          OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),
  
  // Layer 1: Windows Base Layer
  [LAYER_WIN_BASE] = LAYOUT_voyager(
    CW_TOGG,        KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           TO(LAYER_CONFIG),          
    CW_TOGG,        MT(MOD_LGUI, KC_H),MT(MOD_LALT, KC_I),MT(MOD_LCTL, KC_E),KC_A,           KC_O,                                           KC_D,           MT(MOD_RCTL, KC_T),MT(MOD_LALT, KC_R),MT(MOD_RGUI, KC_N),KC_S,           LALT(KC_TAB),   
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           LALT(LSFT(KC_TAB)),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    OSL(LAYER_SYMBOLS), OSM(MOD_LSFT),                                          OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),
  
  // Placeholder layers (will be implemented in later phases)
  [LAYER_SYMBOLS] = LAYOUT_voyager(
    KC_TRANSPARENT, DE_SECT,        DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_TILD,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_AT,          DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_UNDS,        DE_BSLS,        DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  
  [LAYER_FUNCTION] = LAYOUT_voyager(
    KC_F12,         KC_TAB,         DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F11,         KC_ESCAPE,      DE_SS,          DE_EURO,        DE_AE,          DE_OE,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F10,         KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGDN,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  
  [LAYER_NUMBERS] = LAYOUT_voyager(
    KC_TRANSPARENT, DE_MINS,        KC_7,           KC_8,           KC_9,           DE_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_COLN,        KC_1,           KC_2,           KC_3,           KC_0,                                           OS_UNDO,        OS_COPY,        OS_PASTE,       OS_CUT,         KC_TRANSPARENT, KC_APPLICATION, 
    KC_TRANSPARENT, DE_PLUS,        KC_4,           KC_5,           KC_6,           DE_SLSH,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_COMMA,       KC_DOT,                                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  
  [LAYER_CONFIG] = LAYOUT_voyager(
    // Left half - RGB Controls
    RGB_TOG,        TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    RGB_VAD,        RGB_VAI,        RGB_HUD,        RGB_HUI,        RGB_SAD,        RGB_SAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_SPD,        RGB_SPI,        HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(LAYER_WIN_BASE), TO(LAYER_MAC_BASE),
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const key_override_t dot_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);
const key_override_t quote_doublequote_override = ko_make_basic(MOD_MASK_SHIFT, DE_DQOT, DE_QUOT);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_comma_override,
    &quote_doublequote_override,
    NULL
};


const uint16_t PROGMEM combo0[] = { KC_DOT, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo1[] = { OSM(MOD_LSFT), DE_QUOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_DOT, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo3[] = { DE_QUOT, OSM(MOD_LSFT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_COMMA),
    COMBO(combo1, DE_DQOT),
    COMBO(combo2, KC_COMMA),
    COMBO(combo3, DE_DQOT),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [LAYER_MAC_BASE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,78,233}, {139,149,221}, {139,210,188}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {68,239,219}, {0,0,0}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [LAYER_WIN_BASE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [LAYER_CONFIG] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,238,159}, {0,0,0}, {68,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case LAYER_MAC_BASE:
        set_layer_color(LAYER_MAC_BASE);
        break;
      case LAYER_WIN_BASE:
        set_layer_color(LAYER_WIN_BASE);
        break;
      case LAYER_CONFIG:
        set_layer_color(LAYER_CONFIG);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
    // OS-aware clipboard operations (T028)
    case OS_UNDO:
      if (record->event.pressed) {
        if (is_macos_base()) {
          register_code16(LGUI(KC_Z));  // Cmd+Z on macOS
        } else {
          register_code16(LCTL(KC_Z));  // Ctrl+Z on Windows
        }
      } else {
        if (is_macos_base()) {
          unregister_code16(LGUI(KC_Z));
        } else {
          unregister_code16(LCTL(KC_Z));
        }
      }
      return false;
      
    case OS_COPY:
      if (record->event.pressed) {
        if (is_macos_base()) {
          register_code16(LGUI(KC_C));  // Cmd+C on macOS
        } else {
          register_code16(LCTL(KC_C));  // Ctrl+C on Windows
        }
      } else {
        if (is_macos_base()) {
          unregister_code16(LGUI(KC_C));
        } else {
          unregister_code16(LCTL(KC_C));
        }
      }
      return false;
      
    case OS_PASTE:
      if (record->event.pressed) {
        if (is_macos_base()) {
          register_code16(LGUI(KC_V));  // Cmd+V on macOS
        } else {
          register_code16(LCTL(KC_V));  // Ctrl+V on Windows
        }
      } else {
        if (is_macos_base()) {
          unregister_code16(LGUI(KC_V));
        } else {
          unregister_code16(LCTL(KC_V));
        }
      }
      return false;
      
    case OS_CUT:
      if (record->event.pressed) {
        if (is_macos_base()) {
          register_code16(LGUI(KC_X));  // Cmd+X on macOS
        } else {
          register_code16(LCTL(KC_X));  // Ctrl+X on Windows
        }
      } else {
        if (is_macos_base()) {
          unregister_code16(LGUI(KC_X));
        } else {
          unregister_code16(LCTL(KC_X));
        }
      }
      return false;

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
  }
  return true;
}


