# SharedPointer

## Overview

The `SharedPointer` is a custom implementation of a shared smart pointer similar to `std::shared_ptr` in the C++ Standard Library. It manages the lifecycle of a resource through reference counting, ensuring that the resource is properly deleted when the last `SharedPointer` pointing to it is destroyed or reset.

## Project Structure

- **`include/`**: Contains header files for smart pointer implementations.
  - `shared_ptr.h`: Implementation of the `SharedPointer`.

- **`src/`**: Contains application and example files.
  - `main.cpp`: Example usage of the `SharedPointer`.

- **`tests/`**: Contains unit tests for the smart pointers.
  - `test_shared_ptr.cpp`: Unit tests for the `SharedPointer`.

- **`CMakeLists.txt`**: CMake configuration file for building the project.

## Features

- **`SharedPointer`**: A custom implementation of a shared smart pointer that supports:
  - Default constructor
  - Parameterized constructor
  - Copy constructor
  - Move constructor
  - Copy assignment operator
  - Move assignment operator
  - `reset` method
  - `useCount` method to get the number of `SharedPointer` instances managing the resource
  - Conversion to `bool` for validity checking
  - Comparison operators (`==`, `!=`)

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
./shared_ptr_exe
```

## Running the Tests

To run the unit tests, use the following command from the build directory:

```sh
ctest --output-on-failure --verbose
```
or
```sh
./shared_ptr_test
```