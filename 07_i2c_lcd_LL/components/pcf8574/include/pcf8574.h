#pragma once

#include <driver/i2c_master.h>
#include <esp_err.h>

typedef struct 
{
    /* data */
    i2c_master_dev_handle_t i2c_device;
    uint8_t address;
} pcf8574_t;


esp_err_t pcf8574_init(
    pcf8574_t *device,
    uint8_t address
);

esp_err_t pcf854_write(
    pcf8574_t *device,
    uint8_t data
);

esp_err_t pcf8574_read(
    pcf8574_t *device,
    uint8_t *data
);