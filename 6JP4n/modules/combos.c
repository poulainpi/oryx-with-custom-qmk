const uint16_t PROGMEM c_home_rus[] = { RU_EN, RU_GHE, RU_SHA, COMBO_END};
const uint16_t PROGMEM c_home_grp[] = { KC_NUM,         KC_F,           KC_O, COMBO_END};

const uint16_t PROGMEM c_end_rus[] = { RU_SHA,         RU_SHCH,        RU_ZE, COMBO_END};
const uint16_t PROGMEM c_end_grp[] = { KC_O,           KC_U,           KC_J, COMBO_END};

const uint16_t PROGMEM c_langsw_rus[] = { RU_GHE, RU_SHA, RU_SHCH, COMBO_END};
const uint16_t PROGMEM c_langsw_grp[] = { KC_F, KC_O, KC_U, COMBO_END};

const uint16_t PROGMEM c_enter_rus[] = { MT(MOD_RCTL, RU_O),MT(MOD_RSFT, RU_EL),MT(MOD_RALT, RU_DE), COMBO_END};
const uint16_t PROGMEM c_enter_grp[] = { MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A),MT(MOD_RALT, KC_E), COMBO_END};
const uint16_t PROGMEM c_enter_tbl[] = { KC_4,           KC_5,           KC_6, COMBO_END};

const uint16_t PROGMEM c_togg_rus[] = { RU_EF,          MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE), COMBO_END};
const uint16_t PROGMEM c_togg_grp[] = { KC_N,           MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T), COMBO_END};

const uint16_t PROGMEM c_caps_rus[] = { MT(MOD_LSFT, RU_VE), MT(MOD_LCTL, RU_A), RU_PE, COMBO_END};
const uint16_t PROGMEM c_caps_grp[] = { MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S),KC_G, COMBO_END};


const uint16_t PROGMEM c_copy_grp[] = { MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T), COMBO_END};
const uint16_t PROGMEM c_copy_rus[] = { MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE), COMBO_END};
const uint16_t PROGMEM c_copy_tbl[] = { ST_MACRO_4,     ST_MACRO_5, COMBO_END};

const uint16_t PROGMEM c_paste_grp[] = { MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S, COMBO_END};
const uint16_t PROGMEM c_paste_rus[] = { MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE),MT(MOD_LCTL, RU_A), COMBO_END};
const uint16_t PROGMEM c_paste_tbl[] = { ST_MACRO_4,     ST_MACRO_5,     KC_F23, COMBO_END};

const uint16_t PROGMEM c_cut_grp[] = { MT(MOD_LGUI, KC_N),MT(MOD_LALT, KC_R), COMBO_END};
const uint16_t PROGMEM c_cut_rus[] = { MT(MOD_LGUI, RU_EF),MT(MOD_LALT, RU_YERU), COMBO_END};


const uint16_t PROGMEM c_undo_grp[] = { KC_K,           KC_P,           KC_F22, COMBO_END};
const uint16_t PROGMEM c_undo_rus[] = { RU_TE, RU_SOFT, RU_BE, COMBO_END};

const uint16_t PROGMEM c_redo_rus[] = { RU_BE,          RU_YU,          RU_YO, COMBO_END};
const uint16_t PROGMEM c_redo_grp[] = { KC_F22,         KC_F23,         KC_F24, COMBO_END};

const uint16_t PROGMEM c_voice_rus[] = { RU_ER,          MT(MOD_RCTL, RU_O),MT(MOD_RSFT, RU_EL), COMBO_END};
const uint16_t PROGMEM c_voice_grp[] = { KC_Y,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A), COMBO_END};

const uint16_t PROGMEM c_tab_grp[] = { MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S), COMBO_END};
const uint16_t PROGMEM c_tab_rus[] = { MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE),MT(MOD_LCTL, RU_A)), COMBO_END};


combo_t key_combos[] = {
    COMBO(c_home_rus, KC_HOME),
    COMBO(c_home_grp, KC_HOME),

    COMBO(c_end_rus, KC_END),
    COMBO(c_end_grp, KC_END),

    COMBO(c_langsw_rus, LANG_SWITCH_COMBO_ACTION),
    COMBO(c_langsw_grp, LANG_SWITCH_COMBO_ACTION),

    COMBO(c_enter_rus, KC_ENTER),
    COMBO(c_enter_grp, KC_ENTER),
    COMBO(c_enter_tbl, KC_ENTER),

    COMBO(c_togg_rus, CW_TOGG),
    COMBO(c_togg_grp, CW_TOGG),

    COMBO(c_caps_rus, KC_CAPS),
    COMBO(c_caps_grp, KC_CAPS),


    COMBO(c_copy_rus, OS_AWARE_COPY),
    COMBO(c_copy_grp, OS_AWARE_COPY),  
    COMBO(c_copy_tbl, OS_AWARE_COPY),  

    COMBO(c_paste_rus, OS_AWARE_PASTE),
    COMBO(c_paste_grp, OS_AWARE_PASTE),
    COMBO(c_paste_tbl, OS_AWARE_PASTE),

    COMBO(c_cut_rus, OS_AWARE_CUT),
    COMBO(c_cut_grp, OS_AWARE_CUT),


    COMBO(c_undo_rus, OS_AWARE_UNDO),
    COMBO(c_undo_grp, OS_AWARE_UNDO),

    COMBO(c_redo_rus, OS_AWARE_REDO),
    COMBO(c_redo_grp, OS_AWARE_REDO),

    COMBO(c_voice_rus, OS_AWARE_VOICE),
    COMBO(c_voice_grp, OS_AWARE_VOICE),

    COMBO(c_tab_rus, KC_TAB),
    COMBO(c_tab_grp, KC_TAB),
};
