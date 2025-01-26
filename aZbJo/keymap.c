#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_LEFT_ALT,    
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_SCLN,        TD(DANCE_0),    
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_P,           MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_MINUS,       
                                                    KC_SPACE,       LT(3,KC_DELETE),                                LT(2,KC_ENTER), KC_BSPC
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          TD(DANCE_1),                                    RU_EN,          RU_GHE,         TD(DANCE_2),    RU_BE,          RU_ZE,          RU_HA,          
    KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,                                          RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         MT(MOD_RSFT, RU_E),
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          TD(DANCE_3),    RU_COMM,        RU_DOT,         RU_YU,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        TD(DANCE_4),    KC_PERC,                                        KC_KP_MINUS,    KC_1,           KC_2,           KC_3,           KC_KP_SLASH,    KC_QUOTE,       
    KC_TRANSPARENT, KC_EQUAL,       KC_AMPR,        KC_ASTR,        TD(DANCE_5),    KC_QUES,                                        KC_0,           KC_4,           KC_5,           KC_6,           KC_KP_ASTERISK, KC_BSPC,        
    KC_TRANSPARENT, KC_BSLS,        KC_DLR,         KC_TILD,        TD(DANCE_6),    KC_CIRC,                                        KC_KP_PLUS,     KC_7,           KC_8,           KC_9,           KC_KP_DOT,      KC_ENTER,       
                                                    KC_TRANSPARENT, KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    LGUI(LSFT(KC_S)),KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LALT(LCTL(KC_TAB)),KC_NO,          KC_NO,          LALT(KC_E),     LALT(KC_R),     LALT(KC_T),                                     KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          KC_F12,         
    KC_TRANSPARENT, LALT(KC_ENTER), TD(DANCE_7),    LALT(KC_D),     LALT(LCTL(KC_ENTER)),KC_NO,                                          KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_CAPS,        
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     TO(1),                                          KC_NO,          TO(4),          KC_NO,          KC_NO,          KC_NO,          CW_TOGG,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(LCTL(KC_LEFT_SHIFT)),KC_LEFT_ALT
  ),
  [4] = LAYOUT_voyager(
    TO(0),          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN5,     KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN4,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_MS_BTN1,     KC_MS_BTN3,                                     KC_NO,          KC_MS_BTN2
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,255,255}, {21,255,255}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {18,255,81}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {21,251,169}, {18,255,81}, {21,255,255}, {21,255,255} },

    [2] = { {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {157,211,105}, {0,0,255}, {0,0,255}, {0,0,255}, {157,211,105}, {157,211,105}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {157,211,105}, {157,211,105}, {157,211,105}, {0,0,255}, {0,0,255}, {0,0,255}, {157,211,105}, {157,211,105}, {0,0,255}, {157,211,105} },

    [3] = { {0,0,255}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {156,230,237}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {156,230,237}, {185,205,82}, {0,0,255}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {190,95,242}, {185,205,82}, {185,205,82}, {185,205,82}, {185,205,82}, {190,95,242}, {190,95,242}, {190,95,242}, {185,205,82}, {84,236,255}, {185,205,82}, {115,218,204}, {185,205,82}, {185,205,82}, {185,205,82}, {146,237,255}, {185,205,82}, {185,205,82} },

    [4] = { {21,255,255}, {118,204,132}, {118,204,132}, {118,204,132}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {117,218,204}, {117,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {118,206,74}, {118,206,74}, {118,218,204}, {118,206,74}, {0,0,0}, {0,0,0}, {118,206,74}, {118,218,204}, {118,218,204}, {118,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {117,218,204} },

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

static tap dance_state[8];

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
        tap_code16(RU_HA);
        tap_code16(RU_HA);
        tap_code16(RU_HA);
    }
    if(state->count > 3) {
        tap_code16(RU_HA);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(RU_HA); break;
        case SINGLE_HOLD: register_code16(RU_HARD); break;
        case DOUBLE_TAP: register_code16(RU_HA); register_code16(RU_HA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_HA); register_code16(RU_HA);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(RU_HA); break;
        case SINGLE_HOLD: unregister_code16(RU_HARD); break;
        case DOUBLE_TAP: unregister_code16(RU_HA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_HA); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_IE);
        tap_code16(RU_IE);
        tap_code16(RU_IE);
    }
    if(state->count > 3) {
        tap_code16(RU_IE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(RU_IE); break;
        case SINGLE_HOLD: register_code16(RU_YO); break;
        case DOUBLE_TAP: register_code16(RU_IE); register_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_IE); register_code16(RU_IE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(RU_IE); break;
        case SINGLE_HOLD: unregister_code16(RU_YO); break;
        case DOUBLE_TAP: unregister_code16(RU_IE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_IE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_SHA);
        tap_code16(RU_SHA);
        tap_code16(RU_SHA);
    }
    if(state->count > 3) {
        tap_code16(RU_SHA);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(RU_SHA); break;
        case SINGLE_HOLD: register_code16(RU_SHCH); break;
        case DOUBLE_TAP: register_code16(RU_SHA); register_code16(RU_SHA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_SHA); register_code16(RU_SHA);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(RU_SHA); break;
        case SINGLE_HOLD: unregister_code16(RU_SHCH); break;
        case DOUBLE_TAP: unregister_code16(RU_SHA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_SHA); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
        tap_code16(RU_SOFT);
    }
    if(state->count > 3) {
        tap_code16(RU_SOFT);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(RU_SOFT); break;
        case SINGLE_HOLD: register_code16(RU_HARD); break;
        case DOUBLE_TAP: register_code16(RU_SOFT); register_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RU_SOFT); register_code16(RU_SOFT);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(RU_SOFT); break;
        case SINGLE_HOLD: unregister_code16(RU_HARD); break;
        case DOUBLE_TAP: unregister_code16(RU_SOFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RU_SOFT); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRC);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_LBRC); break;
        case SINGLE_HOLD: register_code16(KC_RBRC); break;
        case DOUBLE_TAP: register_code16(KC_LBRC); register_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRC); register_code16(KC_LBRC);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case SINGLE_HOLD: unregister_code16(KC_RBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRC); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
        tap_code16(LCTL(KC_S));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_S));
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_S))); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_S)); register_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_S)); register_code16(LCTL(KC_S));
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_S))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_S)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_S)); break;
    }
    dance_state[7].step = 0;
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
};
