cmake_minimum_required(VERSION 3.10)

# Project name
project(SmartPointers)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(shared-pointer)
add_subdirectory(unique-pointer)
