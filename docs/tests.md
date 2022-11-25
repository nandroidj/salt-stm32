

# Primeras pruebas con el flor STMCubeProgrammer + STMCube MX + CLion

Dado que de una me mandé a probar el cliente mqtt de hive mq cloud sin exito debido a alguno/s de los supuestos de manera individual o en su conjunto (parcial o no):

+ con agregar la URL y el puerto no fue suficiente para realizar la demo plaintext de freertos correctamente. en ningun momento se suscribio

+ si bien el proyecto compila, algunas de las biblbiotecas incorporadas para realizar la demo contienen uno o mas errores

+ agregue algunos printfs para probar aunque sea la impresion de mensajes por el flujo de salida utilizando el Serial Wire Viewer (SWV), debe estar asociado al ST-LINK si o si segun el manual,  del cual no obtuve mensaje alguno.


## Pruebas

1. Prueba de encender/apagar un led cada 1 seg en base al [tutorial de digikey](https://www.digikey.com/en/maker/projects/getting-started-with-stm32-introduction-to-stm32cubeide/6a6c60a670c447abb90fd0fd78008697) -> **[OK]**

2. Prueba de impesion a traves del flujo de salida segun el [articulo](https://forum.digikey.com/t/easily-use-printf-on-stm32/20157) en el foro de digikey 

3. Prueba del coreMQTT client [demo plaintext](https://www.freertos.org/mqtt/basic-mqtt-example.html)

3. prueba utilizando OpenOCD. Ver doc en otro markdown






































