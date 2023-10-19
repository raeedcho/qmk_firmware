// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

enum layer_names {
    _BASL,
    _QWEL,
    _NUML,
    _NAVL,
    _EXTL,
    _GAML,
};

// #define OS_LGUI OSM(MOD_LGUI)
// #define OS_LCTL OSM(MOD_LCTL)
// #define OS_LALT OSM(MOD_LALT)
// #define OS_LSFT OSM(MOD_LSFT)

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

#define LA_NUML MO(_NUML)
#define LA_NAVL MO(_NAVL)
#define TT_NUML TT(_NUML)
#define TT_NAVL TT(_NAVL)
#define TT_EXTL TT(_EXTL)
#define TT_GAML TT(_GAML)
#define TT_QWEL TT(_QWEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASL] = LAYOUT(
        KC_TAB, KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_QUOT,KC_BSPC,TT_NAVL,
        KC_LCTL,KC_A,   KC_R,   KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,TT_GAML,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,   KC_COMM,KC_DOT, KC_QUES,TT_QWEL,
                KC_ESC, KC_LGUI,LA_NUML,KC_LSFT,        KC_SPC, LA_NAVL,KC_BSPC,TT_NUML ),
    [_QWEL] = LAYOUT(
        _______,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   _______,_______,
        _______,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,_______,_______,
        _______,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,_______,
                _______,_______,_______,_______,        _______,_______,_______,_______ ),
    [_NUML] = LAYOUT(
        _______,KC_GRV, KC_AT,  KC_LCBR,KC_RCBR,KC_PERC,KC_ASTR,KC_7,   KC_8,   KC_9,   KC_MINS,_______,_______,
        _______,KC_CIRC,KC_HASH,KC_LPRN,KC_RPRN,KC_DLR, KC_UNDS,KC_4,   KC_5,   KC_6,   KC_PLUS,_______, _______,
        _______,KC_SLSH,KC_LABK,KC_LBRC,KC_RBRC,KC_RABK,KC_AMPR,KC_1,   KC_2,   KC_3,   KC_EQL, _______,
                _______,_______,_______,_______,        KC_0,   _______,_______,_______ ),
    [_NAVL] = LAYOUT(
        _______,KC_TAB, KC_MUTE,KC_VOLD,KC_VOLU,_______, _______,KC_END, KC_HOME,KC_END, _______,_______,_______,
        _______,OS_SHFT,OS_CTRL,OS_ALT, OS_CMD, _______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT, KC_ESC,_______,_______,
        _______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,KC_ENT, _______,_______,_______,_______,
                _______,_______,_______,_______,        _______,_______,_______,_______ ),
    [_EXTL] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,_______,
        _______,_______,_______,_______,_______,_______,_______,KC_F4,  KC_F5,  KC_F6,  KC_F11, _______,_______,
        _______,_______,_______,_______,_______,_______,_______,KC_F1,  KC_F2,  KC_F3,  KC_F12, _______,
                _______,_______,_______,_______,        _______,_______,_______,_______ ),
    [_GAML] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
                _______,_______,_______,KC_SPC,         _______,_______,_______,_______ ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NUML:
    case LA_NAVL:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NUML:
    case LA_NAVL:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAVL, _NUML, _EXTL);
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t question_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
const key_override_t amps_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &question_override,
    &slash_override,
    &amps_override,
    &dot_override,
    &comma_override,
    NULL // Null terminate the array of overrides!
};
