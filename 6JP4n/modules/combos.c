const uint16_t PROGMEM combo0_eng[] = { KC_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo0_rus[] = { RU_EN, RU_GHE, RU_SHA, COMBO_END};
const uint16_t PROGMEM combo1[]     = { KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo2_eng[] = { KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo2_rus[] = { RU_GHE,         RU_SHA,         RU_SHCH, COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_RALT, KC_L), COMBO_END};
const uint16_t PROGMEM combo4_eng[] = { MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), LT(7, KC_G), COMBO_END};
const uint16_t PROGMEM combo4_rus[] = { MT(MOD_LSFT, RU_VE), MT(MOD_LCTL, RU_A), LT(8, RU_PE), COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), COMBO_END};
const uint16_t PROGMEM combo6_eng[] = { LT(9, KC_W), KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo6_rus[] = { LT(10, RU_TSE), RU_U, RU_KA, COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo9_eng[] = { KC_N, KC_M, KC_F22, COMBO_END};
const uint16_t PROGMEM combo9_rus[] = { RU_TE, RU_SOFT, RU_BE, COMBO_END};
const uint16_t PROGMEM combo10_eng[] = { KC_F22, KC_F23, KC_F24, COMBO_END};
const uint16_t PROGMEM combo10_rus[] = { RU_BE, RU_YU, RU_YO, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo0_eng, KC_HOME),
    COMBO(combo0_rus, KC_HOME),
    COMBO(combo1, KC_END),
    COMBO(combo2_eng, LANG_SWITCH_COMBO_ACTION),
    COMBO(combo2_rus, LANG_SWITCH_COMBO_ACTION),
    COMBO(combo3, KC_ENTER),
    COMBO(combo4_eng, CW_TOGG),
    COMBO(combo4_rus, CW_TOGG),
    COMBO(combo5, KC_CAPS),
    COMBO(combo6_eng, OS_AWARE_COPY),
    COMBO(combo6_rus, OS_AWARE_COPY),
    COMBO(combo7, OS_AWARE_PASTE),
    COMBO(combo8, OS_AWARE_CUT),
    COMBO(combo9_eng, OS_AWARE_UNDO),
    COMBO(combo9_rus, OS_AWARE_UNDO),
    COMBO(combo10_eng, OS_AWARE_REDO),
    COMBO(combo10_rus, OS_AWARE_REDO),
};
