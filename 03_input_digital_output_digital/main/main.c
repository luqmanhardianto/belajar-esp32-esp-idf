#include <stdio.h>

#include <driver/gpio.h>    // library for configure gpio

#include <freertos/FreeRTOS.h>  // lib for time
#include <freertos/task.h>  // lib rof time

#include <esp_log.h>    // lib for log


#define pushButton_pin 21   // define gpio 21
#define led_pin 23  // define gpio 23

static const char *TAG = "input output digital project :";  // log tag


bool pushButton_state;  // variable for store pushButton state
bool led_state = false; // variable for led state

void app_main(void)
{
    gpio_reset_pin(pushButton_pin); // reset pushButton_pin state
    gpio_set_direction(pushButton_pin,GPIO_MODE_INPUT); // set pushButton_pin as input mode

    gpio_reset_pin(led_pin);    // reset led_pin state
    gpio_set_direction(led_pin,GPIO_MODE_OUTPUT);   // set led_pin as output mode

    pushButton_state = gpio_get_level(pushButton_pin);  // initial read state of pushButton_pin
    gpio_set_level(led_pin,led_state);  // initial set state (false) of led_pin
}
