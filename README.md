# qmk-orion

QMK Keymap for the [Ferris Sweep](https://github.com/davidphilipbarr/Sweep) with [Sea-Picro EXT](https://github.com/joshajohnson/sea-picro#sea-picro-ext) MCU.

## Instructions to flash

1. Git clone in `keyboards/ferris/sweep/keymaps` in `qmk-firmware` project under `orion`.
2. Connect the **left** side of split and short `GND`+`RST` pins on the MCU for 2 seconds to get into the bootloader.
3. Run the following at the root of `qmk_firmware` project:

   ```shell
   make ferris/sweep:orion:uf2-split-left
   ```

4. Connect the **right** side of split and short `GND`+`RST` pins on the MCU for 2 seconds to get into the bootloader.
5. Run the following at the root of `qmk_firmware` project:

   ```shell
   make ferris/sweep:orion:uf2-split-right
   ```
