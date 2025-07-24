#ifndef LIBPACIO_PACROMSET_H
	#define LIBPACIO_PACROMSET_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Represents the ROM set for the Pac-Man and Ms. Pac-Man PCBs.
	typedef struct pac_romset {
		char* path;
		size_t size;
		char** roms;
	} pac_romset_t;

	/*
		## MEMORY FUNCTIONS ##
	*/

	// Sets up a PacROMSet struct.
	void pac_romset_init(pac_romset_t* romset, const char* path);

	// Creates a new PacROMSet into memory.
	pac_romset_t* pac_romset_create(const char* path);

	// Clears a PacROMSet with zeroes.
	void pac_romset_clear(pac_romset_t* romset);

	// Destroys a PacROMSet from memory.
	void pac_romset_destroy(pac_romset_t* romset);

	/*
		## DIRECTORY FUNCTIONS ##
	*/

	// Creates a new PacROMSet, and opens the directory relating to it, getting all of its filenames inside of it.
	pac_romset_t* pac_romset_open(const char* path);

	// Clears and frees everything regarding a PacROMSet from memory.
	void pac_romset_close(pac_romset_t* romset);

	/*
		## FILE FUNCTIONS ##
	*/

	// Loads a PacROM using an index for a PacROMSet's ROMs array.
	pac_rom_t* pac_romset_load_rom(const pac_romset_t* romset, const size_t index);

	// Loads a PacROM using a file name in a PacROMSet.
	pac_rom_t* pac_romset_load_rom_by_name(const pac_romset_t* romset, const char* name);

	/*
		## SETTER FUNCTIONS ##
	*/

	// Sets a pointer in a ROM name in a PacROMSet.
	void pac_romset_set_rom(pac_romset_t* romset, const size_t index, char* pointer);

	/*
		## GETTER FUNCTIONS ##
	*/

	// Returns the path of a PacROMSet.
	char* pac_romset_get_path(const pac_romset_t* romset);

	// Returns the size of a PacROMSet.
	size_t pac_romset_get_size(const pac_romset_t* romset);

	// Returns the ROMs array in a PacROMSet.
	char** pac_romset_get_roms(const pac_romset_t* romset);

	// Gets a specific ROM name in the ROMs array in a PacROMSet.
	char* pac_romset_get_rom(const pac_romset_t* romset, const size_t index);

	// Gets the address of a specific ROM name in a PacROMSet.
	char** pac_romset_get_rom_address(const pac_romset_t* romset, const size_t index);

	// Searches for a specific ROM name in a PacROMSet.
	size_t pac_romset_find_rom(const pac_romset_t* romset, const char* name);

	/*
		## SORT FUNCTIONS ##
	*/

	// Sorts all of the ROMs in a PacROMSet in lexicographic order.
	void pac_romset_sort(pac_romset_t* romset);

	// Swaps two ROM names in a PacROMSet.
	void pac_romset_swap_roms(pac_romset_t* romset, const size_t index_a, const size_t index_b);

	// Searches for the lowest ASCII ROM name in a PacROMSet.
	size_t pac_romset_find_lowest_rom(const pac_romset_t* romset, size_t offset);

	/*
		## MISC FUNCTIONS ##
	*/

	// Appends a ROM name into a PacROMSet's stack.
	void pac_romset_append_rom(pac_romset_t* romset, const char* rom_name);

	// Concats a PacROMSet's path and a ROM's name together.
	char* pac_romset_concat(const pac_romset_t* romset, size_t index);

	#ifdef __cplusplus
		}
	#endif

#endif
