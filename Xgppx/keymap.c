#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  MAC_MISSION_CONTROL,
  MAC_SPOTLIGHT,
  MAC_SIRI,
  MAC_LOCK,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TD(DANCE_1),    
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           CH_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_A,           MT(MOD_LCTL, KC_S),MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F),KC_G,                                           KC_H,           MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RCTL, KC_L),TD(DANCE_2),    MT(MOD_RSFT, CH_QUOT),
    TD(DANCE_0),    CH_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    ST_MACRO_0,     
                                                    LT(1,KC_BSPC),  LT(2,KC_ENTER),                                 MO(2),          LT(1,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_DOT,         CH_LESS,        CH_MORE,        CH_DQOT,        CH_QUOT,                                        CH_AMPR,        KC_TRANSPARENT, LALT(KC_5),     LALT(KC_6),     CH_PERC,        KC_F12,         
    KC_TRANSPARENT, CH_EXLM,        MT(MOD_LCTL, KC_KP_MINUS),MT(MOD_LALT, KC_KP_PLUS),MT(MOD_LGUI, KC_KP_EQUAL),CH_HASH,                                        CH_PIPE,        TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    CH_QST,         KC_TRANSPARENT, 
    KC_TRANSPARENT, CH_CARR,        KC_KP_SLASH,    KC_KP_ASTERISK, LALT(LSFT(KC_7)),ST_MACRO_1,                                     ST_MACRO_2,     CH_DLR,         LALT(KC_8),     LALT(KC_9),     LALT(KC_G),     KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_HUI,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,MAC_MISSION_CONTROL,MAC_SPOTLIGHT,  MAC_SIRI,                                       TD(DANCE_9),    KC_MEDIA_PLAY_PAUSE,TD(DANCE_10),   KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,MAC_LOCK,       
    RGB_HUD,        KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_UP,          KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(CH_OE),    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_RGUI, KC_LEFT),MT(MOD_RALT, KC_DOWN),MT(MOD_RCTL, KC_RIGHT),RGUI(CH_OE),    KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(CH_AE),    KC_TRANSPARENT, KC_MAC_COPY,    KC_MAC_PASTE,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_BTN3,     RGUI(CH_AE),    KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LGUI, KC_S),KC_TRANSPARENT, MT(MOD_LCTL, KC_F),KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_RCTL, KC_J),KC_TRANSPARENT, MT(MOD_RGUI, KC_L),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_DOT,         CH_LESS,        CH_MORE,        CH_DQOT,        CH_QUOT,                                        CH_AMPR,        KC_TRANSPARENT, CH_LBRC,        CH_RBRC,        CH_PERC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, CH_EXLM,        MT(MOD_LGUI, KC_KP_MINUS),TD(DANCE_11),   MT(MOD_LCTL, KC_KP_EQUAL),CH_HASH,                                        CH_PIPE,        TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   CH_QST,         KC_TRANSPARENT, 
    KC_TRANSPARENT, CH_CARR,        KC_KP_SLASH,    KC_KP_ASTERISK, CH_BSLS,        ST_MACRO_3,                                     CH_TILD,        CH_DLR,         CH_LCBR,        CH_RCBR,        CH_AT,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    RGB_HUI,        RGB_VAD,        KC_F15,         MAC_MISSION_CONTROL,MAC_SPOTLIGHT,  MAC_SIRI,                                       KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, 
    RGB_HUD,        KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_UP,          KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255} },

    [1] = { {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {86,255,255}, {0,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,0,0}, {86,255,255}, {0,255,255}, {86,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {86,255,255}, {86,255,255}, {86,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255} },

    [4] = { {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255} },

    [5] = { {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {129,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255}, {86,255,255}, {129,255,255}, {86,255,255}, {129,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {86,255,255}, {0,255,255} },

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
      SEND_STRING(SS_LSFT(SS_TAP(X_8)) SS_DELAY(100) SS_LSFT(SS_TAP(X_9)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT) SS_DELAY(100) SS_TAP(X_DOT) SS_DELAY(100) SS_TAP(X_KP_SLASH));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_N)));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_KP_DOT) SS_DELAY(100) SS_TAP(X_KP_DOT) SS_DELAY(100) SS_TAP(X_KP_SLASH));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_SPOTLIGHT:
      HCS(0x221);
    case MAC_SIRI:
      HCS(0xCF);
    case MAC_LOCK:
      HCS(0x19E);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


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

static tap dance_state[15];

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
        tap_code16(CH_LESS);
        tap_code16(CH_LESS);
        tap_code16(CH_LESS);
    }
    if(state->count > 3) {
        tap_code16(CH_LESS);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(CH_LESS); break;
        case SINGLE_HOLD: register_code16(CH_MORE); break;
        case DOUBLE_TAP: register_code16(CH_LESS); register_code16(CH_LESS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_LESS); register_code16(CH_LESS);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(CH_LESS); break;
        case SINGLE_HOLD: unregister_code16(CH_MORE); break;
        case DOUBLE_TAP: unregister_code16(CH_LESS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_LESS); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_CARR);
        tap_code16(CH_CARR);
        tap_code16(CH_CARR);
    }
    if(state->count > 3) {
        tap_code16(CH_CARR);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(CH_CARR); break;
        case SINGLE_HOLD: register_code16(CH_GRV); break;
        case DOUBLE_TAP: register_code16(CH_CARR); register_code16(CH_CARR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_CARR); register_code16(CH_CARR);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(CH_CARR); break;
        case SINGLE_HOLD: unregister_code16(CH_GRV); break;
        case DOUBLE_TAP: unregister_code16(CH_CARR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_CARR); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_AE);
        tap_code16(CH_AE);
        tap_code16(CH_AE);
    }
    if(state->count > 3) {
        tap_code16(CH_AE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(CH_AE); break;
        case SINGLE_HOLD: register_code16(CH_OE); break;
        case DOUBLE_TAP: register_code16(CH_UE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_AE); register_code16(CH_AE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(CH_AE); break;
        case SINGLE_HOLD: unregister_code16(CH_OE); break;
        case DOUBLE_TAP: unregister_code16(CH_UE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_AE); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(CH_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(CH_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(CH_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(CH_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_MINS);
        tap_code16(CH_MINS);
        tap_code16(CH_MINS);
    }
    if(state->count > 3) {
        tap_code16(CH_MINS);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(CH_MINS); break;
        case SINGLE_HOLD: register_code16(CH_UNDS); break;
        case DOUBLE_TAP: register_code16(CH_MINS); register_code16(CH_MINS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_MINS); register_code16(CH_MINS);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(CH_MINS); break;
        case SINGLE_HOLD: unregister_code16(CH_UNDS); break;
        case DOUBLE_TAP: unregister_code16(CH_MINS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_MINS); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_COLN);
        tap_code16(CH_COLN);
        tap_code16(CH_COLN);
    }
    if(state->count > 3) {
        tap_code16(CH_COLN);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(CH_COLN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(CH_COLN); register_code16(CH_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_COLN); register_code16(CH_COLN);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(CH_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(CH_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_COLN); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_LPRN);
        tap_code16(CH_LPRN);
        tap_code16(CH_LPRN);
    }
    if(state->count > 3) {
        tap_code16(CH_LPRN);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(CH_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(CH_LPRN); register_code16(CH_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_LPRN); register_code16(CH_LPRN);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(CH_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(CH_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_LPRN); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_RPRN);
        tap_code16(CH_RPRN);
        tap_code16(CH_RPRN);
    }
    if(state->count > 3) {
        tap_code16(CH_RPRN);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(CH_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(CH_RPRN); register_code16(CH_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_RPRN); register_code16(CH_RPRN);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(CH_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(CH_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_RPRN); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_PLUS);
        tap_code16(CH_PLUS);
        tap_code16(CH_PLUS);
    }
    if(state->count > 3) {
        tap_code16(CH_PLUS);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(CH_PLUS); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(CH_PLUS); register_code16(CH_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_PLUS); register_code16(CH_PLUS);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(CH_PLUS); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(CH_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_PLUS); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_COLN);
        tap_code16(CH_COLN);
        tap_code16(CH_COLN);
    }
    if(state->count > 3) {
        tap_code16(CH_COLN);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(CH_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(CH_COLN); register_code16(CH_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_COLN); register_code16(CH_COLN);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(CH_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(CH_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_COLN); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_LPRN);
        tap_code16(CH_LPRN);
        tap_code16(CH_LPRN);
    }
    if(state->count > 3) {
        tap_code16(CH_LPRN);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(CH_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(CH_LPRN); register_code16(CH_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_LPRN); register_code16(CH_LPRN);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(CH_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(CH_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_LPRN); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(CH_RPRN);
        tap_code16(CH_RPRN);
        tap_code16(CH_RPRN);
    }
    if(state->count > 3) {
        tap_code16(CH_RPRN);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(CH_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(CH_RPRN); register_code16(CH_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(CH_RPRN); register_code16(CH_RPRN);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(CH_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(CH_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(CH_RPRN); break;
    }
    dance_state[14].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
};
