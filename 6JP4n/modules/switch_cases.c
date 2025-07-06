    case LANG_SWITCH_COMBO_ACTION:
      if (record->event.pressed) {
        uint8_t current_highest_layer = get_highest_layer(layer_state);
        if (current_highest_layer == QMK_LAYER_ENG) {
            layer_move(QMK_LAYER_RUS);
            SEND_STRING(SS_LCTL(SS_LSFT("2")));
        } else {
            layer_move(QMK_LAYER_ENG);
            SEND_STRING(SS_LCTL(SS_LSFT("1")));
        }
    }
    return false;

    case OS_AWARE_COPY:
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
          SEND_STRING(SS_LGUI("c"));
        } else {
          SEND_STRING(SS_LCTL("c"));
        }
        SEND_STRING(SS_LCTL("c"));
      }
      return false; 

    case OS_AWARE_PASTE:
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
          SEND_STRING(SS_LGUI("v"));
        } else {
          SEND_STRING(SS_LCTL("v"));
        }
        SEND_STRING(SS_LCTL("v"));
      }
      return false;

    case OS_AWARE_CUT:	    
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
          SEND_STRING(SS_LGUI("x"));
        } else {
          SEND_STRING(SS_LCTL("x"));
        }
        SEND_STRING(SS_LCTL("x"));
      }
      return false; 

    case OS_AWARE_UNDO:	    
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
          SEND_STRING(SS_LGUI("z"));
        } else {
          SEND_STRING(SS_LCTL("z"));
        }
        SEND_STRING(SS_LCTL("z"));
      }
      return false; 

    case OS_AWARE_REDO:       
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
          SEND_STRING(SS_LGUI(SS_LSFT("z")));
        } else {
          SEND_STRING(SS_LCTL(SS_LSFT("z")));
        }
        SEND_STRING(SS_LCTL(SS_LSFT("z")));
      }
      return false;

    case OS_AWARE_VOICE:
      if (record->event.pressed) {
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS || host_os == OS_IOS) {
        tap_code16(MAC_SIRI);
          } else if (host_os == OS_WINDOWS) {
              SEND_STRING(SS_LGUI("h"));
          }
      }
      return false;

    case ALT_TAB:
      if (record->event.pressed) {
          register_code(KC_LALT);
          tap_code(KC_TAB);
          unregister_code(KC_LALT);
      }
      return false;