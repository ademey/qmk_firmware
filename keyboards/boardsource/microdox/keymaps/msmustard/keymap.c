/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "split_util.h"

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _NAV,
    _FN
};

enum combo_events {
  COMBO_BSPC,
  COMBO_DEL,
  COMBO_TAB,
  COMBO_ESC,
};

#define LOWERSP LT(_LOWER, KC_SPC)
#define RAISESP LT(_RAISE, KC_SPC)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CENT RCTL_T(KC_ENT)
#define SFTSLSH MT(MOD_RSFT, KC_SLSH)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3( 
    //|--------------------------------------------|                    |--------------------------------------------|
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          KC_A,    KC_S,    KC_D,   KC_SF,    KC_G,                         KC_H,   KC_SJ,    KC_K,    KC_L,  KC_CENT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  SFTSLSH,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_LCTL, KC_LGUI, LOWERSP,    RAISESP, MO(_NAV),  MO(_FN)
                                //`--------------------------'  `--------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x5_3( 
    //|--------------------------------------------|                    |--------------------------------------------|
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV, KC_MINS,  KC_EQL, KC_SCLN,  KC_QUOT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, _______,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  _______, _______, _______,    _______, _______, _______
                                //`--------------------------'  `--------------------------'
  ),
  [_LOWER] = LAYOUT_split_3x5_3( 
    //|--------------------------------------------|                    |--------------------------------------------|
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_TILD,  KC_UNDS, KC_PLUS, KC_COLN,  KC_DQT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX, KC_PIPE, KC_LCBR, KC_RCBR, _______,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  _______, _______, _______,    _______, _______, _______
                                //`--------------------------'  `--------------------------'
  ),
  [_NAV] = LAYOUT_split_3x5_3( 
    //|--------------------------------------------|                    |--------------------------------------------|
        KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LGUI),OSM(MOD_LALT),XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  _______, _______, _______,    _______, _______, _______
                                //`--------------------------'  `--------------------------'
  ),
  [_FN] = LAYOUT_split_3x5_3( 
    //|--------------------------------------------|                    |--------------------------------------------|
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       RGB_MOD, RGB_HUI, RGB_SAI,  RGB_VAI, RGB_SPI,                      KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, CG_TOGG,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                       KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                     RESET, _______, RGB_TOG,    _______, _______, _______
                                //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}                     

void oled_render_layer_state(void) {
    uint8_t layer_index = get_highest_layer(layer_state);
    oled_write_P(PSTR("BASE"), layer_index == _QWERTY);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("_L"), layer_index == _LOWER);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("_R"), layer_index == _RAISE);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("NAV"), layer_index == _NAV);
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("FN"), layer_index  == _FN);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    if(keymap_config.swap_lctl_lgui) {
      oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
      oled_write_P(PSTR(" "), false);
      oled_write_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
      oled_write_P(PSTR(" "), false);
    } else {
      oled_write_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
      oled_write_P(PSTR(" "), false);
      oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
      oled_write_P(PSTR(" "), false);
    }
    oled_write_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("S"), keymap_config.swap_lctl_lgui);
}

void render_rgb_status(void) {

  uint8_t speed = rgblight_get_speed();
  uint8_t mode = rgblight_get_mode();
  uint8_t hue = rgblight_get_hue();
  uint8_t sat = rgblight_get_sat();
  uint8_t val = rgblight_get_val();
  oled_write_ln_P(PSTR(" M   H   S   V  Sp"), false);
  
  static char temp[19] = {0};
  // snprintf(temp, sizeof(temp) + 1, "M:%3dS:%3d", mode);
  snprintf(temp, sizeof(temp) + 1, "%3d %3d %3d %3d %3d", mode, hue, sat, val, speed);
  oled_write(temp, false);
}



void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    render_mod_status(get_mods());
    render_rgb_status();
  } else {
    oled_render_logo();
    // oled_scroll_left();
  }
}

#endif

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
