TERRAZZO_EFFECT(OUTRUN)
#ifdef TERRAZZO_EFFECT_IMPLS

static uint8_t outrun_sun[25] = {
    0, 9, 9, 9, 0,
    7, 7, 7, 7, 7,
    4, 4, 4, 4, 4,
    2, 2, 2, 2, 2,
    0, 1, 1, 1, 0
};

static uint8_t outrun_ground[70] = {
    9, 9, 9, 9, 9, 9, 9,
    0, 0, 1, 1, 1, 0, 0,
    0, 2, 0, 2, 0, 2, 0,
    0, 2, 0, 2, 0, 2, 0,
    0, 2, 0, 4, 0, 2, 0,
    2, 0, 0, 5, 0, 0, 2,
    2, 0, 0, 5, 0, 0, 2,
    2, 0, 0, 6, 0, 0, 2,
    0, 0, 0, 7, 0, 0, 0,
    0, 0, 0, 8, 0, 0, 0
};

static uint8_t outrun_rows[4][63] = {
{
    1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
},
{
    0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
},
{
    1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 9, 9, 9, 9,
    0, 0, 0, 0, 0, 0, 0
},
{
    0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 9, 9, 9, 9
}
};

bool last_dir;
uint8_t change_index = 0;

void OUTRUN(uint8_t i, bool dir) {
    led_matrix_set_index_value_all(0);
    
    if(dir != last_dir) {
       change_index = i;
       // terrazzo_draw_at(1, 0, 5, 5, outrun_sun);
    }

    uint8_t change_diff = abs(i - change_index);

    if(change_diff < 4) { 
        if (dir) {
           terrazzo_draw_at(1, 4 - change_diff, 5, 1 + change_diff, outrun_sun);
        } else {
           terrazzo_draw_at(1, 0 + change_diff, 5, 5 - change_diff, outrun_sun);
        }
    } else if (dir) {
        terrazzo_draw_at(1, 0, 5, 5, outrun_sun);
    }

    // Sun is larger but render the top 3 rows only
    terrazzo_draw_at(0, 5, 7, 11, outrun_ground);
    terrazzo_draw_at(0, 6, 7, 10, outrun_rows[i % 4]);
    last_dir = dir;
}

#endif