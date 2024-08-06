#include "usbc.hpp"
#include "driver/i2c_master.h"
#include "driver/i2c_types.h"
#include "esp_err.h"
#include "hal/i2c_types.h"


esp_err_t Usb303B::create(Usb303B *self, i2c_master_bus_handle_t bus) {
    static constexpr i2c_device_config_t USB303_CONFIG = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = I2C_ADDRESS,
        .scl_speed_hz = 5000,
        .scl_wait_us = 10000,
        .flags = {
            .disable_ack_check = false
        }
    };

    esp_err_t rc = i2c_master_bus_add_device(bus, &USB303_CONFIG, &self->_i2c);
    if(rc != ESP_OK) { return rc; }

    rc = i2c_master_probe(bus, I2C_ADDRESS, 1000);
    return rc;
}
