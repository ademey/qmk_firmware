TERRAZZO_EFFECT(WPM_CHART)
#ifdef TERRAZZO_EFFECT_IMPLS

static uint8_t number_3_4[10][12] = {
{
    9, 9, 9,
    9, 0, 9,
    9, 0, 9,
    9, 9, 9
}, 
{
    0, 9, 0,
    9, 9, 0,
    0, 9, 0,
    9, 9, 9
},
{
    9, 9, 0,
    0, 0, 9,
    0, 9, 0,
    9, 9, 9
},
{ // 3
    9, 9, 9,
    0, 9, 0,
    0, 0, 9,
    9, 9, 0
},
{ // 4
    9, 0, 9,
    9, 0, 9,
    9, 9, 9,
    0, 0, 9
},
{ // 5
    9, 9, 9,
    9, 9, 0,
    0, 0, 9,
    9, 9, 9
},
{ // 6
    0, 0, 9,
    0, 9, 0,
    9, 0, 9,
    0, 9, 0
},
{ // 7
    9, 9, 9,
    0, 0, 9,
    0, 9, 0,
    9, 0, 0
},
{ // 8
    9, 9, 9,
    9, 0, 9,
    9, 4, 9,
    9, 9, 9
},
{ // 9
    9, 9, 9,
    9, 0, 9,
    9, 9, 9,
    0, 0, 9
}
};

void WPM_CHART(uint8_t i, bool dir) {
    led_matrix_set_index_value_all(0);
    uint8_t c_wpm = get_current_wpm();
    uint8_t half_wpm = floor(c_wpm / 2);
    for (int k = 0; k < half_wpm; k++) {
        led_matrix_set_index_value(k, 10);
    };
    uint8_t d1 = (int)floor(c_wpm / 10);
    if (c_wpm > 99) {
      uint8_t tens_place = d1 % 10;
      terrazzo_draw_at(0, 11, 3, 4, number_3_4[tens_place]);
    } else {
      terrazzo_draw_at(0, 11, 3, 4, number_3_4[d1]);
    }
    
    // Last character
    terrazzo_draw_at(4, 11, 3, 4, number_3_4[c_wpm % 10]);
}

#endif