/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "chowderboard.h"

#define ____ KC_TRNS
#define _BASEL 0
#define _NUML 1
#define _MOVEL 2
#define _WSPACEL 3
#define _GAMEL 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASEL] = KEYMAP(
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,       KC_MINS,    KC_BSPC,
  OSL(_MOVEL),    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    KC_ENT,
  OSM(MOD_LSFT),  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    OSM(MOD_RSFT),
  OSM(MOD_LCTL),     OSM(MOD_LALT),    OSM(MOD_LGUI), OSL(_NUML),     KC_SPC, OSL(_WSPACEL),  TT(_GAMEL),    OSL(_MOVEL) ),
[_NUML] = KEYMAP(
  KC_ESC,   ____, KC_BTN2,   KC_MS_U,   KC_BTN1,   ____,   ____,   KC_7,  KC_8,      KC_9,  KC_PLUS,   KC_MINS,   ____,
  ____,     ____, KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_LBRC,KC_RBRC,KC_4,  KC_5,      KC_6,  KC_ASTR,   KC_EQL,    ____,
  ____,     ____,   ____,   ____,   KC_BTN3,   ____,   ____,   KC_1,  KC_2,      KC_3,  ____,      ____,
  ____,     ____,   ____,   ____,   KC_0,   ____,   ____,   ____ ),
[_MOVEL] = KEYMAP(
  KC_GRV,   KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN, ____, ____,
  ____, KC_ESC, KC_VOLD, KC_VOLU, KC_MUTE, ____, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,  KC_INS, KC_DEL, ____,
  ____, KC_MENU, KC_MPRV, KC_MPLY, KC_MNXT, KC_HOME, KC_END,    ____,    ____,    ____, KC_BSLS, ____,
  ____,     ____,   ____,   ____,   ____,   ____,   ____,   ____ ),
[_WSPACEL] = KEYMAP(
  KC_TILD,   KC_F9, KC_F10,   KC_F11,   KC_F12,   ____,   ____,   LGUI(KC_7),  LGUI(KC_8),      LGUI(KC_9),  LGUI(KC_MINS),   ____,   ____,
  ____,     KC_F5, KC_F6,   KC_F7,   KC_F8,   ____,____,LGUI(KC_4),  LGUI(KC_5),      LGUI(KC_6),  LGUI(KC_B),   ____,    ____,
  ____,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   ____,   ____,   LGUI(KC_1),  LGUI(KC_2),      LGUI(KC_3),  ____,      ____,
  ____,     ____,   ____,   ____,   LGUI(KC_0),   ____,   ____,   ____ ),
[_GAMEL] = KEYMAP(
  ____,    ____,  ____,  ____,   ____,   ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,
  KC_ESC,  ____,  ____,  ____,   ____,   ____,  ____,  ____,  ____,  ____,  ____,  ____,  ____,
  KC_LSFT, ____,  ____,  ____,   ____,   ____,  ____,  ____,  ____,  ____,  ____,  ____,
  KC_LCTL,   KC_LALT,  KC_LGUI,  KC_SPC,   ____,   ____,  ____,  ____ ),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
