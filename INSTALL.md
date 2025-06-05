# How to Install

Installing *LibPacSet* is very simple to do. Here are the things to follow to build the project.

## Requirements

* C99
* C++11
* CMake versions 3.18 or higher
* GNU Make

C99 is used for understanding the C programming language--as well as its standard headers, C++11 is used for understanding the C++ language, CMake is used for building the project, and GNU Make is used for compiling the project onto your system.

To check the version of CMake, run `cmake --version` on your terminal. Make sure the version is higher than 3.18 so the project can be installed onto your system.

## Steps to Install

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacSet.git`

2. Go to the project you've just cloned using: `cd LibPacSet`

3. Create the build directory using: `mkdir build`

4. Build the project with CMake using: `cmake -S . -B build`

5. Compile the project using: `cmake --build build`

6. Install the project using: `sudo cmake --install build`

7. After installing, update the shared libraries by running: `sudo ldconfig`
