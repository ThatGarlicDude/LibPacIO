#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libpacio.h>
#include "pacio_test.h"

#define DEFAULT_PATH "."
#define DEFAULT_TEST "romset_test" // UNUSED Refers to which test you want to run.

#define FLAG_PATH "-p" // UNUSED.
#define FLAG_HELP "-help" // UNUSED.

char* path = DEFAULT_PATH; // UNUSED.

// Test the ROM creation process.
int rom_test(char* path) {
	pac_rom_t* rom = pac_rom_load(path);
	if (!rom) {
		printf("ROM creation failed.\n");
		return -1;
	}
	pac_rom_print(rom, 0xFF);
	pac_rom_unload(rom);
	return 0;
}

// Test the ROM Set creation process.
int romset_test(char* path) {
	pac_romset_t* set = pac_romset_open(path);
	if (!set) {
		printf("ROM set creation failed.\n");
		return -1;	
	}
	pac_romset_print(set, 0xFF);
	pac_romset_close(set);
	return 0;
}

// Prints all the ROM set's ROM data.
int all_test(char* path) {
	pac_romset_t* set = pac_romset_open(path);
	if (!set) {
		printf("ROM set creation failed.\n");
		return -1;
	}
	pac_romset_print(set, 0xFF);
	for (size_t index = 0; index < set->size; index++) {
		pac_rom_t* rom = pac_romset_load_rom(set, index);
		if (!rom) {
			printf("ROM creation failed.\n");
			return -1;
		}
		pac_rom_print(rom, 0xFF);
		pac_rom_unload(rom);
	}
	pac_romset_close(set);
	return 0;
}

// Main function.
int main(int argc, char* argv[]) {
	if (!argv[1]) {
		printf("You need to specify the path to continue (type 'pacio_test .' to run the test).\n");
		return -1;
	}
	all_test(argv[1]);
	return 0;
}
