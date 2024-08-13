cmake_minimum_required(VERSION 3.10)

# Project name
project(UniquePointer)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(unique_ptr_exe src/main.cpp)

# Include directories for the main application
target_include_directories(unique_ptr_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add tests
enable_testing()

# Find GoogleTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(unique_ptr_test tests/test_unique_ptr.cpp)
target_include_directories(unique_ptr_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(unique_ptr_test PRIVATE ${GTEST_LIBRARIES} gtest_main)

# Register the test with CTest
add_test(NAME UniquePointerTests COMMAND unique_ptr_test)
