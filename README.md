# mbed_for_VBLUno+CMSIS-DAP
These are resources that help use mbed OS (2, 5) for VBLUno board + CMSIS-DAP (DAPLink) interface of VNGIoTLab
http://iotviet.com.vn/

##1. Hardwares
###1.1. VNGIoTLab VBLUno board
+ Support: mbed-OS, Arduino IDE,...
+ CPU: Nordic nRF51822XXAC - 256KB Flash - 32KB RAM - ARM Cortex-M0
+ Arduino Uno Rev. 3 compatible connector for use with 3rd party shields
+ Bluetooth Low Energy (BLE)
+ Toolchain, compiler: mbed Online Compiler, ARM (Keil MDK), GCC_ARM, IAR
+ Flash program: Drag and Drop programming; USB-DAP with Keil, pyOCD, OpenOCD, and so on.
+ Debugging: Keil Debugger, pyOCD, OpenOCD GDB Debugger on GNU ARM Eclipse tool and so on.
+ Support Firmware Over The Air (OTA).
+ Accepts power through:
    + USB
    + Adapter (5-12v)
    + Power Pin on jumper.
+ Pinout: ![alt tag](https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP/blob/master/data/VBLUno_v1_Pinout-MBED.jpg)

###1.2. VNGIoTLab CMSIS-DAP (DAPLink) interface
+ Support: Programming and Debugging for VBLUno board
+ USB MSD: Support Drag-and-Drop programming
+ USB CDC: Virtual Comport
+ USB HID (DAP): For Debug
+ Diagrams: ![alt tag](https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP/blob/master/data/VBLUno_CMSIS-DAP.PNG)

##2. Tutorials with mbed-OS
[HERE](https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP/tree/master/Tutorial)
