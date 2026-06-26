#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(7, KC_W)
#define DUAL_FUNC_1 LT(11, KC_F5)
#define DUAL_FUNC_2 LT(11, KC_F12)
#define DUAL_FUNC_3 LT(14, KC_F11)
#define DUAL_FUNC_4 LT(3, KC_I)
#define DUAL_FUNC_5 LT(13, KC_F)
#define DUAL_FUNC_6 LT(5, KC_A)
#define DUAL_FUNC_7 LT(4, KC_F15)
#define DUAL_FUNC_8 LT(12, KC_F10)
#define DUAL_FUNC_9 LT(10, KC_I)
#define DUAL_FUNC_10 LT(12, KC_0)
#define DUAL_FUNC_11 LT(2, KC_J)
#define DUAL_FUNC_12 LT(6, KC_Y)
#define DUAL_FUNC_13 LT(4, KC_M)
#define DUAL_FUNC_14 LT(9, KC_T)
#define DUAL_FUNC_15 LT(9, KC_L)
#define DUAL_FUNC_16 LT(3, KC_S)
#define DUAL_FUNC_17 LT(12, KC_F19)
#define DUAL_FUNC_18 LT(11, KC_2)
#define DUAL_FUNC_19 LT(15, KC_F22)
#define DUAL_FUNC_20 LT(3, KC_G)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,    DUAL_FUNC_5,    DUAL_FUNC_6,                                    DUAL_FUNC_11,   DUAL_FUNC_12,   DUAL_FUNC_13,   DUAL_FUNC_14,   DUAL_FUNC_15,   DUAL_FUNC_16,   DUAL_FUNC_17,   
    KC_TRANSPARENT, DUAL_FUNC_7,    DUAL_FUNC_8,    DUAL_FUNC_9,    KC_P,           KC_Y,           CW_TOGG,                                        KC_DELETE,      KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           DUAL_FUNC_18,   
    KC_TAB,         KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_LEFT_SHIFT,                                                                  KC_RIGHT_SHIFT, KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           DUAL_FUNC_19,   
    KC_CAPS,        DUAL_FUNC_10,   KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           DUAL_FUNC_20,   
    KC_LEFT_CTRL,   KC_GRAVE,       KC_TAB,         KC_UP,          KC_DOWN,        KC_ESCAPE,                                                                                                      MO(1),          KC_LEFT,        KC_RIGHT,       KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  
    KC_SPACE,       KC_LEFT_ALT,    KC_LEFT_GUI,                    KC_RIGHT_GUI,   KC_ENTER,       KC_BSPC
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_MS_JIGGLER_TOGGLE,KC_TRANSPARENT, KC_LANGUAGE_3,                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RIGHT:
            return TAPPING_TERM + 95;
        default:
            return TAPPING_TERM;
    }
}


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
    [0] = { {192,249,135}, {255,249,135}, {50,249,134}, {50,249,134}, {109,230,115}, {192,249,135}, {192,249,135}, {151,255,152}, {192,249,135}, {50,249,134}, {192,249,135}, {192,249,135}, {151,255,152}, {151,255,152}, {50,249,134}, {192,249,135}, {192,249,135}, {151,255,152}, {151,255,152}, {0,0,255}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {0,0,255}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {192,249,135}, {109,230,115}, {109,230,115}, {131,255,255}, {109,230,115}, {109,230,115}, {255,249,135}, {192,249,135}, {192,249,135}, {192,249,135}, {192,249,135}, {27,244,123}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {27,244,123}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {27,244,123}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {0,0,255}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {0,0,255}, {192,249,135}, {151,255,152}, {151,255,152}, {151,255,152}, {192,249,135}, {109,230,115}, {109,230,115}, {131,255,255}, {113,230,115}, {109,230,115}, {255,249,135} },

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

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DLR);
        } else {
          unregister_code16(KC_DLR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_TILD);
        } else {
          unregister_code16(KC_TILD);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AMPR);
        } else {
          unregister_code16(KC_AMPR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PERC);
        } else {
          unregister_code16(KC_PERC);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_7 : KC_LBRC);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_7 : KC_LBRC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_7);
        } else {
          unregister_code16(KC_7);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_5 : KC_LCBR);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_5 : KC_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_5);
        } else {
          unregister_code16(KC_5);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_3 : KC_RCBR);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_3 : KC_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_3);
        } else {
          unregister_code16(KC_3);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_1 : KC_LPRN);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_1 : KC_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_1);
        } else {
          unregister_code16(KC_1);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_9 : KC_EQUAL);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_9 : KC_EQUAL);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_9);
        } else {
          unregister_code16(KC_9);
        }  
      }  
      return false;
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUOTE);
        } else {
          unregister_code16(KC_QUOTE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DQUO);
        } else {
          unregister_code16(KC_DQUO);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SCLN);
        } else {
          unregister_code16(KC_SCLN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_COLN);
        } else {
          unregister_code16(KC_COLN);
        }  
      }  
      return false;
    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_0 : KC_ASTR);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_0 : KC_ASTR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_0);
        } else {
          unregister_code16(KC_0);
        }  
      }  
      return false;
    case DUAL_FUNC_12:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_2 : KC_RPRN);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_2 : KC_RPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_2);
        } else {
          unregister_code16(KC_2);
        }  
      }  
      return false;
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_4 : KC_PLUS);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_4 : KC_PLUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_4);
        } else {
          unregister_code16(KC_4);
        }  
      }  
      return false;
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_6 : KC_RBRC);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_6 : KC_RBRC);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_6);
        } else {
          unregister_code16(KC_6);
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(host_keyboard_led_state().caps_lock ? KC_8 : KC_EXLM);
        } else {
          unregister_code16(host_keyboard_led_state().caps_lock ? KC_8 : KC_EXLM);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_8);
        } else {
          unregister_code16(KC_8);
        }  
      }  
      return false;
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_HASH);
        } else {
          unregister_code16(KC_HASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_GRAVE);
        } else {
          unregister_code16(KC_GRAVE);
        }  
      }  
      return false;
    case DUAL_FUNC_17:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AT);
        } else {
          unregister_code16(KC_AT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_CIRC);
        } else {
          unregister_code16(KC_CIRC);
        }  
      }  
      return false;
    case DUAL_FUNC_18:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SLASH);
        } else {
          unregister_code16(KC_SLASH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }  
      }  
      return false;
    case DUAL_FUNC_19:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_MINUS);
        } else {
          unregister_code16(KC_MINUS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }  
      }  
      return false;
    case DUAL_FUNC_20:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_BSLS);
        } else {
          unregister_code16(KC_BSLS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_PIPE);
        } else {
          unregister_code16(KC_PIPE);
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

