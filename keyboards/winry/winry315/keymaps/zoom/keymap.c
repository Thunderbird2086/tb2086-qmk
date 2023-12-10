// Copyright 2022 Sergey Vlasov (@sigprof)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _ZOOM_M,
  _ZOOM_W,
  //_MOUSE_,
  _RGB___,
  _ADJUST,
};

//  macOS       | Windows     |  Description
//  ------------+-------------+------------------------------------
//  SCMD(KC_A)  | LALT(KC_A)  |  Audio On/Off
//  SCMD(KC_D)  |             |  Switch to Dual Monitors
//  SCMD(KC_F)  | LALT(KC_F)  |  Enter/Exit Full Screen Mode
//  SCMD(KC_H)  | LALT(KC_H)  |  Show/Hide In-meeting Chat Panel
//  SCMD(KC_M)  |             |  Switch to Minimal Window
//  SCMD(KC_N)  | LALT(KC_N)  |  Switch Camera
//  SCMD(KC_S)  | LALT(KC_S)  |  Start/Stop Screen Sharing
//  SCMD(KC_T)  | LALT(KC_T)  |  Pause Screen Sharing
//  SCMD(KC_V)  | LALT(KC_V)  |  Video On/Off
//  SCMD(KC_W)  |             |  Switch to Speaker/Gallery View
//              | LALT(KC_F1) |  Switch to Speaker View
//              | LALT(KC_F2) |  Switch to Gallery View
//
//  LCMD(KC_L)  | LALT(KC_L)  |  Switch to Portrait/Landscape View
//  LCMD(KC_U)  | LALT(KC_U)  |  Show/Hide Participants Panel
//  LCMD(KC_W)  | LALT(KC_F4) |  Close Current Window

#define ZOOM_M DF(_ZOOM_M)
#define ZOOM_W DF(_ZOOM_W)
#define ______ KC_NO

// Shorter defines for some QMK keycodes (to keep the keymap aligned)
#define U_LTESC LT(_RGB, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ZOOM_M] = LAYOUT_top(
            SCMD(KC_V),          KC_MPLY   ,        LCMD(KC_A),
    KC_ESC      , LCMD(KC_U) , SCMD(KC_W)  , SCMD(KC_D) , KC_ENT     ,
    TT(_ADJUST) , SCMD(KC_H) , SCMD(KC_N)  , SCMD(KC_T) , SCMD(KC_M) ,
    TT(_RGB___) , SCMD(KC_A) , SCMD(KC_V)  , SCMD(KC_S) , LCMD(KC_W)
    ),

    [_ZOOM_W] = LAYOUT_top(
            LALT(KC_V),          KC_MPLY,           LALT(KC_A),
    KC_ESC      , LALT(KC_U) , LALT(KC_F1) , LALT(KC_F2), KC_ENT       ,
    TT(_ADJUST) , LALT(KC_H) , LALT(KC_N)  , LALT(KC_T) , C(A(S(KC_H))),
    TT(_RGB___) , LALT(KC_A) , LALT(KC_V)  , LALT(KC_S) , LALT(KC_F4)
    ),

    [_RGB___] = LAYOUT_top(
            KC_MSTP,             KC_MPLY,           KC_MUTE,
    ______      , RGB_M_P    , RGB_M_B     , RGB_M_R    , RGB_MOD     ,
    TT(_ADJUST) , RGB_M_SW   , RGB_M_SN    , RGB_M_TW   , RGB_RMOD    ,
    MO(_RGB___) , RGB_M_X    , RGB_M_K     , RGB_M_G    , RGB_M_T
    ),

    [_ADJUST] = LAYOUT_top(
            KC_MSTP,              KC_MPLY,          KC_MUTE,
    EE_CLR      , ZOOM_W     , RGB_SAI     , RGB_VAI    , RGB_MOD     ,
    ______      , ZOOM_M     , RGB_SAD     , RGB_VAD    , RGB_RMOD    ,
    ______      , ______     , RGB_HUD     , RGB_HUI    , RGB_TOG
    ),
};
// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    switch (index) {
        case 0:
            // Left encoder
            if (layer == _RGB___) {
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            } else {
                tap_code(clockwise ? KC_PGDN : KC_PGUP);
            }
            break;

        case 1:
            // Center encoder
            if (layer == _RGB___) {
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
            } else {
                tap_code_delay(clockwise ? KC_MNXT : KC_MPRV, 10);
            }
            break;

        case 2:
            // Right encoder
            if (layer == _RGB___) {
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
            } else {
                tap_code_delay(clockwise ? KC_VOLU : KC_VOLD, 10);
            }
            break;
    }
    return false;
}
