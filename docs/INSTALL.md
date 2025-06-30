# How to Install

Installing *LibPacIO* is very easy to do. Here are the requirements and steps to follow in order to build the project.

## Requirements

* C99
* CMake versions 3.18 or higher
* GNU Make
* GCC (If building on Linux)
* Clang (If building on MacOS)

C99 is a version for the C language, the language that *LibPacIO* uses. CMake is a cross-platform build tool that helps set up, compile, and install the project onto your system. GNU Make is a build tool for Linux and MacOS that follows instructions that CMake generates. GCC is a C compiler for Linux, while Clang is a C compiler unique to MacOS.

To check the version of CMake, run `cmake --version` on your terminal. Make sure the version is 3.18 or higher so the project can be installed onto your system.

## Steps to Install

**NOTE:** Installing the project onto your system requires admin rights. If you are a user in an operating system that isn't an admin, the installation process will not work.

### Linux

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacIO.git`

2. Go to the project that you just cloned using: `cd LibPacIO`

3. Create the build directory using: `mkdir build`

4. Set up the project with CMake using: `cmake -S . -B build`

5. Build the project using: `cmake --build build`

6. Install the project using: `sudo cmake --install build`

7. After installing, update the linker by running: `sudo ldconfig`

Now you have *LibPacIO* installed onto your system! If you want to learn how to get started with this shared library, here's a [link to the manual](./manual/main.md).

### MacOS

1. Open your terminal, and clone the repository by using: `git clone --recurse-submodules https://github.com/ThatGarlicDude/LibPacIO.git`

2. Go to the project you've just cloned using: `cd LibPacIO`

3. Create the build directory using: `mkdir build`

4. Set up the project with CMake using: `cmake -S . -B build`

5. Build the project using: `cmake --build build`

6. Install the project using: `sudo cmake --install build`

Now you have *LibPacIO* installed onto your system! If you want to learn how to get started with this shared library, here's a [link to the manual](./manual/main.md).
