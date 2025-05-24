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
