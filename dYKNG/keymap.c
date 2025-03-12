#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      RALT(KC_EQUAL), RALT(KC_SCLN),  KC_BSPC,        KC_DELETE,      KC_ENTER,                                       KC_DELETE,      KC_GRAVE,       KC_CIRC,        KC_TRANSPARENT, KC_RIGHT_ALT,   TG(3),          
    KC_TAB,         KC_B,           KC_F,           KC_L,           KC_K,           KC_Q,                                           KC_P,           KC_G,           KC_O,           KC_U,           KC_COMMA,       KC_F12,         
    KC_LEFT_SHIFT,  KC_N,           KC_S,           KC_H,           KC_T,           KC_M,                                           KC_Y,           KC_C,           KC_A,           KC_E,           KC_I,           KC_SCLN,        
    KC_LEFT_GUI,    MT(MOD_LALT, KC_X),KC_V,           KC_J,           KC_D,           KC_Z,                                           KC_QUOTE,       KC_W,           KC_UNDS,        KC_SLASH,       MT(MOD_LALT, KC_DOT),KC_RIGHT_CTRL,  
                                                    LT(1,KC_R),     MT(MOD_LCTL, KC_BSPC),                                MT(MOD_LSFT, KC_ENTER),LT(2,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_DLR,         KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_PLUS,                                        KC_EQUAL,       KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_TRANSPARENT, KC_F12,         
    KC_BSPC,        KC_0,           KC_1,           KC_2,           KC_3,           KC_4,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_PERC,        
    KC_LEFT_GUI,    MT(MOD_LALT, KC_GRAVE),KC_BSLS,        KC_LABK,        KC_RABK,        KC_EXLM,                                        KC_DQUO,        KC_PIPE,        KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD,        RGB_VAD,        RGB_VAI,                                        HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_TRANSPARENT, KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_MEDIA_STOP,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_BSLS,        KC_RIGHT_ALT,   KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_M,           KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_GUI,    KC_G,           KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_CTRL,                                   KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_LCTL, KC_BSPC), KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LCTL, KC_BSPC), KC_L, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LCTL(KC_C)),
    COMBO(combo1, LCTL(KC_V)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [3] = { {138,190,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {235,242,230}, {0,0,0}, {0,0,0}, {0,0,0}, {235,242,230}, {235,242,230}, {232,17,221}, {235,242,230}, {0,0,0}, {138,190,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {235,242,230}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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



