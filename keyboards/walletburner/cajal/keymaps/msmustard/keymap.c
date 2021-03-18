/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

enum layers {
    _BASE,
    _RAISE,
    _LOWER,
    _NAV,
    _FN
};

// Tap for key, hold shift
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)

#define LOWERSP LT(_LOWER, KC_SPC)
#define RAISESP LT(_RAISE, KC_SPC)
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)
#define KC_CENT LCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_stagger(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC, KC_MUTE,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,    KC_H,    KC_SJ,   KC_K,    KC_L,    KC_QUOT, KC_CENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SFTSLSH,          KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, LOWERSP, RAISESP, MO(_NAV),MO(_FN),                                     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_RAISE] = LAYOUT_stagger(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, RGB_MOD,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, _______,          KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______,                                     KC_HOME, KC_PGDN, KC_END
    ),

    [_LOWER] = LAYOUT_stagger(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, KC_COLN, KC_DQT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_LCBR, KC_RCBR, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,                                     _______, _______, _______
    ),


    [_NAV] = LAYOUT_stagger(
        _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,                                     _______, _______, _______
    ),

    [_FN] = LAYOUT_stagger(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, RGB_TOG,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F20,  KC_F21,  KC_F22,  KC_F23,  _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,          RGB_VAI,
        RESET,   _______, _______, _______, _______, _______, _______,                                    RGB_RMOD, RGB_VAD, RGB_MOD
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        writePinLow(B6);
        break;
    case 2:
        writePinLow(B7);
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    default:
        writePinLow(B7);
        writePinLow(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {

    switch(get_highest_layer(layer_state)) {
        case _FN:
            clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();
            break;
        case _NAV:
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
        default:
            clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
            break;
    }  
}

