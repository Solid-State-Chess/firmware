#include <stdio.h>
#include <esp_log.h>
#include <esp_nimble_hci.h>
#include <nvs_flash.h>

extern "C" void app_main(void) {
    ESP_ERROR_CHECK(nvs_flash_init());
    esp_nimble_hci_init();
}
