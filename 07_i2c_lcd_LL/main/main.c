#include <stdio.h>

#include <i2c_bus.h>
#include <pcf8574.h>

#include <esp_log.h>

static const char *TAG="MAIN";

void app_main(void)
{
    i2c_master_bus_handle_t bus_handle = NULL;
    
    const i2c_bus_config_t i2c_config = {
        .port = I2C_NUM_0,
        .sda_io = 21,
        .scl_io = 22,
        .frequency = 100000
    };


    ESP_ERROR_CHECK(i2c_bus_init(&i2c_config, &bus_handle));

    pcf8574_t pcf8574_config = {
        .address = 0x27,
        .frequency = 100000
    };

    ESP_ERROR_CHECK(pcf8574_init(
        &pcf8574_config,
        bus_handle
    ));

    ESP_LOGI(TAG,"App start");
}
