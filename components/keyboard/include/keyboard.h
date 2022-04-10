
#ifndef MY_KEYBOARD
#define MY_KEYBOARD

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define ROWS 4
#define COLS 3

/*
                    18  5   4
                    |   |   |
                 23 ---------
                    |   |   |
                 22 ---------
                    |   |   |
                 21 ---------
                    |   |   |
                 19 ---------
*/

typedef enum
{
   LOW,
   HIGH
} keyboard_output_t;

typedef enum
{
   COL_0,
   COL_1,
   COL_2
} keyboard_col_t;

void keypad_output_set(keyboard_output_t col0, keyboard_output_t col1, keyboard_output_t col2);
void keyboard_detect(keyboard_col_t col);
void keyboard_pins_init();
int keyboard_read();

#endif
