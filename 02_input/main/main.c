#include <stdio.h>

#include <driver/gpio.h>

#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

#include<esp_log.h>

static const char *TAG = "input project";   //create tag variable for projcet log

#define pushButton_pin 23   // define gpio 23 as input

bool pushButton_state = false;  //variable for store pushButton state

void app_main(void)
{
    gpio_reset_pin(pushButton_pin);     // reset gpio pin
    gpio_set_direction(pushButton_pin,GPIO_MODE_INPUT);     //set gpio pin as input mode

    while (1)
    {
        /* code */
        pushButton_state = gpio_get_level(pushButton_pin);  //get pushButton_pin level
        ESP_LOGI(TAG,"pushButtonState : %s", pushButton_state ? "low" : "high");    //log input push button state
        vTaskDelay(pdMS_TO_TICKS(1000));    //delay 1000ms
    }
    

}
