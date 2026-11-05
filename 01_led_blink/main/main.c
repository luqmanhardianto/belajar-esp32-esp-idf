#include <stdio.h>

// access gpio esp32
#include <driver/gpio.h>

// access freeRTOS
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// access log esp32
#include <esp_log.h>

/*
hardware : esp32-devkitc_v4
connection : gpio 19 + --- led >|--- - gnd
*/

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

    // main loop
    while (1)
    {
        // toggle led_state
        led_state = !led_state;

        // set output level
        gpio_set_level(led_pin,led_state);

        // add data logger for led_state
        ESP_LOGI(TAG,"led_state: %s",led_state ? "on": "off");

        // delay 1000ms
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}
