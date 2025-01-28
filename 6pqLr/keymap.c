#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#include "features/achordion.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_NO,          MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_LCTL, KC_K),MT(MOD_LALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TD(DANCE_0),    
                                                    KC_BSPC,        KC_TAB,                                         KC_ENTER,       LT(1,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_LBRC,        KC_NO,          KC_ESCAPE,      KC_PAGE_UP,     KC_PSCR,        RGB_VAI,                                        KC_AUDIO_VOL_UP,KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_F12,         
    KC_RBRC,        KC_NO,          KC_HOME,        KC_PGDN,        KC_END,         RGB_VAD,                                        KC_AUDIO_VOL_DOWN,KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          LCTL(KC_W),     KC_NO,          KC_NO,          LCTL(KC_T),                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          LCTL(KC_A),     KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          LCTL(KC_Z),     KC_NO,          LCTL(KC_C),     LCTL(KC_V),     KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_NO
  ),
  [3] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        TD(DANCE_1),    
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_BSPC,        KC_LEFT_CTRL,                                   KC_ENTER,       KC_SPACE
  ),
};

const uint16_t PROGMEM combo0[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_F), MT(MOD_RSFT, KC_J), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LALT(KC_TAB)),
    COMBO(combo1, KC_CAPS),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM -50;
        case KC_Z:
            return TAPPING_TERM + 200;
        case KC_P:
            return TAPPING_TERM + 200;
        case MT(MOD_RSFT, KC_J):
            return TAPPING_TERM -50;
        case KC_SLASH:
            return TAPPING_TERM + 200;
        case KC_END:
            return TAPPING_TERM + 50;
        case KC_LEFT:
            return TAPPING_TERM + 50;
        case TD(DANCE_1):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255} },

    [1] = { {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,153,255}, {0,0,0}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,153,255}, {0,153,255}, {0,153,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255}, {0,153,255} },

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
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

static tap dance_state[2];

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


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_HOLD: layer_move(3); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_HOLD: layer_move(0); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
};

//BACKSPACE OVERRIDE 
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
//Bracket Override
const key_override_t parenthesis1_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LCBR);
const key_override_t parenthesis2_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_LCBR);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL // Null terminate the array of overrides! 
};