#ifndef LIBPACIO_PACIO_TEST_H
	#define LIBPACIO_PACIO_TEST_H

	#include "version_print.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Test the ROM creation process.
	int rom_test(char* path);

	// Test the ROM Set creation process.
	int romset_test(char* path);

	// Prints all the ROM set's ROM data.
	int all_test(char* path);

	#ifdef __cplusplus
		}
	#endif

#endif
