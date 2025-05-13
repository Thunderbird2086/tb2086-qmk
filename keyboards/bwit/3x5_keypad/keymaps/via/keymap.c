// Copyright 2025 Allen Choi (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"

//  macOS       | Windows     |  Description
//  ------------+-------------+------------------------------------
//  SCMD(KC_A)  | LALT(KC_A)  |  Audio On/Off
//  SCMD(KC_D)  |             |  Switch to Dual Monitors
//  SCMD(KC_F)  | LALT(KC_F)  |  Enter/Exit Full Screen Mode
//  SCMD(KC_H)  | LALT(KC_H)  |  Show/Hide In-meeting Chat Panel
//  SCMD(KC_Y)  | LATL(KC_Y)  |  Raise/Lower Hand
//  SCMD(KC_N)  | LALT(KC_N)  |  Switch Camera
//  SCMD(KC_S)  | LALT(KC_S)  |  Start/Stop Screen Sharing
//  SCMD(KC_T)  | LALT(KC_T)  |  Pause Screen Sharing
//  SCMD(KC_V)  | LALT(KC_V)  |  Video On/Off
//  SCMD(KC_Y)  | LATL(KC_Y)  |  Raise/Lower Hand
//  SCMD(KC_W)  |             |  Switch to Speaker/Gallery View
//              | LALT(KC_F1) |  Switch to Speaker View
//              | LALT(KC_F2) |  Switch to Gallery View
//  SCMD(KC_M)  |             |  Switch to Minimal Window
//              | C(A(S(KC_H) |  Show/Hide Meeting Controls
//
//  LCMD(KC_L)  | LALT(KC_L)  |  Switch to Portrait/Landscape View
//  LCMD(KC_U)  | LALT(KC_U)  |  Show/Hide Participants Panel
//  LCMD(KC_W)  | LALT(KC_F4) |  Close Current Window

#define ______ KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_top(
    KC_ESC      , LCMD(KC_U) , SCMD(KC_W)  , SCMD(KC_D) , KC_ENT     ,
    TT(2)       , SCMD(KC_H) , SCMD(KC_N)  , SCMD(KC_T) , SCMD(KC_M) ,
    LALT(KC_Y)  , SCMD(KC_A) , SCMD(KC_V)  , SCMD(KC_S) , LCMD(KC_W)
    ),

    [1] = LAYOUT_top(
    KC_ESC      , LALT(KC_U) , LALT(KC_F1) , LALT(KC_F2), KC_ENT       ,
    TT(2)       , LALT(KC_H) , LALT(KC_N)  , LALT(KC_T) , C(A(S(KC_H))),
    LALT(KC_Y)  , LALT(KC_A) , LALT(KC_V)  , LALT(KC_S) , LALT(KC_F4)
    ),

    [2] = LAYOUT_top(
    EE_CLR      , DF(1)      , RGB_SAI     , RGB_VAI    , RGB_MOD    ,
    ______      , DF(0)      , RGB_SAD     , RGB_VAD    , RGB_RMOD   ,
    QK_BOOT     , ______     , RGB_HUD     , RGB_HUI    , RGB_TOG
    ),

    [3] = LAYOUT_top(
    ______      , ______     , ______      , ______     , ______     ,
    ______      , ______     , ______      , ______     , ______     ,
    ______      , ______     , ______      , ______     , ______ 
    ),
};
// clang-format on
