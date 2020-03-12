// make walletburner/neuron:spacewoman
#include QMK_KEYBOARD_H

#if (__has_include("secrets.h"))
#include "secrets.h"
#else
#define SECRET_1 "secret 1"
#define SECRET_2 "secret 2"
#define SECRET_3 "secret 3"
#define SECRET_4 "secret 4"
#define SECRET_5 "secret 5"
#endif

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5
};

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
#define NAV MO(_NAV)
#define FN MO(_FN)

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           SFTSLSH, 
		         KC_LGUI, KC_RALT,          LOWERSP, LOWERSP, RAISESP,          NAV,     FN),

	[_RAISE] = LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
		_______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_SCLN,          KC_QUOT,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),

	[_LOWER] = LAYOUT(
		KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
		_______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_COLN,          KC_DQT, 
		_______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_PIPE,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),
	
	[_NAV] = LAYOUT(
		_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_UP,   _______, _______, _______, 
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,         _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),
	
	[_FN] = LAYOUT(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
		KC_CAPS, MACRO_1, MACRO_2, MACRO_3, MACRO_4, MACRO_5, _______, _______, KC_F11,  KC_F12,          _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         CG_TOGG, 
		         RESET,   _______,          _______, _______, _______,          _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MACRO_1:
                SEND_STRING(SECRET_1);
                return false;
            case MACRO_2:
                SEND_STRING(SECRET_2);
                return false;
            case MACRO_3:
                SEND_STRING(SECRET_3);
                return false;
            case MACRO_4:
                SEND_STRING(SECRET_4);
                return false;
            case MACRO_5:
                SEND_STRING(SECRET_5);
                return false;
        }
    }

   return true;
};