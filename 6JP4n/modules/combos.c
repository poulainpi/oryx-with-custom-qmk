const uint16_t PROGMEM combo0[] = { KC_Y, LT(7, KC_U), KC_I, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo2[] = { LT(7, KC_U), KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_RALT, KC_L), COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), LT(7, KC_G), COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), COMBO_END};
const uint16_t PROGMEM combo6[] = { LT(10, KC_W), KC_E, LT(7, KC_R), COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_N, KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_COMMA, KC_DOT, KC_SLASH, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo0, KC_HOME),
    COMBO(combo1, KC_END),
    COMBO(combo2, LANG_SWITCH_COMBO_ACTION),
    COMBO(combo3, KC_ENTER),
    COMBO(combo4, CW_TOGG),
    COMBO(combo5, KC_CAPS),
    COMBO(combo6, OS_AWARE_COPY),
    COMBO(combo7, OS_AWARE_PASTE),
    COMBO(combo8, OS_AWARE_CUT),
    COMBO(combo9, OS_AWARE_UNDO),
    COMBO(combo10, OS_AWARE_REDO),
};
