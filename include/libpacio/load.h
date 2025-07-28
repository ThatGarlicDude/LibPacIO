#ifndef LIBPACIO_LOAD_H
	#define LIBPACIO_LOAD_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Creates a new PacROM and loads its ROM file's data.
	pac_rom_t* pac_rom_load(const char* path);

	// Clears all data regarding a PacROM, and frees it from memory.
	void pac_rom_unload(pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
