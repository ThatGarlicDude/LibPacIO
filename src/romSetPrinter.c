#include <stdio.h>
#include "romFile.h"
#include "romSet.h"

// Prints information about a ROM file.
void printROMFile(RomFile* romFile) {
	printf("\n\t-- ROM FILE --\n");
	printf("\t\tAddress: %p.\n", romFile);
	printf("\t\tFilename: %s.\n", romFile->fileName);
	printf("\t\tFilename points to: %p.\n", romFile->fileName);
}

// Prints the entire data of a ROM set.
void printROMSet(RomSet* romSet) {
	printf("\n-- ROM SET --\n");
	printf("\tAddress: %p.\n", romSet);
	printf("\tSize: %zu.\n", romSet->size);
	printf("\n\t-- CONTENTS --\n");
	for (size_t index = 0; index < romSet->size; index++) {
		RomFile* romFile = getROM(romSet, index);
		printROMFile(romFile);
	}
}
