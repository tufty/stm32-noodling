# Some STM32 Noodling #

Project to illustrate some (mis)use of ST's HAL, STM32CubeMX and where some workarounds are necessary.

The board I'm using is a "Baite" clone of the Maple Mini, running the updated Maple bootloader.  This puts the start location at 0x08002000.  The original bootloader puts the start location at 0x08005000, so if you're using that (or a different board), you'll need to change the linker script [STM32F103CBTx\_FLASH.ld](file://STM32F103CBTx_FLASH.ld) and [Core/Src/system\_stm32f1xx.c](Core/Src/system_stm32f1xx.c) to reflect the start location you're using.

I'm uploading using perpetual bootloader mode (press and release reset, then, while the led is flashing fast, press the second button) and dfu-util as follows

```
dfu-util -v -d "1eaf:003" -c 1 -i 0 -a 2 -D build/stm32-noodling.bin
```

Your mileage may vary.


We'll be using encoder input mode, generating stepper motor signalling, but doing as little actual work as possible.
