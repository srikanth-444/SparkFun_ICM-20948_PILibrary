/****************************************************************
 * Example1_Basics.cpp
 * Modified by Srikanth Popuri 
 * Original code by Owen Lyke @ SparkFun Electronics
 * Based on SparkFun ICM-20948 library (MIT License)
 * 
 * See LICENSE.md for full licensing information.
 ***************************************************************/

#include "ICM_20948.h"  // Include the SparkFun ICM-20948 IMU library

// Create an instance of the ICM_20948_SPI object for SPI communication
ICM_20948_SPI myICM; // If using SPI create an ICM_20948_SPI object

// Main function
int main() {
    bool initialized = false; // Flag to track if the sensor is initialized

    // Try initializing the sensor until successful
    while (!initialized) {
        const char *spiDevice = "/dev/spidev0.0";  // SPI device on Raspberry Pi
        uint32_t SPIFreq = 7000000;  // SPI frequency set to 7 MHz

        // Initialize the sensor with the SPI device and frequency
        myICM.begin(spiDevice, SPIFreq);

        // Output the initialization result to the console
        std::cout << "Initialization of the sensor returned: " << myICM.statusString() << std::endl;

        // If the initialization was not successful, retry after a delay
        if (myICM.status != ICM_20948_Stat_Ok) {
            std::cout << "Trying again..." << std::endl;
            usleep(500000);  // Delay for 500 milliseconds before retrying
        }
        else {
            initialized = true;  // If initialized successfully, exit the loop
        }
    }

    // Infinite loop to continuously read and print data
    while (true) {
        // Check if data is ready to be read
        if (myICM.dataReady()) {
            // Fetch Accelerometer, Gyroscope, Magnetometer, and Temperature data
            myICM.getAGMT(); // The values are only updated when you call 'getAGMT'

            // Print the scaled sensor data (adjusted based on the scale settings)
            printScaledAGMT(&myICM);

            // Delay for 30 milliseconds before the next reading
            usleep(30000);
        }
        else {
            // If data is not ready, print a waiting message and wait
            std::cout << "Waiting for data" << std::endl;
            usleep(500000);  // Delay for 500 milliseconds before checking again
        }
    }

    return 0;  // Exit the program (though this part will never be reached)
}

// Helper function to print a 16-bit integer value with leading zeros for alignment
void printPaddedInt16b(int16_t val) {
    // If the value is positive, print a space, otherwise print a minus sign
    if (val > 0) {
        std::cout << " ";
    }
    else {
        std::cout << "-";
    }

    // Print leading zeros if the absolute value of the number is small
    int absVal = abs(val);
    if (absVal < 10000) std::cout << "0";
    if (absVal < 1000) std::cout << "0";
    if (absVal < 100) std::cout << "0";
    if (absVal < 10) std::cout << "0";

    // Finally, print the absolute value
    std::cout << absVal;
}

// Helper function to print raw Accelerometer, Gyroscope, Magnetometer, and Temperature data
void printRawAGMT(ICM_20948_AGMT_t agmt) {
    std::cout << "RAW. Acc [ ";
    printPaddedInt16b(agmt.acc.axes.x);  // Print accelerometer x-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.acc.axes.y);  // Print accelerometer y-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.acc.axes.z);  // Print accelerometer z-axis
    std::cout << " ], Gyr [ ";
    printPaddedInt16b(agmt.gyr.axes.x);  // Print gyroscope x-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.gyr.axes.y);  // Print gyroscope y-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.gyr.axes.z);  // Print gyroscope z-axis
    std::cout << " ], Mag [ ";
    printPaddedInt16b(agmt.mag.axes.x);  // Print magnetometer x-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.mag.axes.y);  // Print magnetometer y-axis
    std::cout << ", ";
    printPaddedInt16b(agmt.mag.axes.z);  // Print magnetometer z-axis
    std::cout << " ], Tmp [ ";
    printPaddedInt16b(agmt.tmp.val);     // Print temperature
    std::cout << " ]" << std::endl;      // End line after printing all data
}

// Helper function to print formatted float values with specified precision and width
void printFormattedFloat(float val, uint8_t leading, uint8_t decimals) {
    // Absolute value of the number (used for formatting)
    float aval = abs(val);

    // Print the sign for negative values
    if (val < 0) {
        std::cout << "-";
    } else {
        std::cout << " ";
    }

    // Print leading zeros if the absolute value of the number is small
    for (uint8_t indi = 0; indi < leading; indi++) {
        uint32_t tenpow = 0;
        if (indi < (leading - 1)) {
            tenpow = 1;
        }
        for (uint8_t c = 0; c < (leading - 1 - indi); c++) {
            tenpow *= 10;
        }
        if (aval < tenpow) {
            std::cout << "0";
        } else {
            break;
        }
    }

    // Print the floating-point value with the specified decimal places
    std::cout << std::fixed << std::setprecision(decimals) << val;
}

// Helper function to print scaled Accelerometer, Gyroscope, Magnetometer, and Temperature data
void printScaledAGMT(ICM_20948_SPI *sensor) {
    // Print scaled accelerometer data (in milligrams)
    std::cout << "Scaled. Acc (mg) [ ";
    printFormattedFloat(sensor->accX(), 5, 2);  // X-axis acceleration
    std::cout << ", ";
    printFormattedFloat(sensor->accY(), 5, 2);  // Y-axis acceleration
    std::cout << ", ";
    printFormattedFloat(sensor->accZ(), 5, 2);  // Z-axis acceleration
    std::cout << " ], Gyr (DPS) [ ";

    // Print scaled gyroscope data (in degrees per second)
    printFormattedFloat(sensor->gyrX(), 5, 2);  // X-axis gyroscope
    std::cout << ", ";
    printFormattedFloat(sensor->gyrY(), 5, 2);  // Y-axis gyroscope
    std::cout << ", ";
    printFormattedFloat(sensor->gyrZ(), 5, 2);  // Z-axis gyroscope
    std::cout << " ], Mag (uT) [ ";

    // Print scaled magnetometer data (in microteslas)
    printFormattedFloat(sensor->magX(), 5, 2);  // X-axis magnetometer
    std::cout << ", ";
    printFormattedFloat(sensor->magY(), 5, 2);  // Y-axis magnetometer
    std::cout << ", ";
    printFormattedFloat(sensor->magZ(), 5, 2);  // Z-axis magnetometer
    std::cout << " ], Tmp (C) [ ";

    // Print scaled temperature data (in Celsius)
    printFormattedFloat(sensor->temp(), 5, 2);
    std::cout << " ]" << std::endl;  // End line after printing all data
}
