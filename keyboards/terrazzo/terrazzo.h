#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00, K01, K02, K03, K04, K05, K70, K71, K72, K73, K74, K75, K65, \
	K10, K11, K12, K13, K14, K15, K60, K61, K62, K63, K64, K55, \
	K20, K21, K22, K23, K24, K25, K50, K51, K52, K53, K54, K45, \
	K30, K31, K32, K33, K40, K42, K43 \
) { \
	{ K00, K01, K02, K03, K04, K05, }, \
	{ K10, K11, K12, K13, K14, K15, }, \
	{ K20, K21, K22, K23, K24, K25, }, \
	{ K30, K31, K32, K33, KC_NO, KC_NO, },  \
	{ K40, KC_NO, K42, K43, KC_NO, K45, }, \
	{ K50, K51, K52, K53, K54, K55, },  \
	{ K60, K61, K62, K63, K64, K65, },  \
	{ K70, K71, K72, K73, K74, K75 }  \
}

// void charlie_debug(void);


