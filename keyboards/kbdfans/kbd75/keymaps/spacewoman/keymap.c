// /c/Users/Anne/Dev/qmk_firmware
// make kbdfans/kbd75/rev2:spacewoman


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

#define _______ KC_TRNS


#define _BL 0 // base
#define _MAC 1
#define _GAME 2
#define _FN 3 // original fn
#define _LT 4 // lights


#define EMOJI LGUI(KC_DOT)
#define OSX_LT LCTL(KC_LEFT)
#define OSX_RT LCTL(KC_RGHT)
#define FN_SPC LT(_FN, KC_SPC)


enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACR0_5
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
        }
    }

   return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_BL] = LAYOUT_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,   KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,             KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_PGDN,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,              EMOJI,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,     MO(_LT),
    KC_LCTL,  KC_LGUI,  KC_LALT,                                FN_SPC,                                KC_RALT,  MO(_FN),            KC_LEFT,  KC_DOWN,   KC_RGHT
  ),

  [_MAC] = LAYOUT_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,   KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,             KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_PGDN,
    KC_LGUI,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,              EMOJI,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,     TO(_BL),
    KC_LCTL,  KC_LALT,  KC_LGUI,                                FN_SPC,                                KC_RGUI,  MO(_FN),            KC_LEFT,  KC_DOWN,   KC_RGHT
  ),

  [_GAME] = LAYOUT_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,   KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,             KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_PGDN,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,              EMOJI,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,     TO(_BL),
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                KC_RALT,  MO(_FN),            KC_LEFT,  KC_DOWN,   KC_RGHT
  ),


  [_FN] = LAYOUT_ansi(
    RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PAUS,  _______,
    _______,  MACRO_1,  MACRO_2,  MACRO_3,  MACRO_4,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,             XXXXXXX,
    _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  OSX_LT,   KC_UP,    OSX_RT,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    KC_CAPS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,            XXXXXXX,            TO(_GAME),
    _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,  TO(_MAC),
    _______,  _______,  _______,                                XXXXXXX,                                _______,  XXXXXXX,            KC_MPRV,  KC_MPLY,  KC_MNXT
  ),

  [_LT] = LAYOUT_ansi(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    XXXXXXX,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    XXXXXXX,  VLK_TOG,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
    XXXXXXX,            BL_TOGG,  BL_INC,   BL_DEC,   BL_BRTG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
  )
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls

// Modes
// 1 Solid
// 2-5 Pulse
// 6-8 Color Cycle
// 9-  Rainbow

uint8_t prev = _BL;
uint32_t mode = 1;
uint16_t hue = 255;
uint16_t sat = 255;
uint16_t val = 255;

void get_hsv(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
    mode = rgblight_get_mode();
}

void reset_hsv(void) {
    rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_enable();
    rgblight_mode(mode);
    reset_hsv();
    rgblight_setrgb(255, 0, 0);
}

void matrix_scan_user() {
    if (prev == _LT) {
      get_hsv();
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BL:
            rgblight_mode(1);
            rgblight_sethsv(HSV_SPRINGGREEN);
            break;
        case _MAC:
            rgblight_mode(1);
            rgblight_sethsv(HSV_CYAN);
            // HSV_TURQUOISE
            // HSV_TEAL
            // HSV_CYAN
            // rgblight_setrgb(222, 3, 255);
            break;
        case _GAME:
            rgblight_mode(1);
            rgblight_sethsv(HSV_GOLDENROD);
            break;            
        case _FN:
            rgblight_mode(1);
            rgblight_sethsv(HSV_PINK);
            break;
    }
    prev = layer;
    return state;
}

