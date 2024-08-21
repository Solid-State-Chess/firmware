#pragma once

#include "host/ble_gap.h"
#include <cstdint>
#include <nimble/ble.h>

struct BluetoothConnection {
    BluetoothConnection();
    
    void advertise(std::uint32_t duration);

private:
    static int ble_gap_event_cb(struct ble_gap_event *ev, void *arg);
    int on_ble_gap_event(struct ble_gap_event *ev);

    bool _connected;
    std::uint16_t _conn_handle;
};
