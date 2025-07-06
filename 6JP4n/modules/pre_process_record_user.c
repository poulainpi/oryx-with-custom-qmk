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



bool is_oneshot_cancel_key(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        // На даун: печатаем, например, "D:0xABCD\n"
        SEND_STRING("D:");
        send_hex_16(keycode);
        SEND_STRING("\n");
    } else {
        // На релиз: печатаем "U:0xABCD tc=2 st=0x12\n"
        SEND_STRING("U:");
        send_hex_16(keycode);
        SEND_STRING(" tc=");
        send_hex(record->tap.count);
        SEND_STRING(" st=");
        send_hex_32(layer_state);
        SEND_STRING("\n");
    }
    
    if (record->event.pressed) return false;

    if (keycode == TD(DANCE_2)) {
        return (record->tap.count == 0);
    }

    if ((keycode & QK_LAYER_TAP) == QK_LAYER_TAP) {
        uint8_t layer = (keycode >> 8) & 0xFF;
        uint8_t kc    =  keycode        & 0xFF;
        if (record->tap.count > 0) return false;
        if ((kc == KC_DELETE || kc == KC_SPACE) && layer_state_is(layer)) {
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
