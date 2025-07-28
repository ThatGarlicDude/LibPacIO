#ifndef LIBPACIO_WRITE_H
	#define LIBPACIO_WRITE_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Writes a single byte from a PacROM's memory.
	void pac_rom_write(pac_rom_t* rom, const off_t offset, const uint8_t byte);

	// Writes multiple bytes from a PacROM's memory.
	void pac_rom_writen(pac_rom_t* rom, const off_t offset, const uint8_t* bytes, const size_t size);

	#ifdef __cplusplus
		}
	#endif

#endif
