#include <print.h>
#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_RAISE,
	_LOWER,
	_NAV,
	_FN
};

// Tap for space, hold layer
#define LOWERSP LT(_LOWER, KC_SPC)
#define RAISESP LT(_RAISE, KC_SPC)

// Tap for backspace, hold layer
#define LOWRBSP LT(_LOWER, KC_BSPC)

// Tap for key, hold shift
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
// Tap for enter, hold control
#define KC_CENT LCTL_T(KC_ENT)
// Tap for /, hold shift
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)

// One shot mods
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)

enum combo_events {
  COMBO_BSPC,
  COMBO_DEL,
  COMBO_TAB,
  COMBO_ESC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_mit(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC, KC_BSPC,
        KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,    KC_H,    KC_SJ,   KC_K,     KC_L,    KC_CENT, KC_TAB,  KC_PGUP,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_UP,   SFTSLSH, KC_PGDN,
                 KC_LCTL, KC_LGUI, KC_RALT, LOWRBSP, RAISESP,          MO(_NAV), KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_RAISE] = LAYOUT_mit(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_DEL,  KC_ESC,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_MINS, KC_EQL,   KC_SCLN, KC_QUOT, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_LBRC,  KC_RBRC, _______, _______, _______, 
                 _______, _______, _______, _______, _______,          _______,  _______, _______, _______
    ),

    [_LOWER] = LAYOUT_mit(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS,  KC_COLN, KC_DQT,  _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_LCBR,  KC_RCBR, _______, _______, _______,
                 _______, _______, _______, _______, _______,          _______,  _______, _______, _______
    ),

    [_NAV] = LAYOUT_mit(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,    KC_END,  KC_PGUP, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,  KC_RGHT, KC_PGDN, _______, _______,
        OSM_SFT, OSM_CTL, OSM_GUI, OSM_ALT, XXXXXXX, XXXXXXX, XXXXXXX, _______,  KC_MUTE, KC_VOLD, KC_VOLU, _______,
                 _______, _______, _______, TO(_FN), _______,          _______,  KC_MPRV, KC_MPLY, KC_MNXT
    ),

    [_FN] = LAYOUT_mit(
	      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_PSCR, CG_TOGG,
		    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_F21,  KC_F23,
		    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_F20,  KC_F22,
		             RESET,   _______, _______, _______, _______,          TO(_BASE),_______, _______, _______
    )
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
};

#endif