# UniquePointer

## Overview

The `UniquePointer` is a custom implementation of a unique smart pointer similar to `std::unique_ptr` in the C++ Standard Library. It ensures that only one `UniquePointer` instance owns a given resource at any time, providing automatic resource management and preventing resource leaks.

## Project Structure

- **`include/`**: Contains header files for smart pointer implementations.
  - `unique_ptr.h`: Implementation of the `UniquePointer`.

- **`src/`**: Contains application and example files.
  - `main.cpp`: Example usage of the `UniquePointer`.

- **`tests/`**: Contains unit tests for the smart pointers.
  - `test_unique_ptr.cpp`: Unit tests for the `UniquePointer`.

- **`CMakeLists.txt`**: CMake configuration file for building the project.

## Features

- **`UniquePointer`**: A custom implementation of a unique smart pointer that supports:
  - Default constructor
  - Parameterized constructor
  - Move constructor
  - Move assignment operator
  - Reset method
  - Conversion to `bool` for validity checking

## Building the Project

1. **Create a build directory and navigate to it:**
    ```sh
    mkdir build
    cd build
    ```

2. **Generate the build files using CMake:**
    ```sh
    cmake ..
    ```

3. **Build the project:**
    ```sh
    make
    ```

## Running the Executable

After building the project, you can run the example executable directly. From the `build` directory, use the following command:

```sh
./unique_ptr_exe
```

## Running the Tests

To run the unit tests, use the following command from the build directory:

```sh
ctest --output-on-failure --verbose
```
or
```sh
./unique_ptr_test
```
