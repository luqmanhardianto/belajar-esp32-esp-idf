#include <stdio.h>

#include <i2c_bus.h>

#include <esp_log.h>

static const char *TAG="MAIN";

void app_main(void)
{

    i2c_bus_config_t i2c_config = {
        .port = I2C_NUM_0,
        .sda_io = 21,
        .scl_io = 22,
        .frequency = 100000
    };

    ESP_ERROR_CHECK(i2c_bus_init(&i2c_config));

    ESP_LOGI(TAG,"App start");
}
