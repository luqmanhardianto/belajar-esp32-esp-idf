#include <stdio.h>
#include "pcf8574.h"

#include <esp_log.h>

static const char *TAG="pcf8574";

esp_err_t pcf8574_init(
    pcf8574_t *device,
    i2c_master_bus_handle_t bus_handle
)
{
    if (device == NULL|| bus_handle == NULL)
    {
        return ESP_ERR_INVALID_ARG;
    }
    
    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = device->address,
        .scl_speed_hz = device->frequency
    };

    esp_err_t ret = i2c_master_bus_add_device(
        bus_handle,
        &dev_config,
        &device->dev_handle
    );

    if (ret!= ESP_OK)
    {
        ESP_LOGE(TAG,"init failed");
        return ret;
    }

    ESP_LOGI(TAG,"init success");
    
    return ESP_OK;
}

esp_err_t pcf8574_write(
    pcf8574_t *device,
    uint8_t data
)
{
    if (device == NULL)
    {
        return ESP_ERR_INVALID_ARG;
    }

    esp_err_t ret = i2c_master_transmit(
        device->dev_handle,
        &data,
        sizeof(data),
        -1
    );

    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "write 0x%02X failed",data);
        return ret;
    }

    ESP_LOGI(TAG,"write 0x%02X success", data);

    return ESP_OK;
}