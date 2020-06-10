TERRAZZO_EFFECT(HEART)
#ifdef TERRAZZO_EFFECT_IMPLS

static uint8_t full_heart[] = {
    0, 5, 5, 0, 5, 5, 0,
    5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5,
    0, 5, 5, 5, 5, 5, 0,
    0, 0, 5, 5, 5, 0, 0,
    0, 0, 0, 5, 0, 0, 0
};

void HEART(uint8_t i) {
    led_matrix_set_index_value_all(0);
    terrazzo_draw_at(0, 4, 7, 6, full_heart);
}

#endif