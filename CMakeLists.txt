CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(lrmf_randgen)

# Eigen3
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(Eigen3 REQUIRED)
include_directories("${EIGEN3_INCLUDE_DIR}")

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(SOURCES
  RandGen/io.cpp
  RandGen/main.cpp
  RandGen/options.cpp
  RandGen/parser.cpp
)

# Create the executable.
ADD_EXECUTABLE(lrmf_randgen_exec ${SOURCES})

# Install command
INSTALL(TARGETS lrmf_randgen_exec DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
