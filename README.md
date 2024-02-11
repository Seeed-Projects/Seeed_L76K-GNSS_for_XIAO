
<div align="center">

# **L76K GNSS Module for SeeedStudio XIAO**

This repository contains Arduino example code for the Quectel L76K GNSS Module, designed to be used with the SeeedStudio XIAO series development boards. The L76K module supports multi-GNSS systems including GPS, BeiDou, GLONASS, and QZSS, providing high-precision and energy-efficient positioning capabilities.

</div>
<p align="center">
  <a href="https://wiki.seeedstudio.com/get_start_l76k_gnss/">
    <img src="https://files.seeedstudio.com/wiki/Seeeduino-XIAO-Expansion-Board/GPS_Module/L76K/1-L76K-GNSS-Module-for-Seeed-Studio-XIAO-45font.jpg" width="480" height="auto" alt="SenseCAP">
  </a>
</p>
</div>

## Features

- Multi-GNSS support for GPS, BeiDou, GLONASS, and QZSS.
- Enhanced reception with built-in Low Noise Amplifier and Surface Acoustic Wave Filter.
- High precision with up to 32 tracking channels.
- Energy-efficient with low current consumption in tracking and standby modes.
- Comes with a high-performance active GNSS antenna.

## Getting Started

### Hardware Requirements

- A SeeedStudio XIAO development board (SAMD21, RP2040, nRF52840, ESP32C3, or ESP32S3).
- The L76K GNSS Module for SeeedStudio XIAO.
- An active GNSS antenna (included with the module).

### Software Setup

1. **Install Arduino IDE** - Download and install the Arduino IDE from the [official Arduino website](https://www.arduino.cc/en/software).

2. **Configure Arduino IDE for SeeedStudio XIAO** - Follow the instructions in the [Seeed Wiki](https://wiki.seeedstudio.com/Seeeduino-XIAO/#software) to add support for your specific XIAO development board.

3. **Install TinyGPSPlus Library** - In the Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries...`, search for "TinyGPSPlus", and install the library.

### Examples

This repository includes several example sketches demonstrating how to use the L76K GNSS Module:

- **BasicExample.ino** - Demonstrates basic GNSS data parsing and output.
- **LEDControl.ino** - Shows how to control the module's LED indicator through serial commands.

### Wiring

Connect the L76K GNSS Module to your XIAO development board according to the pinout provided in the module's documentation. Ensure the GNSS antenna is properly connected to the module before powering it up.

<p align="center">
    <img src="https://files.seeedstudio.com/wiki/Seeeduino-XIAO-Expansion-Board/GPS_Module/L76K/gnss-xiao-assembled.png" width="480" height="auto" alt="SenseCAP">
  </a>
</p>

## Example Usage

Open the `BasicExample.ino` sketch in the Arduino IDE, select your XIAO board and the correct COM port, then upload the sketch. Open the Serial Monitor at 115200 baud to see the parsed GNSS data being displayed.

## Troubleshooting

- Ensure the antenna has a clear view of the sky for optimal GNSS signal reception.
- If you encounter issues with GNSS data not being displayed, verify the module's wiring and check that the correct board configuration is selected in the Arduino IDE.

## Purchase

Get your L76K GNSS Module for SeeedStudio XIAO [here](https://www.seeedstudio.com/L76K-GNSS-Module-for-Seeed-Studio-XIAO-p-5864.html).

## Contributing

We welcome contributions to improve the examples and documentation. Please feel free to submit issues and pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
