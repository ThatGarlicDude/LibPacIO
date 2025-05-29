#include <stdio.h>
#include "romFile.h"
#include "romSet.h"

// Prints the entire ROM data.
void printROMData(RomFile* romFile) {
	// Fail if there's no data in the ROM file.
	if (romFile->data == NULL) {
		printf("There's no data in the ROM file to print.\n");
		return;
	}
	// Print each of the ROM data in hexadecimal.
	for (int index = 0; index < romFile->size; index++) {
		printf("Address %04X: %02X", index, romFile->data[index]);
	}
}

// Prints information about a ROM file.
void printROMFile(RomFile* romFile) {
	// Fail if there isn't a ROM file to print.
	if (romFile == NULL) {
		printf("There isn't a ROM file to print.\n");
		return;
	}
	printf("--ROM FILE --\n");
	printf("Address: %p.\n", romFile);
	printf("Filename: %s.\n", romFile->fileName);
	printf("Filename points to: %p.\n", romFile->fileName);
}

// Prints the entire data of a ROM set.
void printROMSet(RomSet* romSet) {
	// Fail if there isn't a ROM set to print.
	if (romSet == NULL) {
		printf("There isn't a ROM set to print.\n");
		return;
	}
	// Print info about the ROM set.
	printf("== ROM SET ==\n");
	printf("Address: %p.\n", romSet);
	printf("Size: %zu.\n", romSet->size);
	// Go through each of the ROMs in the set.
	printf("== CONTENTS ==\n");
	for (size_t index = 0; index < romSet->size; index++) {
		RomFile* romFile = getROM(romSet, index);
		printROMFile(romFile);
	}
}
