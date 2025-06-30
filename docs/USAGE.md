# How to Use LibPacIO

## Table of Contents

1. Structs
2. Opening a ROM Set Directory
3. Printing a Directory
4. Loading a ROM File
5. Reading a ROM File
6. Writing a ROM File
7. Saving a ROM File
8. Conclusion

## Structs

*LibPacIO* offers two typedef structs that are unique to this utility. One being PacROM (`pac_rom_t`) and the other being PacROMSet (`pac_romset_t`). These structs represent what are in the PCBs for both *Pac-Man* and *Ms. Pac-Man*. When ROM-hacking the games, these structs are worth remembering.

### PacROM

```c
// Represents an 8-bit ROM within the Pac-Man and Ms. Pac-Man ROM sets.
typedef struct pac_rom {
	char* path;
	size_t size;
	uint8_t* data;
} pac_rom_t;
```
(Source: pacrom.h)

A PacROM (`pac_rom_t`) is a typedef struct that represents an 8-bit ROM within the *Pac-Man* and *Ms. Pac-Man* ROM sets. It includes `char* path`, which is the file path of the ROM, `size_t size` being the size of the ROM in bytes, and `uint8_t* data` being a dynamic array containing the ROM's bytes.

### PacROMSet

```c
// Represents the ROM set for the Pac-Man and Ms. Pac-Man PCBs.
typedef struct pac_romset {
	char* path;
	size_t size;
	char** roms;
} pac_romset_t;
```
(Source: pacromset.h)

A PacROMSet (`pac_romset_t`) is a typedef struct that represents the ROM sets for both *Pac-Man* and *Ms. Pac-Man*. Like PacROMs, it has `char* path` and `size_t size`, which have the same meaning, except the size refers to the amount of ROMs that are in the ROM set. The struct's sole unique feature is `char** roms`, which is a dynamic array that holds each of the ROM names in the ROM set.

## Opening a ROM Set Directory

### Opening

```c
// Creates a new PacROMSet, and opens the directory relating to it, getting all of its filenames inside of it.
pac_romset_t* pac_romset_open(const char* path);
```
(Source: pacromset.h)

To open a ROM Set Directory, you must call `pac_romset_open(const char* path)`. This function will create and allocate a PacROMSet somewhere in memory, set up all of its data, including the directory's filenames, and then return the pointer (`pac_romset_t*`) if successful. If the creation fails, it'll return `NULL` instead.

Its only argument, `const char* path` can be anything you want. It can be `"."`, which is your pwd (project working directory), but you have to make sure it is a valid directory. If there is no such thing as a directory you are looking for, the PacROMSet creation fails and returns `NULL`.

### Closing

```c
// Clears and frees everything regarding a PacROMSet from memory.
void pac_romset_close(pac_romset_t* romset);
```
(Source: pacromset.h)

To close and free a PacROMSet, you must use `pac_romset_close(pac_romset_t* romset)`. That function will clear everything about the PacROMSet, and frees the struct from memory.

This is a MUST-call function. If you are done working with a PacROMSet, you have to call that function to clear and free it. If you don't call it, the PacROMSet, as well as its contents will be dangling in memory until a program ends. So in that case, it is a good practice to call `pac_rom_set_close(pac_romset_t* romset)` when you are done using PacROMSets.

### Example

```c
#include <libpacio/pacromset.h>

int main(int argc, char* argv[]) {
	pac_romset_t* romset = pac_romset_open(".");
	pac_romset_close(romset);
	return 0;
}
```

Here, we included `<libpacio/pacromset.h>` because that's where the struct and the functions related to it are at. We declared a PacROMSet pointer called `romset`, and assigned it using `pac_romset_open(".")`, which creates a PacROMSet somewhere in memory, and sets up all of its data. The `"."` in the arguments refers to the project working directory (pwd) in your terminal. Since the creation is successful, the pointer points to that struct.

But since we're done using the PacROMSet, we close it using `pac_romset_close(romset)`, which clears and frees the struct from memory.

## Printing a Directory

```c
// Prints all information about a PacROMSet.
void pac_romset_print(const pac_romset_t* romset, const uint8_t flags);
```
(Source: print.h)

*LibPacIO* is also bundled with debugging tools, like printing!

To print a PacROMSet onto your terminal, you can call `pac_romset_print(const pac_romset_t* romset, const uint8_t flags)`. Make sure you have your newly opened PacROMSet, and don't worry about `uint8_t flags`. You're better off using `0xFF` just to print everything about a PacROMSet.

### Example

```c
#include <libpacio/pacromset.h>
#include <libpacio/print.h>

int main(int argc, char* argv[]) {
	pac_romset_t* romset = pac_romset_open(".");
	pac_romset_print(romset, 0xFF);
	pac_romset_close(romset);
	return 0;
}
```

Like in the previous example, we included `<libpacio/pacromset.h>`, but we also added in `<libpacio/print.h>`. That's where the debugging functions are at.

Yet again, we created a PacROMSet somewhere in memory, and got `romset` to point it. Then we print the PacROMSet using `pac_romset_print(romset, 0xFF)`. With `0xFF` as the flags, we print everything about the PacROMSet, including the filenames inside the ROM Set directory. As a fact, *LibPacIO* prints data in a very detailed fashion--using colors, bold text, and even tabs. Very neat if you come and think about it.

Since we're done with the PacROMSet, we close it using `pac_romset_close(romset)`.

## Loading a ROM File

Like PacROMSets, PacROMs can be created and allocated into memory. But their creation process is handled differently. Not only are there two different methods related to that, but they use "load" instead of "open" in their function names. It's something worth keeping note of.

### Loading via pac_rom_load()

```c
// Creates a new PacROM and loads its ROM file's data.
pac_rom_t* pac_rom_load(const char* path);
```
(Source: pacrom.h)

To load a PacROM without needing a PacROMSet, you can use `pac_rom_load(const char* path)`. This function will create a PacROM somewhere in memory, and set up everything in it, including its file's ROM data. Like the PacROMSet creation process, this function will also return a pointer to that struct if successful, but returns a null pointer if it fails.

### Loading via pac_romset_load_rom()

```c
// Loads a PacROM using an index for a PacROMSet's ROMs array.
pac_rom_t* pac_romset_load_rom(const pac_romset_t* romset, const size_t index);
```
(Source: pacromset.h)

This should be commonly used, since both *Pac-Man* and *Ms. Pac-Man* use ROM sets. Like `pac_rom_load(const char* path)`, it creates a PacROM somewhere in memory and points to it if successful. The only catch is that it uses `const size_t index`. The index refers to which ROM you want to select.

If you're not sure about which PacROM you want to work with, use `pac_romset_print(const pac_romset_t* romset)` to get a list of the ROM indexes. Don't worry, they're always sorted in lexicographical order each time you open up a PacROMSet, so they wouldn't be scattered in the directory.

### Unloading

```c
// Clears all data regarding a PacROM, and frees it from memory.
void pac_rom_unload(pac_rom_t* rom);
```
(Source: pacrom.h)

To unload a PacROM, all you need to do is call `pac_rom_unload(pac_rom_t* rom)`. This function will clear and free the struct from memory.

Like `pac_romset_close(pac_romset_t* romset)`, this function also needs to be called. If you are done working with a ROM, then it is a good practice to unload them from memory by calling that function.

### Example

```c
#include <libpacio/pacromset.h>
#include <libpacio/pacrom.h>
#include <libpacio/print.h>

int main(int argc, char* argv[]) {
	pac_romset_t* romset = pac_romset_open(".");
	pac_rom_t* rom = pac_romset_load_rom(romset, 0);
	pac_rom_print(rom, 0xFF);
	pac_rom_unload(rom);
	pac_romset_close(rom);
	return 0;
}
```

Here, we included `<libpacio/pacromset.h>`, `<libpacio/pacrom.h>`, and `<libpacio/print.h>`. Everything about the PacROM (struct and functions) are in `<libpacio/pacrom.h>`.

First, we created a PacROMSet, and then we created a PacROM using a PacROMSet with `pac_romset_load_rom(romset, 0)`. That PacROM will be the first ROM in the set, considering that we're using `0` as the index.

Then we print out the PacROM using `pac_rom_print(rom, 0xFF)`. That will print out everything about the ROM, including its byte data.

Lastly, we unload the PacROM using `pac_rom_unload(rom)`, since we're done using it, and then we closed the PacROMSet because we're also done with it too.

## Reading a ROM File

```c
// Reads a single byte from a PacROM's memory.
uint8_t pac_rom_read(const pac_rom_t* rom, const off_t offset);
```
(Source: pacrom.h)

To read a single byte of ROM data, call `pac_rom_read(const pac_rom_t* orm, const off_t offset)`. The `offset` can be anything, but it has to be within the bounds of the ROM file. This function will return the byte you just read.

```c
// Read multiple bytes from a PacROM's memory.
uint8_t* pac_rom_readn(const pac_rom_t* rom, const off_t offset, const size_t size);
```
(Source: pacrom.h)

You can also read multiple bytes at once using `pac_rom_readn(const pac_rom_t* rom, const off_t offset, const size_t size)`. The `size` refers to how many bytes to do want to read. The return value is a `uint8_t*`, meaning that array is allocated into memory. Just be sure to free it when you're done.

```c
// Read all bytes from a PacROM's memory.
uint8_t* pac_rom_read_all(const pac_rom_t* rom);
```
(Source: pacrom.h)

If you want to read all the bytes in the PacROM's memory, use `pac_rom_read_all(const pac_rom_t* rom)`. Like the previous function, this one returns a `uint8_t*`, meaning it's also allocated somewhere in memory. Make sure to free it when you're done using it.

## Writing a ROM File

```c
// Writes a single byte from a PacROM's memory.
void pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t byte);
```
(Source: pacrom.h)

To write a single byte into the PacROM's memory, use `pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t byte)`. I guess this function pretty much speaks for itself, considering that you're already familiar with the read functions at this point.

```c
// Writes multiple bytes from a PacROM's memory.
void pac_rom_writen(pac_rom_t* rom, const off_t offset, const uint8_t* bytes, const size_t size);
```
(Source: pacrom.h)

It writes multiple bytes. This time it uses `const uint8_t* bytes` and `const size_t size`. The `bytes` refer to the array you're using, and the `size` refers to the amount of bytes you want to write.

## Saving a ROM File

```c
// Saves information to a ROM file using a PacROM's data.
void pac_rom_save(const pac_rom_t* rom);
```
(Source: pacrom.h)

Finally, the last crucial part of *LibPacIO* is that you can save the ROM files onto your ROM set directory. To do that, call `void pac_rom_save(const pac_rom_t* rom)`, and it'll do the saving process for you. It'll overwrite the ROM file you're working with, so you can play your hacked version of *Pac-Man* or *Ms. Pac-Man* with your modified ROMs.

## Conclusion

That pretty much does about it for the guide for using *LibPacIO*. I hope you actually understand how to use this shared library.

If you want to support this project, why not star it in the ![GitHub Page](https://www.github.com/ThatGarlicDude/LibPacIO)? If you want to keep yourself updated with this project, click the watch button too. It'll really help out if you do that.

If you have any questions about this project, I can be best reached at in ![Bluesky](https://bsky.app/profile/thatgarlicdude.bsky.social). I'm more active here, so if you have anything, please feel free to ask.

Return back to ![README](../README.md).
