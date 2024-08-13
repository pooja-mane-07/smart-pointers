cmake_minimum_required(VERSION 3.10)

# Project name
project(SharedPointer)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(shared_ptr src/main.cpp)

# Include directories for the main application
target_include_directories(shared_ptr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
