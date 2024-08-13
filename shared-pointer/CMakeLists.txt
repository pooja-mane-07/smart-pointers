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

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(gtest)

# Add the test executable
add_executable(test_shared_ptr tests/test_shared_ptr.cpp)

# Include directories for the test executable
target_include_directories(test_shared_ptr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link test executable against GoogleTest and pthread
target_link_libraries(test_shared_ptr PRIVATE gtest gtest_main pthread)
