#ifndef LIBPACIO_READ_H
	#define LIBPACIO_READ_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Reads a single byte from a PacROM's memory.
	uint8_t pac_rom_read(const pac_rom_t* rom, const off_t offset);

	// Read multiple bytes from a PacROM's memory.
	uint8_t* pac_rom_readn(const pac_rom_t* rom, const off_t offset, const size_t size);

	// Read all bytes from a PacROM's memory.
	uint8_t* pac_rom_read_all(const pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
