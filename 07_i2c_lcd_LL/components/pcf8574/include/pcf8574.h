#pragma once

#include <driver/i2c_master.h>
#include <esp_err.h>

#define PCF8574_DEFAULT_ADDR 0x27

typedef struct 
{
    /* data */
    uint8_t address;
    uint8_t output_state;
    uint32_t frequency;
} pcf8574_t;

/**
 * @brief init pcf8574
 * 
 * @param device pcf8574 device handle
 * @param bus i2c master bus handle
 * @param address i2c device address
 */
esp_err_t pcf8574_init(
    pcf8574_t *device,
    i2c_master_bus_handle_t bus_handle
);