/ Copyright 2023 Thunderbird2086 (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define EE_HANDS
#define SPLIT_USB_DETECT

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

#define VER_NEWLINE_WAIT 200 // in milliseconds

#if defined(OLED_ENABLE)
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#    undef OLED_TIMEOUT
        //  due to timer_read() for render_prompt(), we have own implementation of oled time out
#   define OLED_KEY_TIMEOUT 30000
#   define KEY_LOG_ENABLE
#endif
