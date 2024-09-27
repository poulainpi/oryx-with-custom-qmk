/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef TAPPING_TERM
#define TAPPING_TERM 225

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 5000

#define PERMISSIVE_HOLD

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define SERIAL_NUMBER "NY75B/WdzqP"
#define LAYER_STATE_16BIT
#define COMBO_COUNT 4

#define RGB_MATRIX_STARTUP_SPD 10

// Custom QMK here

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CHORDAL_HOLD


