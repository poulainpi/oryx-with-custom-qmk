#undef TAPPING_TERM                              // Override default tapping term
#define TAPPING_TERM 150                         // Set tapping term to 150ms

#define USB_SUSPEND_WAKEUP_DELAY 0               // Disable delay on USB wake

#define CAPS_LOCK_STATUS                         // Enable caps lock LED status
#define SERIAL_NUMBER "EaoKY/zL4XLG"             // Set custom USB serial number
#define LAYER_STATE_8BIT                         // Use 8-bit layer state representation

#define RGB_MATRIX_STARTUP_SPD 60                // Set RGB matrix startup speed

#define CIRQUE_PINNACLE_TAP_ENABLE               // Enable tap-to-click on Cirque Pinnacle touchpad
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X  // Options are: 4X | 2X | 1X. Use 1X attenuation for highest sensitivity

#define POINTING_DEVICE_ROTATION_90              // Rotate X/Y data by 90 degrees
#define MOUSE_EXTENDED_REPORT                    // Enable extended mouse report range (-32767 to 32767)
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE        // Enable automatic activation of mouse layer when trackpad is used
#define AUTO_MOUSE_TIME 280                      // Auto mouse layer stays active for 280ms after use
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE   // Enable scroll gestures on compatible pointing devices
#define POINTING_DEVICE_TASK_THROTTLE_MS 1       // Max polling rate (1 kHz)
#define USB_POLLING_INTERVAL_MS 1                // Optional: higher USB polling
