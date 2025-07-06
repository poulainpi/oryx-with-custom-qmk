#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif
#include "./modules/define.c"

#include "print.h"   // для uprintf()
#include "debug.h"   // для dprintf() и других макросов DEBUG_*

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
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
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  MAC_SIRI,
  #include "./modules/custom_keycodes.c"
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      LALT(LCTL(KC_1)),LALT(LCTL(KC_2)),LALT(LCTL(KC_3)),LALT(LCTL(KC_4)),TD(DANCE_0),                                    TD(DANCE_1),    AS_DOWN,        AS_TOGG,        AS_UP,          AS_RPT,         AS_OFF,         
    KC_TRANSPARENT, KC_B,           LT(9, KC_L),    KC_D,           KC_W,           KC_Z,                                           KC_NUM,         KC_F,           KC_O,           KC_U,           KC_J,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_N,           KC_R,           KC_T,           KC_S,           KC_G,                                           KC_Y,           KC_H,           KC_A,           KC_E,           KC_I,           KC_TRANSPARENT, 
    TT(1),          KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,                                           KC_K,           KC_P,           KC_F22,         KC_F23,         KC_F24,         TT(2),          
                                                    LT(7, KC_BSPC), LT(3, KC_DELETE),                                TD(DANCE_2),    LT(4, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RU_SHTI,        LT(10, RU_TSE), RU_U,           RU_KA,          RU_IE,                                          RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,          
    KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,                                          RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,           
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_YO,          RU_HARD,        
                                                    LT(8, KC_BSPC), KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     KC_F22,         KC_NO,                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_NO,          ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     KC_F23,         ST_MACRO_6,                                     KC_SPACE,       KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     KC_F24,         ST_MACRO_10,                                    KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PLUS,        KC_MINUS,       KC_SLASH,       KC_ASTR,        KC_NO,          KC_NO,          
    KC_ENTER,       KC_LABK,        KC_RABK,        KC_LPRN,        KC_RPRN,        KC_NO,                                          KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_TAB,         OS_CMD,         OS_ALT,         OS_SHFT,        OS_CTRL,        KC_NO,                                          KC_NO,          KC_4,           KC_5,           KC_6,           KC_DOT,         KC_NO,          
    KC_LEFT_GUI,    KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_NO,                                          KC_DOT,         KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [4] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_UP,KC_NO,          KC_NO,          QK_BOOT,        
    KC_ENTER,       KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,MAC_SIRI,                                       KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          KC_NO,          
    KC_TAB,         OS_CMD,         OS_ALT,         OS_SHFT,        OS_CTRL,        KC_AUDIO_MUTE,                                  KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_LEFT_GUI,    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_DELETE,      LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_RIGHT)),KC_INSERT,      
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_NO,          LALT(LCTL(KC_1)),LALT(LCTL(KC_2)),LALT(LCTL(KC_3)),LALT(LCTL(KC_4)),KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_ENTER,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    KC_TAB,         OS_CMD,         OS_ALT,         OS_SHFT,        OS_CTRL,        KC_NO,                                          KC_NO,          OS_CTRL,        OS_SHFT,        OS_ALT,         OS_CMD,         KC_NO,          
    KC_LEFT_GUI,    KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_ESCAPE,      ST_MACRO_11,    ST_MACRO_12,    KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_COLN,        ST_MACRO_13,    ST_MACRO_14,    ST_MACRO_15,    KC_NO,          ST_MACRO_16,                                    ST_MACRO_18,    ST_MACRO_19,    KC_K,           ST_MACRO_20,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          ST_MACRO_17,                                    ST_MACRO_21,    KC_H,           KC_J,           KC_L,           KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TILD,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PERC,        KC_DLR,         KC_NO,          
    KC_GRAVE,       KC_LABK,        KC_RABK,        KC_LPRN,        KC_RPRN,        KC_NO,                                          KC_HASH,        KC_UNDS,        KC_MINUS,       KC_SLASH,       KC_BSLS,        KC_ASTR,        
    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    KC_SLASH,       KC_PIPE,                                        KC_AT,          KC_DOT,         KC_COMMA,       KC_EXLM,        KC_QUES,        KC_PLUS,        
    ST_MACRO_26,    KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_NO,                                          KC_QUOTE,       KC_DQUO,        KC_COLN,        KC_SCLN,        KC_EQUAL,       KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          RU_RUBL,        KC_NO,          RU_ASTR,        RU_PERC,        KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          RU_LPRN,        RU_RPRN,        KC_NO,                                          RU_NUM,         RU_UNDS,        RU_MINS,        RU_SLSH,        RU_BSLS,        RU_ASTR,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          RU_DOT,         RU_COMM,        RU_EXLM,        RU_QUES,        RU_PLUS,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          RU_DQUO,        RU_COLN,        RU_SCLN,        RU_EQL,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,                                          ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    ST_MACRO_30,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          ST_MACRO_31,    ST_MACRO_32,    ST_MACRO_33,    ST_MACRO_34,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          ST_MACRO_35,    ST_MACRO_36,    KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_Q:
            return g_tapping_term + 299;
        case KC_F24:
            return g_tapping_term + 299;
        case RU_YA:
            return g_tapping_term + 299;
        case RU_YO:
            return g_tapping_term + 299;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {18,255,101}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {205,255,255}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {205,255,255}, {18,255,101}, {18,255,101}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {18,255,101}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {18,255,101}, {74,255,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {3,255,255}, {3,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {11,255,255}, {11,255,255}, {28,255,255}, {28,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {172,255,255}, {172,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {205,255,255}, {0,0,0}, {205,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255} },

    [5] = { {0,0,0}, {40,218,204}, {31,218,204}, {17,218,204}, {7,218,204}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {51,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {51,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {51,255,255}, {3,255,255}, {3,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255}, {215,255,255}, {51,255,255}, {215,255,255}, {11,255,255}, {11,255,255}, {28,255,255}, {28,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {51,255,255}, {0,0,0}, {51,255,255}, {51,255,255}, {0,0,0}, {0,0,0}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0}, {51,255,255}, {51,255,255}, {51,255,255}, {51,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

static char hex_digit(uint8_t v) {
   return v < 10 ? '0' + v : 'A' + (v - 10);
}

static void send_hex16(uint16_t v) {
   char buf[5] = {0};
   for (int i = 0; i < 4; i++) {
       buf[i] = hex_digit((v >> ((3 - i)*4)) & 0xF);
   }
   SEND_STRING(buf);
}

// // Печатает 8-битное значение (0–255) в виде двух HEX цифр
// static void send_hex8(uint8_t v) {
//    char buf[3] = { hex_digit((v>>4)&0xF), hex_digit(v&0xF), 0 };
//    SEND_STRING(buf);
// }


bool is_oneshot_cancel_key(uint16_t keycode, keyrecord_t *record) {


    // if (record->event.pressed) {
    //    SEND_STRING("RELEASE code=0x");
    //    send_hex16(keycode);
    //    SEND_STRING(" tc=");
    //    send_hex8(record->tap.count);
    //    SEND_STRING("\n");
    // }



    if ((keycode & QK_LAYER_TAP) == QK_LAYER_TAP) {
      uint8_t layer = (keycode >> 8) & 0xFF;
      uint8_t kc    =  keycode        & 0xFF;
      if (record->tap.count > 0) return false;

        send_hex16(kc);
        SEND_STRING(" : ");
        send_hex16(KC_DELETE);
        SEND_STRING(" : ");
        send_hex16(KC_SPACE);
        SEND_STRING(" : ");
        send_hex16(layer);
        SEND_STRING(" : ");
        SEND_STRING(layer_state_is(layer) ? "1\n" : "0\n");
        SEND_STRING("\n");

        
      if ((kc == KC_DELETE || kc == KC_SPACE) && layer_state_is(layer)) {
        SEND_STRING("ooooooooooo");
        SEND_STRING("\n");

        return true;
      }
    }

    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LT(7, KC_BSPC):
    case LT(3, KC_DELETE):
    case TD(DANCE_2):
    case LT(4, KC_SPACE):
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

  
  switch (keycode) {
   #include "./modules/switch_cases.c"
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_1)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_6)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_6)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(10)  SS_TAP(X_F)SS_DELAY(10)  SS_TAP(X_I)SS_DELAY(10)  SS_TAP(X_N)SS_DELAY(10)  SS_TAP(X_D)SS_DELAY(10)  SS_TAP(X_B)SS_DELAY(10)  SS_TAP(X_Y)SS_DELAY(10)  SS_TAP(X_N)SS_DELAY(10)  SS_TAP(X_A)SS_DELAY(10)  SS_TAP(X_M)SS_DELAY(10)  SS_TAP(X_E)SS_DELAY(10)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_8)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_1)SS_DELAY(1)  SS_TAP(X_2)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0)SS_DELAY(1)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH)SS_DELAY(10)  SS_TAP(X_B)SS_DELAY(10)  SS_TAP(X_I)SS_DELAY(10)  SS_TAP(X_R)SS_DELAY(10)  SS_TAP(X_Z)SS_DELAY(10)  SS_TAP(X_H)SS_DELAY(10)  SS_TAP(X_A)SS_DELAY(10)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_Q)SS_DELAY(20)  SS_LSFT(SS_TAP(X_1))SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_W)SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_Q)SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_W)SS_DELAY(20)  SS_TAP(X_Q)SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(20)  SS_TAP(X_SPACE)SS_DELAY(20)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(10)  SS_TAP(X_G)SS_DELAY(10)  SS_TAP(X_G));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(10)  SS_TAP(X_T)SS_DELAY(10)  SS_TAP(X_B));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W))SS_DELAY(20)  SS_TAP(X_Q));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_S)SS_DELAY(20)  SS_TAP(X_P)SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(20)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(20)  SS_TAP(X_V)SS_DELAY(20)  SS_TAP(X_S)SS_DELAY(20)  SS_TAP(X_P)SS_DELAY(20)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_SPACE)SS_DELAY(10)  SS_LSFT(SS_TAP(X_GRAVE))SS_DELAY(10)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE))SS_DELAY(10)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_SPACE)SS_DELAY(10)  SS_TAP(X_DOT)SS_DELAY(10)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_8)SS_DELAY(10)  SS_TAP(X_MINUS)SS_DELAY(10)  SS_LSFT(SS_TAP(X_O)));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_TAP(X_MINUS)SS_DELAY(10)  SS_LSFT(SS_TAP(X_BSLS)));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_TAP(X_MINUS)SS_DELAY(10)  SS_TAP(X_BSLS));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_TAP(X_GRAVE)SS_DELAY(10)  SS_TAP(X_LBRC));
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_LSFT(SS_TAP(X_D)));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_LSFT(SS_TAP(X_0)));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_LSFT(SS_TAP(X_9)));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_TAP(X_MINUS)SS_DELAY(10)  SS_LSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_6))SS_DELAY(10)  SS_LSFT(SS_TAP(X_0)));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_6))SS_DELAY(10)  SS_LSFT(SS_TAP(X_9)));
    }
    break;
    case MAC_SIRI:
      HCS(0xCF);

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


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_HOLD: register_code16(LGUI(LSFT(KC_S))); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case DOUBLE_HOLD: unregister_code16(LGUI(LSFT(KC_S))); break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_HOLD: register_code16(KC_CALCULATOR); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case DOUBLE_HOLD: unregister_code16(KC_CALCULATOR); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_HOLD: layer_on(6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD:
          layer_off(5);
        break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
              case DOUBLE_HOLD: 
                layer_off(6);
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};

#include "./modules/combos.c"
