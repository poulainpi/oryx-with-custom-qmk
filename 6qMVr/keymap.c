#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

#define DUAL_FUNC_0 LT(10, KC_F22)
#define DUAL_FUNC_1 LT(1, KC_F17)
#define DUAL_FUNC_2 LT(5, KC_F18)
#define DUAL_FUNC_3 LT(1, KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT_ALT,                                    KC_LEFT_ALT,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_LEFT_CTRL,                                   KC_LEFT_CTRL,   KC_J,           KC_L,           KC_U,           KC_Y,           LALT(LCTL(KC_TAB)),LSFT(KC_TAB),   
    KC_LEFT,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_LEFT_SHIFT,                                                                  KC_LEFT_SHIFT,  KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           LCTL(KC_TAB),   
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           DUAL_FUNC_0,    DUAL_FUNC_1,    TD(DANCE_1),    KC_RIGHT,       
    KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_E),     KC_UP,          OSL(3),                                                                                                         KC_ENTER,       KC_DOWN,        LGUI(KC_T),     KC_TRANSPARENT, KC_LEFT_GUI,    TG(1),          
    KC_SPACE,       KC_LEFT_CTRL,   LSFT(KC_LEFT_CTRL),                KC_APPLICATION, KC_LEFT_ALT,    OSL(2)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_W),     KC_MS_BTN1,     KC_MS_WH_UP,    KC_MS_BTN2,     LALT(LCTL(KC_TAB)),LSFT(KC_TAB),                                   KC_TRANSPARENT, KC_F3,          LSFT(KC_F3),    KC_F12,         KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F3,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, LCTL(KC_Y),     LCTL(KC_TAB),                                                                   KC_TRANSPARENT, RCTL(KC_Y),     KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, 
    TO(0),          KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     TD(DANCE_2),    LGUI(KC_V),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    LALT(KC_F4),    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          LSFT(KC_SPACE),                                 LCTL(KC_SPACE), KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,      
    KC_TRANSPARENT, DUAL_FUNC_2,    DUAL_FUNC_3,    KC_HASH,        ES_LA_35,       ES_LA_34,       KC_TRANSPARENT,                                 KC_TRANSPARENT, ES_LA_33,       ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ES_LA_03,       KC_TRANSPARENT, 
    ES_LA_29,       KC_KP_PLUS,     KC_KP_MINUS,    KC_TRANSPARENT, ES_LA_09,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_ASTERISK, KC_KP_SLASH,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LSFT(KC_PSCR),  KC_PSCR,        ES_LA_16,       ES_LA_15,       KC_TRANSPARENT, KC_TRANSPARENT, 
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_9,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_7,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_8,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
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
    [0] = { {179,204,237}, {21,240,240}, {68,223,241}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {130,216,237}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {68,223,241}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {52,217,255}, {52,217,255}, {52,217,255}, {139,172,246}, {97,255,244}, {139,172,246}, {139,172,246}, {179,204,237}, {21,240,240}, {21,240,240}, {68,223,241}, {139,172,246}, {139,172,246}, {213,238,244}, {139,172,246}, {179,204,237}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {179,204,237}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {179,204,237}, {130,216,237}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {68,223,241}, {139,172,246}, {139,172,246}, {139,172,246}, {139,172,246}, {52,217,255}, {52,217,255}, {52,217,255}, {139,172,246}, {97,255,244}, {139,172,246}, {139,172,246} },

    [1] = { {0,0,0}, {223,255,245}, {0,0,0}, {1,243,224}, {0,0,0}, {138,28,239}, {0,211,241}, {87,218,204}, {194,247,253}, {0,0,0}, {138,28,239}, {41,255,255}, {41,255,255}, {194,247,253}, {19,243,244}, {138,28,239}, {41,255,255}, {41,255,255}, {194,247,253}, {130,216,237}, {138,28,239}, {41,255,255}, {41,255,255}, {194,247,253}, {0,0,0}, {138,28,239}, {97,255,244}, {178,255,248}, {194,247,253}, {0,0,0}, {223,255,245}, {223,255,245}, {0,0,0}, {97,255,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {1,243,224}, {138,28,239}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {138,28,239}, {41,255,255}, {41,255,255}, {0,0,0}, {19,243,244}, {138,28,239}, {0,211,241}, {41,255,255}, {0,0,0}, {130,216,237}, {138,28,239}, {47,255,246}, {0,0,0}, {0,0,0}, {0,0,0}, {138,28,239}, {87,218,204}, {178,255,248}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {97,255,244}, {0,0,0}, {0,0,0} },

    [2] = { {0,183,238}, {0,0,0}, {195,237,237}, {0,0,0}, {87,250,255}, {143,5,140}, {31,255,255}, {195,237,237}, {0,0,0}, {0,0,0}, {143,5,140}, {0,0,255}, {195,237,237}, {0,0,0}, {0,0,0}, {143,5,140}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {143,5,140}, {0,0,255}, {85,203,158}, {0,0,0}, {0,0,0}, {143,5,140}, {0,0,255}, {0,0,0}, {0,0,0}, {139,172,246}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {195,237,237}, {0,0,0}, {0,0,0}, {143,5,140}, {0,0,0}, {195,237,237}, {0,0,0}, {0,0,0}, {143,5,140}, {31,255,255}, {0,0,0}, {30,230,245}, {0,0,0}, {143,5,140}, {31,255,255}, {0,0,0}, {30,230,245}, {0,0,0}, {143,5,140}, {31,255,255}, {31,255,255}, {0,0,255}, {0,0,0}, {143,5,140}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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

static tap dance_state[3];

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
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(ES_LA_24);
        tap_code16(ES_LA_24);
        tap_code16(ES_LA_24);
    }
    if(state->count > 3) {
        tap_code16(ES_LA_24);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(ES_LA_24); break;
        case DOUBLE_TAP: register_code16(ES_LA_08); break;
        case DOUBLE_SINGLE_TAP: tap_code16(ES_LA_24); register_code16(ES_LA_24);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(ES_LA_24); break;
        case DOUBLE_TAP: unregister_code16(ES_LA_08); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(ES_LA_24); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_V)); register_code16(LCTL(KC_V));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_V))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_BSLS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_8))SS_DELAY(100)  SS_RSFT(SS_TAP(X_9))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL)SS_DELAY(100)  SS_RSFT(SS_TAP(X_MINUS))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(100)  SS_TAP(X_BSLS)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(100)  SS_TAP(X_1)SS_DELAY(100)  SS_TAP(X_1)SS_DELAY(100)  SS_TAP(X_0)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(100)  SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(100)  SS_TAP(X_P)SS_DELAY(100)  SS_TAP(X_R)SS_DELAY(100)  SS_TAP(X_E)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(100)  SS_TAP(X_1)SS_DELAY(100)  SS_TAP(X_2)SS_DELAY(100)  SS_TAP(X_0)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LEFT_GUI)SS_DELAY(100)  SS_TAP(X_R));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R))SS_DELAY(100)  SS_TAP(X_P)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(ES_LA_13);
        } else {
          unregister_code16(ES_LA_13);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(ES_LA_11);
        } else {
          unregister_code16(ES_LA_11);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(ES_LA_38);
        } else {
          unregister_code16(ES_LA_38);
        }
      } else {
        if (record->event.pressed) {
          register_code16(ES_LA_25);
        } else {
          unregister_code16(ES_LA_25);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(ES_LA_37);
        } else {
          unregister_code16(ES_LA_37);
        }
      } else {
        if (record->event.pressed) {
          register_code16(ES_LA_28);
        } else {
          unregister_code16(ES_LA_28);
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

