#include <stdio.h>

#include <esp_log.h>    // log
#include <i2cdev.h>
#include <pcf8574.h>    // lib for ic pcf8574
#include <hd44780.h>    // lib for ic lcd

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

}
