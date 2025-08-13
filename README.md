# u8

![u8 library](u8.jpg)

Do not like ICU? Here is a basic UTF-8 library on C.

Please, see [u8.h](include/u8.h) for more details.

## Features

- UTF-8 aware string manipulation functions
- Rune (Unicode character) navigation and comparison
- String searching and length calculation
- Invalid UTF-8 sequence sanitization
- Lightweight and focused on UTF-8 basics

## Building

### Prerequisites

- CMake 3.10 or higher
- C compiler (GCC, Clang, MSVC)
- Conan 2.x package manager

### Build Instructions

```bash
# 1. Create build directory and install dependencies
mkdir build && cd build
conan install .. --build=missing

# 2. Configure with CMake
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# 3. Build the library and tests
make

# 4. Run tests
./u8_cunit
```

To clean the build:
```bash
rm -rf build
```

### Build Output

- `libu8.a` - Static library
- `u8_cunit` - Unit test executable

## Dependencies

- **CUnit** - Unit testing framework (managed via Conan)

