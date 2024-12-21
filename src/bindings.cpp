#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 
#include <pybind11/numpy.h>

#include "ICM_20948.h"
#include "ICM_20948_C.h"
#include "ICM_20948_DMP.h"

namespace py = pybind11;



PYBIND11_MODULE(icm20948, m) {

    py::enum_<ICM_20948_Status_e>(m, "ICM_20948_Status")
        .value("ICM_20948_Stat_Ok", ICM_20948_Stat_Ok)
        .value("ICM_20948_Stat_Err", ICM_20948_Stat_Err)
        .value("ICM_20948_Stat_NotImpl", ICM_20948_Stat_NotImpl)
        .value("ICM_20948_Stat_ParamErr", ICM_20948_Stat_ParamErr)
        .value("ICM_20948_Stat_WrongID", ICM_20948_Stat_WrongID)
        .value("ICM_20948_Stat_InvalSensor", ICM_20948_Stat_InvalSensor)
        .value("ICM_20948_Stat_NoData", ICM_20948_Stat_NoData)
        .value("ICM_20948_Stat_SensorNotSupported", ICM_20948_Stat_SensorNotSupported)
        .value("ICM_20948_Stat_DMPNotSupported", ICM_20948_Stat_DMPNotSupported)
        .value("ICM_20948_Stat_DMPVerifyFail", ICM_20948_Stat_DMPVerifyFail)
        .value("ICM_20948_Stat_FIFONoDataAvail", ICM_20948_Stat_FIFONoDataAvail)
        .value("ICM_20948_Stat_FIFOIncompleteData", ICM_20948_Stat_FIFOIncompleteData)
        .value("ICM_20948_Stat_FIFOMoreDataAvail", ICM_20948_Stat_FIFOMoreDataAvail)
        .value("ICM_20948_Stat_UnrecognisedDMPHeader", ICM_20948_Stat_UnrecognisedDMPHeader)
        .value("ICM_20948_Stat_UnrecognisedDMPHeader2", ICM_20948_Stat_UnrecognisedDMPHeader2)
        .value("ICM_20948_Stat_InvalDMPRegister", ICM_20948_Stat_InvalDMPRegister)
        .value("ICM_20948_Stat_NUM", ICM_20948_Stat_NUM)
        .value("ICM_20948_Stat_Unknown", ICM_20948_Stat_Unknown)
        .export_values();

    py::enum_<inv_icm20948_sensor>(m, "inv_icm20948_sensor")
        .value("INV_ICM20948_SENSOR_ACCELEROMETER", INV_ICM20948_SENSOR_ACCELEROMETER)
        .value("INV_ICM20948_SENSOR_GYROSCOPE", INV_ICM20948_SENSOR_GYROSCOPE)
        .value("INV_ICM20948_SENSOR_RAW_ACCELEROMETER", INV_ICM20948_SENSOR_RAW_ACCELEROMETER)
        .value("INV_ICM20948_SENSOR_RAW_GYROSCOPE", INV_ICM20948_SENSOR_RAW_GYROSCOPE)
        .value("INV_ICM20948_SENSOR_MAGNETIC_FIELD_UNCALIBRATED", INV_ICM20948_SENSOR_MAGNETIC_FIELD_UNCALIBRATED)
        .value("INV_ICM20948_SENSOR_GYROSCOPE_UNCALIBRATED", INV_ICM20948_SENSOR_GYROSCOPE_UNCALIBRATED)
        .value("INV_ICM20948_SENSOR_ACTIVITY_CLASSIFICATON", INV_ICM20948_SENSOR_ACTIVITY_CLASSIFICATON)
        .value("INV_ICM20948_SENSOR_STEP_DETECTOR", INV_ICM20948_SENSOR_STEP_DETECTOR)
        .value("INV_ICM20948_SENSOR_STEP_COUNTER", INV_ICM20948_SENSOR_STEP_COUNTER)
        .value("INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR", INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR)
        .value("INV_ICM20948_SENSOR_ROTATION_VECTOR", INV_ICM20948_SENSOR_ROTATION_VECTOR)
        .value("INV_ICM20948_SENSOR_GEOMAGNETIC_ROTATION_VECTOR", INV_ICM20948_SENSOR_GEOMAGNETIC_ROTATION_VECTOR)
        .value("INV_ICM20948_SENSOR_GEOMAGNETIC_FIELD", INV_ICM20948_SENSOR_GEOMAGNETIC_FIELD)
        .value("INV_ICM20948_SENSOR_WAKEUP_SIGNIFICANT_MOTION", INV_ICM20948_SENSOR_WAKEUP_SIGNIFICANT_MOTION)
        .value("INV_ICM20948_SENSOR_FLIP_PICKUP", INV_ICM20948_SENSOR_FLIP_PICKUP)
        .value("INV_ICM20948_SENSOR_WAKEUP_TILT_DETECTOR", INV_ICM20948_SENSOR_WAKEUP_TILT_DETECTOR)
        .value("INV_ICM20948_SENSOR_GRAVITY", INV_ICM20948_SENSOR_GRAVITY)
        .value("INV_ICM20948_SENSOR_LINEAR_ACCELERATION", INV_ICM20948_SENSOR_LINEAR_ACCELERATION)
        .value("INV_ICM20948_SENSOR_ORIENTATION", INV_ICM20948_SENSOR_ORIENTATION)
        .value("INV_ICM20948_SENSOR_B2S", INV_ICM20948_SENSOR_B2S)
        .value("INV_ICM20948_SENSOR_RAW_MAGNETOMETER", INV_ICM20948_SENSOR_RAW_MAGNETOMETER)
        .value("INV_ICM20948_SENSOR_MAX", INV_ICM20948_SENSOR_MAX)
        .export_values();  // Exports all the enum values to Python        

    py::enum_<DMP_ODR_Registers>(m, "DMP_ODR_Registers")
        .value("DMP_ODR_Reg_Accel", DMP_ODR_Reg_Accel)
        .value("DMP_ODR_Reg_Gyro", DMP_ODR_Reg_Gyro)
        .value("DMP_ODR_Reg_Cpass", DMP_ODR_Reg_Cpass)
        .value("DMP_ODR_Reg_ALS", DMP_ODR_Reg_ALS)
        .value("DMP_ODR_Reg_Quat6", DMP_ODR_Reg_Quat6)
        .value("DMP_ODR_Reg_Quat9", DMP_ODR_Reg_Quat9)
        .value("DMP_ODR_Reg_PQuat6", DMP_ODR_Reg_PQuat6)
        .value("DMP_ODR_Reg_Geomag", DMP_ODR_Reg_Geomag)
        .value("DMP_ODR_Reg_Pressure", DMP_ODR_Reg_Pressure)
        .value("DMP_ODR_Reg_Gyro_Calibr", DMP_ODR_Reg_Gyro_Calibr)
        .value("DMP_ODR_Reg_Cpass_Calibr", DMP_ODR_Reg_Cpass_Calibr)
        .export_values();  // Export values so they can be used in Python
      py::enum_<DMP_Header_Bitmap>(m, "DMP_Header_Bitmap")
        .value("Header2", DMP_header_bitmap_Header2)
        .value("Step_Detector", DMP_header_bitmap_Step_Detector)
        .value("Compass_Calibr", DMP_header_bitmap_Compass_Calibr)
        .value("Gyro_Calibr", DMP_header_bitmap_Gyro_Calibr)
        .value("Pressure", DMP_header_bitmap_Pressure)
        .value("Geomag", DMP_header_bitmap_Geomag)
        .value("PQuat6", DMP_header_bitmap_PQuat6)
        .value("Quat9", DMP_header_bitmap_Quat9)
        .value("Quat6", DMP_header_bitmap_Quat6)
        .value("ALS", DMP_header_bitmap_ALS)
        .value("Compass", DMP_header_bitmap_Compass)
        .value("Gyro", DMP_header_bitmap_Gyro)
        .value("Accel", DMP_header_bitmap_Accel)
        .export_values();  // Makes all enum values available in the Python module

    py::class_<ICM_20948>(m, "ICM_20948")
        .def(py::init<>()) // Constructor
        .def("setBank", &ICM_20948::setBank)
        .def("swReset", &ICM_20948::swReset)
        .def("sleep", &ICM_20948::sleep)
        .def("lowPower", &ICM_20948::lowPower)
        .def("setClockSource", &ICM_20948::setClockSource)
        .def("checkID", &ICM_20948::checkID)
        .def("dataReady", &ICM_20948::dataReady)
        .def("getWhoAmI", &ICM_20948::getWhoAmI)
        .def("isConnected", &ICM_20948::isConnected)
        .def("setSampleMode", &ICM_20948::setSampleMode)
        .def("setFullScale", &ICM_20948::setFullScale)
        .def("setDLPFcfg", &ICM_20948::setDLPFcfg)
        .def("enableDLPF", &ICM_20948::enableDLPF)
        .def("setSampleRate", &ICM_20948::setSampleRate)
        .def("clearInterrupts", &ICM_20948::clearInterrupts)
        .def("cfgIntActiveLow", &ICM_20948::cfgIntActiveLow)
        .def("cfgIntOpenDrain", &ICM_20948::cfgIntOpenDrain)
        .def("cfgIntLatch", &ICM_20948::cfgIntLatch)
        .def("cfgIntAnyReadToClear", &ICM_20948::cfgIntAnyReadToClear)
        .def("cfgFsyncActiveLow", &ICM_20948::cfgFsyncActiveLow)
        .def("cfgFsyncIntMode", &ICM_20948::cfgFsyncIntMode)
        .def("intEnableI2C", &ICM_20948::intEnableI2C)
        .def("intEnableDMP", &ICM_20948::intEnableDMP)
        .def("intEnablePLL", &ICM_20948::intEnablePLL)
        .def("intEnableWOM", &ICM_20948::intEnableWOM)
        .def("intEnableWOF", &ICM_20948::intEnableWOF)
        .def("intEnableRawDataReady", &ICM_20948::intEnableRawDataReady)
        .def("write", &ICM_20948::write, 
             "Write data to a register",
             py::arg("reg"), py::arg("pdata"), py::arg("len"))
        .def("readMag", &ICM_20948::readMag, 
             "Read magnetometer data from a register",
             py::arg("reg"))
        .def("writeMag", &ICM_20948::writeMag, 
             "Write data to a magnetometer register",
             py::arg("reg"), py::arg("pdata"))
        .def("resetMag", &ICM_20948::resetMag, 
             "Reset the magnetometer")
        .def("enableFIFO", &ICM_20948::enableFIFO, 
             "Enable or disable FIFO",
             py::arg("enable"))
        .def("resetFIFO", &ICM_20948::resetFIFO, 
             "Reset FIFO")
        .def("setFIFOmode", &ICM_20948::setFIFOmode, 
             "Set FIFO mode (snapshot or stream)",
             py::arg("snapshot"))
        .def("getFIFOcount", &ICM_20948::getFIFOcount, 
             "Get the FIFO count",
             py::arg("count"))
        .def("readFIFO", &ICM_20948::readFIFO, 
             "Read data from FIFO",
             py::arg("data"), py::arg("len"))
        .def("enableDMP", &ICM_20948::enableDMP, 
             "Enable or disable the DMP (Digital Motion Processor)",
             py::arg("enable"))
        .def("resetDMP", &ICM_20948::resetDMP, 
             "Reset the DMP")
        .def("loadDMPFirmware", &ICM_20948::loadDMPFirmware, 
             "Load the DMP firmware if available")
        .def("setDMPstartAddress", &ICM_20948::setDMPstartAddress, 
             "Set the DMP start address",
             py::arg("address"))
        .def("enableDMPSensor", &ICM_20948::enableDMPSensor, 
             "Enable or disable a sensor for the DMP",
             py::arg("sensor"), py::arg("enable"))
        .def("enableDMPSensorInt", &ICM_20948::enableDMPSensorInt, 
             "Enable or disable the DMP sensor interrupt",
             py::arg("sensor"), py::arg("enable"))
        .def("writeDMPmems", &ICM_20948::writeDMPmems, 
             "Write to the DMP memory",
             py::arg("reg"), py::arg("length"), py::arg("data"))
        .def("readDMPmems", &ICM_20948::readDMPmems, 
             "Read from the DMP memory",
             py::arg("reg"), py::arg("length"), py::arg("data"))
        .def("setDMPODRrate", &ICM_20948::setDMPODRrate, 
             "Set the output data rate (ODR) for the DMP sensor",
             py::arg("odr_reg"), py::arg("interval"))
        .def_readwrite("status", &ICM_20948::status) 
        .def("readDMPdataFromFIFO", [](ICM_20948 &self){
            icm_20948_DMP_data_t data;
            self.readDMPdataFromFIFO(&data);
            return std::make_tuple(data.header, data.Quat6.Data.Q1, data.Quat6.Data.Q2, data.Quat6.Data.Q3);
          
        })
        .def("setGyroSF", &ICM_20948::setGyroSF, 
             "Set the Gyro Scale Factor (SF)",
             py::arg("div"), py::arg("gyro_level"))
        .def("initializeDMP", &ICM_20948::initializeDMP, 
             "Initialize the DMP with the necessary configuration")
        .def("startupMagnetometer", &ICM_20948::startupMagnetometer, 
             "Startup the magnetometer with optional minimal configuration",
             py::arg("minimal") = false)
        .def("magWhoIAm", &ICM_20948::magWhoIAm, 
             "Check the WHO_AM_I register of the magnetometer to verify it's working");
        // .def("writeSPI", &ICM_20948_write_SPI, 
        //      "Write to the SPI device",
        //      py::arg("reg"), py::arg("data"), py::arg("len"), py::arg("user"))
        // .def("readSPI", &ICM_20948_read_SPI, 
        //      "Read from the SPI device",
        //      py::arg("reg"), py::arg("buff"), py::arg("len"), py::arg("user"));
        

    py::class_<ICM_20948_SPI, ICM_20948>(m, "ICM_20948_SPI")
    .def(py::init<>())  // Constructor
    .def("begin", [](ICM_20948_SPI &self, const std::string &spiDevice, int spiSpeed) {
    return static_cast<int>(self.begin(spiDevice.c_str(), spiSpeed));
    });

}
