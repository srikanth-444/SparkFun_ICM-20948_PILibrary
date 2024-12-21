# SparkFun ICM-20948 C++ Library

This is the C++ adaptation of the SparkFun library for the TDK InvenSense ICM-20948 Inertial Measurement Unit, a 9-Degree Of Freedom sensor, as used on the SparkFun 9DoF IMU Breakout - ICM-20948 (Qwiic).

This library includes support for the InvenSense Digital Motion Processor (DMP™) and SPI-based communication in C++ using the Raspberry Pi's `spidev0.0` interface. For further details, see [DMP.md](DMP.md).

## Repository Contents

- `/examples` - Example scripts for the library. Run these using C++.
- `/src` - Source files for the library.
- `CONTRIBUTING.md` - Guidelines on how to contribute to this library.
- `DMP.md` - Information about the InvenSense Digital Motion Processor (DMP™).

## Documentation

- **Hookup Guide**: Basic hookup guide for the SparkFun 9DoF IMU Breakout.
- **Raspberry Pi Setup**: The library is designed to work with Raspberry Pi using the `spidev0.0` interface for SPI communication. Ensure that SPI is enabled on your Raspberry Pi before using the library.

## Products that use this Library

- [SparkFun 9DoF IMU Breakout - ICM-20948 (Qwiic)](https://www.sparkfun.com/products/15335)
- [SparkFun OpenLog Artemis](https://www.sparkfun.com/products/16832)
- [SparkFun MicroMod Asset Tracker Carrier Board](https://www.sparkfun.com/products/17272)

## License Information

This product is open source! The original Arduino library is provided by SparkFun Electronics. See the included `License.md` for more information.

Distributed as-is; no warranty is given.

**Credits**: Full credits to SparkFun Electronics for their original work on the Arduino library. This C++ adaptation has been created to support Raspberry Pi applications with SPI-based communication via the `spidev0.0` interface and is based on their excellent work. This adaptation is an independent project and is not affiliated with SparkFun Electronics.
