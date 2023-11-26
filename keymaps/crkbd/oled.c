// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

#include "tb2086/includes/font_util.h"


#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)

void render_rgb_status(void) {
    oled_write_P(read_icon_rgb_status(
#                   if defined(RGBLIGHT_ENABLE)
                    rgblight_is_enabled()
#                   elif defined(RGB_MATRIX_ENABLE)
                    rgb_matrix_is_enabled()
#                   endif
                ), false);
}
#endif

void render_mod_status(void) {
#if defined(NO_ACTION_ONESHOT)
    uint8_t modifiers = get_mods();
#else
    uint8_t modifiers = get_mods() | get_oneshot_mods();
#endif

    // 2x1 Ctrl, Alt, Shift, GUI, Caps
    oled_write_P(((modifiers & MOD_MASK_CTRL) ? read_icon_mod_ctrl() : PSTR("  ")), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(((modifiers & MOD_MASK_SHIFT) ? read_icon_mod_shift() : PSTR("  ")), false);

    oled_write_P(((modifiers & MOD_MASK_ALT) ? read_icon_mod_alt() : PSTR("  ")), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(((modifiers & MOD_MASK_GUI) ? read_icon_mod_gui() : PSTR("  ")), false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P((led_state.caps_lock ? read_icon_caps_lock() : PSTR("  ")), false);
}

void render_feature_status(void) {
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
    render_rgb_status();
#endif
}


void render_layer(bool is_one_line) {
    uint8_t layer = 0;
    if (layer_state_is(_FUNCTION)) {
        layer = 1;
    } else if (layer_state_is(_CODE)) {
        layer = 2;
    } else if (layer_state_is(_ADJUST)) {
        layer = 3;
    }
    oled_write_P(read_layer(layer, is_one_line), false);
}


// Keylogger
#define KEYLOGGER_LENGTH 5
static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
// clang-format off
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};


#if defined(KEY_LOG_ENABLE)
void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX)
        || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
        || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }
}
#endif

static uint16_t key_timer  = 0;
static bool is_key_processed = true;
bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_timer = timer_read();
        is_key_processed = true;

#       if defined(KEY_LOG_ENABLE)
        add_keylog(keycode);
#endif
    }

    return true;
}


void render_keylogger_status(void) {
    oled_write(keylog_str, false);
}


void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;

    if (layer_state_is(_FUNCTION)) {
        oled_write_ln_P(blink ? PSTR("> ft_") : PSTR("> ft "), false);
    } else if (layer_state_is(_CODE)) {
        oled_write_ln_P(blink ? PSTR("> sy_") : PSTR("> sy "), false);
    } else if (layer_state_is(_ADJUST)) {
        oled_write_ln_P(blink ? PSTR("> aj_") : PSTR("> aj "), false);
    } else {
        oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
    }
}


void render_status_secondary(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);

    // 5x2 Keyboard, Controller logos
    oled_write_P(read_font_kb_split(), false);

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_layer(true);

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
    layer_state_is(_ADJUST) ? render_feature_status() : render_mod_status();
#else
    render_mod_status();
#endif
}


void render_status_main(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);

    // 5x3 Logos
    oled_write_P(read_font_qmk_logo(), false);

    oled_write_ln("", false);
    oled_write_ln("", false);

    render_layer(false);

    oled_write_ln("", false);
    oled_write_ln("", false);

    render_prompt();

    oled_write_ln("", false);

    render_keylogger_status();
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (is_key_processed && (timer_elapsed(key_timer) < OLED_KEY_TIMEOUT)) {
            render_status_main();
        } else if (is_key_processed) {
            is_key_processed = false;
            oled_off();
        }
    } else {
        render_status_secondary();
    }

    return false;
}
