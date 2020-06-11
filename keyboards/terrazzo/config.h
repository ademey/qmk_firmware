#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    msmustard
#define PRODUCT         Terrazzo
#define DESCRIPTION     40

/* key matrix size */
#define MATRIX_ROWS 8 
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { D2, D7, E6, B4, B5, B6, B2, B3 }
#define MATRIX_COL_PINS { D3, F4, F5, F6, F7, B1 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW


#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D4 }
#define ENCODER_RESOLUTION 4

#define BACKLIGHT_LEVELS 20
#define LED_MATRIX_MAXIMUM_BRIGHTNESS 20


// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
#ifdef LED_MATRIX_ENABLE
#define LED_DRIVER_ADDR_1 0x74 
// (0x74 << 1)


#define LED_DRIVER_COUNT 1
#define LED_DRIVER_LED_COUNT 105
#define LED_MATRIX_ROWS 15
#define LED_MATRIX_COLS 7
#endif
#endif
