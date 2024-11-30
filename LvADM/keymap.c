#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"

// DHB:
/* specify which layer will be associated with which LED */
#define LED_INDICATOR_RED_LAYER 3
#define LED_INDICATOR_GREEN_LAYER 2
#define LED_INDICATOR_BLUE_LAYER 1

/* specify which USB Host Status will be associated with which LED */
#define LED_INDICATOR_STATE_RED caps_lock
#define LED_INDICATOR_STATE_GREEN num_lock
#define LED_INDICATOR_STATE_BLUE scroll_lock

/* specify the PWM values for each LED at each brightness */
#define LED_INDICATOR_RED_DIM 8
#define LED_INDICATOR_RED_HALF 96
#define LED_INDICATOR_RED_FULL 228
#define LED_INDICATOR_GREEN_DIM 2
#define LED_INDICATOR_GREEN_HALF 48
#define LED_INDICATOR_GREEN_FULL 160
#define LED_INDICATOR_BLUE_DIM 16
#define LED_INDICATOR_BLUE_HALF 172
#define LED_INDICATOR_BLUE_FULL 255

// DHB:
bool led_update_user(led_t led_state) {
    uint8_t layer = biton32(layer_state);
    uint8_t red = 0, green = 0, blue = 0;

    if (layer == LED_INDICATOR_RED_LAYER) red = LED_INDICATOR_RED_HALF;
    if (led_state.LED_INDICATOR_STATE_RED) red = LED_INDICATOR_RED_DIM;
    if ((led_state.LED_INDICATOR_STATE_RED) && layer == LED_INDICATOR_RED_LAYER) red = LED_INDICATOR_RED_FULL;

    if (layer == LED_INDICATOR_GREEN_LAYER) green = LED_INDICATOR_GREEN_HALF;
    if (led_state.LED_INDICATOR_STATE_GREEN) green = LED_INDICATOR_GREEN_DIM;
    if (led_state.LED_INDICATOR_STATE_GREEN && layer == LED_INDICATOR_GREEN_LAYER) green = LED_INDICATOR_GREEN_FULL;

    if (layer == LED_INDICATOR_BLUE_LAYER) blue = LED_INDICATOR_BLUE_HALF;
    if (led_state.LED_INDICATOR_STATE.BLUE) blue = LED_INDICATOR_BLUE_DIM;
    if (led_state.LED_INDICATOR_STATE.BLUE && layer == LED_INDICATOR_BLUE_LAYER) blue = LED_INDICATOR_BLUE_FULL;

    if (red | green | blue) {
        ergodox_board_led_on();
    } else {
        ergodox_board_led_off();
    }
    if (red) {
        ergodox_right_led_1_on();
        ergodox_right_led_1_set(red);
    }
    if (green) {
        ergodox_right_led_2_on();
        ergodox_right_led_2_set(green);
    }
    if (blue) {
        ergodox_right_led_3_on();
        ergodox_right_led_3_set(blue);
    }
    return true;
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        ; // nothing more to do
    }
    return res;
}

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_CALCULATOR,                                  KC_TAB,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_LCBR,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_QUOTE,       KC_ENTER,
    SC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,                                       KC_NUM,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          SC_RSPC,
    KC_LEFT_CTRL,   MO(1),          KC_LEFT_GUI,    KC_LEFT_ALT,    LT(3,KC_GRAVE),                                                                                                 MT(MOD_RALT, KC_SCLN),MT(MOD_RCTL, KC_SLASH),KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                    KC_PSCR,        KC_APPLICATION, KC_LBRC,        KC_RBRC,
                                                                                                                    KC_HOME,        KC_PAGE_UP,
                                                                                    KC_SPACE,       KC_BSPC,        KC_END,         KC_PGDN,        KC_DELETE,      KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    LCTL(LSFT(KC_ESCAPE)),KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
    KC_TRANSPARENT, LALT(KC_F4),    LCTL(KC_F4),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(2),                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT,
    KC_RCBR,        KC_TRANSPARENT, KC_SCRL,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_CAPS,        KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_TRANSPARENT, KC_ENTER,                                       TG(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_HOME,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(3),                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK,    KC_TRANSPARENT, KC_WWW_FORWARD,
                                                                                                    KC_SCRL,        KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_SLD,
                                                                                                                    RGB_VAI,        RGB_HUI,
                                                                                    KC_TRANSPARENT, RGB_TOG,        RGB_VAD,        RGB_HUD,        KC_INSERT,      KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CALCULATOR,                                  KC_NUM,         KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_KP_MINUS,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT, KC_KP_SLASH,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ASTERISK, KC_TRANSPARENT, KC_KP_ENTER,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_0,        KC_KP_COMMA,    KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_SLASH,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_AUDIO_VOL_UP,KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_UP,    KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_AUDIO_VOL_DOWN,KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_MS_ACCEL1,                                                                   KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,
    KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_BTN3,     KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MS_ACCEL0,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,
                                                                                                    KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,
                                                                                                                    KC_MS_WH_UP,    KC_MEDIA_NEXT_TRACK,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE
  ),
};




rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
    
    //not sure if the new layer_state will be available yet?
    led_update_user(host_keyboard_led_state());

    switch (layer) {
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(171,255, rgblight_config.val);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(99,255, rgblight_config.val);
        }
        break;
      case 3:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(1,255, rgblight_config.val);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}



