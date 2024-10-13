#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// Left-hand home row mods - used with achordion
#define HOME_A MT(MOD_LCTL, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LGUI, KC_D)
#define HOME_F MT(MOD_LSFT, KC_F)

// Right-hand home row mods - used with achordion
#define HOME_J MT(MOD_RSFT, KC_J)
#define HOME_K MT(MOD_RGUI, KC_K)
#define HOME_L MT(MOD_LALT, KC_L)
#define HOME_SCLN MT(MOD_RCTL, KC_SCLN)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LGUI(LCTL(KC_Q)),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    CW_TOGG,        KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_LALT, KC_L),KC_SCLN,        KC_QUOTE,       
    OSL(4),         KC_Z,           ALL_T(KC_X),    MT(MOD_LCTL, KC_C),MEH_T(KC_V),    KC_B,                                           KC_N,           MEH_T(KC_M),    MT(MOD_RCTL, KC_COMMA),MEH_T(KC_DOT),  KC_SLASH,       TG(3),          
                                                    KC_BSPC,        MO(2),                                          LT(1,KC_ENTER), KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          CW_TOGG,        KC_KP_MINUS,    KC_LPRN,        KC_RPRN,        KC_PLUS,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_GRAVE,       KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_EQUAL,                                       KC_NO,          OSM(MOD_LSFT),  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_NO,          KC_NO,          
    KC_NO,          KC_TILD,        KC_LABK,        KC_LBRC,        KC_RBRC,        KC_RABK,                                        KC_NO,          KC_NO,          OSM(MOD_LCTL),  KC_NO,          KC_NO,          KC_NO,          
                                                    KC_DELETE,      ST_MACRO_0,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          LGUI(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LGUI(KC_RIGHT), QK_LLCK,        KC_NO,          
    KC_NO,          KC_NO,          OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    ST_MACRO_1,     KC_NO,          KC_NO,          OSM(MOD_LCTL),  KC_NO,          KC_NO,                                          LALT(KC_LEFT),  LALT(KC_RIGHT), LALT(LGUI(KC_LEFT)),LALT(LGUI(KC_RIGHT)),KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT,                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    KC_MS_BTN1,     KC_MS_BTN3,                                     KC_TRANSPARENT, KC_MS_BTN2
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_2,     ST_MACRO_3,     KC_TRANSPARENT, ST_MACRO_4,     ST_MACRO_5,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_7,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_6,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_8,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
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
        case MEH_T(KC_DOT):
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

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {11,218,204}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {0,0,0}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {45,192,240}, {255,218,204}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {91,236,217}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {91,236,217}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,236,217}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {173,143,255}, {173,143,255}, {39,255,255}, {39,255,255}, {0,0,0}, {0,0,0}, {39,255,255}, {11,237,217}, {11,237,217}, {39,255,255}, {167,143,255}, {0,0,0}, {173,255,161}, {173,255,161}, {173,255,161}, {173,255,161}, {0,0,0}, {0,0,0}, {39,255,255}, {39,255,255}, {11,237,217}, {11,237,217}, {0,0,0}, {0,0,0}, {91,236,217}, {0,237,217} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {168,218,204}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {81,218,204}, {81,218,204}, {81,218,204}, {81,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {220,227,186}, {220,227,186}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {220,227,186}, {220,227,186}, {220,227,186}, {220,227,186}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {220,227,186} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {223,105,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
  // Achordion config
  if (!process_achordion(keycode, record)) { return false; }
  
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
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_D));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_D));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) SS_TAP(X_R));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_LSFT(SS_TAP(X_T)) SS_DELAY(100) SS_TAP(X_T));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_G));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_L));
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

// Start: Achordion config
void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LGUI:
    case MOD_RGUI:
      return true;  // Eagerly apply Shift and Cmd mods.
    default:
      return false;
  }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds
  switch (tap_hold_keycode) {
    case HOME_D:
      if (other_keycode == HOME_S || other_keycode == KC_T || other_keycode == KC_W || other_keycode == KC_R || other_keycode == KC_Z || other_keycode == KC_V || other_keycode == KC_Q || other_keycode == HOME_A) { return true; }
      break;
    case HOME_A:
      if (other_keycode == KC_C || other_keycode == HOME_D) { return true; }
      break;
    case HOME_SCLN:
      if (other_keycode == KC_U) { return true; }
      break;
  }

  // We want to ignore thumb clusters (except enter key)
  if (other_record->event.key.row == 5) { return true; }
  if (other_record->event.key.row == 11 && other_record->event.key.col == 6) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    // Thumb key for enter/layer
    case LT(1,KC_ENTER):
      return 0;  // Bypass Achordion for these keys.
  }

  return 500;  // Otherwise use a timeout of 500 ms.
}
// End: Achordion config