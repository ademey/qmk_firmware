#include "terrazzo.h"

#ifdef LED_MATRIX_ENABLE
    #include "is31fl3731-simple.h"

const is31_led g_is31_leds[LED_DRIVER_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 * https://cdn-learn.adafruit.com/downloads/pdf/adafruit-15x7-7x15-charlieplex-led-matrix-charliewing-featherwing.pdf
 *  driver
 *  |   LED address
 *  |   | */
    {0, C1_2}, {0, C1_3}, {0, C1_4}, {0, C1_5}, {0, C1_6}, {0, C1_7}, {0, C1_8},
    {0, C2_2}, {0, C2_3}, {0, C2_4}, {0, C2_5}, {0, C2_6}, {0, C2_7}, {0, C2_8},
    {0, C3_2}, {0, C3_3}, {0, C3_4}, {0, C3_5}, {0, C3_6}, {0, C3_7}, {0, C3_8},
    {0, C4_2}, {0, C4_3}, {0, C4_4}, {0, C4_5}, {0, C4_6}, {0, C4_7}, {0, C4_8},
    {0, C5_2}, {0, C5_3}, {0, C5_4}, {0, C5_5}, {0, C5_6}, {0, C5_7}, {0, C5_8},
    {0, C6_2}, {0, C6_3}, {0, C6_4}, {0, C6_5}, {0, C6_6}, {0, C6_7}, {0, C6_8},
    {0, C7_2}, {0, C7_3}, {0, C7_4}, {0, C7_5}, {0, C7_6}, {0, C7_7}, {0, C7_8},
    {0, C8_2}, {0, C8_3}, {0, C8_4}, {0, C8_5}, {0, C8_6}, {0, C8_7}, {0, C8_8},
    //
    {0, C8_15},{0, C8_14},{0, C8_13},{0, C8_12},{0, C8_11},{0, C8_10},{0, C8_9},
    {0, C7_15},{0, C7_13},{0, C7_14},{0, C7_12},{0, C7_11},{0, C7_10},{0, C7_9},
    {0, C6_15},{0, C6_14},{0, C6_13},{0, C6_12},{0, C6_11},{0, C6_10},{0, C6_9},
    {0, C5_15},{0, C5_14},{0, C5_13},{0, C5_12},{0, C5_11},{0, C5_10},{0, C5_9},
    {0, C4_15},{0, C4_14},{0, C4_13},{0, C4_12},{0, C4_11},{0, C4_10},{0, C4_9},
    {0, C3_15},{0, C3_14},{0, C3_13},{0, C3_12},{0, C3_11},{0, C3_10},{0, C3_9},
    {0, C2_15},{0, C2_14},{0, C2_13},{0, C2_12},{0, C2_11},{0, C2_10},{0, C2_9}
};

/*
void setPixel(int x, int y, int value) {
  const int width = 7;
  led_matrix_set_index_value(y * width + x, value);
}

uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 18, 20, 30, 40,  50, 55, 60};

void led_matrix_indicators_kb(void) {

    led_matrix_set_index_value_all(1);

    for(int y = 0; y < 15; y++) {
        for(int x  = 0; x < 7; x++){
          setPixel(x, y, sweep[y]);
        }
    }
}


void charlie_debug(void) {
    led_matrix_set_index_value_all(4);
}
*/

#endif