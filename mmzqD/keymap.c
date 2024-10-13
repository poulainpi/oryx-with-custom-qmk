#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LGUI(LCTL(KC_Q)),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    CW_TOGG,        KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_LALT, KC_L),KC_SCLN,        KC_QUOTE,       
    OSL(3),         KC_Z,           ALL_T(KC_X),    MT(MOD_LCTL, KC_C),MEH_T(KC_V),    KC_B,                                           KC_N,           MEH_T(KC_M),    MT(MOD_RCTL, KC_COMMA),ALL_T(KC_DOT),  KC_SLASH,       OSL(3),         
                                                    KC_BSPC,        MO(2),                                          LT(1,KC_ENTER), KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_KP_MINUS,    KC_LPRN,        KC_RPRN,        KC_PLUS,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_GRAVE,       KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_EQUAL,                                       KC_NO,          OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_NO,          KC_NO,          
    KC_NO,          KC_TILD,        KC_LABK,        KC_LBRC,        KC_RBRC,        KC_RABK,                                        KC_NO,          KC_NO,          OSM(MOD_LCTL),  KC_NO,          KC_NO,          KC_NO,          
                                                    KC_DELETE,      ST_MACRO_0,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          LGUI(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LGUI(KC_RIGHT), QK_LLCK,        KC_NO,          
    KC_NO,          KC_NO,          OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    ST_MACRO_1,     KC_NO,          KC_NO,          OSM(MOD_LCTL),  KC_NO,          KC_NO,                                          LALT(KC_LEFT),  LALT(KC_RIGHT), LALT(LGUI(KC_LEFT)),LALT(LGUI(KC_RIGHT)),KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          LGUI(LCTL(KC_Q)),
    KC_NO,          KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_NO,                                          KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          KC_NO,          
    KC_NO,          KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_NO,                                          KC_NO,          KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TT(4),          KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_MS_BTN1,     KC_MS_BTN3,                                     KC_TRANSPARENT, KC_MS_BTN2
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 20;
        case ALL_T(KC_X):
            return TAPPING_TERM + 20;
        case MEH_T(KC_V):
            return TAPPING_TERM + 20;
        case MT(MOD_LALT, KC_L):
            return TAPPING_TERM + 40;
        case MEH_T(KC_M):
            return TAPPING_TERM + 20;
        case MT(MOD_RCTL, KC_COMMA):
            return TAPPING_TERM + 20;
        case ALL_T(KC_DOT):
            return TAPPING_TERM + 20;
        case OSM(MOD_LSFT):
            return 0;
        case OSM(MOD_LALT):
            return TAPPING_TERM + 40;
        case OSM(MOD_LCTL):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239}, {125,233,239} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {45,192,240}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {91,236,217}, {91,236,217}, {0,0,0}, {91,236,217}, {0,0,0}, {0,0,0}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {91,236,217}, {91,236,217}, {91,236,217}, {91,236,217}, {0,0,0}, {91,236,217}, {0,0,0}, {91,236,217}, {91,236,217}, {0,0,0}, {0,0,0}, {91,236,217}, {91,236,217}, {91,236,217}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {1,255,255}, {1,255,255}, {1,255,255}, {1,255,255}, {0,0,0}, {0,0,0}, {1,255,255}, {1,255,255}, {1,255,255}, {1,255,255}, {0,0,0}, {1,255,255}, {1,255,255}, {1,255,255}, {1,255,255}, {1,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {1,255,255}, {0,0,0}, {1,255,255}, {1,255,255}, {1,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {1,255,255}, {1,255,255}, {1,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {1,255,255}, {1,255,255}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,218,204}, {223,218,204}, {223,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {223,218,204}, {223,218,204}, {223,218,204}, {223,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,218,204}, {223,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,218,204}, {223,218,204}, {223,218,204}, {223,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,218,204} },

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
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_K)) SS_DELAY(100) SS_TAP(X_PAUSE)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



