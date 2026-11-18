#include <stdio.h>

#include <esp_log.h>

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

void app_main(void)
{

}
