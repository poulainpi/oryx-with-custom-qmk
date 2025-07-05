bool is_oneshot_cancel_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(3, KC_DELETE):
        if (record->event.pressed) return false;
        if (record->tap.count > 0 && record->tap.keycode == KC_DELETE) {
            return false;
        }
        return true;
    case LT(4, KC_SPACE):
        if (record->event.pressed) return false;
        if (record->tap.count > 0 && record->tap.keycode == KC_SPACE) {
            return false;
        }
        return true;
    case TD(DANCE_2):
        if (record->event.pressed) return false;
        return (record->tap.count == 0);
    default:
        return false;
    }
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
