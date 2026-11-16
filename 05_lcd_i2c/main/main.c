#include <stdio.h>

#include <esp_log.h>    // log
#include <i2cdev.h>
#include <pcf8574.h>    // lib for ic pcf8574
#include <hd44780.h>    // lib for ic lcd
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define I2C_PORT        0
#define I2C_SDA_GPIO    21  // sda pin esp32
#define I2C_SCL_GPIO    22  // scl pin esp32
#define LCD_I2C_ADDR    0x27    // address lcd i2c pcf8574

static const char *TAG="LCD1602";   // variable log
static i2c_dev_t pcf8574;

// callback write byte from hd44780 to pcf8574
static esp_err_t write_lcd_data(const hd44780_t *lcd, uint8_t data)
{
    return pcf8574_port_write(&pcf8574,data);
}

void app_main(void)
{
    ESP_ERROR_CHECK(i2cdev_init()); // init i2c use i2cdev from esp-idf-lib

    memset(&pcf8574,0,sizeof(i2c_dev_t));   // init i2c for pcf8574
    ESP_ERROR_CHECK(pcf8574_init_desc(&pcf8574, 
        LCD_I2C_ADDR,
        I2C_PORT,
        I2C_SDA_GPIO,
        I2C_SCL_GPIO)); // init pcf8574

        // config pin mapping pcf8574 -> hd44780
        hd44780_t lcd = {
            .write_cb = write_lcd_data,
            .font = HD44780_FONT_5X8,
            .lines = 2,
            .pins = {
                .rs = 0,
                .e = 2,
                .d4 = 4,
                .d5 = 5,
                .d6 = 6,
                .d7 = 7,
                .bl = 3
            }
        };

        ESP_ERROR_CHECK(hd44780_init(&lcd));    // init lcd
        hd44780_switch_backlight(&lcd,true);    // turn on backlight

        hd44780_clear(&lcd);    // lcd clear
        hd44780_gotoxy(&lcd,0,0);   // set pointer in x=0,y=0
        hd44780_puts(&lcd,"hello esp-idf"); // write string

        hd44780_gotoxy(&lcd,0,1);   // set pointer in x0,y1
        hd44780_puts(&lcd,"hd44780 v1.2.6");

        ESP_LOGI(TAG,"teks successfully write in lcd");

        while (true)
        {
            /* code */
            vTaskDelay(pdMS_TO_TICKS(1000));    // delay 1000ms
        }
        
}
