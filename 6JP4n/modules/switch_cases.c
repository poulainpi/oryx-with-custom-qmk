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
    case OS_AWARE_COPY:
      if (record->event.pressed) {
#if defined(OS_DETECTION_ENABLE)
        os_variant_t host_os = detected_host_os();
        if (host_os == OS_MACOS |
| host_os == OS_IOS) {
          SEND_STRING(SS_LGUI("c")); // Cmd+C для macOS/iOS
        } else {
          SEND_STRING(SS_LCTL("c")); // Ctrl+C для Windows/Linux/других
        }
#else
        // Фоллбэк, если OS_DETECTION_ENABLE не включен (например, всегда Ctrl+C)
        //SEND_STRING(SS_LCTL("c"));
	SEND_STRING("nicht!");
#endif
      }
      return false; // Важно, чтобы QMK не обрабатывал этот кейкод дальше

    return false;
