# TamaHome ESP32-C3 UART USB Bridge

A custom ESP32-C3 firmware bridge designed to connect the **Tamagotchi Paradise** to the **TamaHome App** via USB.

---

## 🛠 Hardware Required

* **ESP32-C3** (Other ESP32 boards will work with minor adjustments in PlatformIO)
* **Tamagotchi Paradise**

### Optional
* 3D Printed Tamagotchi Paradise socket adapter ([Thingiverse Model #7310297](https://www.thingiverse.com/thing:7310297))

---

## 🚀 Installation & Flashing

### Step 1: Download Binaries
Download the latest binary files from the [Releases](https://github.com/FattLlama/TamaHome-ESP32-C3-UART-USB/releases) page.

### Step 2: Flash the Board
1. Connect your ESP32-C3 to your computer via USB.
2. Open a terminal, navigate to the folder containing your downloaded `.bin` files, and run `esptool.py`:

```esptool --chip esp32c3 --port <SERIAL_PORT_HERE> --baud 460800 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0000 bootloader.bin 0x8000 partitions.bin 0xe000 boot_app0.bin 0x10000 firmware.bin```

   1. **NOTE:** replace `<SERIAL_PORT_HERE>` with the serial port that your device is using. ex:
   2. Linux: `/dev/ttyACM0` or `/dev/ttyUSB0`
   3. Windows: `COM3` (check device manager)
   4. Mac: `/dev/cu.usbmodem*` or `/dev/cu.usbserial*`

## 🔌 Using the setup
Connect the pins of your Tamagotchi Paradise as such:

```
    Tama          ESP32-C3
    ┌────────┐     ┌─────────┐
    │  Tx    │────►│  GPIO5  │
    │  Gnd   │─────│  Gnd    │
    │  Rx    │◄────│  GPIO4  │
    └────────┘     └─────────┘
 ``` 
* Tama pins are (left to right) `Tx` — `Gnd` — `Rx`

## Connecting to TamaHome
1. Open [TamaHome App](https://ko-fi.com/s/1843fe1f03)
2. Click **Refresh** to make sure your COM port shows up
3. Select your corresponding COM / Serial port
4. Open a playdate on your Tama
5. Click "Test Echo" on TamaHome App

&nbsp;
***
### 📜 Credits:
The bulk of this code is adapted from [electronicayciencia/esp32-uart-bridge](https://github.com/electronicayciencia/esp32-uart-bridge). I've simply done the following:
* Ported it into an arduino-framework PlatformIO project
* Set the UART channel to 1 to isolate it from the ESP32's debug messages 
* Set the UART speed to match the Tama's 460800 since the UART speed (according to electronicayciencia) is not configurable after compilation