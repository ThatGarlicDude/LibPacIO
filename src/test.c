#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pacrom.h"
#include "pacset.h"
#include "pacio.h"
#include "pacprint.h"

#define NAME_SINGLE_ROM_TEST "Single ROM Test"
#define NAME_MULTI_ROM_TEST "Multiple ROM Test"
#define NAME_ROM_SET_TEST "ROM Set Test"

// Tests a ROM's size, location, and clears memory.
void single_rom_test() {
	pac_rom_t* rom = pac_rom_create("TestROM.4a");
	pac_rom_print(rom);
	pac_rom_destroy(rom);
	rom = NULL;
}

// Tests 2 ROMs at once, and yes, showing the weird null-padding issue.
void multi_rom_test() {
	pac_rom_t* rom1 = pac_rom_create("TestROM.1b");
	pac_rom_t* rom2 = pac_rom_create("TestROM.2h");
	pac_rom_print(rom1);
	pac_rom_print(rom2);
	pac_rom_destroy(rom1);
	pac_rom_destroy(rom2);
	rom1 = NULL;
	rom2 = NULL;
}

// Test out the ROM set.
void rom_set_test() {
	pac_set_t* set = pac_set_create();
	pac_rom_t* rom1 = pac_rom_create("GarlicDude.1b");
	pac_rom_t* rom2 = pac_rom_create("OnionGal.2h");
	pac_set_append_rom(set, rom1);
	pac_set_append_rom(set, rom2);
	pac_set_print(set);
	pac_set_destroy(set);
	pac_rom_destroy(rom1);
	pac_rom_destroy(rom2);
	set = NULL;
	rom1 = NULL;
	rom2 = NULL;
}

// Prints the heading of a test.
void print_test(const char* test_name) {
	printf("== %s ==\n", test_name);
}

int main(int argc, char* argv[]) {
	int test_index;
	// Is there an argument?
	if (argv[1]) {
		test_index = ((int) argv[1][0]) - 48;
	} else {
		printf("Please enter a test number (0, 1, 2, ...).\n");
		return -1;
	}
	// Select test function.
	switch(test_index) {
		case 0:
			print_test(NAME_SINGLE_ROM_TEST);
			single_rom_test();
			break;
		case 1:
			print_test(NAME_MULTI_ROM_TEST);
			multi_rom_test();
			break;
		case 2:
			print_test(NAME_ROM_SET_TEST);
			rom_set_test();
			break;
		default:
			printf("No test function can be found.\n");
			break;
	}
	printf("End of test.\n");
	return 0;
}
