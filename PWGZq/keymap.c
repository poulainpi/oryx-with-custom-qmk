#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_152_255_255,
  HSV_88_218_204,
  HSV_34_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  MAC_MISSION_CONTROL,
};



#define DUAL_FUNC_0 LT(23, KC_6)
#define DUAL_FUNC_1 LT(31, KC_F1)
#define DUAL_FUNC_2 LT(17, KC_F)
#define DUAL_FUNC_3 LT(22, KC_F18)
#define DUAL_FUNC_4 LT(22, KC_F14)
#define DUAL_FUNC_5 LT(25, KC_F15)
#define DUAL_FUNC_6 LT(17, KC_F14)
#define DUAL_FUNC_7 LT(23, KC_T)
#define DUAL_FUNC_8 LT(32, KC_0)
#define DUAL_FUNC_9 LT(19, KC_M)
#define DUAL_FUNC_10 LT(29, KC_7)
#define DUAL_FUNC_11 LT(28, KC_0)
#define DUAL_FUNC_12 LT(23, KC_F9)
#define DUAL_FUNC_13 LT(18, KC_F20)
#define DUAL_FUNC_14 LT(32, KC_F22)
#define DUAL_FUNC_15 LT(19, KC_F20)
#define DUAL_FUNC_16 LT(21, KC_M)
#define DUAL_FUNC_17 LT(19, KC_N)
#define DUAL_FUNC_18 LT(21, KC_D)
#define DUAL_FUNC_19 LT(17, KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    DUAL_FUNC_0,    KC_Q,           DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,                                    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    TT(5),          MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),LT(2, KC_F),    DUAL_FUNC_5,                                    KC_H,           LT(3, KC_J),    MT(MOD_LSFT, KC_K),MT(MOD_LALT, KC_L),MT(MOD_LCTL, KC_SCLN),KC_QUOTE,       
    TT(1),          DUAL_FUNC_6,    DUAL_FUNC_7,    DUAL_FUNC_8,    DUAL_FUNC_9,    DUAL_FUNC_10,                                   KC_N,           DUAL_FUNC_12,   KC_COMMA,       KC_DOT,         KC_SLASH,       KC_MINUS,       
    KC_HYPR,        KC_MEH,         CW_TOGG,        KC_TAB,         DUAL_FUNC_11,   KC_SPACE,                                       DUAL_FUNC_13,   DUAL_FUNC_14,   RCTL(RSFT(KC_TAB)),DUAL_FUNC_15,   KC_BSLS,        KC_RIGHT_GUI,   
                                                    TT(4),          KC_MS_BTN1,                                     KC_MS_BTN2,     TT(4)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F,           DUAL_FUNC_16,   KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_S),LT(2, KC_T),    KC_TRANSPARENT,                                 KC_M,           LT(3, KC_N),    MT(MOD_RSFT, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RCTL, KC_O),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_17,   DUAL_FUNC_18,                                   KC_K,           DUAL_FUNC_19,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    TO(0),          KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     KC_EQUAL,       
    KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_KP_ASTERISK, KC_BSLS,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_KP_SLASH,    KC_MINUS,       
    KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0,           KC_0,           KC_DOT,         KC_KP_ENTER,    QK_LLCK,        
                                                    TO(0),          KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
  [3] = LAYOUT_voyager(
    QK_BOOT,        KC_AUDIO_VOL_UP,KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_SLD,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SYSTEM_SLEEP,KC_AUDIO_VOL_DOWN,KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAI,        KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SYSTEM_WAKE, KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_INSERT,                                      KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAD,        KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SYSTEM_POWER,MAC_MISSION_CONTROL,KC_WWW_BACK,    KC_WWW_HOME,    KC_WWW_FORWARD, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, HSV_152_255_255,HSV_88_218_204, HSV_34_255_255, QK_LLCK,        
                                                    TO(0),          KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PIPE,        KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_LCBR,        KC_RCBR,        QK_LLCK,        
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

const uint16_t PROGMEM combo0[] = { KC_P, KC_EQUAL, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LCTL, KC_SCLN), KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_SLASH, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_BSLS, KC_RIGHT_GUI, COMBO_END};
const uint16_t PROGMEM combo4[] = { DUAL_FUNC_0, KC_Q, COMBO_END};
const uint16_t PROGMEM combo5[] = { DUAL_FUNC_0, KC_Q, COMBO_END};
const uint16_t PROGMEM combo6[] = { TT(1), DUAL_FUNC_0, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_HYPR, KC_MEH, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_HYPR, KC_MEH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, ST_MACRO_0),
    COMBO(combo1, KC_TRANSPARENT),
    COMBO(combo2, KC_TRANSPARENT),
    COMBO(combo3, ST_MACRO_1),
    COMBO(combo4, ST_MACRO_2),
    COMBO(combo5, KC_TRANSPARENT),
    COMBO(combo6, ST_MACRO_3),
    COMBO(combo7, ST_MACRO_4),
    COMBO(combo8, KC_TRANSPARENT),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QUOTE:
            return TAPPING_TERM -100;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {88,218,204}, {142,255,255}, {0,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {88,218,204}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {88,218,204}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {88,218,204} },

    [1] = { {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233}, {131,164,233} },

    [2] = { {212,217,252}, {102,163,255}, {102,163,255}, {102,163,255}, {212,217,252}, {212,217,252}, {212,217,252}, {102,163,255}, {102,163,255}, {102,163,255}, {212,217,252}, {212,217,252}, {212,217,252}, {102,163,255}, {102,163,255}, {102,163,255}, {212,217,252}, {212,217,252}, {212,217,252}, {102,163,255}, {102,163,255}, {102,163,255}, {212,217,252}, {212,217,252}, {0,255,255}, {212,217,252}, {212,217,252}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {212,217,252}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {212,217,252}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {212,217,252}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,255,255}, {212,217,252}, {0,255,255} },

    [3] = { {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {0,255,255}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,214,201}, {142,255,255}, {88,218,204}, {34,255,255}, {0,255,255}, {142,214,201}, {0,255,255} },

    [4] = { {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {45,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,255,255}, {34,255,255}, {34,255,255} },

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
      SEND_STRING(SS_LSFT(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_B));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_E));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_H));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_I));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(KC_DELETE)));
        } else {
          unregister_code16(LALT(LCTL(KC_DELETE)));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_W);
        } else {
          unregister_code16(KC_W);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_HASH);
        } else {
          unregister_code16(KC_HASH);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_E);
        } else {
          unregister_code16(KC_E);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DELETE);
        } else {
          unregister_code16(KC_DELETE);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_R);
        } else {
          unregister_code16(KC_R);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_5)));
        } else {
          unregister_code16(LCTL(LSFT(KC_5)));
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_T);
        } else {
          unregister_code16(KC_T);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(KC_L));
        } else {
          unregister_code16(LGUI(KC_L));
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_G);
        } else {
          unregister_code16(KC_G);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_F));
        } else {
          unregister_code16(LCTL(KC_F));
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Z);
        } else {
          unregister_code16(KC_Z);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_Z));
        } else {
          unregister_code16(LCTL(KC_Z));
        }  
      }  
      return false;
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_X);
        } else {
          unregister_code16(KC_X);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_X));
        } else {
          unregister_code16(LCTL(KC_X));
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_C);
        } else {
          unregister_code16(KC_C);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_C));
        } else {
          unregister_code16(LCTL(KC_C));
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_V));
        } else {
          unregister_code16(LCTL(KC_V));
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_B);
        } else {
          unregister_code16(KC_B);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_B));
        } else {
          unregister_code16(LCTL(KC_B));
        }  
      }  
      return false;
    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ENTER);
        } else {
          unregister_code16(KC_ENTER);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_ENTER));
        } else {
          unregister_code16(LSFT(KC_ENTER));
        }  
      }  
      return false;
    case DUAL_FUNC_12:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_M);
        } else {
          unregister_code16(KC_M);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PSCR);
        } else {
          unregister_code16(KC_PSCR);
        }  
      }  
      return false;
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_BSPC);
        } else {
          unregister_code16(KC_BSPC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_BSPC));
        } else {
          unregister_code16(LCTL(KC_BSPC));
        }  
      }  
      return false;
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DELETE);
        } else {
          unregister_code16(KC_DELETE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(RCTL(KC_DELETE));
        } else {
          unregister_code16(RCTL(KC_DELETE));
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(KC_TAB));
        } else {
          unregister_code16(LALT(KC_TAB));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_TAB));
        } else {
          unregister_code16(LSFT(KC_TAB));
        }  
      }  
      return false;
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_P);
        } else {
          unregister_code16(KC_P);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_5)));
        } else {
          unregister_code16(LCTL(LSFT(KC_5)));
        }  
      }  
      return false;
    case DUAL_FUNC_17:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_D);
        } else {
          unregister_code16(KC_D);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_V));
        } else {
          unregister_code16(LCTL(KC_V));
        }  
      }  
      return false;
    case DUAL_FUNC_18:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_F));
        } else {
          unregister_code16(LCTL(KC_F));
        }  
      }  
      return false;
    case DUAL_FUNC_19:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_H);
        } else {
          unregister_code16(KC_H);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PSCR);
        } else {
          unregister_code16(KC_PSCR);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_152_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(152,255,255);
      }
      return false;
    case HSV_88_218_204:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(88,218,204);
      }
      return false;
    case HSV_34_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(34,255,255);
      }
      return false;
  }
  return true;
}


