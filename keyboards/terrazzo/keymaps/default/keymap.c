#include <print.h>
#include "terrazzo.h"
#include QMK_KEYBOARD_H

#include "charlie.h"


#define _______ KC_TRNS

#define _QWERTY 0
#define _LOWER 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  INC,
  DEC,
  MODE,
  SPI,
  SPD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
		SPI,    KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
	  INC,    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
	  DEC,    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, 
	  MODE,   KC_LGUI, KC_RALT, KC_SPC, KC_SPC, KC_RALT, KC_RGUI
  ),
  
  [_LOWER] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
              led_matrix_set_index_value(0, 5);
              return true;
          case DEC:
              dprint("LED DEC\n");
              led_matrix_set_index_value(1, 10);
              // led_matrix_disable();
              // led_matrix_init();
              return true;
          case MODE:
              dprint("LED MODE\n");
              led_matrix_set_index_value_all(4);
              return true;
      }
  }
	return true;
}

void led_matrix_indicators_user() {
  // led_matrix_set_index_value_all(5);
  charlie_render();
}

void led_matrix_indicators_kb(void) {
}

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  // debug_keyboard=true;
  //debug_mouse=true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  // printf("ENCODER %n \n", clockwise);
  charlie_scroll_pixel(clockwise);
  if (clockwise) {
      tap_code(KC_PGDN);
  } else {
      tap_code(KC_PGUP);
  }
}