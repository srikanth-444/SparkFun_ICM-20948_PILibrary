/****************************************************************
 * Example2_Advanced.ino
 * ICM 20948 Arduino Library Demo
 * Shows how to use granular configuration of the ICM 20948
 * Owen Lyke @ SparkFun Electronics
 * Original Creation Date: April 17 2019
 *
 * Please see License.md for the license information.
 *
 * Distributed as-is; no warranty is given.
 ***************************************************************/
#include "ICM_20948.h" // Click here to get the library: http://librarymanager/All#SparkFun_ICM_20948_IMU

ICM_20948_SPI myICM; // If using SPI create an ICM_20948_SPI object

void setup(){
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
}

int main(){
  setup();

  

  // In this advanced example we'll cover how to do a more fine-grained setup of your sensor
  std::cout<<"Device connected!"<<std::endl;

  // Here we are doing a SW reset to make sure the device starts in a known state
  myICM.swReset();
  if (myICM.status != ICM_20948_Stat_Ok)
  {
    std::cout<<"Software Reset returned: ";
    std::cout<<myICM.statusString()<<std::endl;
  }
  usleep(250000);

  // Now wake the sensor up
  myICM.sleep(false);
  myICM.lowPower(false);

  // The next few configuration functions accept a bit-mask of sensors for which the settings should be applied.

  // Set Gyro and Accelerometer to a particular sample mode
  // options: ICM_20948_Sample_Mode_Continuous
  //          ICM_20948_Sample_Mode_Cycled
  myICM.setSampleMode((ICM_20948_Internal_Acc | ICM_20948_Internal_Gyr), ICM_20948_Sample_Mode_Continuous);
  if (myICM.status != ICM_20948_Stat_Ok)
  {
    std::cout<<"setSampleMode returned: ";
    std::cout<<myICM.statusString()<<std::endl;
  }
  
  // Set full scale ranges for both acc and gyr
  ICM_20948_fss_t myFSS; // This uses a "Full Scale Settings" structure that can contain values for all configurable sensors

  myFSS.a = gpm2; // (ICM_20948_ACCEL_CONFIG_FS_SEL_e)
                  // gpm2
                  // gpm4
                  // gpm8
                  // gpm16

  myFSS.g = dps250; // (ICM_20948_GYRO_CONFIG_1_FS_SEL_e)
                    // dps250
                    // dps500
                    // dps1000
                    // dps2000

  myICM.setFullScale((ICM_20948_Internal_Acc | ICM_20948_Internal_Gyr), myFSS);
  if (myICM.status != ICM_20948_Stat_Ok)
  {
    std::cout<<"setFullScale returned: ";
    std::cout<<myICM.statusString()<<std::endl;
  }

  // Set up Digital Low-Pass Filter configuration
  ICM_20948_dlpcfg_t myDLPcfg;    // Similar to FSS, this uses a configuration structure for the desired sensors
  myDLPcfg.a = acc_d473bw_n499bw; // (ICM_20948_ACCEL_CONFIG_DLPCFG_e)
                                  // acc_d246bw_n265bw      - means 3db bandwidth is 246 hz and nyquist bandwidth is 265 hz
                                  // acc_d111bw4_n136bw
                                  // acc_d50bw4_n68bw8
                                  // acc_d23bw9_n34bw4
                                  // acc_d11bw5_n17bw
                                  // acc_d5bw7_n8bw3        - means 3 db bandwidth is 5.7 hz and nyquist bandwidth is 8.3 hz
                                  // acc_d473bw_n499bw

  myDLPcfg.g = gyr_d361bw4_n376bw5; // (ICM_20948_GYRO_CONFIG_1_DLPCFG_e)
                                    // gyr_d196bw6_n229bw8
                                    // gyr_d151bw8_n187bw6
                                    // gyr_d119bw5_n154bw3
                                    // gyr_d51bw2_n73bw3
                                    // gyr_d23bw9_n35bw9
                                    // gyr_d11bw6_n17bw8
                                    // gyr_d5bw7_n8bw9
                                    // gyr_d361bw4_n376bw5

  myICM.setDLPFcfg((ICM_20948_Internal_Acc | ICM_20948_Internal_Gyr), myDLPcfg);
  if (myICM.status != ICM_20948_Stat_Ok)
  {
    std::cout<<"setDLPcfg returned: ";
    std::cout<<myICM.statusString()<<std::endl;
  }

  // Choose whether or not to use DLPF
  // Here we're also showing another way to access the status values, and that it is OK to supply individual sensor masks to these functions
  ICM_20948_Status_e accDLPEnableStat = myICM.enableDLPF(ICM_20948_Internal_Acc, false);
  ICM_20948_Status_e gyrDLPEnableStat = myICM.enableDLPF(ICM_20948_Internal_Gyr, false);
  std::cout<<"Enable DLPF for Accelerometer returned: ";
  std::cout<<myICM.statusString(accDLPEnableStat)<<std::endl;
  std::cout<<"Enable DLPF for Gyroscope returned: ";
  std::cout<<myICM.statusString(gyrDLPEnableStat)<<std::endl;

  // Choose whether or not to start the magnetometer
  myICM.startupMagnetometer();
  if (myICM.status != ICM_20948_Stat_Ok)
  {
    std::cout<<"startupMagnetometer returned: ";
    std::cout<<myICM.statusString()<<std::endl;
  }

 
  std::cout<<"Configuration complete!"<<std::endl;
}


  


void loop()
{

  if (myICM.dataReady())
  {
    myICM.getAGMT();              // The values are only updated when you call 'getAGMT'
    //printRawAGMT( myICM.agmt ); // Uncomment this to see the raw values, taken directly from the agmt structure
    printScaledAGMT(&myICM);      // This function takes into account the scale settings from when the measurement was made to calculate the values with units
    usleep(30000);
  }
  else
  {
    std::cout<<"Waiting for data"<<std::endl;
    usleep(500000);
  }
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
