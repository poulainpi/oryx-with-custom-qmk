#define QMK_LAYER_ENG 0
#define QMK_LAYER_RUS 1
#define TAPPING_TERM 200
#include "./modules/oneshot.h"
#include "./modules/swapper.h"
#include "./modules/oneshot.c"
#include "./modules/swapper.c"

#if defined(OS_DETECTION_ENABLE)
#include "os_detection.h"
#define OS_DETECTION_DEBOUNCE 250
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_SINGLE_REPORT
#endif

//#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS


enum unicode_names {
    EN_DASH,        // ‒
    EM_DASH,        // —
    DAGGER,         // †
    TRIPLE_DOT      // ...
    TRIPLE_PRIME,   // ‴
    DOUBLE_EXCL,    // ‼
    INFINITY,       // ∞
    NOT_EQUAL,      // ≠
    GREEK_DIALYT,   // ΅
    ONE_QUARTER,    // ¼
    ONE_HALF,       // ½
    THREE_QUART,    // ¾
    CHECK_BOLD,     // ✔
    CHECK_BOXED,    // ☑
    CHECK_THIN,     // ✓
};

const uint32_t unicode_map[] PROGMEM = {
    [EN_DASH]       = 0x2012, // ‒ Figure Dash
    [EM_DASH]       = 0x2014, // — Em Dash
    [DAGGER]        = 0x2020, // †
    [TRIPLE_DOT]    = 0x2026, // ...
    [TRIPLE_PRIME]  = 0x2034, // ‴
    [DOUBLE_EXCL]   = 0x203C, // ‼
    [INFINITY]      = 0x221E, // ∞
    [NOT_EQUAL]     = 0x2260, // ≠
    [GREEK_DIALYT]  = 0x0385, // ΅
    [ONE_QUARTER]   = 0x00BC, // ¼
    [ONE_HALF]      = 0x00BD, // ½
    [THREE_QUART]   = 0x00BE, // ¾
    [CHECK_BOLD]    = 0x2714, // ✔ Heavy Check Mark
    [CHECK_BOXED]   = 0x2611, // ☑ Ballot Box with Check
    [CHECK_THIN]    = 0x2713, // ✓ Check Mark (тонкая)
};
