#include <stdio.h>
#include <stdint.h>

#ifndef PACROM_H
#define PACROM_H

	// A struct that represents a ROM file within the Pac-Man ROM set.
	typedef struct pac_rom {
		char* name;			// The filename of the ROM.
		size_t size;		// The size of the ROM.
		uint8_t* data;		// The ROM's data.
	} pac_rom_t;

	// Initiates a new ROM.
	int pac_rom_init(pac_rom_t* rom, const char* name);

	// Creates a new ROM.
	pac_rom_t* pac_rom_create(const char* name);

	// Clear the ROM.
	int pac_rom_clear(pac_rom_t* rom);

	// Destroy the ROM.
	void pac_rom_destroy(pac_rom_t* rom);

	// Sets the filename of a ROM.
	void pac_rom_set_name(pac_rom_t* rom, const char* name);

	// Returns a ROM's filename.
	const char* pac_rom_get_name(const pac_rom_t* rom);

	// Returns a ROM's size.
	size_t pac_rom_get_size(const pac_rom_t* rom);

	// Returns a ROM's data.
	const uint8_t* pac_rom_get_data(const pac_rom_t* rom);

#endif
