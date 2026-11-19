#pragma once

#include <driver/i2c_master.h>

typedef struct
{
    /* data */
    i2c_port_num_t port;
    uint32_t  sda_io;
    uint32_t scl_io;
    uint32_t frequency;

} i2c_bus_config_t;