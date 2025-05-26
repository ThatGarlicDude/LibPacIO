# How to Install

Installing *LibPacSet* is very simple to do. Here are the things to follow to build the project.

## Requirements

* CMake versions 3.18 or higher
* GNU Make

CMake is used for building the project, and GNU Make is used for compiling the project onto your system.

To check the version of CMake, run `cmake --version` on your terminal. Make sure the version is higher than 3.18 so the project can be installed onto your system.

## Steps to Install

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacSet.git`

2. Create the build directory inside the root of the project (LibPacSet) using: `mkdir build`

3. Build the project with CMake using: `cmake -S . -B build`

4. Compile the project using: `cmake --build build`

5. Install the project using: `sudo cmake --install build`

6. After installing, update the shared libraries by running: `sudo ldconfig`
