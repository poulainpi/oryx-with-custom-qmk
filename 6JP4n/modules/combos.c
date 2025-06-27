const uint16_t PROGMEM combo0_rus[] = { RU_EN, RU_GHE, RU_SHA, COMBO_END};
const uint16_t PROGMEM combo0_grp[] = { KC_NUM,         KC_F,           KC_O, COMBO_END};

const uint16_t PROGMEM combo1_rus[] = { RU_SHA,         RU_SHCH,        RU_ZE, COMBO_END};
const uint16_t PROGMEM combo1_grp[] = { KC_O,           KC_U,           KC_J, COMBO_END};

const uint16_t PROGMEM combo2_rus[] = { RU_GHE, RU_SHA, RU_SHCH, COMBO_END};
const uint16_t PROGMEM combo2_grp[] = { KC_F, KC_O, KC_U, COMBO_END};

const uint16_t PROGMEM combo3_rus[] = { MT(MOD_RCTL, RU_O),MT(MOD_RSFT, RU_EL),MT(MOD_RALT, RU_DE), COMBO_END};
const uint16_t PROGMEM combo3_grp[] = { MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A),MT(MOD_RALT, KC_E), COMBO_END};
const uint16_t PROGMEM combo3_tbl[] = { KC_4,           KC_5,           KC_6, COMBO_END};

const uint16_t PROGMEM combo4_rus[] = { RU_EF,          MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE), COMBO_END};
const uint16_t PROGMEM combo4_grp[] = { KC_N,           MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T), COMBO_END};

const uint16_t PROGMEM combo5_rus[] = { MT(MOD_LSFT, RU_VE), MT(MOD_LCTL, RU_A), RU_PE, COMBO_END};
const uint16_t PROGMEM combo5_grp[] = { MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S),KC_G, COMBO_END};


const uint16_t PROGMEM combo6_rus[] = { LT(10, RU_TSE), RU_U, RU_KA, COMBO_END};
const uint16_t PROGMEM combo6_grp[] = { LT(9, KC_L), KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM combo6_tbl[] = { ST_MACRO_1,     ST_MACRO_2,     KC_F22, COMBO_END};

const uint16_t PROGMEM combo7_rus[] = { MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE),MT(MOD_LCTL, RU_A), COMBO_END};
const uint16_t PROGMEM combo7_grp[] = { MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S), COMBO_END};
const uint16_t PROGMEM combo7_tbl[] = { ST_MACRO_4,     ST_MACRO_5,     KC_F23, COMBO_END};

const uint16_t PROGMEM combo8_rus[] = { RU_CHE,         RU_ES,          RU_EM, COMBO_END};
const uint16_t PROGMEM combo8_grp[] = { KC_X, KC_M, KC_C, COMBO_END};


const uint16_t PROGMEM combo9_rus[] = { RU_TE, RU_SOFT, RU_BE, COMBO_END};
const uint16_t PROGMEM combo9_grp[] = { KC_K,           KC_P,           KC_F22, COMBO_END};

const uint16_t PROGMEM combo10_rus[] = { RU_BE,          RU_YU,          MT(MOD_RGUI, RU_YO), COMBO_END};
const uint16_t PROGMEM combo10_grp[] = { KC_F22,         KC_F23,         MT(MOD_RGUI, KC_F24), COMBO_END};

const uint16_t PROGMEM combo11_rus[] = { RU_ER,          MT(MOD_RCTL, RU_O),MT(MOD_RSFT, RU_EL), COMBO_END};
const uint16_t PROGMEM combo11_grp[] = { KC_Y,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A), COMBO_END};


combo_t key_combos[] = {
    COMBO(combo0_rus, KC_HOME),
    COMBO(combo0_grp, KC_HOME),

    COMBO(combo1_rus, KC_END),
    COMBO(combo1_grp, KC_END),

    COMBO(combo2_rus, LANG_SWITCH_COMBO_ACTION),
    COMBO(combo2_grp, LANG_SWITCH_COMBO_ACTION),

    COMBO(combo3_rus, KC_ENTER),
    COMBO(combo3_grp, KC_ENTER),
    COMBO(combo3_tbl, KC_ENTER),

    COMBO(combo4_rus, CW_TOGG),
    COMBO(combo4_grp, CW_TOGG),

    COMBO(combo5_rus, KC_CAPS),
    COMBO(combo5_grp, KC_CAPS),


    COMBO(combo6_rus, OS_AWARE_COPY),
    COMBO(combo6_grp, OS_AWARE_COPY),  
    COMBO(combo6_tbl, OS_AWARE_COPY),  

    COMBO(combo7_rus, OS_AWARE_PASTE),
    COMBO(combo7_grp, OS_AWARE_PASTE),
    COMBO(combo7_tbl, OS_AWARE_PASTE),

    COMBO(combo8_rus, OS_AWARE_CUT),
    COMBO(combo8_grp, OS_AWARE_CUT),


    COMBO(combo9_rus, OS_AWARE_UNDO),
    COMBO(combo9_grp, OS_AWARE_UNDO),

    COMBO(combo10_rus, OS_AWARE_REDO),
    COMBO(combo10_grp, OS_AWARE_REDO),

    COMBO(combo11_rus, OS_AWARE_VOICE),
    COMBO(combo11_grp, OS_AWARE_VOICE),
};
