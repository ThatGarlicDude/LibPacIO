#ifndef LIBPACIO_HELP_H
	#define LIBPACIO_HELP_H

	#include <stdio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Prints the help menu for LibPacIO.
	void libpacio_print_help(void);

	// Prints a specific option to the terminal.
	void libpacio_print_option(const size_t index);

	#ifdef __cplusplus
		}
	#endif

#endif
