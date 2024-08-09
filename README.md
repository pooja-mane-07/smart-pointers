# Smart Pointers

This project provides a custom implementation of smart pointers in C++. Currently, it includes the implementation of a unique smart pointer: `UniquePointer`. Future plans include additional smart pointers, such as `SharedPointer`.

## Project Structure

- `include/`: Contains header files for smart pointer implementations.
  - `unique_ptr.h`: Implementation of the `UniquePointer`.

- `src/`: Contains application and example files.
  - `main.cpp`: Example usage of the `UniquePointer`.

- `tests/`: Contains unit tests for the smart pointers.
  - `test_unique_ptr.cpp`: Unit tests for the `UniquePointer`.

- `CMakeLists.txt`: CMake configuration file for building the project.

## Features

- **`UniquePointer`**: A custom implementation of a unique smart pointer that supports:
  - Default constructor
  - Parameterized constructor
  - Move constructor
  - Move assignment operator
  - Reset method
  - Conversion to `bool` for validity checking

## Requirements

- C++17 or later
- CMake 3.10 or later
- Google Test (for unit testing)

## Building the Project

1. **Clone the repository:**
   ```sh
   git clone https://github.com/pooja-mane-07/smart-pointers.git
   cd smart-pointers

2. **Create a build directory and navigate to it:**
    ```sh
    mkdir build
    cd build

3. **Generate the build files using CMake:**
    ```sh
    cmake ..

4. **Build the project:**
    ```sh
    make

## Running the tests

**To run the unit tests, use the following command from the build directory::**
   ```sh
   ./test_unique_ptr
