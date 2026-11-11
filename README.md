# MYTemplate

A basic C++23 project template using CMake and Ninja.

## Requirements

* CMake
* Ninja
* GCC and/or Clang

## Build

List the available presets:

```bash
cmake --list-presets
```

Configure and build, for example with Clang:

```bash
cmake --preset debug-clang
cmake --build --preset debug-clang
```

Run the program:

```bash
./build/debug-clang/MYTemplate
```

Available configurations include:

* `debug-gcc`
* `debug-clang`
* `release-gcc`
* `release-clang`
* `asan-gcc`
* `asan-clang`
* `ubsan-gcc`
* `ubsan-clang`
* `tsan-gcc`
* `tsan-clang`
* `asan-ubsan-gcc`
* `asan-ubsan-clang`
* `tsan-ubsan-gcc`
* `tsan-ubsan-clang`
* `clang-tidy`

