#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_86_255_170,
  HSV_151_145_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_4,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_19,
  DANCE_20,
  DANCE_21,
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_5,
  DANCE_11,
  DANCE_12,
  DANCE_18,
  DANCE_22,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    TD(DANCE_0),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TD(DANCE_3),    
    TT(4),          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_SCLN,        MT(MOD_RCTL, KC_BSLS),
    TD(DANCE_1),    MT(MOD_LALT, KC_A),MT(MOD_LSFT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_RSFT, KC_L),MT(MOD_RALT, KC_P),MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    TD(DANCE_2),    MT(MOD_LCTL, KC_TAB),                                KC_LEFT_SHIFT,  LT(2,KC_MINUS)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,         
    KC_DQUO,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_BSPC,        
    TD(DANCE_4),    KC_QUES,        KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_CAPS),  KC_AUDIO_VOL_UP,
    KC_LEFT_ALT,    LALT(LSFT(KC_KP_ASTERISK)),LCTL(LSFT(KC_TAB)),TD(DANCE_5),    LCTL(KC_TAB),   TD(DANCE_6),                                    LCTL(LSFT(KC_H)),LCTL(LSFT(KC_LEFT)),KC_UP,          LCTL(LSFT(KC_RIGHT)),TD(DANCE_8),    KC_AUDIO_MUTE,  
    KC_TRANSPARENT, LALT(LSFT(KC_KP_MINUS)),KC_MS_BTN2,     TD(DANCE_7),    KC_MS_BTN1,     KC_BSPC,                                        TD(DANCE_9),    KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, LALT(LSFT(KC_KP_PLUS)),LGUI(KC_LBRC),  LGUI(KC_W),     LGUI(KC_RBRC),  ST_MACRO_0,                                     LGUI(LSFT(KC_S)),KC_PAGE_UP,     TD(DANCE_10),   KC_PGDN,        TD(DANCE_11),   KC_TRANSPARENT, 
                                                    LT(3,KC_SPACE), KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_CAPS),  KC_AUDIO_VOL_UP,
    KC_LEFT_ALT,    LALT(LSFT(KC_KP_ASTERISK)),LCTL(LSFT(KC_TAB)),TD(DANCE_12),   LCTL(KC_TAB),   TD(DANCE_13),                                   LCTL(LSFT(KC_H)),LCTL(LSFT(KC_LEFT)),KC_MS_UP,       LCTL(LSFT(KC_RIGHT)),TD(DANCE_15),   KC_AUDIO_MUTE,  
    KC_TRANSPARENT, LALT(LSFT(KC_KP_MINUS)),KC_MS_BTN2,     TD(DANCE_14),   KC_MS_BTN1,     KC_BSPC,                                        TD(DANCE_16),   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, LALT(LSFT(KC_KP_PLUS)),LGUI(KC_LBRC),  LGUI(KC_W),     LGUI(KC_RBRC),  ST_MACRO_1,                                     LGUI(LSFT(KC_S)),KC_PAGE_UP,     TD(DANCE_17),   KC_PGDN,        TD(DANCE_18),   KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        HSV_86_255_170, HSV_151_145_255,                                KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        QK_BOOT,        KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, LCTL(KC_CAPS),  KC_AUDIO_VOL_UP,KC_TRANSPARENT, ST_MACRO_2,     TD(DANCE_19),                                   LCTL(LSFT(KC_H)),KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        TD(DANCE_20),   KC_AUDIO_MUTE,  
    KC_TRANSPARENT, RALT(KC_RIGHT_CTRL),KC_AUDIO_MUTE,  KC_TRANSPARENT, ST_MACRO_3,     KC_BSPC,                                        TD(DANCE_21),   KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, RCTL(KC_L),     KC_AUDIO_VOL_DOWN,KC_TRANSPARENT, LCTL(RSFT(KC_J)),ST_MACRO_4,                                     LGUI(LSFT(KC_S)),KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        TD(DANCE_22),   KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_LEFT_SHIFT, MT(MOD_LCTL, KC_TAB), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(5)),
    COMBO(combo1, KC_MEH),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(DANCE_2):
            return TAPPING_TERM -50;
        case MT(MOD_LCTL, KC_TAB):
            return TAPPING_TERM -50;
        case LT(2,KC_MINUS):
            return TAPPING_TERM -50;
        case TD(DANCE_11):
            return TAPPING_TERM + 300;
        case TD(DANCE_18):
            return TAPPING_TERM + 300;
        case TD(DANCE_22):
            return TAPPING_TERM + 300;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {0,140,253}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {253,66,204}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {138,55,198}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240}, {133,142,240} },

    [1] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {41,155,166}, {41,155,166}, {28,255,255}, {28,255,255}, {251,255,186}, {251,255,186}, {245,255,117}, {245,255,117}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {251,255,186}, {251,255,186}, {0,0,0}, {28,255,255}, {28,255,255}, {28,255,255}, {251,255,186}, {251,255,186}, {0,0,0}, {28,255,255}, {28,255,255}, {28,255,255}, {251,255,186}, {251,255,186}, {0,0,0}, {251,255,186}, {28,255,255} },

    [2] = { {0,0,0}, {27,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {0,0,0}, {28,255,255}, {149,255,204}, {149,255,204}, {149,255,204}, {83,255,255}, {0,0,0}, {0,255,255}, {100,71,252}, {100,71,252}, {100,71,252}, {26,255,255}, {0,0,0}, {83,255,255}, {149,255,204}, {0,255,255}, {149,255,204}, {0,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {27,255,255}, {86,255,255}, {134,255,204}, {251,255,186}, {149,255,204}, {100,71,252}, {149,255,204}, {25,218,204}, {251,255,186}, {41,255,255}, {100,71,252}, {100,71,252}, {100,71,252}, {25,218,204}, {134,255,204}, {76,255,255}, {149,255,204}, {0,255,255}, {149,255,204}, {25,218,204}, {251,255,186}, {27,255,255}, {27,255,255} },

    [3] = { {0,0,0}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {0,0,0}, {28,255,255}, {149,255,204}, {149,255,204}, {149,255,204}, {83,255,255}, {0,0,0}, {0,255,255}, {100,71,252}, {100,71,252}, {100,71,252}, {26,255,255}, {0,0,0}, {83,255,255}, {149,255,204}, {0,255,255}, {149,255,204}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {251,255,186}, {86,255,255}, {134,255,204}, {251,255,186}, {149,255,204}, {134,255,204}, {149,255,204}, {25,218,204}, {251,255,186}, {41,255,255}, {134,255,204}, {134,255,204}, {134,255,204}, {25,218,204}, {134,255,204}, {9,195,255}, {149,255,204}, {0,255,255}, {149,255,204}, {25,218,204}, {0,255,255}, {251,255,186}, {251,255,186} },

    [4] = { {140,69,242}, {0,255,255}, {0,255,255}, {0,255,255}, {92,255,255}, {151,145,255}, {0,255,255}, {142,163,255}, {167,255,255}, {133,142,240}, {133,142,240}, {83,255,255}, {0,0,0}, {142,163,255}, {0,255,255}, {0,0,0}, {0,0,0}, {26,255,255}, {0,0,0}, {123,254,255}, {167,255,255}, {0,0,0}, {86,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,245,245}, {134,255,204}, {251,255,186}, {0,0,0}, {0,255,255}, {0,255,255}, {25,218,204}, {251,255,186}, {41,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {25,218,204}, {134,255,204}, {76,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {25,218,204}, {0,255,255}, {0,255,255}, {0,255,255} },

    [5] = { {231,78,244}, {231,78,244}, {231,78,244}, {231,78,244}, {231,78,244}, {231,78,244}, {251,75,244}, {251,75,244}, {251,75,244}, {251,75,244}, {251,75,244}, {251,75,244}, {249,53,255}, {249,53,255}, {249,53,255}, {249,53,255}, {249,53,255}, {249,53,255}, {103,11,226}, {103,11,226}, {103,11,226}, {103,11,226}, {103,11,226}, {103,11,226}, {103,11,226}, {103,11,226}, {81,126,87}, {81,126,87}, {81,126,87}, {81,126,87}, {81,126,87}, {81,126,87}, {66,158,119}, {66,158,119}, {66,158,119}, {66,158,119}, {66,158,119}, {66,158,119}, {55,126,169}, {55,126,169}, {55,126,169}, {55,126,169}, {55,126,169}, {55,126,169}, {46,89,243}, {46,89,243}, {46,89,243}, {46,89,243}, {46,89,243}, {46,89,243}, {46,89,243}, {46,89,243} },

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
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
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
      SEND_STRING(SS_LCTL(SS_RSFT(SS_TAP(X_J)))SS_DELAY(2000)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_RSFT(SS_TAP(X_J)))SS_DELAY(2000)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_CAPS)SS_DELAY(100)  SS_TAP(X_F)SS_DELAY(100)  SS_TAP(X_O)SS_DELAY(100)  SS_TAP(X_L)SS_DELAY(100)  SS_TAP(X_L)SS_DELAY(100)  SS_TAP(X_O)SS_DELAY(100)  SS_TAP(X_W)SS_DELAY(100)  SS_TAP(X_SPACE)SS_DELAY(100)  SS_TAP(X_U)SS_DELAY(100)  SS_TAP(X_P)SS_DELAY(100)  SS_TAP(X_CAPS)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_RSFT(SS_TAP(X_J)))SS_DELAY(2000)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)SS_DELAY(100)  SS_TAP(X_TAB)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;

    case TD(DANCE_4):
    case TD(DANCE_6):
    case TD(DANCE_7):
    case TD(DANCE_8):
    case TD(DANCE_9):
    case TD(DANCE_10):
    case TD(DANCE_13):
    case TD(DANCE_14):
    case TD(DANCE_15):
    case TD(DANCE_16):
    case TD(DANCE_17):
    case TD(DANCE_19):
    case TD(DANCE_20):
    case TD(DANCE_21):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_86_255_170:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,170);
      }
      return false;
    case HSV_151_145_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(151,145,255);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[9];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LSFT(KC_D)))); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LSFT(KC_D)))); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
        case DOUBLE_HOLD: register_code16(KC_F24); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_HOLD: unregister_code16(KC_F24); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: layer_on(1); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_HOLD: layer_on(1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD:
          layer_off(1);
        break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
              case DOUBLE_HOLD: 
                layer_off(1);
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(KC_DELETE))); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_HOLD: register_code16(LCTL(LGUI(KC_Q))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(KC_DELETE))); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(LGUI(KC_Q))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[3].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_T));
        tap_code16(LGUI(KC_T));
        tap_code16(LGUI(KC_T));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_T));
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_T)); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_T))); break;
        case DOUBLE_TAP: register_code16(LGUI(RSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_T)); register_code16(LGUI(KC_T));
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_T)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_T))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(RSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_T)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[5].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_T));
        tap_code16(LGUI(KC_T));
        tap_code16(LGUI(KC_T));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_T));
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_T)); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_T))); break;
        case DOUBLE_TAP: register_code16(LGUI(RSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_T)); register_code16(LGUI(KC_T));
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_T)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_T))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(RSFT(KC_T))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_T)); break;
    }
    dance_state[6].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[7].step = 0;
}
void on_dance_22(tap_dance_state_t *state, void *user_data);
void dance_22_finished(tap_dance_state_t *state, void *user_data);
void dance_22_reset(tap_dance_state_t *state, void *user_data);

void on_dance_22(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_22_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_4] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOTE, KC_TILD),
        [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(KC_U), KC_INSERT),
        [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(KC_MS_BTN3, LGUI(KC_R)),
        [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_L), LGUI(LSFT(KC_M))),
        [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_M)), KC_SPACE),
        [DANCE_10] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, KC_END),
        [DANCE_13] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(KC_U), KC_INSERT),
        [DANCE_14] = ACTION_TAP_DANCE_TAP_HOLD(KC_MS_BTN3, LGUI(KC_R)),
        [DANCE_15] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_L), LGUI(LSFT(KC_M))),
        [DANCE_16] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_M)), KC_SPACE),
        [DANCE_17] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, KC_END),
        [DANCE_19] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(KC_U), KC_INSERT),
        [DANCE_20] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_L), LGUI(LSFT(KC_M))),
        [DANCE_21] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_M)), KC_SPACE),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
};
