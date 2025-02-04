/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 105

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1

#define SERIAL_NUMBER "Eon7Y/jq7MY"
#define LAYER_STATE_8BIT
#define COMBO_COUNT 18

#define RGB_MATRIX_STARTUP_SPD 60

#define JOYSTICK_AXIS_COUNT 5
#define JOYSTICK_AXIS_RESOLUTION 8
#define JOYSTICK_BUTTON_COUNT 3
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
