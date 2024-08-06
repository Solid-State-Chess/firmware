#pragma once

#include "driver/i2c_types.h"
#include "esp_err.h"
#include <cstdint>
#include <driver/i2c_master.h>

namespace usb303b {

namespace reg {

static constexpr std::uint8_t
    DEVICE_ID = 0x01,
    DEVICE_TYPE = 0x03,
    PORTROLE = 0x03,
    CONTROL = 0x04,
    CONTROL_1 = 0x05,
    MANUAL = 0x09,
    RESET = 0x0A,
    MASK = 0x0E,
    MASK1 = 0x0F,
    STATUS = 0x11,
    STATUS1 = 0x12,
    TYPE = 0x13,
    INTERRUPT = 0x14,
    INTERRUPT1 = 0x15;
}

}

/// Wrapper for the USB303B IC connected over I2C bus used to select 15V USB power delivery
struct Usb303B {
public:
    static constexpr std::uint8_t I2C_ADDRESS = 0x42;

    inline constexpr Usb303B() : _i2c{} {}
    
    /// Add the USB303B device to the given I2C master bus, and probe the bus to ensure that a device with the expected address is present.
    /// \return ESP_OK if the device could be added and exists on the bus
    static esp_err_t create(Usb303B* self, i2c_master_bus_handle_t bus);
private:
    i2c_master_dev_handle_t _i2c;

    static constexpr std::uint16_t I2C_TX_RX_TIMEOUT_MS = 100;

    inline esp_err_t read_register(std::uint8_t id, std::uint8_t& rdbuf) {
        return i2c_master_transmit_receive(_i2c, &id, 1, &rdbuf, 1, I2C_TX_RX_TIMEOUT_MS);
    }
};
