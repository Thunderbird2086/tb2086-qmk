// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS

#if defined(APPLE_FN_ENABLE)
/* USB Device descriptor parameter */
#   if defined(VENDOR_ID)
#      undef   VENDOR_ID
#      define  VENDOR_ID    0x05ac
#   endif

#   if defined(PRODUCT_ID)
#      undef   PRODUCT_ID
#      define  PRODUCT_ID   0x021E
#   endif

#   if defined(DEVICE_VER)
#      undef   DEVICE_VER
#      define  DEVICE_VER   0x0931
#   endif

#   if defined(MANUFACTURER)
#      undef   MANUFACTURER
#      define  MANUFACTURER "Apple Inc."
#   endif

#   if defined(PRODUCT)
#      undef   PRODUCT
#      define PRODUCT "Aluminum Mini Keyboard (ISO)"
#   endif
#endif

// #define RGB_LAYER_ENABLE

#define PERMISSIVE_HOLD

#if defined(TAPPING_TERM)
#   undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define VER_NEWLINE_WAIT 200 // in milliseconds

#define NO_ACTION_ONESHOT

#if defined(OLED_ENABLE)
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
        //  due to timer_read() for render_prompt(), we have own implementation of oled time out
#   define KEY_LOG_ENABLE
#endif

#if defined(RGB_MATRIX_ENABLE) && !defined(QMK_MCU_RP2040)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED       // turn off effects when suspended

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
//#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
//#   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON
//#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#   undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   undef ENABLE_RGB_MATRIX_HUE_BREATHING
#   undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#   undef ENABLE_RGB_MATRIX_HUE_WAVE
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
//#   undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN
//#   undef ENABLE_RGB_MATRIX_STARLIGHT
#   if defined(OLED_ENABLE)
#       undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#       undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#   endif
#   undef ENABLE_RGB_MATRIX_RIVERFLOW

    //  These modes introduce additional logic that can increase firmware size.
#   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

    //  These modes introduce additional logic that can increase firmware size.
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef ENABLE_RGB_MATRIX_SPLASH
//#   undef ENABLE_RGB_MATRIX_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
