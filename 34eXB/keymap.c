#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_CAPS,        KC_U,           KC_O,           KC_F,           KC_Z,                                           KC_B,           KC_P,           KC_Y,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT, 
    CW_TOGG,        MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_I),LT(1,KC_E),     MT(MOD_LSFT, KC_N),MT(MOD_LGUI, KC_M),                                MT(MOD_LGUI, KC_G),MT(MOD_LSFT, KC_T),LT(1,KC_S),     MT(MOD_LCTL, KC_R),MT(MOD_LALT, KC_C),KC_DELETE,      
    KC_TRANSPARENT, OSL(2),         KC_TAB,         KC_J,           KC_H,           KC_X,                                           KC_K,           KC_D,           KC_V,           KC_W,           KC_Q,           KC_TRANSPARENT, 
                                                    KC_BSPC,        KC_ESCAPE,                                      KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_LCBR,        KC_RCBR,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_LPRN,        KC_RPRN,        KC_NO,                                          KC_PAGE_UP,     KC_NO,          KC_UP,          KC_NO,          KC_HOME,        KC_NO,          
    KC_NO,          KC_SCLN,        KC_SLASH,       KC_COMMA,       KC_DOT,         KC_GRAVE,                                       KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_NO,          
    KC_NO,          KC_QUOTE,       KC_BSLS,        KC_EQUAL,       KC_MINUS,       KC_NO,                                          KC_NO,          LCTL(LSFT(KC_TAB)),KC_NO,          LCTL(KC_TAB),   KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_NO,          
    KC_NO,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          KC_NO,          KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,          
    KC_NO,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {139,221,204}, {139,221,204}, {139,221,204}, {139,221,204}, {139,221,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,221,204}, {139,221,204}, {139,221,204}, {139,221,204}, {139,221,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



