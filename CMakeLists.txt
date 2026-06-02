cmake_minimum_required(VERSION 3.13)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

# PICO-SDK
if (DEFINED ENV{PICO_SDK_PATH})
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
else()
    set(PICO_SDK_PATH "${PROJECT_ROOT}/../pico-sdk")
endif()

# set(PICO_BOARD pimoroni_pico_plus2_rp2350)
# set(PICO_BOARD pico2)
set(PICO_BOARD weact_studio_rp2350b_core CACHE STRING "Board type")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(PicoPsramSample_project C CXX ASM)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.0.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.1.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

pico_sdk_init()

#ソースファイル
add_executable(PicoPsramSample
    ./source/main.cpp
    ./source/uart.cpp
    ./source/psram.cpp
)

target_link_libraries(PicoPsramSample
    pico_stdlib
    hardware_uart
    hardware_spi
    hardware_pio
    hardware_dma
)
pico_set_program_name(PicoPsramSample "PicoPsramSample")
pico_set_program_version(PicoPsramSample "0.0.1")
pico_enable_stdio_usb(PicoPsramSample 1)
pico_enable_stdio_uart(PicoPsramSample 0)

# target_include_directories(PicoPsramSample PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source)
target_include_directories(PicoPsramSample PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(PicoPsramSample)
