// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASEL,
    _NUML,
    _NAVL,
    _WSPACEL,
    _GAMEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASEL] = LAYOUT(
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_MINS,    KC_BSPC,
        OSL(_NAVL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_RSFT,
                KC_LCTL,    KC_LALT,    KC_LGUI,    OSL(_NUML), KC_SPC, OSL(_WSPACEL),  TT(_GAMEL), OSL(_NAVL) ),
    [_NUML] = LAYOUT(
        KC_ESC,     _______,KC_BTN2,KC_MS_U,KC_BTN1,_______,_______,KC_7,   KC_8,       KC_9,   KC_PLUS,    KC_MINS,    _______,
        _______,    _______,KC_MS_L,KC_MS_D,KC_MS_R,KC_LBRC,KC_RBRC,KC_4,   KC_5,       KC_6,   KC_ASTR,    KC_EQL,     _______,
        _______,    _______,_______,_______,KC_BTN3,_______,_______,KC_1,   KC_2,       KC_3,   _______,    _______,
                _______,    _______,    _______,    _______,    KC_0,   _______,        _______,    _______ ),
    [_NAVL] = LAYOUT(
        KC_GRV,     KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,    KC_LPRN,KC_RPRN,    _______,    _______,
        _______,    KC_ESC, KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_LEFT,KC_DOWN,KC_UP,      KC_RGHT,KC_INS,     KC_DEL,     _______,
        _______,    KC_MENU,KC_MPRV,KC_MPLY,KC_MNXT,KC_HOME,KC_END, _______,_______,    _______,KC_BSLS,    _______,
                _______,    _______,    _______,    _______,    _______,_______,        _______,    _______ ),
    [_WSPACEL] = LAYOUT(
        KC_TILD,    KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,LGUI(KC_7),LGUI(KC_8),LGUI(KC_9),LGUI(KC_MINS), _______,_______,
        _______,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  _______,_______,LGUI(KC_4),LGUI(KC_5),LGUI(KC_6),LGUI(KC_B),    _______,_______,
        _______,    KC_F1,  KC_F2,  KC_F3,  KC_F4,  _______,_______,LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),_______,_______,
                _______,     _______,   _______,   _______,   LGUI(KC_0),_______,   _______,   _______ ),
    [_GAMEL] = LAYOUT(
        _______,    _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_ESC,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______, _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
                _______,   _______,  _______,  KC_SPC,   _______,   _______,  _______,  _______ ),
};
