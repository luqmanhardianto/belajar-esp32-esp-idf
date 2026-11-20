#pragma once

#include <driver/i2c_master.h>
#include <esp_err.h>

#define PCF8574_DEFAULT_ADDR 0x27

typedef struct 
{
    /* data */
    uint8_t address;
    i2c_master_dev_handle_t dev_handle;
    uint32_t frequency;
} pcf8574_t;

esp_err_t pcf8574_init(
    pcf8574_t *device,
    i2c_master_bus_handle_t bus_handle
);