#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
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
  DANCE_15,
  DANCE_16,
  DANCE_17,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    LGUI(DE_MINS),  LGUI(KC_0),     LGUI(DE_PLUS),  KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(9),          
    KC_TRANSPARENT, KC_P,           KC_U,           KC_ESCAPE,      DE_MINS,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT, 
    CW_TOGG,        MT(MOD_LCTL, KC_H),MT(MOD_LALT, KC_I),MT(MOD_LGUI, KC_E),KC_A,           KC_O,                                           KC_D,           KC_T,           MT(MOD_RGUI, KC_R),MT(MOD_LALT, KC_N),MT(MOD_RCTL, KC_S),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_QUOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT, 
                                                    OSL(1),         OSM(MOD_LSFT),                                  OSL(2),         LT(3,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_SECT,        DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        TD(DANCE_3),    MT(MOD_LALT, DE_MINS),TD(DANCE_4),    KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_UNDS,        DE_BSLS,        DE_PIPE,        KC_TRANSPARENT, DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_5),    TD(DANCE_6)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(KC_LEFT),  LGUI(KC_UP),    KC_TRANSPARENT, LALT(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_ESCAPE),MT(MOD_LALT, DE_SS),TD(DANCE_7),    DE_AE,          DE_OE,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_DOWN),  LGUI(KC_LEFT),  LGUI(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    OSL(8),         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_MINS,        KC_7,           KC_8,           KC_9,           DE_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_COLN,        KC_1,           KC_2,           KC_3,           KC_0,                                           KC_MAC_UNDO,    KC_MAC_COPY,    KC_MAC_PASTE,   KC_MAC_CUT,     KC_TRANSPARENT, KC_APPLICATION, 
    KC_TRANSPARENT, DE_PLUS,        KC_4,           KC_5,           KC_6,           DE_SLSH,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_COMMA,       KC_DOT,                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TD(DANCE_8),    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(9),          
    CW_TOGG,        KC_P,           KC_U,           KC_ESCAPE,      DE_MINS,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT, 
    CW_TOGG,        MT(MOD_LGUI, KC_H),MT(MOD_LALT, KC_I),MT(MOD_LCTL, KC_E),KC_A,           KC_O,                                           KC_D,           KC_T,           MT(MOD_RCTL, KC_R),MT(MOD_LALT, KC_N),MT(MOD_RGUI, KC_S),LALT(KC_TAB),   
    KC_TRANSPARENT, KC_K,           DE_Y,           KC_DOT,         DE_QUOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           LALT(LSFT(KC_TAB)),
                                                    OSL(6),         OSM(MOD_LSFT),                                  OSL(5),         LT(7,KC_SPACE)
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_LEFT),  KC_PAGE_UP,     KC_TRANSPARENT, LCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_ESCAPE),MT(MOD_LALT, DE_SS),TD(DANCE_9),    DE_AE,          DE_OE,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ENTER,       KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGDN,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    OSL(8),         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_SECT,        DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_10),   TD(DANCE_11),   TD(DANCE_12),   DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        TD(DANCE_13),   MT(MOD_LALT, DE_MINS),TD(DANCE_14),   KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_UNDS,        DE_BSLS,        DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_15),   TD(DANCE_16)
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_MINS,        KC_7,           KC_8,           KC_9,           DE_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_COLN,        KC_1,           KC_2,           KC_3,           KC_0,                                           KC_PC_UNDO,     KC_PC_COPY,     KC_PC_PASTE,    KC_PC_CUT,      KC_TRANSPARENT, KC_APPLICATION, 
    KC_TRANSPARENT, DE_PLUS,        KC_4,           KC_5,           KC_6,           DE_SLSH,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_COMMA,       KC_DOT,                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TAB,         KC_F7,          KC_F8,          KC_F9,          KC_F12,                                         DE_ASTR,        KC_7,           KC_8,           KC_9,           DE_MINS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F11,                                         KC_0,           KC_1,           KC_2,           KC_3,           TD(DANCE_17),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ENTER,       KC_F4,          KC_F5,          KC_F6,          KC_F10,                                         DE_SLSH,        KC_4,           KC_5,           KC_6,           DE_PLUS,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DOT,         KC_COMMA
  ),
  [9] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        TO(4),          KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_SPD,        RGB_SPI,                                        KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  RGB_HUD,        RGB_HUI,                                        KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { OSM(MOD_LSFT), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { OSM(MOD_LSFT), DE_QUOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { OSM(MOD_LSFT), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo3[] = { OSM(MOD_LSFT), DE_QUOT, COMBO_END};

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

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,238,159}, {0,0,0}, {68,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 4:
      set_layer_color(4);
      break;
    case 9:
      set_layer_color(9);
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

static tap dance_state[18];

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
        tap_code16(DE_AT);
        tap_code16(DE_AT);
        tap_code16(DE_AT);
    }
    if(state->count > 3) {
        tap_code16(DE_AT);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(DE_AT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(DE_AT); register_code16(DE_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_AT); register_code16(DE_AT);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(DE_AT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_AT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_SLSH);
        tap_code16(DE_SLSH);
        tap_code16(DE_SLSH);
    }
    if(state->count > 3) {
        tap_code16(DE_SLSH);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(DE_SLSH); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(DE_SLSH); register_code16(DE_SLSH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_SLSH); register_code16(DE_SLSH);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(DE_SLSH); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(DE_SLSH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_SLSH); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
    }
    if(state->count > 3) {
        tap_code16(DE_LCBR);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(DE_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(DE_LCBR); register_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_LCBR); register_code16(DE_LCBR);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(DE_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LCBR); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_RPRN);
        tap_code16(DE_RPRN);
        tap_code16(DE_RPRN);
    }
    if(state->count > 3) {
        tap_code16(DE_RPRN);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(DE_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(DE_RPRN); register_code16(DE_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_RPRN); register_code16(DE_RPRN);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(DE_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(DE_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_RPRN); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
    }
    if(state->count > 3) {
        tap_code16(DE_COLN);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(DE_COLN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(DE_COLN); register_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_COLN); register_code16(DE_COLN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(DE_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_COLN); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_BSPC)); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_BSPC)); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_DELETE)); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_DELETE)); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_EURO);
        tap_code16(DE_EURO);
        tap_code16(DE_EURO);
    }
    if(state->count > 3) {
        tap_code16(DE_EURO);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(DE_EURO); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(DE_EURO); register_code16(DE_EURO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_EURO); register_code16(DE_EURO);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(DE_EURO); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(DE_EURO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_EURO); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_EURO);
        tap_code16(DE_EURO);
        tap_code16(DE_EURO);
    }
    if(state->count > 3) {
        tap_code16(DE_EURO);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(DE_EURO); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(DE_EURO); register_code16(DE_EURO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_EURO); register_code16(DE_EURO);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(DE_EURO); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_EURO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_EURO); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_AT);
        tap_code16(DE_AT);
        tap_code16(DE_AT);
    }
    if(state->count > 3) {
        tap_code16(DE_AT);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(DE_AT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(DE_AT); register_code16(DE_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_AT); register_code16(DE_AT);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(DE_AT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(DE_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_AT); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_SLSH);
        tap_code16(DE_SLSH);
        tap_code16(DE_SLSH);
    }
    if(state->count > 3) {
        tap_code16(DE_SLSH);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(DE_SLSH); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(DE_SLSH); register_code16(DE_SLSH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_SLSH); register_code16(DE_SLSH);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(DE_SLSH); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(DE_SLSH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_SLSH); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
    }
    if(state->count > 3) {
        tap_code16(DE_LCBR);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(DE_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(DE_LCBR); register_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_LCBR); register_code16(DE_LCBR);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(DE_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LCBR); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_RPRN);
        tap_code16(DE_RPRN);
        tap_code16(DE_RPRN);
    }
    if(state->count > 3) {
        tap_code16(DE_RPRN);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(DE_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(DE_RPRN); register_code16(DE_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_RPRN); register_code16(DE_RPRN);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(DE_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_RPRN); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
    }
    if(state->count > 3) {
        tap_code16(DE_COLN);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(DE_COLN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(DE_COLN); register_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_COLN); register_code16(DE_COLN);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(DE_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_COLN); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(LALT(KC_BSPC)); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_BSPC)); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(LALT(KC_DELETE)); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_DELETE)); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
        tap_code16(DE_COLN);
    }
    if(state->count > 3) {
        tap_code16(DE_COLN);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(DE_COLN); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(DE_COLN); register_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_COLN); register_code16(DE_COLN);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(DE_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(DE_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_COLN); break;
    }
    dance_state[17].step = 0;
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
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
};
