# AdventOfCode2019
My entry for Advent Of Code 2019.

## How to build
### macOS
Use the command line to build the code. `cd` into the root directory using terminal and run this command:
```sh
cmake -H. -B_builds && cmake --build _builds
```
The build executables are available in subdirectory '_builds' and runnable.

You can run an executable using
```sh
./_builds/01-December
```
You can run a test using
```sh
./_builds/01-DecemberTest
```

### Windows
Use the command line to build the code. `cd` into the root directory using cmd and run this command:
```sh
cmake -H. -B_builds && cmake --build _builds
```
The build executables are available in subdirectory '_builds' and runnable.

You can run an executable using
```sh
/_builds/01-December.exe
```

NOTE: Since I use macOS dlls for googletest for Windows are not available. You can build them yourself and alter the CMakeLists.txt if you want to run the tests on Windows.
