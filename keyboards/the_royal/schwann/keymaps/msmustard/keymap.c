#include <print.h>
#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_RAISE,
	_LOWER,
	_NAV,
	_FN
};

#define KC_CESC CTL_T(KC_ESC)
#define LOWERSP LT(_LOWER, KC_SPC)
#define RAISESP LT(_RAISE, KC_SPC)
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_mit(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, 
                KC_TAB,  KC_LGUI, KC_RALT, MO(_LOWER), KC_SPC, MO(_RAISE), MO(_NAV), MO(_FN), KC_DEL
    ),

    [_RAISE] = LAYOUT_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, _______, _______, 
                _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT_mit(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_COLN, KC_DQT,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_LCBR, KC_RCBR, _______, _______, 
                _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_mit(
        _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,_______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, 
                _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_FN] = LAYOUT_mit(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
		KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  _______, _______, 
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, CG_TOGG, 
		         RESET,   _______, _______, _______,     _______,      _______, _______, _______, _______
    )
};
