#include <stdio.h>
#include "romSet.h"

// Prints the entire data of a ROM set.
void printRomSet(RomSet* romSet) {
	printf("\n-- ROM SET --\n");
	printf("\tAddress: %p.\n", romSet);
	printf("\tSize: %zu.\n", romSet->size);
	printf("\n\t-- CONTENTS --\n");
	for (size_t index = 0; index < romSet->size; index++) {
		printf("\tROM #%ld: %s.\n", index, romSet->filePaths[index]);
		printf("\tROM #%ld Address: %p.\n\n", index, romSet->filePaths[index]);
	}
}
