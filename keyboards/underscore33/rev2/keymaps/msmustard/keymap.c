/* Copyright 2020 tominabox1
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
  _NAV
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CENT RCTL_T(KC_ENT)
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)

// #define KC_NAV_ENT LT(_NAV, KC_ENT)
// #define KC_NAV_ENT LT(_NAV, KC_ENT)
// #define KC_GA LCTL_T(KC_A)
// #define KC_AS LGUI_T(KC_S)
// #define KC_CD LALT_T(KC_D)
// #define KC_AL RALT_T(KC_L)

enum combo_events {
  COMBO_BSPC,
  COMBO_DEL,
  COMBO_TAB,
  COMBO_ESC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_BASE] = LAYOUT_33_big_space(
    KC_Q,     KC_W,     KC_E,    KC_R,       KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,    KC_SF,      KC_G,    KC_H,     KC_SJ,    KC_K,     KC_L,     KC_CENT,
    KC_Z,     KC_X,     KC_C,    KC_V,       KC_B,    KC_N,     KC_M,     KC_COMM,   KC_DOT,  SFTSLSH,
                        KC_LCTL, KC_NUM_SPC, MO(_NAV)
  ),

  [_NUM_SYM] = LAYOUT_33_big_space(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,  KC_GRV,  KC_MINS,  KC_EQL,  KC_SCLN,  KC_QUOT,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_LBRC, KC_RBRC, _______,
                        _______,  _______,   _______ 
  ),

  [_NAV] = LAYOUT_33_big_space(
    KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,   XXXXXXX,  XXXXXXX,   KC_HOME,  KC_UP,    KC_END,  KC_PGUP,
    KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,   XXXXXXX,  XXXXXXX,   KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PGDN,
   OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LGUI),  OSM(MOD_LALT),   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX, CG_TOGG,
                        RESET,    _______,   _______
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
