idf_component_register(
    SRCS "ssc.cpp" "ble.cpp"
    INCLUDE_DIRS "."
    PRIV_REQUIRES bt nvs_flash
)
