TERRAZZO_EFFECT(GRADIENT)
#ifdef TERRAZZO_EFFECT_IMPLS

void GRADIENT(uint8_t seed) {
    // 24 uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};
    // uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60};
    uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10};
    uint8_t levels = 7;
    float soften = 1;
    
    
    for (int y = 0; y < LED_MATRIX_ROWS; y++) {
        for (int x  = 0; x < LED_MATRIX_COLS; x++) {
            uint8_t target = ;
            terrazzo_set_pixel(x, y, floor(sweep[target] / soften));
        }
    }
}

#endif