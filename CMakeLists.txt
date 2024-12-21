cmake_minimum_required(VERSION 3.12)
project(ICM20948Bindings)

# Set pybind11 directory (assuming virtual environment)
set(pybind11_DIR "/home/raspi/Documents/env/lib/python3.11/site-packages/pybind11/share/cmake/pybind11")

# Find pybind11
find_package(pybind11 REQUIRED)

# Set output directory for the Python module
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)


# Collect C and C++ source files
file(GLOB C_SOURCES ${CMAKE_SOURCE_DIR}/src/util/*.c)
file(GLOB CPP_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src/util)  # Adjust the path if necessary


# Define the Python module
pybind11_add_module(icm20948
    src/bindings.cpp  # Python binding file
    ${CPP_SOURCES}
    ${C_SOURCES}
)

# Set C++ and C compilation flags
set_target_properties(icm20948 PROPERTIES CXX_STANDARD 11 C_STANDARD 99)

# Link additional libraries if needed (e.g., math library)
target_link_libraries(icm20948 PRIVATE m)

