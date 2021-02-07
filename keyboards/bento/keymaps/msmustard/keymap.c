/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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

#if (__has_include("secrets.h"))
#include "secrets.h"
#else
#define SECRET_1 "secret 1"
#define SECRET_2 "secret 2"
#endif

enum layers {
    _BASE,
    _RGB,
    _MON,
    _MACRO,
    _V1,
    _V2,
    _V3
};

enum custom_keycodes {
    MORD_1 = SAFE_RANGE,
    MORD_2,
    MORD_3,
    MORD_4,
    MORD_5,
    MORD_6,
    MORD_7,
    MORD_8,
    MORD_9,
    MORD_10,
    MORD_11,
    MORD_12,
    MACRO_1,
    MACRO_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LGUI(KC_D), KC_MYCM, KC_MUTE,
        KC_MPLY  , KC_MNXT, TO(_RGB)
    ),
    [_RGB] = LAYOUT(
        RGB_MOD, RGB_VAI, RGB_TOG,
        RGB_RMOD, RGB_VAD, TO(_MON)
    ),
    [_MON] = LAYOUT(
        KC_F21, KC_F23, _______,
        KC_F20, KC_F22, TO(_MACRO)
    ),
    [_MACRO] = LAYOUT(
        MACRO_1, MACRO_2, _______,
        KC_NO, KC_ENT, TO(_V1)
    ),
    [_V1] = LAYOUT(
        MORD_1, MORD_2, _______,
        MORD_3, MORD_4, TO(_V2)
    ),
    [_V2] = LAYOUT(
        MORD_5, MORD_6, TO(_V1),
        MORD_7, MORD_8, TO(_V3)
    ),
    [_V3] = LAYOUT(
        MORD_9, MORD_10, TO(_V2),
        MORD_11, MORD_12, TO(_BASE)
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {

    switch(get_highest_layer(layer_state)) {
        case _RGB:           
           clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();

           // clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
        default:
            clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            break;
    }  
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*
     c1 Yes          cc1 Sorry     ccc1 Hold
     c2 No           cc2 Laugh     ccc2 Hello
     c3 Help         cc3 Thanks    ccc3 Follow
     c4 Insult       cc4 Friend    ccc4 Respect
     c5 Intimidate   cc5 Retreat   ccc5 Charge
    */ 
    if (record->event.pressed) {
        switch (keycode) {
            case MORD_1: SEND_STRING("c1"); break; // Yes
            case MORD_2: SEND_STRING("c2"); break; // No
            case MORD_3: SEND_STRING("ccc2"); break; // Hello
            case MORD_4: SEND_STRING("cc3"); break; // Thanks
            
            case MORD_5: SEND_STRING("cc1"); break; // Sorry
            case MORD_6: SEND_STRING("cc4"); break; // Friend
            case MORD_7: SEND_STRING("c4"); break; // Insult
            case MORD_8: SEND_STRING("ccc4"); break; // Respect

            case MORD_9: SEND_STRING("ccc5"); break; // Charge
            case MORD_10: SEND_STRING("cc5"); break; // Retreat
            case MORD_11: SEND_STRING("c5"); break; // Intimidate
            case MORD_12: SEND_STRING("ccc3"); break; // Follow
            
            case MACRO_1: SEND_STRING(SECRET_1); break;
            case MACRO_2: SEND_STRING(SECRET_2); break;
        }
    }
    return true;
};

const rgblight_segment_t PROGMEM mon_color_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_PURPLE}
);


const rgblight_segment_t PROGMEM macro_color_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM v1_color_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM v2_color_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM v3_color_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mon_color_layer,
    macro_color_layer,
    v1_color_layer,
    v2_color_layer,
    v3_color_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _MON));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MACRO));
    rgblight_set_layer_state(2, layer_state_cmp(state, _V1));
    rgblight_set_layer_state(3, layer_state_cmp(state, _V2));
    rgblight_set_layer_state(4, layer_state_cmp(state, _V3));
    
    return state;
}