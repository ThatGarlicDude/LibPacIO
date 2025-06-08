#include <stdio.h>
#include <stdint.h>
#include "pacrom.h"
#include "pacset.h"
#include "pacprint.h"

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
	printf("\033[91m\033[1mROM DATA:\033[0m\n");
	for (uint16_t index = 0; index < rom->size; index++) {
		printf("\t\033[96mAddress 0x%04X:\033[0m %02X\n", index, rom->data[index]);
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
	printf("\033[93m\033[1mROM FILE:\033[0m\n");
	printf("\t\033[94mAddress:\033[0m %p.\n", rom);
	// Print the filename.
	printf("\t\033[94mFilename:\033[0m %s.\n", rom->name);
	printf("\t\033[94mFilename Address:\033[0m %p.\n", rom->name);
	// Print the size.
	printf("\t\033[94mSize:\033[0m %zu.\n", rom->size);
	printf("\t\033[94mSize Address:\033[0m %p.\n", &rom->size);
	// Print the data pointer.
	printf("\t\033[94mData Address:\033[0m %p.\n", &rom->data);
}

// Prints all the pointers in the ROM set array.
void pac_set_printp(const pac_set_t* set) {
	// Stop if there isn't a ROM set to print.
	if (!set) {
		printf("Error (pac_set_printp): ROM set pointer is null.\n");
		return;
	}
	// Print each of the ROM pointers.
	printf("\033[91m\033[1mROM POINTERS:\033[0m\n");
	for (size_t index = 0; index < set->size; index++) {
		printf("\t\033[94mROM %ld:\033[0m %p.\n", index, set->roms[index]);
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
	printf("\033[93m\033[1mROM SET:\033[0m\n");
	printf("\t\033[94mAddress:\033[0m %p.\n", set);
	printf("\t\033[94mFilepath:\033[0m %s.\n", set->path);
	printf("\t\033[94mFilepath Address:\033[0m %p.\n", set->path);
	printf("\t\033[94mSize:\033[0m %zu.\n", set->size);
	printf("\t\033[94mSize Address:\033[0m %p.\n", &set->size);
	printf("\t\033[94mROMs Pointers Address:\033[0m %p.\n", set->roms);
	pac_set_printp(set);
	// Go through each of the ROMs in the set.
	for (size_t index = 0; index < set->size; index++) {
		pac_rom_print(set->roms[index]);
	}
}
