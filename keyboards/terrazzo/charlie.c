#include <math.h>
#include "quantum.h"
#include "charlie.h"

void charlie_set_pixel(uint8_t x, uint8_t y, uint8_t value) {
  const int width = 7;
  led_matrix_set_index_value(y * width + x, value);
}

void charlie_debug(void) {
}

uint8_t C_LED_INDEX = 0;

void charlie_scroll_pixel(bool clockwise) {

    if (clockwise) {
        C_LED_INDEX++;
    } else {
        C_LED_INDEX--;
    } 
    
    if (C_LED_INDEX >= LED_DRIVER_LED_COUNT) {
        C_LED_INDEX = 0;
    } else if (C_LED_INDEX <= 0 ) {
        C_LED_INDEX = LED_DRIVER_LED_COUNT - 1;
    }
}

void charlie_render(void) {
    // led_matrix_set_index_value(C_LED_INDEX, 5);
    charlie_swirl();
}

void charlie_swirl() {
    // 24 uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};
    uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60};
    // 7 uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10};
    uint8_t levels = 12;
    float soften = 5;

    for (int y = 0; y < 15; y++) {
        for (int x  = 0; x < 7; x++) {
            uint8_t target = (x+y+C_LED_INDEX)%levels;
            charlie_set_pixel(x, y, floor(sweep[target] / soften));
        }
    }
}