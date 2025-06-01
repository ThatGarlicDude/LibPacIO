#include <stdio.h>
#include <stdint.h>
#include "pacrom.h"
#include "pacset.h"

// Prints the entire ROM data.
void pac_rom_printd(const pac_rom_t* rom) {
	// Stop if there isn't a valid ROM.
	if (!rom) {
		printf("Error (pac_rom_printd): ROM pointer is null.\n");
		return;
	}
	// Fail if there's no data in the ROM file.
	if (!rom->data) {
		printf("Error (pac_rom_printd): ROM data pointer is null.\n");
		return;
	}
	// Print each of the ROM data in hexadecimal.
	printf("ROM DATA:");
	for (uint16_t index = 0; index < rom->size; index++) {
		printf("\tAddress 0x%04X: %02X\n", index, rom->data[index]);
	}
}

// Prints information about a ROM file.
void pac_rom_print(const pac_rom_t* rom) {
	// Stop if there isn't a ROM file to print.
	if (!rom) {
		printf("Error (pac_rom_print): ROM pointer is null.\n");
		return;
	}
	// Print the heading.
	printf("ROM FILE:\n");
	printf("\tAddress: %p.\n", rom);
	// Print the filename.
	printf("\tFilename: %s.\n", rom->name);
	printf("\tFilename Address: %p.\n", rom->name);
	printf("\tFilename Location: %p.\n", &rom->name);
	// Print the size.
	printf("\tSize: %zu.\n", rom->size);
	printf("\tSize Location: %p.\n", &rom->size);
	// Print the data pointer.
	printf("\tData Address: %p.\n", rom->data);
	printf("\tData Location: %p.\n", &rom->data);
}

// Prints all the pointers in the ROM set array.
void pac_set_printp(const pac_set_t* set) {
	// Stop if there isn't a ROM set to print.
	if (!set) {
		printf("Error (pac_set_printp): ROM set pointer is null.\n");
		return;
	}
	// Print each of the ROM pointers.
	printf("ROM POINTERS:\n");
	for (size_t index = 0; index < set->size; index++) {
		printf("\tROM %ld: %p.\n", index, set->roms[index]);
	}
}

// Prints the entire data of a ROM set.
void pac_set_print(const pac_set_t* set) {
	// Stop if there isn't a ROM set to print.
	if (!set) {
		printf("Error (pac_set_print): ROM set pointer is null.\n");
		return;
	}
	// Print info about the ROM set.
	printf("ROM SET:\n");
	printf("\tAddress: %p.\n", set);
	printf("\tSize: %zu.\n", set->size);
	printf("\tSize Location: %p.\n", &set->size);
	printf("\tROMs Array Address: %p.\n", set->roms);
	printf("\tROMs Array Location: %p.\n", &set->roms);
	pac_set_printp(set);
	// Go through each of the ROMs in the set.
	for (size_t index = 0; index < set->size; index++) {
		const pac_rom_t* rom = pac_set_get_rom(set, index);
		pac_rom_print(rom);
	}
}
