#include <stdio.h>
#include <string.h>
#include "pacsort.h"
#include "pacset.h"
#include "pacrom.h"
#include "pacerror.h"

const char* NAME_PAC_SET_SORT = "pac_set_sort";
const char* NAME_PAC_ROM_COMPARE = "pac_rom_compare";
const char* NAME_PAC_SET_FIND_LOWEST_ROM = "pac_set_find_lowest_rom";

// Sorts all the ROMs in a ROM set in lexicographical order.
int pac_set_sort(pac_set_t* set) {
	if (!set) {
		pac_warn(NAME_PAC_SET_SORT, "ROM set pointer is NULL!");
		return -1;
	}
	for (size_t index = 0; index < set->size; index++) {
		int lowest_rom = pac_set_find_lowest_rom(set, index);
		pac_rom_swap(&set->roms[index], &set->roms[lowest_rom]);
	}
	return 0;
}

// Swaps two ROM pointers together.
void pac_rom_swap(pac_rom_t** rom_a, pac_rom_t** rom_b) {
	pac_rom_t* temp_rom = *rom_a;
	*rom_a = *rom_b;
	*rom_b = temp_rom;
}

// Compares 2 ROMs.
int pac_rom_compare(pac_rom_t* rom_a, pac_rom_t* rom_b) {
	pac_info(NAME_PAC_ROM_COMPARE, "Comparing 2 ROMs...");
	int result = strcmp(rom_b->name, rom_a->name);
	return result;
}

// Get the index of an array that contains the lowest lexicographic filename.
int pac_set_find_lowest_rom(const pac_set_t* set, const off_t offset) {
	if (!set) {
		pac_warn(NAME_PAC_SET_FIND_LOWEST_ROM, "ROM set pointer is NULL!");
		return -1;
	}
	int lowest_rom = offset;
	for (size_t index = offset + 1; index < set->size; index++) {
		// Ignore null pointers.
		if (!set->roms[index]) {
			continue;
		}
		if (pac_rom_compare(set->roms[index], set->roms[lowest_rom]) > 0) {
			lowest_rom = index;
		}
	}
	return lowest_rom;
}
