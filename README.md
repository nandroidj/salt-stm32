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

3. Conectar el cliente montado en el kit de desarrollo con el cluster provisto por [Hive MQ](https://console.hivemq.cloud/).






## Referencias

### Artículos / Foros

- [Build error STM32 HAL when FreeRTOS is enabled](https://youtrack.jetbrains.com/issue/CPP-18629/Build-error-STM32-HAL-when-FreeRTOS-is-enabled)

### Tutoriales

- [CLion for embedded development](https://www.jetbrains.com/help/clion/embedded-overview.html)

- [Tutorial CLion + STM32CubeMX](https://www.jetbrains.com/help/clion/embedded-development.html)

- [gcc-arm-none-eabi installation for MacOS](https://gist.github.com/joegoggins/7763637)

- [openocd installation for MacOS](https://formulae.brew.sh/formula/open-ocd)



### Libros


- [Bare Metal C](https://nostarch.com/bare-metal-c)

- [Effective C](https://nostarch.com/Effective_C)

- [The C Programming Language](https://fr.wikipedia.org/wiki/The_C_Programming_Language)

