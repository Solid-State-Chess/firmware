#include "ble.hpp"
#include "nimble/ble.h"
#include <cstdint>
#include <cstring>
#include <esp_bt.h>
#include <host/ble_gap.h>

BluetoothConnection::BluetoothConnection() : _connected{false} {
    
}

void BluetoothConnection::advertise(std::uint32_t duration) {
    struct ble_gap_adv_params params;
    memset(&params, 0, sizeof(params));
    
    params.channel_map = BLE_GAP_ADV_DFLT_CHANNEL_MAP;
    params.conn_mode = BLE_GAP_CONN_MODE_NON;
    params.disc_mode = BLE_GAP_DISC_MODE_GEN;
    
    ble_gap_adv_start(BLE_ADDR_RANDOM, NULL, duration * 1000, &params, &ble_gap_event_cb, this);
}

int BluetoothConnection::ble_gap_event_cb(ble_gap_event *ev, void *arg) { return reinterpret_cast<BluetoothConnection*>(arg)->on_ble_gap_event(ev); }

int BluetoothConnection::on_ble_gap_event(ble_gap_event *ev) {

}
