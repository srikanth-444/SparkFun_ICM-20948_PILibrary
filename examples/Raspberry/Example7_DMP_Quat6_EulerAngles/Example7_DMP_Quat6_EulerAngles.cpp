#include <iostream>
#include <iomanip>  // For setting decimal precision for float
#include <chrono>
#include <thread>
#include <cmath>  // For trigonometric functions like atan2

// Include your ICM20948 library here
#include "ICM_20948.h"  // Make sure to replace with the actual header file

#define SPI_PORT "/dev/spidev0.0"  // SPI device file on Raspberry Pi
#define CS_PIN 0                  // Chip select pin
#define AD0_VAL 1                 // I2C address (just an example)

ICM_20948_SPI myICM; // Assuming you're using SPI communication. Change to ICM_20948_I2C if using I2C.

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void setup() {
    std::cout << "Initializing ICM-20948..." << std::endl;
    delay(100);
    myICM.enableDebugging();
    bool initialized = false;
    while (!initialized) {
        // Initialize the ICM-20948 sensor
        if (myICM.begin() == ICM_20948_Stat_Ok) {
            std::cout << "Device connected!" << std::endl;
            initialized = true;
        } else {
            std::cout << "Initialization failed. Retrying..." << std::endl;
            delay(500);  // Retry after 500ms
        }
    }

    // Initialize DMP
    bool success = myICM.initializeDMP() == ICM_20948_Stat_Ok;
    if (success) {
        std::cout << "DMP enabled!" << std::endl;
    } else {
        std::cout << "Enable DMP failed!" << std::endl;
        std::cout << "Please check that you have uncommented the line (#define ICM_20948_USE_DMP) in ICM_20948_C.h..." << std::endl;
        exit(1);  // Exit if DMP initialization fails
    }

    // Enable Game Rotation Vector sensor and configure DMP
    success &= (myICM.enableDMPSensor(INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR) == ICM_20948_Stat_Ok);
    if (!success) {
        std::cout << "Failed to enable DMP sensor!" << std::endl;
        exit(1);
    }

    // Configure DMP to output data at multiple ODRs (optional)
    success &= (myICM.setDMPODRrate(DMP_ODR_Reg_Quat6, 0) == ICM_20948_Stat_Ok);
    success &= (myICM.enableFIFO() == ICM_20948_Stat_Ok);
    success &= (myICM.enableDMP() == ICM_20948_Stat_Ok);
    success &= (myICM.resetDMP() == ICM_20948_Stat_Ok);
    success &= (myICM.resetFIFO() == ICM_20948_Stat_Ok);

    if (success) {
        std::cout << "DMP initialization complete!" << std::endl;
    } else {
        std::cout << "DMP initialization failed!" << std::endl;
        exit(1);
    }
}

void loop() {
    icm_20948_DMP_data_t data;
    myICM.readDMPdataFromFIFO(&data);

    if ((myICM.status == ICM_20948_Stat_Ok) || (myICM.status == ICM_20948_Stat_FIFOMoreDataAvail)) {
        if ((data.header & DMP_header_bitmap_Quat6) > 0) {
            // Read and convert quaternion data
            double q1 = static_cast<double>(data.Quat6.Data.Q1) / 1073741824.0;  // Convert to double and divide by 2^30
            double q2 = static_cast<double>(data.Quat6.Data.Q2) / 1073741824.0;
            double q3 = static_cast<double>(data.Quat6.Data.Q3) / 1073741824.0;

            // Calculate roll, pitch, yaw using the quaternion data
            double q0 = sqrt(1.0 - ((q1 * q1) + (q2 * q2) + (q3 * q3)));  // q0 = sqrt(1 - q1^2 - q2^2 - q3^2)

            double qw = q0;
            double qx = q2;
            double qy = q1;
            double qz = -q3;

            double t0 = +2.0 * (qw * qx + qy * qz);
            double t1 = +1.0 - 2.0 * (qx * qx + qy * qy);
            double roll = atan2(t0, t1) * 180.0 / M_PI;

            double t2 = +2.0 * (qw * qy - qx * qz);
            t2 = t2 > 1.0 ? 1.0 : t2;
            t2 = t2 < -1.0 ? -1.0 : t2;
            double pitch = asin(t2) * 180.0 / M_PI;

            double t3 = +2.0 * (qw * qz + qx * qy);
            double t4 = +1.0 - 2.0 * (qy * qy + qz * qz);
            double yaw = atan2(t3, t4) * 180.0 / M_PI;

            // Output the Euler angles
            std::cout << "Roll: " << std::fixed << std::setprecision(1) << roll
                      << " Pitch: " << pitch
                      << " Yaw: " << yaw << std::endl;
        }
    }

    if (myICM.status != ICM_20948_Stat_FIFOMoreDataAvail) {
        delay(10);  // Wait for the next data
    }
}

int main() {
    setup();

    while (true) {
        loop();
    }

    return 0;
}
