# How to Install

Installing *LibPacSet* is very simple to do. Here are the things to follow to build the project.

## Requirements

* C99
* C++11
* CMake versions 3.18 or higher
* MinGW (If building on Windows)
* Clang (If building on MacOS)
* Clang++ (If building on MacOS)
* GNU Make (If building on Linux)

C99 and C++11 are the versions for C and C++ respectively. CMake is the cross-platform compiler, making use of MinGW, Clang, Clang++, or GNU Make, depending on your system. MinGW is a compiler exclusive to Windows operating systems, Clang and Clang++ are exclusive to MacOS, and GNU Make is exclusive on Linux systems.

To check the version of CMake, run `cmake --version` on your terminal. Make sure the version is 3.18 or higher so the project can be installed onto your system.

## Steps to Install

**NOTE:** Installing the project onto your system requires admin rights. If you are a user in an operating system that isn't an admin, the installation process will not work.

### Windows

1. Run CMD as an admin (or open PowerShell), and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacSet.git`

2. Go to the project you've just cloned using: `cd LibPacSet`

3. Create the build directory using: `mkdir build`

4. Set up the project with CMake using: `cmake -S . -B build`

5. Build the project using: `cmake --build build`

6. Install the project using: `cmake --install build`

### MacOS

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacSet.git`

2. Go to the project you've just cloned using: `cd LibPacSet`

3. Create the build directory using: `mkdir build`

4. Set up the project with CMake using: `cmake -S . -B build`

5. Build the project using: `cmake --build build`

6. Install the project using: `sudo cmake --install build`

### Linux

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacSet.git`

2. Go to the project you've just cloned using: `cd LibPacSet`

3. Create the build directory using: `mkdir build`

4. Set up the project with CMake using: `cmake -S . -B build`

5. Build the project using: `cmake --build build`

6. Install the project using: `sudo cmake --install build`

7. After installing, update the shared libraries by running: `sudo ldconfig`
