#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.23)

# specify cross-compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# project settings
project(salt-stm32 C CXX ASM)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 90)


######################################################
## tcp/ip
# Allow the project to be organized into folders.
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set(CMAKE_VERBOSE_MAKEFILE ON)

set( MODULE_ROOT_DIR ./ )

set( KERNEL_DIRECTORY /Middlewares/Third_Party/FreeRTOS/Source/ )

######################################################



#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)


# coreMqtt
# Include filepaths for source and include.
include( coreMQTT/mqttFilePaths.cmake )


if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(
        Core/Inc

        Drivers/STM32F4xx_HAL_Driver/Inc
        Drivers/STM32F4xx_HAL_Driver/Inc/Legacy

        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
        Drivers/CMSIS/Device/ST/STM32F4xx/Include
        Drivers/CMSIS/Include

        coreMQTT/source/include
        coreMQTT/source/interface
        coreMQTT/test/cbmc/include
        coreMQTT/demo/


        FreeRTOS-Plus-TCP/source/include

        FreeRTOS-Plus-TCP/test/Coverity/ConfigFiles
        FreeRTOS-Plus-TCP/test/FreeRTOS-Kernel/portable/GCC/ARM_CM4F
        FreeRTOS-Plus-TCP/tools/CMock/vendor/unity/src
        FreeRTOS-Plus-TCP/source/portable/NetworkInterface/include

        Utilities/logging
        Utilities/backoff_algorithm/source/include

        network_transport/using_plaintext
        network_transport/sockets_wrapper/cellular

        FreeRTOS-Cellular-Interface/source/include
        FreeRTOS-Cellular-Interface/source/include/private
        FreeRTOS-Cellular-Interface/source/include/common
        FreeRTOS-Cellular-Interface/source/interface
        FreeRTOS-Cellular-Interface/test/unit-test
)

add_definitions(-DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx)


file(
        GLOB_RECURSE SOURCES
        "Core/*.*"
        "Middlewares/*.*"
        "Drivers/*.*"

        "Drivers/STM32F4xx_HAL_Driver/Src/*.c"

        "coreMQTT/source/*.c"

        "Utilities/backoff_algorithm/source/backoff_algorithm.c"
        "Utilities/backoff_algorithm/test/unit-test/Unity/examples/example_1/src/ProductionCode2.h"

        "FreeRTOS-Plus-TCP/source/FreeRTOS_IP_Timers.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_IP_Utils.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_Sockets.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_IP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_ARP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DHCP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DNS.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Cache.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Callback.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Networking.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Parser.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_ICMP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_IP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_Stream_Buffer.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Reception.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_State_Handling.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Transmission.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Utils.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_WIN.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_Tiny_TCP.c"
        "FreeRTOS-Plus-TCP/source/FreeRTOS_UDP_IP.c"

        "FreeRTOS-Plus-TCP/source/portable/NetworkInterface/STM32Fxx/NetworkInterface.c"

        "FreeRTOS-Plus-TCP/tools/CMock/vendor/unity/extras/fixture/src/unity_fixture.h"

        "network_transport/using_plaintext/using_plaintext.c"
        "network_transport/sockets_wrapper/cellular/sockets_wrapper.c"

        "FreeRTOS-Cellular-Interface/source/cellular_api.c"
        "FreeRTOS-Plus-TCP/source/portable/BufferManagement/BufferAllocation_2.c"

)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F429ZITX_FLASH.ld Core/Inc/stm32f4xx_hal_eth_macros.h)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")
