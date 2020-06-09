TERRAZZO_EFFECT(DOT)
#ifdef TERRAZZO_EFFECT_IMPLS

void DOT(uint8_t i) {
    led_matrix_set_index_value_all(0);
    led_matrix_set_index_value(i, 10);
}

#endif