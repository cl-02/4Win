# DummyCppCmakeRepo

## Using CMake and Mingw, under Windows
1. Install MSYS2 according to https://www.msys2.org/#installation
1. Install a compiler toolchain according to https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites
```
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```
2. Install CMake in MSYS2 according to https://www.msys2.org/docs/cmake/
```
pacman -S mingw-w64-x86_64-cmake
```
3a. Build and run tests
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
ctest

3b. Alternatively run main
```
Open project in VS Code, navigate to main.cpp. 
Select Run -> Start Debugging (F5). Then select Environment C++ GDB (GNU Debugger). Then g++.exe Create active file and debug.

