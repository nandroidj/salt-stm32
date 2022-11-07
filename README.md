# SAL/T + NUCLEO F429ZI + STMCUBE MX + CLion

En el paso a paso que se presenta a continuación se considera que ya se dispone de las siguientes aplicaciones, *toolchains* y compiladores:

* STM32CubeMX 

* CLion

* gcc-arm-none-eabi

* openocd


## Paso a Paso

1. Acceder al [link](https://www.jetbrains.com/help/clion/embedded-development.html) y realizar el tutorial propuesto.

El archivo de configuración elegido para el kit de desarrollo NUCLEO F429ZI ha sido [*st_nucleo_f4*](https://github.com/openocd-org/openocd/blob/master/tcl/board/st_nucleo_f4.cfg)

2. En el archivo `CMakeLists.txt` descomentar las siguientes líneas para habilitar la unidad de punto flotante (FPU):


```
#Uncomment for hardware floating point

add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
```

3. En el archivo `CMakeLists.txt` agregar las siguientes líneas para el uso de la biblioteca *coreMQTT* provista por *FreeRTOS-Plus*:

```
# Include filepaths for source and include.
include( coreMQTT/mqttFilePaths.cmake )

include_directories(
        "coreMQTT/source/include"
        "coreMQTT/source/interface"
)
```

* La inclusión de los *headers* se basa en lo propuesto por el repositorio `FreeRTOS/coreMQTT` para realizar una [prueba](https://github.com/FreeRTOS/coreMQTT/blob/main/test/CMakeLists.txt).

* [mqttFilePaths.cmake](https://github.com/FreeRTOS/coreMQTT/blob/main/mqttFilePaths.cmake) contiene la información de todas los archivos *source* y *header* que permiten construir la biblioteca MQTT.


4. En primera instancia, definir la etiqueta `#define MQTT_DO_NOT_USE_CUSTOM_CONFIG 1` en el archivo `core_mqtt.h` tal que temporalmente no sea necesario definir el encabezado `core_mqtt_config.h` 




## Próximos pasos

1. Extraer lo necesario del repositorio [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS) para el uso *standalone* del protocolo MQTT en la NUCLE F429ZI

2. Comenzar con la primera demo llamada [PlaintextMQTTExample](https://github.com/FreeRTOS/FreeRTOS/blob/main/FreeRTOS-Plus/Demo/coreMQTT_Windows_Simulator/MQTT_Plain_Text/DemoTasks/PlaintextMQTTExample.c) siguiendo la [documentación](https://www.freertos.org/mqtt/basic-mqtt-example.html)

3. Conectar el cliente montado en el kit de desarrollo con el broker del cluster provisto por [Hive MQ](https://console.hivemq.cloud/).

4. Analizar la relevancia de las otras demos propuestas y basarse en alguna/s de ella/s para desarrollar el cliente MQTT de interés. 

5. Probar la publicación del cliente MQTT (NUCLEO F429ZI) con el broker desarrollado en el backend.

6. Probar la suscripción del cliente MQTT (NUCLEO F429ZI) con el broker desarrollado en el backend.

7. Analizar si es necesario abstraer el client MQTT de FreeRTOS ([v3.1.1](https://www.freertos.org/mqtt/index.html)) en base a las mejoras propuestas por la última versión del protocolo [MQTT 5.0](https://docs.oasis-open.org/mqtt/mqtt/v5.0/).

+ [Differences between 3.1.1 and 5.0](https://github.com/mqtt/mqtt.org/wiki/Differences-between-3.1.1-and-5.0)

+ FreeRTOS esta linkeado con el producto [wolfMQTT client library](https://www.wolfssl.com/products/wolfmqtt/) de wolfssl ?


## Referencias

### Artículos / Foros

- [Build error STM32 HAL when FreeRTOS is enabled](https://youtrack.jetbrains.com/issue/CPP-18629/Build-error-STM32-HAL-when-FreeRTOS-is-enabled)

- [Artículo con LwIP (Lightweight TCP/IP)](https://m.blog.naver.com/eziya76/221938551688)


### Tutoriales

- [CLion for embedded development](https://www.jetbrains.com/help/clion/embedded-overview.html)

- [Tutorial CLion + STM32CubeMX](https://www.jetbrains.com/help/clion/embedded-development.html)

- [gcc-arm-none-eabi installation for MacOS](https://gist.github.com/joegoggins/7763637)

- [openocd installation for MacOS](https://formulae.brew.sh/formula/open-ocd)

- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

### Libros


- [Bare Metal C](https://nostarch.com/bare-metal-c)

- [Effective C](https://nostarch.com/Effective_C)

- [The C Programming Language](https://fr.wikipedia.org/wiki/The_C_Programming_Language)


### Videos

- [ARM Development](https://www.youtube.com/playlist?list=PLfByYz-5078aJuy57IaiLleK4M12BZwup)


### Tecnologías utilizadas

#### STM32

+ [Getting Started with STM32 - Introduction to FreeRTOS](https://www.digikey.com/en/maker/projects/getting-started-with-stm32-introduction-to-freertos/ad275395687e4d85935351e16ec575b1#:~:text=FreeRTOS%20is%20a%20free%20and,provides%20regular%20maintenance%20and%20support.)

+ [Hands-on: Start New STM32 Project](https://github.com/ethanhuanginst/STM32CubeIDE-Workshop-2019/tree/master/hands-on/01_Start)

+ [Getting Started with STM32 and Nucleo](https://youtube.com/playlist?list=PLEBQazB0HUyRYuzfi4clXsKUSgorErmBv)

+ [Introduction to RTOS](https://youtube.com/playlist?list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz)


+ [FreeRTOS on STM32](https://youtube.com/playlist?list=PLnMKNibPkDnFeFV4eBfDQ9e5IrGL_dx1Q)


#### FreeRTOS


- [TCP Stack demo](https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_TCP/TCP_Networking_Tutorial_Adding_Source_Files.html)

- [STM32CubeMX - With Example Work-flow](https://www.freertos.org/FreeRTOS-Plus/BSP_Solutions/ST/STM32CubeMX.html)

- [RTOS CORTEX M4](https://www.freertos.org/RTOS-Cortex-M3-M4.html)

#### CMSIS-RTOS2

- [Pagina principal](https://www.keil.com/pack/doc/CMSIS/RTOS2/html/rtos_api2.html)


#### arm based mcu setup with gcc-arm + neovim + macOS

- https://chmanie.com/post/2020/07/18/debugging-arm-based-microcontrollers-in-neovim-with-gdb/

- https://github.com/glegrain/STM32-with-macOS


#### STM32 NUCLEO

- [getting started with STM32 Nucleo](https://www.open-electronics.org/lets-code-with-stm32-nucleo/)































