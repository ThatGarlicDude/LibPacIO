#include <stdio.h>
#include <stdint.h>
#include "pacrom.h"

#ifndef PACIO_H
#define PACIO_H

	// Loads data from a ROM file.
	int pac_rom_load(pac_rom_t* rom);

	// Saves data to a ROM file.
	int pac_rom_save(const pac_rom_t* rom);

	// Unloads extracted ROM data from memory.
	int pac_rom_unload(pac_rom_t* rom);

#endif
