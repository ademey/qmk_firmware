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
#define NAV MO(_NAV)
#define FN MO(_FN)

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC, 
		KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,         KC_ENT, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       SFTSLSH, 
		         KC_LGUI, KC_RALT,          LOWERSP, LOWERSP, RAISESP,          NAV,     FN), 

	[_RAISE] = LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),

	[_LOWER] = LAYOUT(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),
	
	[_NAV] = LAYOUT(
		_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_UP,   _______, _______, _______, 
		_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,         _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		         _______, _______,          _______, _______, _______,          _______, _______),
	
	[_FN] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		         RESET,   _______,          _______, _______, _______,          _______, _______)
};

