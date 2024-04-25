cmake_minimum_required(VERSION 3.10)
project(AutomobilDemo)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Add executable
add_executable(AutomobilDemo ${SOURCES})