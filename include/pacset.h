#ifndef PACSET_H
	#define PACSET_H

	#include <stdio.h>
	#include "pacrom.h"
	#include "paclimits.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	// A struct that represents a ROM set. Designed specifically for Pac-Man in mind.
	typedef struct pac_set {
		char path[PAC_PATH_MAX];		// The filepath of the ROM set.
		size_t size;					// The amount of ROMs in the set.
		pac_rom_t* roms[PAC_ROMS_MAX];	// Dynamic array containing the ROM pointers.
	} pac_set_t;

	// Initializes a new ROM set.
	void pac_set_init(pac_set_t* set, const char* path);

	// Creates a new ROM set.
	pac_set_t* pac_set_create(const char* path);

	// Clears the ROM set.
	void pac_set_clear(pac_set_t* set);

	// Destroys the ROM set.
	void pac_set_destroy(pac_set_t* set);

	// Copies a ROM set source to a destination.
	void pac_set_copy(const pac_set_t* set_source, pac_set_t* set_destination);

	// Duplicates a ROM set to a destination.
	pac_set_t* pac_set_duplicate(const pac_set_t* set_source);

	// Returns the filepath of the ROM set.
	const char* pac_set_get_path(const pac_set_t* set);

	// Returns the size of the ROM set.
	size_t pac_set_get_size(const pac_set_t* set);

	// Returns the ROMs array in the ROM set.
	pac_rom_t* const* pac_set_get_roms(const pac_set_t* set);

	// Returns the address of a ROM file.
	const pac_rom_t* pac_set_get_rom(const pac_set_t* set, const size_t index);

	// Appends a ROM into the set.
	int pac_set_append_rom(pac_set_t* set, pac_rom_t* rom);

	#ifdef __cplusplus
		}
	#endif

#endif
