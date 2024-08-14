# Smart Pointers

This project includes custom implementations of two fundamental smart pointers in C++: `SharedPointer` and `UniquePointer`. These implementations provide functionality similar to `std::shared_ptr` and `std::unique_ptr` in the C++ Standard Library.

## Project Structure

- **`shared-pointer/`**: Contains the implementation and tests for the `SharedPointer`.

- **`unique-pointer/`**: Contains the implementation and tests for the `UniquePointer`.

- **`CMakeLists.txt`**: Top-level CMake configuration file that includes the subdirectories for building the `SharedPointer` and `UniquePointer`.


## Requirements

- C++17 or later
- CMake 3.10 or later
- Google Test (for unit testing)

## Building the Project

1. **Clone the repository:**
   ```sh
   git clone https://github.com/pooja-mane-07/smart-pointers.git

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


## Running the Executables

After building the project, you can run the example executables directly. From the `build` directory, use the following commands:

* For `SharedPointer`:
  ```sh
  ./shared_ptr_exe
  ```

* For `UniquePointer`:
  ```sh
  ./unique_ptr_exe
  ```

## Running the tests

**To run the unit tests for both smart pointers, use the following command from the build directory:**
   ```sh
   ctest --output-on-failure --verbose
   ```

## Running individual tests

**To run the unit tests for each smart pointer individually, use the following commands from the build directory:**

* For `SharedPointer`:
  ```sh
  ./shared-pointer/shared_ptr_test
  ```

* For `UniquePointer`:
  ```sh
  ./unique-pointer/unique_ptr_test
  ```
