# PD-Camera for XIAO ESP32S3 Sense

This project is a port of the [PD-Camera for M5Stack](https://github.com/YOUR_ORIGINAL_M5STACK_REPO_LINK_IF_DIFFERENT) (which itself is based on the original [PD-Camera project](https://github.com/t0mg/pd-camera)) to the Seeed Studio XIAO ESP32S3 Sense.

![pd-camera-esp32](images/pd-camera-esp32.jpg)

>PD-Camera is an unofficial, experimental accessory for [Panic Inc.](https://panic.com/)'s [Playdate](https://play.date) handheld console, which as the name hopefully suggests allows the device to record pictures as well as animated gifs, in whopping  1-bit color and QVGA (320x240) resolution. Kind of similar to the [1998 accessory for that other monochrome handheld device](https://en.wikipedia.org/wiki/Game_Boy_Camera) (which has 2-bit color and fewer pixels).
>
>-- <cite>[PD-Camera project](https://github.com/t0mg/pd-camera/tree/main#pd-camera-project)</cite>


For more information, see the original [PD-Camera project](https://github.com/t0mg/pd-camera).

## PD-Camera for XIAO ESP32S3 Sense Features

- Install the companion app on Playdate and the PD-Camera firmware on your XIAO ESP32S3 Sense. All that's left to do is connect via USB cable. It works amazingly easy!

- The XIAO ESP32S3 Sense has a built-in camera and requires minimal external components.

- The PD-Camera for XIAO ESP32S3 Sense is not available with a dedicated cover or case.

## Disclaimer

>This project is 
>- not affiliated with nor endorsed by [Panic Inc.](https://panic.com/), 
>- highly experimental,
>- very hacky,
>   - oh so hacky.
>
>While I crashed my own Playdate countless times working on this, and it has survived so far, I cannot be held responsible for any damage, data loss, bad selfie, pandemic, etc. that might occur to you while playing with this project. Use this at your own risk. Thanks ❤️.
>
>-- <cite>[PD-Camera project](https://github.com/t0mg/pd-camera/tree/main#disclaimer)</cite>

PD-Camera for XIAO ESP32S3 Sense is very experimental as well. Enjoy at your own risk!

## Hardware

PD-Camera for XIAO ESP32S3 Sense requires the following hardware.

- [Playdate](https://play.date)

- [Seeed Studio XIAO ESP32S3 Sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html)

- [3.7v Battery (like this one)](https://www.amazon.it/dp/B08214DJLJ)

- USB-C cable

## Companion app

The companion app that needs to be sideloaded into Playdate can be the [PD-Camera project App](https://github.com/t0mg/pd-camera-app) from the original project.

## Firmware

## Building

This firmware is developed with [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide). Please read [PlatformIO IDE for VSCode](https://docs.platformio.org/en/stable/integration/ide/vscode.html) for detailed build instructions.

## Known issues

- Operation can be unstable; USB communication may be interrupted, companion app and firmware may freeze or crash. This is a work in progress.

- [Known Issues](https://github.com/t0mg/pd-camera-app#known-issues) with the Companion App may be reproduced as well.

## Dependency Libraries

- [PD-Camera project](https://github.com/t0mg/pd-camera) by [t0mg](https://github.com/t0mg)

    Based on the source code from the PD-Camera project, this firmware adapts it for the XIAO ESP32S3 Sense.

- [USB Host CDC-ACM Class Driver](https://github.com/espressif/idf-extra-components/tree/master/usb/usb_host_cdc_acm)

- [Template Repository for Generating User Custom Firmware for M5Burner v3](https://github.com/3110/m5burner-user-custom-platformio-template) by [SAITO, Tetsuya](https://github.com/3110) 

    The original M5Stack firmware was created for public use in [generate_user_custom.py](https://github.com/3110/m5burner-user-custom-platformio-template/blob/main/generate_user_custom.py). This is less relevant for the XIAO version but kept for historical context of the original port.

- [dithering_halftoning](https://github.com/deeptronix/dithering_halftoning) by [deeptronix](https://github.com/deeptronix)

## Referenced Sites

- [playdate-reverse-engineering](https://github.com/jaames/playdate-reverse-engineering) by [jaames](https://github.com/jaames)

- [M5CoreS3_CameraTest](https://github.com/ronron-gh/M5CoreS3_CameraTest) by [motoh](https://github.com/ronron-gh) (Referenced for the M5Stack version)

- [esp32-usb-host-demos](https://github.com/touchgadget/esp32-usb-host-demos) by [touchgadget](https://github.com/touchgadget)

- [EspUsbHost](https://github.com/tanakamasayuki/EspUsbHost) by [TANAKA Masayuki](https://github.com/tanakamasayuki)

- [ESP32-S3 USB Hostの調査1](https://note.com/ndenki/n/n2bba54a9b3cc) by [えぬでんき](https://note.com/ndenki)

## Special Thanks

My sincere thanks to [t0mg](https://github.com/t0mg) for releasing the very nice and exciting [PD-Camera project](https://github.com/t0mg/pd-camera)!

----

 Playdate is © [Panic Inc.](https://panic.com/) - this project isn't affiliated with or endorsed by them in any way.
 