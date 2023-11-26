// Copyright 2023 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

enum custom_keycodes {
    // Layer Macros
    COLEMAK = QK_USER,
#if defined(QWERTY_ENABLED)
    QWERTY,
#   endif
    CODE,
    FUNCTION,
    NAV,
    MEDIA,
#   if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    RGBRST,
#   endif
    VRSN,
#if defined(SECRETS_ENABLE)
    // Secret Macros
    M_XXX1,
    M_XXX2,
    M_XXX3,
    M_XXX4,
    M_XXX5,
#endif
};


enum layers {
    _COLEMAK,
#if defined(QWERTY_ENABLED)
    _QWERTY,
#   endif
    _CODE,
    _FUNCTION,
    _NAV,
    _MEDIA,
#if defined(SECRETS_ENABLE)
    _SECRET,
#endif
};

// Shortcut Keys
#define K_BACK      LCMD(KC_LBRC)           // browser back
#define K_FWRD      LCMD(KC_RBRC)           // browser forward
#define K_LOCK      LCMD(LCTL(KC_Q))        // Lock screen
#define K_CSCN      LCMD(LCTL(LSFT(KC_4)))  // Copy a portion of the screen to the clipboard
#define K_MDSH      LSFT(LOPT(KC_MINS))

// Layer Keys
#define FCT_TAB     LT(_FUNCTION, KC_TAB)
#define FCT_BSPC    LT(_FUNCTION, KC_BSPC)

#define COD_ENT     LT(_CODE    , KC_ENT)
#define COD_SPC     LT(_CODE    , KC_SPC)

#define NAV_ESC     LT(_NAV     , KC_ESC)
#define MED_DEL     LT(_MEDIA   , KC_DEL)

// Mod-Tap Keys
#define SFT_R       MT(MOD_LSFT, KC_R)
#define SFT_I       MT(MOD_LSFT, KC_I)
#define SFT_MINS    MT(MOD_RSFT, KC_MINS)

#define CTL_S       MT(MOD_LCTL, KC_S)
#define CTL_E       MT(MOD_RCTL, KC_E)
#define CTL_SCLN    MT(MOD_RCTL, KC_SCLN)

#if defined(QWERTY_ENABLED)
#   define CTL_QUOT    MT(MOD_RCTL, KC_QUOT)
#   define CTL_LBRC    MT(MOD_RCTL, KC_LBRC)
#endif

#define LOPT_A      MT(MOD_LALT, KC_A)
#define LOPT_GRV    MT(MOD_LALT, KC_GRV)
#define ROPT_O      MT(MOD_RALT, KC_O)
#define ROPT_BSLS   MT(MOD_RALT, KC_BSLS)

#define M_LCMD_T    MT(MOD_LGUI, KC_T)
#define RCMD_N      MT(MOD_RGUI, KC_N)

#if defined(QWERTY_ENABLED)
#   define RCMD_J      MT(MOD_LGUI, KC_J)
#   define LOPT_F      MT(MOD_LALT, KC_F)
#endif

