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

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient


#define _BL 0
#define _WIN 1
#define _FN 2
#define _CL 3

#define FN_SPC LT(_FN, KC_SPC)

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO  |Ctrl |
   * `-----------------------------------------------------------'
   */
    [_BL] = LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          XXXXXXX,
        KC_LCTL,          KC_LALT, KC_LGUI, XXXXXXX,          FN_SPC ,          XXXXXXX, KC_RGUI, KC_RALT, XXXXXXX, MO(_CL),          KC_RCTL),

    [_WIN] = LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          XXXXXXX,
        KC_LCTL,          KC_LGUI, KC_LALT, XXXXXXX,          FN_SPC ,          XXXXXXX, KC_RALT, KC_RGUI, XXXXXXX, MO(_CL),          KC_RCTL),


    /* Keymap : Second Layer (WASD and Media)
   * ,-----------------------------------------------------------.
   * |ESC| F1| F2| F3  |   |   |   |   |   |   |   |   |   | DEL |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

    [_FN] = LAYOUT(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_DEL ,
        _______,          KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______,
        KC_CAPS,          KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______,          _______,          _______, _______, _______, _______, _______,          _______),

   /* Keymap : Third Layer (RGB / Reset)
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

    [_CL] = LAYOUT(
        KC_GRV , MACRO_1, MACRO_2, MACRO_3, MACRO_4, MACRO_5, _______, _______, _______, _______, _______, _______, KC_PSCR, XXXXXXX, KC_SLEP,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET  ,
        _______,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, _______, _______, _______, _______,          _______,
        _______, _______, BL_DEC , BL_TOGG, BL_INC , BL_STEP, _______, _______, _______, _______, _______, _______, TO(_WIN),         _______,
        _______,          _______, _______, _______,          _______,          _______, _______, _______, _______, _______,          TO(_BL))

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