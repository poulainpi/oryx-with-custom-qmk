const uint16_t PROGMEM cmb_home_grp[]  = { KC_NUM,         KC_F,           KC_O, COMBO_END};
const uint16_t PROGMEM cmb_home_rus[]  = { RU_EN, RU_GHE, RU_SHA, COMBO_END};

const uint16_t PROGMEM cmb_end_grp[]   = { KC_O,           KC_U,           KC_J, COMBO_END};
const uint16_t PROGMEM cmb_end_rus[]   = { RU_SHA,         RU_SHCH,        RU_ZE, COMBO_END};

const uint16_t PROGMEM cmb_lngsw_grp[] = { KC_F,           KC_O,           KC_U, COMBO_END};
const uint16_t PROGMEM cmb_lngsw_rus[] = { RU_GHE,         RU_SHA,         RU_SHCH, COMBO_END};

const uint16_t PROGMEM cmb_enter_grp[] = { KC_H,           KC_A,           KC_E, COMBO_END};
const uint16_t PROGMEM cmb_enter_rus[] = { RU_O,           RU_EL,          RU_DE, COMBO_END};
const uint16_t PROGMEM cmb_enter_tbl[] = { KC_4,           KC_5,           KC_6, COMBO_END};

const uint16_t PROGMEM cmb_togg_grp[]  = { KC_N,           KC_S, COMBO_END};
const uint16_t PROGMEM cmb_togg_rus[]  = { RU_EF,          RU_A, COMBO_END};

const uint16_t PROGMEM cmb_caps_grp[]  = { KC_N,           KC_G, COMBO_END};
const uint16_t PROGMEM cmb_caps_rus[]  = { RU_EF,          RU_PE, COMBO_END};


const uint16_t PROGMEM cmb_copy_grp[]  = { KC_R,           KC_L,     COMBO_END};
const uint16_t PROGMEM cmb_copy_rus[]  = { RU_YERU,        RU_TSE,   COMBO_END};
const uint16_t PROGMEM cmb_copy_tbl[]  = { ST_MACRO_4,     ST_MACRO_1, COMBO_END};

const uint16_t PROGMEM cmb_paste_grp[] = { KC_T,           KC_D,       COMBO_END};
const uint16_t PROGMEM cmb_paste_rus[] = { RU_VE,          RU_U,       COMBO_END};
const uint16_t PROGMEM cmb_paste_tbl[] = { ST_MACRO_2,     ST_MACRO_5, COMBO_END};

const uint16_t PROGMEM cmb_cut_grp[]   = { KC_R,  KC_L, KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_cut_rus[]   = { RU_YERU, RU_TSE, RU_VE,  RU_U, COMBO_END};


const uint16_t PROGMEM cmb_undo_grp[]  = { KC_P,           KC_F22,         KC_F23, COMBO_END};
const uint16_t PROGMEM cmb_undo_rus[]  = { RU_SOFT,        RU_BE,          RU_YU, COMBO_END};

const uint16_t PROGMEM cmb_redo_grp[]  = { KC_F22,         KC_F23,         KC_F24, COMBO_END};
const uint16_t PROGMEM cmb_redo_rus[]  = { RU_BE,          RU_YU,          RU_YO, COMBO_END};

const uint16_t PROGMEM cmb_voice_grp[] = { KC_Y,           KC_H,           KC_A, COMBO_END};
const uint16_t PROGMEM cmb_voice_rus[] = { RU_ER,          RU_O,           RU_EL, COMBO_END};

const uint16_t PROGMEM cmb_tab_grp[]   = { KC_R,           KC_T,           KC_S, COMBO_END};
const uint16_t PROGMEM cmb_tab_rus[]   = { RU_YERU,        RU_VE,          RU_A, COMBO_END};

const uint16_t PROGMEM cmb_shift_grp_left[]   = { KC_N,           KC_R,           KC_T, COMBO_END};
const uint16_t PROGMEM cmb_shift_grp_right[]  = { KC_A,           KC_E,           KC_I, COMBO_END};
const uint16_t PROGMEM cmb_shift_rus_left[]   = { RU_EF,          RU_YERU,        RU_VE, COMBO_END};
const uint16_t PROGMEM cmb_shift_rus_right[]  = { RU_EL,          RU_DE,          RU_ZHE, COMBO_END};

const uint16_t PROGMEM cmb_cshift_grp[] = { KC_N,           KC_R,           KC_T,           KC_S, COMBO_END};
const uint16_t PROGMEM cmb_cshift_rus[] = { RU_EF,          RU_YERU,        RU_VE,          RU_A, COMBO_END};

const uint16_t PROGMEM cmb_smile_grp[] = { KC_B,            KC_Z, COMBO_END};
const uint16_t PROGMEM cmb_smile_rus[] = { RU_SHTI,         RU_IE, COMBO_END};

const uint16_t PROGMEM cmb_vim_grp[] = { KC_Y,            KC_I, COMBO_END};

const uint16_t PROGMEM combo_alt_tab_grp[] = { KC_H,           KC_A,           KC_E,           KC_I, COMBO_END };
const uint16_t PROGMEM combo_alt_tab_eng[] = { RU_O,           RU_EL,          RU_DE,          RU_ZHE, COMBO_END };

const uint16_t PROGMEM combo_select_all_grp[] = { KC_N,           KC_B, COMBO_END };
const uint16_t PROGMEM combo_select_all_eng[] = { RU_EF,           RU_SHTI, COMBO_END };

const uint16_t PROGMEM combo_em_dash_grp[] = { KC_UNDS,           KC_MINUS, COMBO_END };
const uint16_t PROGMEM combo_em_dash_eng[] = { RU_UNDS,           RU_MINS, COMBO_END };

const uint16_t PROGMEM combo_enter_grp[] = { KC_R, KC_S, COMBO_END };
const uint16_t PROGMEM combo_enter_rus[] = { RU_YERU, RU_A, COMBO_END };


enum combo_events {
    COMBO_EM_DASH,
    COMBO_EN_DASH,
    CMB_ENTER_GR,
    CMB_ENTER_RU,
    CMB_LNG_SWCH_GR,
    CMB_LNG_SWCH_RU,
};


combo_t key_combos[] = {
    COMBO(cmb_home_grp, KC_HOME),
    COMBO(cmb_home_rus, KC_HOME),

    COMBO(cmb_end_grp, KC_END),
    COMBO(cmb_end_rus, KC_END),

    //COMBO(cmb_lngsw_grp, LANG_SWITCH_COMBO_ACTION),
    //COMBO(cmb_lngsw_rus, LANG_SWITCH_COMBO_ACTION),

    COMBO(cmb_enter_grp, KC_ENTER),
    COMBO(cmb_enter_rus, KC_ENTER),
    COMBO(cmb_enter_tbl, KC_ENTER),

    COMBO(cmb_togg_grp, CW_TOGG),
    COMBO(cmb_togg_rus, CW_TOGG),

    COMBO(cmb_caps_grp, KC_CAPS),
    COMBO(cmb_caps_rus, KC_CAPS),


    COMBO(cmb_copy_grp, OS_AWARE_COPY),  
    COMBO(cmb_copy_rus, OS_AWARE_COPY),
    COMBO(cmb_copy_tbl, OS_AWARE_COPY),  

    COMBO(cmb_paste_grp, OS_AWARE_PASTE),
    COMBO(cmb_paste_rus, OS_AWARE_PASTE),
    COMBO(cmb_paste_tbl, OS_AWARE_PASTE),

    COMBO(cmb_cut_grp, OS_AWARE_CUT),
    COMBO(cmb_cut_rus, OS_AWARE_CUT),


    COMBO(cmb_undo_grp, OS_AWARE_UNDO),
    COMBO(cmb_undo_rus, OS_AWARE_UNDO),

    COMBO(cmb_redo_grp, OS_AWARE_REDO),
    COMBO(cmb_redo_rus, OS_AWARE_REDO),

    COMBO(cmb_voice_grp, OS_AWARE_VOICE),
    COMBO(cmb_voice_rus, OS_AWARE_VOICE),

    COMBO(cmb_tab_grp, KC_TAB),
    COMBO(cmb_tab_rus, KC_TAB),

    COMBO(cmb_shift_grp_left, KC_LEFT_SHIFT),
    COMBO(cmb_shift_grp_right, KC_LEFT_SHIFT),
    COMBO(cmb_shift_rus_left, KC_LEFT_SHIFT),
    COMBO(cmb_shift_rus_right, KC_LEFT_SHIFT),

    COMBO(cmb_cshift_grp, C(KC_LEFT_SHIFT)),
    COMBO(cmb_cshift_rus, C(KC_LEFT_SHIFT)),

    COMBO(cmb_smile_grp, MO(9)),
    COMBO(cmb_smile_rus, MO(10)),

    COMBO(cmb_vim_grp, OSL(6)),

    COMBO(combo_alt_tab_grp, ALT_TAB),
    COMBO(combo_alt_tab_eng, ALT_TAB),

    COMBO(combo_select_all_grp, SELECT_ALL),
    COMBO(combo_select_all_eng, SELECT_ALL),

    [COMBO_EM_DASH] = COMBO_ACTION(combo_em_dash_grp),
    [COMBO_EN_DASH] = COMBO_ACTION(combo_em_dash_eng),

    [CMB_ENTER_GR]   = COMBO_ACTION(combo_enter_grp),
    [CMB_ENTER_RU]   = COMBO_ACTION(combo_enter_rus),

    [CMB_LNG_SWCH_GR]    = COMBO_ACTION(cmb_lngsw_grp),
    [CMB_LNG_SWCH_RU]    = COMBO_ACTION(cmb_lngsw_rus),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;

    switch (combo_index) {
        
        case COMBO_EM_DASH:
            if (pressed) {
                register_unicode(EM_DASH);
            }
            break;
        
        case COMBO_EN_DASH:
            if (pressed) {
                register_unicode(EN_DASH);
            }
            break;
        
        case CMB_ENTER_GR:
        case CMB_ENTER_RU:
            if (pressed) {
                tap_code16(KC_ENTER);
            }
            break;
        
        case CMB_LNG_SWCH_GR:
        case CMB_LNG_SWCH_RU:
            if (pressed) {
                uint8_t current_highest_layer = get_highest_layer(layer_state);
        
                if (current_highest_layer == QMK_LAYER_ENG) {
                    layer_move(QMK_LAYER_RUS);
                    SEND_STRING(SS_LCTL(SS_LSFT("2")));
                } else {
                    layer_move(QMK_LAYER_ENG);
                    SEND_STRING(SS_LCTL(SS_LSFT("1")));
                }            
            }
            break;
        
    }
}
