#ifndef LIBPACIO_PACROM_H
	#define LIBPACIO_PACROM_H

	#ifdef __cplusplus
		extern "C" {
	#endif

	#include <stdio.h>
	#include <stdint.h>

	// Represents an 8-bit ROM within the Pac-Man and Ms. Pac-Man ROM sets.
	typedef struct pac_rom {
		char* path;
		size_t size;
		uint8_t* data;
	} pac_rom_t;

	/*
		## MEMORY FUNCTIONS ##
	*/

	// Sets up a PacROM struct.
	void pac_rom_init(pac_rom_t* rom, const char* path);

	// Creates a new PacROM into memory.
	pac_rom_t* pac_rom_create(const char* path);

	// Clears a PacROM with zeroes.
	void pac_rom_clear(pac_rom_t* rom);

	// Destroys a PacROM from memory.
	void pac_rom_destroy(pac_rom_t* rom);

	/*
		## FILE FUNCTIONS ##
	*/

	// Creates a new PacROM and loads its ROM file's data.
	pac_rom_t* pac_rom_load(const char* path);

	// Clears all data regarding a PacROM, and frees it from memory.
	void pac_rom_unload(pac_rom_t* rom);

	// Saves information to a ROM file using a PacROM's data.
	void pac_rom_save(const pac_rom_t* rom);

	/*
		## READ FUNCTIONS ##
	*/

	// Reads a single byte from a PacROM's memory.
	uint8_t pac_rom_read(const pac_rom_t* rom, const off_t offset);

	// Read multiple bytes from a PacROM's memory.
	uint8_t* pac_rom_readn(const pac_rom_t* rom, const off_t offset, const size_t size);

	// Read all bytes from a PacROM's memory.
	uint8_t* pac_rom_read_all(const pac_rom_t* rom);

	/*
		## WRITE FUNCTIONS ##
	*/

	// Writes a single byte from a PacROM's memory.
	void pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t byte);

	// Writes multiple bytes from a PacROM's memory.
	void pac_rom_writen(pac_rom_t* rom, const off_t offset, const uint8_t* bytes, const size_t size);

	/*
		## GETTER FUNCTIONS ##
	*/

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
