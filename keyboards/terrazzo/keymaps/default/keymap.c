#include <print.h>
#include "terrazzo.h"
#include QMK_KEYBOARD_H


#define _______ KC_TRNS


enum custom_keycodes {
  INC = SAFE_RANGE,
  DEC,
  MODE,
  SPI,
  SPD
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
		  SPI,     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
	    INC,     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,            KC_ENT,
	    DEC,     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          SFTSLSH, 
	    MODE,             KC_LGUI, KC_RALT,          LOWERSP,          RAISESP,          MO(_NAV), MO(_FN)
  ),
  
  [_RAISE] = LAYOUT(
      _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_SCLN,          KC_QUOT,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC,          _______, 
	    _______,          _______, _______,          _______,          _______,          _______, _______
  ),

  [_LOWER] = LAYOUT(
      _______, KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_COLN,          KC_DQT,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_LCBR, KC_RCBR,          _______, 
	    _______,          _______, _______,          _______,          _______,          _______, _______
  ),

  [_NAV] = LAYOUT(
      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_UP,   _______,  _______, _______,
	    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,          _______,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           _______, 
	    _______,          _______, _______,          _______,          _______,          _______, _______
  ),

  [_FN] = LAYOUT(
		  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
		  _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_F11,  KC_F12,          _______, 
		  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         CG_TOGG, 
		  _______,          RESET,   _______,          _______,          _______,          _______, _______
  )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      switch(keycode) {
          case INC:
              dprint("LED INC\n");
              terrazzo_step_mode();
              return true;
          case DEC:
              dprint("LED DEC\n");
              terrazzo_step_mode_reverse();
              // led_matrix_disable();
              // led_matrix_init();
              return true;
          case MODE:
              dprint("LED MODE\n");
              // led_matrix_decrease_val();
              return true;
      }
  }
	return true;
}


void keyboard_post_init_user(void) {
  debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  // printf("ENCODER %n \n", clockwise);
  terrazzo_scroll_pixel(clockwise);
  if (clockwise) {
      tap_code(KC_PGDN);
  } else {
      tap_code(KC_PGUP);
  }
}