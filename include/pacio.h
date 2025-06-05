#ifndef PACIO_H
	#define PACIO_H

	#include <stdio.h>
	#include <stdint.h>
	#include "pacset.h"
	#include "pacrom.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Reads a single byte in memory.
	void pac_rom_read(pac_rom_t* rom, const off_t offset, uint8_t* destination);

	// Reads multiple bytes in memory.
	void pac_rom_readn(pac_rom_t* rom, const off_t offset, const size_t amount, uint8_t* destination);

	// Writes a single byte in memory.
	void pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t data);

	// Writes multiple bytes in memory.
	void pac_rom_writen(pac_rom_t* rom, const off_t offset, const uint8_t* data);

	// Loads data from a ROM file.
	int pac_rom_load(pac_rom_t* rom);

	// Unloads ROM data from memory.
	int pac_rom_unload(pac_rom_t* rom);

	// Saves data to a ROM file.
	int pac_rom_save(const pac_rom_t* rom);

	// Unsaves data???? But how can a file get unsaved lol???
	int pac_rom_unsave(const pac_rom_t* rom);

	// Loads a ROM set into memory.
	int pac_set_load(const pac_set_t* set);

	// Unloads all the ROMs' data from memory.
	int pac_set_unload(const pac_set_t* set);

	// Saves all the ROM set's ROMs to their respective files.
	int pac_set_save(const pac_set_t* set);

	// Now you're just getting on my nerves, bruh.
	int pac_set_unsave(const pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
