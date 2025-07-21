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

    CMB_COPY_GR,
    CMB_COPY_RU,
    CMB_COPY_TB,  

    CMB_PASTE_GR,
    CMB_PASTE_RU,
    CMB_PASTE_TB,

    CMB_CUT_GR,
    CMB_CUT_RU,


    CMB_UNDO_GR,
    CMB_UNDO_RU,

    CMB_REDO_GR,
    CMB_REDO_RU,

    CMB_VOICE_GR,
    CMB_VOICE_RU,

    CMB_ALT_TAB_GR,
    CMB_ALT_TAB_RU,

    CMB_SELECT_ALL_GR,
    CMB_CSELECT_ALL_RU,

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

    COMBO(cmb_enter_grp, KC_ENTER),
    COMBO(cmb_enter_rus, KC_ENTER),
    COMBO(cmb_enter_tbl, KC_ENTER),

    COMBO(cmb_togg_grp, CW_TOGG),
    COMBO(cmb_togg_rus, CW_TOGG),

    COMBO(cmb_caps_grp, KC_CAPS),
    COMBO(cmb_caps_rus, KC_CAPS),

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



    [CMB_COPY_GR] = COMBO_ACTION(cmb_copy_grp),  
    [CMB_COPY_RU] = COMBO_ACTION(cmb_copy_rus),
    [CMB_COPY_TB] = COMBO_ACTION(cmb_copy_tbl),  

    [CMB_PASTE_GR] = COMBO_ACTION(cmb_paste_grp),
    [CMB_PASTE_RU] = COMBO_ACTION(cmb_paste_rus),
    [CMB_PASTE_TB] = COMBO_ACTION(cmb_paste_tbl),

    [CMB_CUT_GR] = COMBO_ACTION(cmb_cut_grp),
    [CMB_CUT_RU] = COMBO_ACTION(cmb_cut_rus),


    [CMB_UNDO_GR] = COMBO_ACTION(cmb_undo_grp),
    [CMB_UNDO_RU] = COMBO_ACTION(cmb_undo_rus),

    [CMB_REDO_GR] = COMBO_ACTION(cmb_redo_grp),
    [CMB_REDO_RU] = COMBO_ACTION(cmb_redo_rus),

    [CMB_VOICE_GR] = COMBO_ACTION(cmb_voice_grp),
    [CMB_VOICE_RU] = COMBO_ACTION(cmb_voice_rus),

    [CMB_ALT_TAB_GR] = COMBO_ACTION(combo_alt_tab_grp),
    [CMB_ALT_TAB_RU] = COMBO_ACTION(combo_alt_tab_eng),

    [CMB_SELECT_ALL_GR] = COMBO_ACTION(combo_select_all_grpL),
    [CMB_CSELECT_ALL_RU] = COMBO_ACTION(combo_select_all_eng),

    [COMBO_EM_DASH] = COMBO_ACTION(combo_em_dash_grp),
    [COMBO_EN_DASH] = COMBO_ACTION(combo_em_dash_eng),

    //[CMB_ENTER_GR]   = COMBO_ACTION(combo_enter_grp),
    //[CMB_ENTER_RU]   = COMBO_ACTION(combo_enter_rus),

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
        
        //case CMB_ENTER_GR:
        //case CMB_ENTER_RU:
        //    if (pressed) {
        //        tap_code16(KC_ENTER);
        //    }
        //    break;

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

        case CMB_COPY_GR:
        case CMB_COPY_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI("c"));
                } else {
                  SEND_STRING(SS_LCTL("c"));
                }
            }
            break; 
   
        case CMB__PASTE_GR:
        case CMB__PASTE_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI("v"));
                } else {
                  SEND_STRING(SS_LCTL("v"));
                }
          }
          break;
    
        case CMB_CUT_GR:
        case CMB_CUT_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI("x"));
                } else {
                  SEND_STRING(SS_LCTL("x"));
                }
          }
          break;
    
        case CMB_UNDO_GR:
        case CMB_UNDO_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI("z"));
                } else {
                  SEND_STRING(SS_LCTL("z"));
                }
          }
          break;
    
        case CMB_REDO_GR:
        case CMB_REDO_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI(SS_LSFT("z")));
                } else {
                  SEND_STRING(SS_LCTL(SS_LSFT("z")));
                }    
          }
          break;
    
        case CMB_VOICE_GR:
        case CMB_VOICE_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(MAC_SIRI);
                } else  {
                    SEND_STRING(SS_LGUI("h"));
                }

            }
            break;

        case CMB_ALT_TAB_GR:
        case CMB_ALT_TAB_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    register_code(KC_LGUI);
                    tap_code(KC_TAB);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LALT);
                }
            }
            break;
    
        case CMB_SELECT_ALL_GR:
        case CMB_SELECT_RU:
            if (pressed) {
                os_variant_t host_os = detected_host_os();
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                  SEND_STRING(SS_LGUI("a"));
                } else {
                  SEND_STRING(SS_LCTL("a"));
                }    
            }
            break;       
        
        
        
        
        
        
    }
}
