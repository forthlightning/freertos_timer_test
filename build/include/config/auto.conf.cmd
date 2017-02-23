deps_config := \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/freertos_timer_test/components/arduino/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/bt/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/esp32/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/ethernet/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/freertos/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/log/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/lwip/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/mbedtls/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/openssl/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/spi_flash/Kconfig \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/bootloader/Kconfig.projbuild \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/esptool_py/Kconfig.projbuild \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/components/partition_table/Kconfig.projbuild \
	/Users/maxfieldmorrison/NSR/solsense32/Firmware/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
