# Development Notes

## Prerequisites

This library is tested on WSL Ubuntu 22.04.2. The following dependencies are required:

- `leveldb` (https://github.com/google/leveldb)
- `googletest` (https://github.com/google/googletest)
- `s2geometry` (https://github.com/google/s2geometry)

## Build

```bash
mkdir build && cd build
```

If any of the dependencies are not installed in the default location, you can specify the location of additional include and library paths using CMake variable `CMAKE_PREFIX_PATH`:

```bash
cmake -DCMAKE_PREFIX_PATH=/path/to/custom/prefix -G Ninja ..
```

Then build the library:

```bash
cmake --build .
```

