# OpenOCD

## Tutorial from STM32 forum

1. Exclude syscalls.c
2. Add code for *initialise_monitor_handles()*
3. Set additional flag (*-specs=rdimon.specs -lc -lrdimon*) for linker
4. Use **ST-LINK OpenOCD** as debugger (haven't found a way myself to make the other two debuggers work for semihosting yet).
5. Add initialization commands (*monitor arm semihosting enable*) in "Startup" tab in Debug Configuration.

+ [stm32 forum for semihosting](https://community.st.com/s/question/0D50X0000B5HQMGSQ4/how-to-get-arm-semihosting-to-work-on-stm32cubeide)
+ [stm32 semihosting](https://shawnhymel.com/1840/how-to-use-semihosting-with-stm32/)


## Conexion desde la terminal

1. En la ruta donde se encuentra el binario del proyecto, e.g., `~/CLionProjects/xyz/cmake-build-debug/xyz.bin` se lanza el comando *OpenOCD* del cual se obtiene:

```
Open On-Chip Debugger 0.11.0
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
srst_only separate srst_nogate srst_open_drain connect_deassert_srst

Info : Listening on port 6666 for tcl connections
Info : Listening on port 4444 for telnet connections
Info : clock speed 2000 kHz
Info : STLINK V2J40M27 (API v2) VID:PID 0483:374B
Info : Target voltage: 3.254881
Info : stm32f4x.cpu: hardware has 6 breakpoints, 4 watchpoints
Info : starting gdb server for stm32f4x.cpu on 3333
Info : Listening on port 3333 for gdb connections
```


2. Luego, lancé el comando `openocd -f ~/../../usr/local/Cellar/open-ocd/0.11.0/share/openocd/scripts/board/st_nucleo_f4.cfg -c "program stmProgrammerTest.elf" -c reset` del cual obtuve:

```
Open On-Chip Debugger 0.11.0
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
srst_only separate srst_nogate srst_open_drain connect_deassert_srst

Info : clock speed 2000 kHz
Info : STLINK V2J40M27 (API v2) VID:PID 0483:374B
Info : Target voltage: 3.254881
Info : stm32f4x.cpu: hardware has 6 breakpoints, 4 watchpoints
Info : starting gdb server for stm32f4x.cpu on 3333
Info : Listening on port 3333 for gdb connections
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x08001644 msp: 0x20030000
Info : Unable to match requested speed 8000 kHz, using 4000 kHz
Info : Unable to match requested speed 8000 kHz, using 4000 kHz
** Programming Started **
Info : device id = 0x20036419
Info : flash size = 2048 kbytes
Info : Dual Bank 2048 kiB STM32F42x/43x/469/479 found
** Programming Finished **
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Unable to match requested speed 2000 kHz, using 1800 kHz
Info : Listening on port 6666 for tcl connections
Info : Listening on port 4444 for telnet connections
```



## Referencias

+ [stm32 forum for semihosting](https://community.st.com/s/question/0D50X0000B5HQMGSQ4/how-to-get-arm-semihosting-to-work-on-stm32cubeide)
+ [stm32 semihosting](https://shawnhymel.com/1840/how-to-use-semihosting-with-stm32/)


+ [Workshop](https://github.com/ethanhuanginst/STM32CubeIDE-Workshop-2019/tree/master/hands-on/03_printf)

+ [el robotista](https://elrobotista.com/en/posts/stm32-debug-linux/)

+ [stack exchange](https://electronics.stackexchange.com/questions/149387/how-do-i-print-debug-messages-to-gdb-console-with-stm32-discovery-board-using-gd)

+ [debugger clion](https://www.jetbrains.com/help/clion/configuring-debugger-options.html#debugger-renderers)


+ [flash program in stm cube programmer](https://docs.nanoframework.net/content/stm32/flash-cube-programmer.html)

+ [articulo digikey](https://forum.digikey.com/t/easily-use-printf-on-stm32/20157)



































