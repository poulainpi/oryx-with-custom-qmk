#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"
#include "report.h"
#include "i2c_master.h"
#include "os_detection.h"

enum i2c_keycodes {
  MOUSE_SCROLL_V = QK_USER_10,
  MOUSE_SCROLL_VH,
  MOUSE_SCROLL_V_HOLD,
};

#define I2C_TRACKBALL_ADDRESS 0x0A << 1

typedef struct __attribute__((packed)) {
    int16_t dx;
    int16_t dy;
} mouse_data_t;

void pointing_device_driver_init(void) {
    i2c_init();
}

bool is_scrolling_v = false;
bool is_scrolling_vh = false;
bool is_hold_scrolling_v = false;
#define SCROLL_CHUNK 50;
int scroll_comp_v = 0;
int scroll_comp_h = 0;

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
    mouse_data_t mouse_data = {0};
    i2c_status_t status = i2c_receive(I2C_TRACKBALL_ADDRESS, (uint8_t*)&mouse_data, sizeof(*&mouse_data), 100);
    if (status == I2C_STATUS_SUCCESS) {
        if (is_scrolling_v || is_scrolling_vh || is_hold_scrolling_v) {
            if (is_scrolling_vh) {
                scroll_comp_h -= mouse_data.dx;
                mouse_report.h = scroll_comp_h/SCROLL_CHUNK;
                scroll_comp_h = scroll_comp_h % SCROLL_CHUNK;
            }
            scroll_comp_v -= mouse_data.dy;
            mouse_report.v = scroll_comp_v/SCROLL_CHUNK;
            scroll_comp_v = scroll_comp_v % SCROLL_CHUNK
        } else {
            mouse_report.x = -mouse_data.dx;
            mouse_report.y = mouse_data.dy;
        }
    }
    #ifdef CONSOLE_ENABLE
      xprintf("X: %d, Y: %d\n", mouse_report.x, mouse_report.y);
    #endif
    return mouse_report;
}

uint16_t pointing_device_driver_get_cpi(void) {
    return 0;
}

void pointing_device_driver_set_cpi(uint16_t cpi) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSE_SCROLL_V:
      if (record->event.pressed) {
        is_scrolling_v = !is_scrolling_v;
      }
      return false;
    case MOUSE_SCROLL_VH:
      if (record->event.pressed) {
        is_scrolling_vh = !is_scrolling_vh;
      }
      return false;
    case MOUSE_SCROLL_V_HOLD:
      if (record->event.pressed) {
        is_hold_scrolling_v = true;
      } else {
        is_hold_scrolling_v = false;
      }
      return false;
  }
  return true;
}

// Shift+Backspace == Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

// "Remapping" keys 'cause ZSA won't let me put custom enums in Oryx -_-
#define KC_F24 MOUSE_SCROLL_V
#define KC_F23 MOUSE_SCROLL_VH
#define KC_F22 CG_SWAP
#define KC_F21 CG_NORM
#define KC_F20 MOUSE_SCROLL_V_HOLD

// ============================ END OVERRIDES ==================================

#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_245_245,
};



enum tap_dance_codes {
  DANCE_0,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_UP,                                          KC_LEFT,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DOWN,                                        KC_RIGHT,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    LT(1,KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_MS_BTN2,                                                                     KC_F24,         KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
    KC_LEFT_GUI,    MT(MOD_LCTL, KC_GRAVE),KC_LEFT_ALT,    TD(DANCE_0),    KC_F24,         LGUI(KC_SPACE),                                                                                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     MT(MOD_RALT, KC_LBRC),MT(MOD_RCTL, KC_RBRC),KC_RIGHT_GUI,   
    KC_SPACE,       KC_BSPC,        KC_MS_BTN1,                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_EXLM,        LALT(KC_RIGHT), KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_8,           KC_9,           KC_KP_0,        KC_F12,         
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_F24,         KC_TRANSPARENT,                                                                 KC_ENTER,       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ENTER,       KC_CAPS,        
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        LALT(KC_LEFT),                                  KC_AMPR,        KC_1,           KC_LABK,        KC_RABK,        KC_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_245_245,  KC_LABK,        KC_RABK,        KC_F24,                                                                                                         KC_TRANSPARENT, KC_MS_BTN3,     KC_F20,         RSFT(KC_MS_BTN3),KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_LEFT_ALT,    KC_MS_BTN3,     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_SHIFT, KC_RIGHT_CTRL,  KC_RIGHT_GUI,   KC_F24,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F21,         KC_F22,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F23,         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_K, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_L, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_LPRN, KC_LBRC, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_RPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_DLR, KC_CIRC, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_HASH, KC_PERC, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_DOWN, KC_1, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_UP, KC_LABK, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_RIGHT, KC_RABK, COMBO_END};
const uint16_t PROGMEM combo14[] = { KC_ENTER, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_SCLN, KC_SLASH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_LEFT_CTRL),
    COMBO(combo1, KC_LEFT_SHIFT),
    COMBO(combo2, KC_LEFT_ALT),
    COMBO(combo3, KC_LEFT_GUI),
    COMBO(combo4, KC_RIGHT_SHIFT),
    COMBO(combo5, KC_RIGHT_CTRL),
    COMBO(combo6, KC_RIGHT_ALT),
    COMBO(combo7, KC_LEFT_SHIFT),
    COMBO(combo8, KC_LEFT_ALT),
    COMBO(combo9, KC_LEFT_CTRL),
    COMBO(combo10, KC_LEFT_GUI),
    COMBO(combo11, KC_RIGHT_ALT),
    COMBO(combo12, KC_RIGHT_SHIFT),
    COMBO(combo13, KC_RIGHT_CTRL),
    COMBO(combo14, KC_RIGHT_GUI),
    COMBO(combo15, KC_RIGHT_GUI),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206}, {74,255,206} },

    [1] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255} },

    [2] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
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

static tap dance_state[1];

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
        tap_code16(LGUI(LSFT(KC_SPACE)));
        tap_code16(LGUI(LSFT(KC_SPACE)));
        tap_code16(LGUI(LSFT(KC_SPACE)));
    }
    if(state->count > 3) {
        tap_code16(LGUI(LSFT(KC_SPACE)));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LGUI(LSFT(KC_SPACE))); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_SPACE))); register_code16(LGUI(LSFT(KC_SPACE))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(LSFT(KC_SPACE))); register_code16(LGUI(LSFT(KC_SPACE)));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_SPACE))); break;
        case SINGLE_HOLD:
          layer_off(2);
        break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_SPACE))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(LSFT(KC_SPACE))); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

// Remove keymaps
#undef KC_F24
#undef KC_F23
#undef KC_F22
#undef KC_F21
#undef KC_F20