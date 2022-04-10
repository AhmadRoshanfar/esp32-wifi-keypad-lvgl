#include "keyboard.h"

static const char *TAG = "Keyboard";

int rowPins[ROWS] = {13, 12, 14, 27};
int colPins[COLS] = {26, 25, 33};

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

int num = 10;

/*
    Rows as input and pullup
    COlumns as output
 */
void keyboard_pins_init()
{
    for (int i = 0; i < COLS; i++)
    {
        gpio_set_direction(colPins[i], GPIO_MODE_OUTPUT);
        gpio_set_level(colPins[i], 0);
    }

    for (int i = 0; i < ROWS; i++)
    {
        gpio_set_direction(rowPins[i], GPIO_MODE_INPUT);
        gpio_set_pull_mode(rowPins[i], GPIO_PULLUP_ONLY);
    }
}

void keypad_output_set(keyboard_output_t col0, keyboard_output_t col1, keyboard_output_t col2)
{
    gpio_set_level(colPins[0], col0);
    gpio_set_level(colPins[1], col1);
    gpio_set_level(colPins[2], col2);
}

void keyboard_detect(keyboard_col_t col)
{
    if (gpio_get_level(rowPins[0]) == 0)
        ESP_LOGI(TAG, "print %c", keys[0][col]);

    else if (gpio_get_level(rowPins[1]) == 0)
        ESP_LOGI(TAG, "print %c", keys[1][col]);
    else if (gpio_get_level(rowPins[2]) == 0)
        ESP_LOGI(TAG, "print %c", keys[2][col]);
    else if (gpio_get_level(rowPins[3]) == 0)
        ESP_LOGI(TAG, "print %c", keys[3][col]);
}

int keyboard_read()
{
    keypad_output_set(LOW, HIGH, HIGH);
    keyboard_detect(COL_0);

    keypad_output_set(HIGH, LOW, HIGH);
    keyboard_detect(COL_1);

    keypad_output_set(HIGH, HIGH, LOW);
    keyboard_detect(COL_2);

    vTaskDelay(120 / portTICK_RATE_MS);

    num = num + 1;
    return num;
}
