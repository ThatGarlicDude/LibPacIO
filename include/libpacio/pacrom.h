#ifndef LIBPACIO_PACROM_H
	#define LIBPACIO_PACROM_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Represents an 8-bit ROM within the Pac-Man and Ms. Pac-Man ROM sets.
	typedef struct pac_rom {
		char* path;
		size_t size;
		uint8_t* data;
	} pac_rom_t;

	// Sets up a PacROM struct.
	void pac_rom_init(pac_rom_t* rom, const char* path);

	// Creates a new PacROM into memory.
	pac_rom_t* pac_rom_create(const char* path);

	// Clears a PacROM with zeroes.
	void pac_rom_clear(pac_rom_t* rom);

	// Destroys a PacROM from memory.
	void pac_rom_destroy(pac_rom_t* rom);

	// Returns the path of the PacROM.
	char* pac_rom_get_path(const pac_rom_t* rom);

	// Returns the size of the PacROM.
	size_t pac_rom_get_size(const pac_rom_t* rom);

	// Returns the data of the PacROM.
	uint8_t* pac_rom_get_data(const pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
