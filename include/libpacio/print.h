#ifndef LIBPACIO_PRINT_H
	#define LIBPACIO_PRINT_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	/*
		## GENERAL FUNCTIONS ##
	*/

	// Prints all information about a PacROM.
	void pac_rom_print(const pac_rom_t* rom, const uint8_t flags);

	// Prints all information about a PacROMSet.
	void pac_romset_print(const pac_romset_t* romset, const uint8_t flags);

	/*
		## PACROM FUNCTIONS ##
	*/

	// Prints the address of a PacROM.
	void pac_rom_print_address(const pac_rom_t* rom);

	// Prints the path of a PacROM.
	void pac_rom_print_path(const pac_rom_t* rom);

	// Prints the size of a PacROM.
	void pac_rom_print_size(const pac_rom_t* rom);

	// Prints the data pointer of a PacROM.
	void pac_rom_print_data(const pac_rom_t* rom);

	// Prints all the bytes inside the data array in a PacROM.
	void pac_rom_print_data_all(const pac_rom_t* rom);

	/*
		## PACROMSET FUNCTIONS ##
	*/

	// Prints the address of a PacROMSet.
	void pac_romset_print_address(const pac_romset_t* romset);

	// Prints the path of a PacROMSet.
	void pac_romset_print_path(const pac_romset_t* romset);

	// Prints the size of a PacROMSet.
	void pac_romset_print_size(const pac_romset_t* romset);

	// Prints the ROMs pointer in the PacROMSet.
	void pac_romset_print_roms(const pac_romset_t* romset);

	// Prints all the ROM names in the PacROMSet.
	void pac_romset_print_roms_all(const pac_romset_t* romset);

	/*
		## COLOR FUNCTIONS ##
	*/

	// Prints a title onto the terminal.
	void pac_print_title(const char* title);

	// Prints a subtitle onto the terminal.
	void pac_print_subtitle(const char* subtitle);

	// Prints an address onto the terminal.
	void pac_print_address(const char* name, const void* pointer);

	// Prints a number onto the terminal.
	void pac_print_number(const char* name, const long number);

	// Prints a string onto the terminal.
	void pac_print_string(const char* name, const char* string);

	// Prints a single byte of ROM data onto the terminal.
	void pac_print_data(const uint16_t location, const uint8_t data);

	// Prints a single ROM name along with the index.
	void pac_print_rom_name(size_t index, const char* string);

	#ifdef __cplusplus
		}
	#endif

#endif
