#include <stdio.h>
#include "i2c_bus.h"

#include <esp_log.h>

static const char *TAG = "I2C-BUS";

static i2c_master_bus_handle_t i2c_bus_handle;

esp_err_t i2c_bus_init(
    const i2c_bus_config_t *config
)
{
    if (config == NULL)
    {
        return ESP_ERR_INVALID_ARG;
    }

    i2c_master_bus_config_t bus_config = {
        .i2c_port = config->port,
        .sda_io_num = config->sda_io,
        .scl_io_num = config->scl_io,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true
    };

    esp_err_t ret = i2c_new_master_bus(&bus_config,&i2c_bus_handle);

    if (ret!= ESP_OK)
    {
        ESP_LOGE(TAG,"I2C init failed");
        return ret;
    }

    ESP_LOGI(TAG,"I2C init success");
    
    return ESP_OK;
}