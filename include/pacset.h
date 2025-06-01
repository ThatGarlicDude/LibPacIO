#include <stdio.h>
#include "pacrom.h"

#ifndef PACSET_H
#define PACSET_H

	// A struct that represents a ROM set. Designed specifically for Pac-Man in mind.
	typedef struct pac_set {
		size_t size;		// The amount of ROMs in the set.
		pac_rom_t** roms;	// Dynamic array containing the ROM pointers.
	} pac_set_t;

	// Initializes a new ROM set.
	int pac_set_init(pac_set_t* set);

	// Creates a new ROM set.
	pac_set_t* pac_set_create();

	// Clears the ROM set.
	int pac_set_clear(pac_set_t* set);

	// Destroys the ROM set.
	void pac_set_destroy(pac_set_t* set);

	// Returns the size of the ROM set.
	size_t pac_set_get_size(const pac_set_t* set);

	// Returns the ROM array in the set.
	pac_rom_t** pac_set_get_roms(const pac_set_t* set);

	// Returns the address of a ROM file.
	const pac_rom_t* pac_set_get_rom(const pac_set_t* set, const size_t index);

	// Changes the array size of a ROM set.
	int pac_set_change_size(pac_set_t* set, const size_t size);

	// Appends a ROM into the set.
	int pac_set_append_rom(pac_set_t* set, pac_rom_t* rom);

#endif
