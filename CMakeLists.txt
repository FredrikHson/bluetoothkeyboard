cmake_minimum_required(VERSION 3.4)
# only for creating the compile_commands.json so clangd will work
project(squirrel_holocast_protocol)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(COMMON_SRC
    "bluetoothkeyboard.ino"
    "keyconfig.cpp"
    )

include_directories(
    "src/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/libraries/Bluefruit52Lib/src/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/nordic/nrfx/mdk/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/cmsis/include"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/nordic/softdevice/s132_nrf52_6.1.1_API/include"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/nordic/nrfx/hal/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/nordic/nrfx"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/nordic"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/Adafruit_TinyUSB_Core"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/libraries/Bluefruit52Lib/src/services/"
    "~/.arduino15/packages/adafruit/hardware/nrf52/0.14.6/cores/nRF5/Adafruit_TinyUSB_Core/tinyusb/src"
    )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

add_definitions("-x c++")
add_definitions("-DNRF52832_XXAA")
set_source_files_properties(bluetoothkeyboard.ino PROPERTIES LANGUAGE CXX)

add_executable(${CMAKE_PROJECT_NAME} ${COMMON_SRC})

