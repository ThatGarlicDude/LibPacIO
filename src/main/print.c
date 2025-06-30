#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <libpacio/pacrom.h>
#include <libpacio/pacromset.h>
#include <libpacio/print.h>

/* PACROM FLAGS */
#define FLAG_ROM_PRINT_STRUCT_ADDRESS 0x01
#define FLAG_ROM_PRINT_PATH 0x02
#define FLAG_ROM_PRINT_SIZE 0x04
#define FLAG_ROM_PRINT_DATA 0x08
#define FLAG_ROM_PRINT_DATA_ALL 0x10

/* PACROMSET FLAGS */
#define FLAG_ROMSET_PRINT_STRUCT_ADDRESS 0x01
#define FLAG_ROMSET_PRINT_PATH 0x02
#define FLAG_ROMSET_PRINT_SIZE 0x04
#define FLAG_ROMSET_PRINT_ROMS 0x08
#define FLAG_ROMSET_PRINT_ROMS_ALL 0x10

/* TEXT COLORS */
#define COLOR_TITLE "\033[1;93m"
#define COLOR_SUBTITLE "\033[1;92m"
#define COLOR_VARIABLE "\033[0;36m"
#define COLOR_DATA "\033[1;96m"
#define COLOR_NORMAL "\033[0m"

/*
	## GENERAL FUNCTIONS ##
*/

// Prints all information about a PacROM.
void pac_rom_print(const pac_rom_t* rom, const uint8_t flags) {
	if (!rom) return;
	pac_print_title("ROM");
	if (flags && FLAG_ROM_PRINT_STRUCT_ADDRESS) pac_rom_print_address(rom);
	if (flags && FLAG_ROM_PRINT_PATH) pac_rom_print_path(rom);
	if (flags && FLAG_ROM_PRINT_SIZE) pac_rom_print_size(rom);
	if (flags && FLAG_ROM_PRINT_DATA) pac_rom_print_data(rom);
	if (flags && FLAG_ROM_PRINT_DATA_ALL) pac_rom_print_data_all(rom);
	return;
}

// Prints all information about a PacROMSet.
void pac_romset_print(const pac_romset_t* romset, const uint8_t flags) {
	if (!romset) return;
	pac_print_title("ROM Set");
	if (flags && FLAG_ROMSET_PRINT_STRUCT_ADDRESS) pac_romset_print_address(romset);
	if (flags && FLAG_ROMSET_PRINT_PATH) pac_romset_print_path(romset);
	if (flags && FLAG_ROMSET_PRINT_SIZE) pac_romset_print_size(romset);
	if (flags && FLAG_ROMSET_PRINT_ROMS) pac_romset_print_roms(romset);
	if (flags && FLAG_ROMSET_PRINT_ROMS_ALL) pac_romset_print_roms_all(romset);
	return;
}

/*
	## PACROM FUNCTIONS ##
*/

// Prints the address of a PacROM.
void pac_rom_print_address(const pac_rom_t* rom) {
	pac_print_address("Address", rom);
	return;
}

// Prints the path of a PacROM.
void pac_rom_print_path(const pac_rom_t* rom) {
	const char* path = pac_rom_get_path(rom);
	pac_print_string("Path", path);
	return;
}

// Prints the size of a PacROM.
void pac_rom_print_size(const pac_rom_t* rom) {
	const size_t size = pac_rom_get_size(rom);
	pac_print_number("Size", size);
	return;
}

// Prints the data pointer of a PacROM.
void pac_rom_print_data(const pac_rom_t* rom) {
	const uint8_t* data = pac_rom_get_data(rom);
	pac_print_address("Data", data);
}

// Prints all the bytes inside the data array in a PacROM.
void pac_rom_print_data_all(const pac_rom_t* rom) {
	const size_t size = pac_rom_get_size(rom);
	const uint8_t* data = pac_rom_get_data(rom);
	if (!data) return;
	pac_print_subtitle("ROM Data");
	for (size_t index = 0; index < size; index++) {
		pac_print_data(index, data[index]);
	}
	return;
}

/*
	## PACROMSET FUNCTIONS ##
*/

// Prints the address of a PacROMSet.
void pac_romset_print_address(const pac_romset_t* romset) {
	pac_print_address("Address", romset);
	return;
}

// Prints the path of a PacROMSet.
void pac_romset_print_path(const pac_romset_t* romset) {
	const char* path = pac_romset_get_path(romset);
	pac_print_string("Path", path);
	return;
}

// Prints the size of a PacROMSet.
void pac_romset_print_size(const pac_romset_t* romset) {
	const size_t size = pac_romset_get_size(romset);
	pac_print_number("Size", size);
	return;
}

// Prints the ROMs pointer in the PacROMSet.
void pac_romset_print_roms(const pac_romset_t* romset) {
	char** roms = pac_romset_get_roms(romset);
	pac_print_address("ROMs", roms);
	return;
}

// Prints all the ROM names in the PacROMSet.
void pac_romset_print_roms_all(const pac_romset_t* romset) {
	const size_t size = pac_romset_get_size(romset);
	pac_print_subtitle("ROMs");
	for (size_t index = 0; index < size; index++) {
		const char* rom = pac_romset_get_rom(romset, index);
		pac_print_rom_name(index, rom);
	}
	return;
}

/*
	## COLOR FUNCTIONS ##
*/

// Prints a title onto the terminal.
void pac_print_title(const char* title) {
	printf("%s%s:\n", COLOR_TITLE, title);
	return;
}

// Prints a subtitle onto the terminal.
void pac_print_subtitle(const char* subtitle) {
	printf("%s%s:\n", COLOR_SUBTITLE, subtitle);
	return;
}

// Prints an address onto the terminal.
void pac_print_address(const char* name, const void* pointer) {
	printf("\t%s%s: %s%p\n", COLOR_VARIABLE, name, COLOR_NORMAL, pointer);
	return;
}

// Prints a number onto the terminal.
void pac_print_number(const char* name, const long number) {
	printf("\t%s%s: %s%ld\n", COLOR_VARIABLE, name, COLOR_NORMAL, number);
	return;
}

// Prints a string onto the terminal.
void pac_print_string(const char* name, const char* string) {
	printf("\t%s%s: %s%s\n", COLOR_VARIABLE, name, COLOR_NORMAL, string);
	return;
}

// Prints a single byte of ROM data onto the terminal.
void pac_print_data(const uint16_t location, const uint8_t data) {
	printf("\t%s($%04X): %s%02X\n", COLOR_DATA, location, COLOR_NORMAL, data);
	return;
}

// Prints a single ROM name along with the index.
void pac_print_rom_name(size_t index, const char* string) {
	printf("\t%sROM Index #%ld: %s%s\n", COLOR_VARIABLE, index, COLOR_NORMAL, string);
	return;
}
