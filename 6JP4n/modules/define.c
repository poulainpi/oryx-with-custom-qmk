#define QMK_LAYER_ENG 0
#define QMK_LAYER_RUS 1
#define TAPPING_TERM 200
#if defined(OS_DETECTION_ENABLE)
#include "os_detection.h"
#define OS_DETECTION_DEBOUNCE 250
#define OS_DETECTION_KEYBOARD_RESET
#endif
