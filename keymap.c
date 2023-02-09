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

#ifdef RGB_MATRIX_ENABLE
#include "quantum/rgb_matrix/rgb_matrix.h"
#endif  // RGB_MATRIX_ENABLE

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

uint16_t achordion_timeout(uint16_t tap_hold_keycode)
{
	return 500;
}
 


#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define THREE MO(LAYER_THREE)
#define MOUSE MO(_MOUSE)

/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255};

	if (layer_state_is(2)) {
    //if (layer_state_is(layer_state, 2)) {
        hsv = {130, 255, 255};
    } else {
        hsv = {30, 255, 255};
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}
*/

/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);
		
		
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
					HSV hsv = {0, 255, 255};
					
					if (layer_state_is(3)) {
						rgb_matrix_set_color(index, RGB_RED);
					}
					else if (layer_state_is(2)) {
						hsv.h = 130;
						rgb_matrix_set_color(index, RGB_BLUE);
					}
					else if (layer_state_is(1)) {
						rgb_matrix_set_color(index, RGB_GREEN);
					}
					else {
						//rgb_matrix_set_color(index, RGB_WHITE);
					}
					
					
				}
            }
        }
    //}
    return false;
}
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255};
	uint8_t layer = get_highest_layer(layer_state);
	RGB rgb = hsv_to_rgb(hsv);

	for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
					if (layer_state_is(3)) {
						rgb_matrix_set_color(index, RGB_RED);
						//hsv = (HSV) { (uint8_t)0, (uint8_t)100, (uint8_t)98 };
						//rgb = hsv_to_rgb(hsv);
						//rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
					}
					else if (layer_state_is(2)) {
						//hsv = (HSV) { (uint8_t)130, 100, 90 };
						//rgb = hsv_to_rgb(hsv);
						//rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
						rgb_matrix_set_color(index, RGB_BLUE);
					}
					else if (layer_state_is(1)) {
						//(index, RGB_GREEN);
						//hsv = (HSV) { (uint8_t)58, 100, 80 };
						//rgb = hsv_to_rgb(hsv);
						//rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
						rgb_matrix_set_color(index,  RGB_GREEN);
					}
					else {
						//rgb_matrix_set_color(index, RGB_WHITE);
						hsv = (HSV) { (uint8_t)180, 0, 100 };
						rgb = hsv_to_rgb(hsv);
						rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
					}
				}
				else if (keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_TRNS) {
					hsv = (HSV) { (uint8_t)0, (uint8_t)0, (uint8_t)0 };
					rgb = hsv_to_rgb(hsv);
					rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
				}
            }
        }

	/*
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
	*/
	
    

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}
  

/*
layer_state_t layer_state_set_user_keymap(layer_state_t state) {
  state = update_tri_layer_state(state, LAYER_LOWER, _MOUSE, LAYER_BASE);
  #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(state | default_layer_state)) {
      case LAYER_LOWER:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
        rgb_matrix_sethsv_noeeprom(HSV_RED);
        break;
      case _MOUSE:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
        rgb_matrix_sethsv_noeeprom(HSV_BLUE);
        break;
      case LAYER_BASE:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
        rgb_matrix_sethsv_noeeprom(HSV_WHITE);
        break;

      default: //  for any other layers, or the default layer
        rgb_matrix_reload_from_eeprom();  // Load default values.
        break;
    }
    #endif // RGB_MATRIX_ENABLE
  return state;
}
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,        KC_2,        KC_3,        KC_4,        KC_5,       KC_6,     KC_7,         KC_8,         KC_9,          KC_0,       KC_MINS,
  // ├────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,   	    KC_W,        KC_E,        KC_R,        KC_T,       KC_Y,     KC_U,         KC_I,         KC_O,          KC_P,       KC_BSLS,
  // ├────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────┤
       KC_EQL, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,       KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
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
       RGB_MOD, _______, _______, _______, _______, _______,    KC_TRNS,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, _______, _______, _______, EE_CLR,  QK_BOOT,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, KC_TRNS,    _______, KC_TRNS,
                                           _______, _______,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, , KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, _______, _______, _______,  EE_CLR, QK_BOOT,    KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3,   MO(2), KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______,   KC_NO,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
 [_MOUSE] = LAYOUT_charybdis_4x6(
	_______, _______, _______,  _______, _______, _______,   _______, DPI_RMOD,DPI_MOD,               S_D_RMOD,      S_D_MOD, _______,
	 KC_TAB, _______, 	 KC_W,  _______, _______,    KC_T,   KC_WH_U, _______, _______,                _______,      KC_BTN3, _______,
	_______, KC_LGUI, KC_LALT,  KC_LCTL, KC_LSFT, _______,   KC_WH_D, KC_RSFT, KC_RCTL,                KC_RALT,      KC_RGUI, KC_BTN6,
	_______, 	KC_Z,    KC_X, 	   KC_C,    KC_V, _______,   KC_WWW_BACK, KC_BTN1, KC_BTN2, DRAGSCROLL_MODE_TOGGLE, SNIPING_MODE_TOGGLE,KC_WWW_FORWARD,
							    _______, _______, _______,   _______, _______,
									   _______, _______,    _______
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
