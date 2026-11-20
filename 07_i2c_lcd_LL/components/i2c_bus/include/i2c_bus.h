#pragma once

#include <driver/i2c_master.h>
#include <esp_err.h>

typedef struct
{
    /* data */
    i2c_port_num_t port;
    uint32_t  sda_io;
    uint32_t scl_io;
    uint32_t frequency;
} i2c_bus_config_t;

esp_err_t i2c_bus_init(
    const i2c_bus_config_t *config,
    i2c_master_bus_handle_t *bus_handle
);