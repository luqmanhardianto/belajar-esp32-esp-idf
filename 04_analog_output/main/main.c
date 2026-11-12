#include <stdio.h>

#include <driver/ledc.h>    // library for pwm led

static const char *TAG = "analog output project :";     // log variable

#define led_pin 23  // define gpio led pin

void app_main(void)
{
    // configure ledc timer
    ledc_timer_config_t led_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,  // speed mode ledc timer, esp32 only option LEDC_LOW_SPEED_MODE
        .duty_resolution = LEDC_TIMER_20_BIT,    // set duty cycle resolution to 20 bit 0 - 1.048.576
        .timer_num = LEDC_TIMER_0,  // timer source channel
        .freq_hz = 5000,    // ledc timer frequency (Hz)
        .clk_cfg = LEDC_AUTO_CLK    // source clock of timer
    };

    ledc_timer_config(&led_timer);  // init ledc timer config

    // configure ledc channel
    ledc_channel_config_t ledc_channel = {
        .gpio_num = led_pin, // set led pin to led pwm
        .speed_mode = LEDC_LOW_SPEED_MODE,  // speed mode ledc timer
        .channel = LEDC_CHANNEL_0,  // channel ledc
        .timer_sel = LEDC_TIMER_0,  // select timer source
        .duty = 0,  // set duty cycle range from 0 - dury resolution
        .hpoint = 0
    };

    ledc_channel_config(&ledc_channel); // init ledc channel

}
