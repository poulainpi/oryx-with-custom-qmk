
    // if (
    //     !update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record)
    // || !update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record)
    // || !update_oneshot(&os_alt_state,  KC_LALT, OS_ALT,  keycode, record)
    // || !update_oneshot(&os_cmd_state,  KC_LCMD, OS_CMD,  keycode, record)
    // ) {
    //     return false;
    // }


    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
        keycode, record
    ); 

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
