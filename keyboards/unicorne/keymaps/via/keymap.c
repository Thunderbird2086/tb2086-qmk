// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "includes/keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                                 KC_J,      KC_L,      KC_U,      KC_Y,      KC_QUOT,
        LOPT_A,    LSFT_S,    LCTL_D,    M_LCMD_F,  KC_G,                                 KC_H,      RCMD_J,    RCTL_K,    RSFT_L,    ROPT_SCLN,
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                 KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ` │SFT│CTL│OPT│   │       │   │   │ ; │ - │ = │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│       │   │   │ [ │ ] │ \ │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [1] = LAYOUT_split_3x5_3(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                 KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
        LOPT_GRV,  KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     KC_RCMD,   RCTL_SCLN, RSFT_MINS, ROPT_EQL,
        KC_NO,     KC_N,      KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_NO,     KC_LBRC,   KC_RBRC,   KC_BSLS,
                                         KC_ESC,    KC_TAB,    KC_SPC,         KC_ENT,    KC_BSPC,   KC_DEL 
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │       │F6 │F7 │F8 │F9 │F10│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│F12│       │F11│CMD│CTL│SFT│OPT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [2] = LAYOUT_split_3x5_3(
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_F12,                               KC_F11,    KC_RCMD,   KC_RCTL,   KC_RSFT,   KC_ROPT,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                         KC_ESC,    KC_TAB,    KC_SPC,         KC_ENT,    KC_BSPC,   KC_DEL 
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │       │Ins│Lef│UP │Rig│PU │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │Hom│Dn │End│PD │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [3] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_INS,    KC_LEFT,   KC_UP,     KC_RIGHT,  KC_PGUP,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_HOME,   KC_DOWN,   KC_END,    KC_PGDN,
                                         KC_ESC,    KC_TAB,    KC_SPC,         KC_ENT,    KC_BSPC,   KC_DEL 
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │PWR│SLP│WAK│   │   │       │R.T│R.M│LOK│R.R│Res│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Br+│RWD│PLY│Vo+│W.B│       │   │Va+│Hu+│Sa+│Sp+│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Br-│FWD│Mut│Vo-│W.F│       │   │Va-│Hu-│Ss-│Sp-│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤   │
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [4] = LAYOUT_split_3x5_3(
        KC_PWR,    KC_SLEP,   KC_WAKE,   KC_NO,     KC_NO,                                RM_TOGG,   RM_NEXT,   K_LOCK,    EE_CLR,    QK_BOOT,
        KC_BRIU,   KC_MPRV,   KC_MPLY,   KC_VOLU,   K_BACK,                               KC_NO,     RM_VALU,   RM_HUEU,   RM_SATU,   RM_SPDU,
        KC_BRID,   KC_MNXT,   KC_MUTE,   KC_VOLD,   K_FWRD,                               KC_NO,     RM_VALD,   RM_HUED,   RM_SATD,   RM_SPDD,
                                         KC_ESC,    KC_TAB,    KC_SPC,         KC_ENT,    KC_BSPC,   KC_DEL 
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │       │   │ML │MU │MR │WU │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │WL │MD │WR │WD │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤MB3│
      *           └───┤TAB├───┐   ┌───┤MB2├───┘
      *               └───┤Spc│   │MB1├───┘
      *                   └───┘   └───┘
      */
    [5] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     MS_ACL0,   MS_ACL1,   MS_ACL2,   KC_NO,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     MS_LEFT,   MS_UP  ,   MS_RGHT,   MS_WHLU,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     MS_WHLL,   MS_DOWN,   MS_WHLR,   MS_WHLD,
                                         KC_ESC,    KC_TAB,    KC_SPC,         MS_BTN1,   MS_BTN2,   MS_BTN3
    )
};
