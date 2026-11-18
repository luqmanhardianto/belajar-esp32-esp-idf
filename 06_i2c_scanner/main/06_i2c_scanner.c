#include <stdio.h>

#include <esp_log.h>
#include <esp_err.h>

#include <driver/i2c_master.h>

// i2c configuration
#define I2C_MASTER_SDA_IO 21    // gpio 21 as sda
#define I2C_MASTER_SCL_IO 22    // gpio 22 as scl

#define I2C_MASTER_FREQ_HZ 100000   // frequency 100_000 hz

#define I2C_ADDRESS_MIN 0x08    // i2c address range scan minimum
#define I2C_ADDRESS_MAX 0x77    // i2c address range scan maximum

#define I2C_PROBE_TIMEOUT_MS 100    // i2c timeout communication

// logging
static const char *TAG="I2C_SCANNER";

// i2c handle
static i2c_master_bus_handle_t i2c_bus_handle;  // init i2c master bus handle

static esp_err_t i2c_master_init(void){
    ESP_LOGI(TAG,"init i2c master");

    // configure i2c master
    i2c_master_bus_config_t i2c_master_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = -1, // auto select i2c port
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true
    };

    esp_err_t ret = i2c_new_master_bus(&i2c_master_config, &i2c_bus_handle);    // init i2c master

    if (ret!= ESP_OK)
    {
        ESP_LOGE(TAG,"i2c init failed: %s",
        esp_err_to_name(ret));

        return ret;
    }

    ESP_LOGI(TAG,"init success");
    return ret;
}

void app_main(void)
{
    ESP_LOGI(TAG,"starting i2c scanner");   // log starting app

    ESP_ERROR_CHECK(i2c_master_init()); // init i2c master check

}
