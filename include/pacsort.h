#ifndef PACSORT_H
#define PACSORT_H

	#include <stdio.h>
	#include "pacset.h"
	#include "pacrom.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Sorts all the ROMs in a ROM set in lexicographical order.
	int pac_set_sort(pac_set_t* set);

	// Swaps two ROM pointers together.
	void pac_rom_swap(pac_rom_t** rom_a, pac_rom_t** rom_b);

	// Compares 2 ROMs.
	int pac_rom_compare(pac_rom_t* rom_a, pac_rom_t* rom_b);

	// Get the index of an array that contains the lowest lexicographic filename.
	int pac_set_find_lowest_rom(const pac_set_t* set, const off_t offset);

	#ifdef __cplusplus
		}
	#endif

#endif
