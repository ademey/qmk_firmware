/* Copyright 2020 marksard
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

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _FN
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CENT RCTL_T(KC_ENT)
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)


enum combo_events {
  COMBO_BSPC,
  COMBO_DEL,
  COMBO_TAB,
  COMBO_ESC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_all(
    KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,   KC_BSPC,
    KC_A,     KC_S,     KC_D,     KC_SF,      KC_G,    KC_H,     KC_SJ,    KC_K,     KC_L,     KC_CENT,
    KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,    KC_N,     KC_M,     KC_COMM,   KC_DOT,  SFTSLSH,
    MO(_NAV),                     KC_LCTL, KC_NUM_SPC, MO(_NAV), MO(_FN)
  ),


  [_NUM_SYM] = LAYOUT_all(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,     KC_0,   KC_BSPC,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,  KC_GRV,   KC_MINS,  KC_EQL,  KC_SCLN,  KC_QUOT,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_LBRC, KC_RBRC,  _______,
    _______,                      _______,  _______,  _______,  _______
  ),

  [_NAV] = LAYOUT_all(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_UP,    KC_END,  KC_PGUP, KC_BSPC,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PGDN,
    KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,  XXXXXXX, MO(_FN),
    _______,                      RESET,    _______,  _______,  _______
  ),

  [_FN] = LAYOUT_all(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_BSPC,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_F20,   KC_F21,   KC_F22,  KC_F23,  XXXXXXX,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, CG_TOGG, _______,
    _______,                      RESET,    _______,  _______,  _______
  ),
};


void encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    case _NAV:
      // Change volume when on nav layer
      clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
      break;
    default:
      // Default encoder behavior of Page Up and Down
      clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
      break;
  }   
}

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

