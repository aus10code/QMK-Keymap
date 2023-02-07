/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include QMK_KEYBOARD_H
#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void pointing_device_init_user(void) {
    //set_auto_mouse_layer(<mouse_layer>); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
	_MOUSE,
};

void matrix_scan_user(void) {
  achordion_task();
}

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define THREE MO(LAYER_THREE)
#define MOUSE MO(_MOUSE)
    
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,        KC_2,        KC_3,        KC_4,        KC_5,       KC_6,     KC_7,         KC_8,         KC_9,          KC_0,       KC_MINS,
  // ├────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,   	    KC_W,        KC_E,        KC_R,        KC_T,       KC_Y,     KC_U,         KC_I,         KC_O,          KC_P,       KC_BSLS,
  // ├────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────┤
       KC_EQL, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),   KC_G,       KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────┤
       KC_LBRC,    KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,       KC_N,     KC_M,        KC_COMM,      KC_DOT,     KC_SLSH,  KC_RBRC,
  // ╰────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────╯
												     KC_DEL, KC_BSPC,   MO(1),      KC_ENT,  KC_SPC,
													  	     KC_HOME,  KC_END,      MO(2)
				  //                              ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_TRNS,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, KC_TRNS,    XXXXXXX, KC_TRNS,
                                           XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,    KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3,   MO(2), KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______,   KC_NO,    _______, XXXXXXX,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
 [_MOUSE] = LAYOUT_charybdis_4x6(
	_______, _______, _______, _______, _______, _______,   _______, DPI_RMOD,DPI_MOD, S_D_RMOD,S_D_MOD, _______,
<<<<<<< HEAD
	_______, _______, _______, _______, _______, _______,   KC_WH_U, _______, _______, _______, _______, DRAGSCROLL_MODE,
=======
	_______, _______, _______, _______, _______, _______,   KC_WH_U, _______, _______, _______, _______, DRGSCRL,
>>>>>>> 5c7516c28cfde29242678deb7289aab9b7217950
	_______, _______, _______, _______, _______, _______,   KC_WH_D, KC_BTN4, KC_BTN8, KC_BTN5, KC_BTN6, SNIPING,
	_______, _______, _______, _______, _______, _______,   KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_U, _______,
							   _______, _______, _______,   _______, _______,
									   _______, _______,     _______
),

/*
  [LAYER_THREE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
 */
};
// clang-format on