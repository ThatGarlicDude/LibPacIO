#ifndef LIBPACIO_SAVE_H
	#define LIBPACIO_SAVE_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Saves information to a ROM file using a PacROM's data.
	void pac_rom_save(const pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
