#include <stdio.h>

// access gpio esp32
#include <driver/gpio.h>

// access freeRTOS
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// access log esp32
#include <esp_log.h>

// led_pin gpio19
#define led_pin 19

// create log tag
static const char *TAG = "01_led_blink_project";

void app_main(void)
{
    // reset gpio led_pin
    gpio_reset_pin(led_pin);

    // set led_pin as output
    gpio_set_direction(led_pin,GPIO_MODE_OUTPUT);

    // set initial state of led_pin
    bool led_state = false;

}
