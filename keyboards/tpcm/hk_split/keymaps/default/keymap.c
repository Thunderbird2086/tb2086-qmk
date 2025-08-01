// Copyright 2025 Allen Choi (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../keycodes.h"

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┐
     * │  `  │  1  │  2  │  3  │  4  │  5  │                          │  6  │  7  │  8  │  9  │  0  │  ─  │  =  │ Back SPC │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐                       └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
     * │ Tab    │  Q  │  W  │  E  │  R  │  T  │                          │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ \     │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴───────┤
     * │ ESC     │  A  │  S  │  D  │  F  │  G  │                          │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │
     * ├─────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬─────┬─────┤
     * │ LShift   │  Z  │  X  │  C  │  V  │  B  │                          │  N  │  M  │  <  │  >  │  ?  │ Sft │ Up  │ Fn  │
     * ├──────┬───┴─┬───┴──┬──┴─────┴────┬┴────┬┘                         ┌┴─────┴─────┴──┬──┴────┬┴─────┼─────┼─────┼─────┤
     * │ Ctrl │ Cmd │ Opt  │             │ Fn  │                          │               │ Opt   │ Cmd  │ Lft │ Dwn │ Rgt │
     * └──────┴─────┴──────┴─────────────┴─────┘                          └───────────────┴───────┴──────┴─────┴─────┴─────┘
     */
    [_QWERTY] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,               KC_6,     KC_7,     KC_8,    KC_9,    KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,               KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,      KC_LBRC,     KC_RBRC,     KC_BSLS,
      KC_ESC,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,               KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,   KC_QUOTE,                 KC_ENTER,
      KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,               KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP,       MO(_FUNCTION),
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,      MO(_FUNCTION),          KC_SPACE,                    KC_RALT, KC_RGUI,   KC_LEFT,     KC_DOWN,     KC_RIGHT
      ),
    /* 
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┐
     * │  `  │  1  │  2  │  3  │  4  │  5  │                          │  6  │  7  │  8  │  9  │  0  │  ─  │  =  │ Back SPC │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐                       └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
     * │ Tab    │  Q  │  W  │  F  │  P  │  B  │                          │  J  │  L  │  U  │  Y  │  ;  │  [  │  ]  │ \     │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴───────┤
     * │ ESC     │  A  │  R  │  S  │  T  │  G  │                          │  M  │  N  │  E  │  I  │  O  │  '  │ Enter      │
     * ├─────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬─────┬─────┤
     * │ LShift   │  Z  │  X  │  C  │  D  │  V  │                          │  K  │  H  │  <  │  >  │  ?  │ Sft │ Up  │ Fn  │
     * ├──────┬───┴─┬───┴──┬──┴─────┴────┬┴────┬┘                         ┌┴─────┴─────┴──┬──┴────┬┴─────┼─────┼─────┼─────┤
     * │ Ctrl │ Cmd │ Opt  │             │ Fn  │                          │               │ Opt   │ Cmd  │ Lft │ Dwn │ Rgt │
     * └──────┴─────┴──────┴─────────────┴─────┘                          └───────────────┴───────┴──────┴─────┴─────┴─────┘
     */
    [_COLEMAK] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,               KC_6,     KC_7,     KC_8,    KC_9,    KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_F,     KC_P,    KC_B,               KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN,   KC_LBRC,     KC_RBRC,     KC_BSLS,
      KC_ESC,  LOPT_A,  LSFT_R,  LCTL_S,   M_LCMD_T,KC_G,               KC_M,     RCMD_N,   RCTL_E,  RSFT_I,  ROPT_O,    KC_QUOTE,                 KC_ENTER,
      KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_D,    KC_V,               KC_N,     KC_H,     KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,     KC_UP,       MO(_FUNCTION),
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,      MO(_FUNCTION),               KC_SPACE,                    KC_RALT, KC_RGUI,   KC_LEFT,     KC_DOWN,     KC_RIGHT
      ),
    /*
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┐
     * │     │ F1  │  F2 │ F3  │ F4  │ F5  │                          │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │          │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐                       └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
     * │        │     │     │     │     │     │                          │     │     │     │     │     │     │     │       │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴───────┤
     * │ Caps    │     │     │     │     │     │                          │     │     │     │     │     │     │            │
     * ├─────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬─────┬─────┤
     * │          │     │     │     │     │     │                          │     │     │     │     │     │     │     │Media│
     * ├──────┬───┴─┬───┴──┬──┴─────┴────┬┴────┬┘                         ┌┴─────┴─────┴──┬──┴────┬┴─────┼─────┼─────┼─────┤
     * │      │     │      │             │Media│                          │               │       │      │     │     │     │
     * └──────┴─────┴──────┴─────────────┴─────┘                          └───────────────┴───────┴──────┴─────┴─────┴─────┘
     */
    [_FUNCTION] = LAYOUT(
      K_LOCK,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
      KC_CAPS, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, MO(_MEDIA),
      _______, _______, _______, _______,          MO(_MEDIA),       _______,                   _______, _______, _______, _______, _______
      ),
    /*
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐                          ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┐
     * │ Boot│Reset│     │     │     │QWERT│                          │COLEM│     │     │ LOK │Reset│Boot │     │          │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐                       └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
     * │        │ PWR │ SPL │ WAK │     │     │                          │     │ Sa+ │ Va+ │ SP+ │ R.M │     │     │       │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴───────┤
     * │         │ Br+ │ RWD │ PLY │ Vo+ │ W.B │                          │     │ Sa- │ Va- │ SP- │ R.D │     │            │
     * ├─────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐                         └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬─────┬─────┤
     * │          │ Br- │ FWD │ Mut │ Vo- │ W.F │                          │     │ Hu+ │ Hu- │     │ R.T │     │     │     │
     * ├──────┬───┴─┬───┴──┬──┴─────┴────┬┴────┬┘                         ┌┴─────┴─────┴──┬──┴────┬┴─────┼─────┼─────┼─────┤
     * │      │     │      │             │     │                          │               │       │      │     │     │     │
     * └──────┴─────┴──────┴─────────────┴─────┘                          └───────────────┴───────┴──────┴─────┴─────┴─────┘
     */
    [_MEDIA] = LAYOUT(
      QK_BOOT, EE_CLR,  _______, _______, _______, QWERTY,         COLEMAK, _______, _______, K_LOCK,  EE_CLR,  QK_BOOT,   _______, _______,
      _______, KC_PWR,  KC_SLEP, KC_WAKE, _______, _______,        _______, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, _______,   _______, _______,
      _______, KC_BRIU, KC_MPRV, KC_MPLY, KC_VOLU, _______,        _______, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,_______,            _______,
      _______, KC_BRID, KC_MNXT, KC_MUTE, KC_VOLD, _______,        _______, RGB_HUD, RGB_HUI, _______, RGB_TOG, _______,   _______, _______,
      _______, _______, _______, _______,          _______,        _______,                   _______, _______, _______,   _______, _______
  ),
};
