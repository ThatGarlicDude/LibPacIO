#ifndef LIBPACIO_PRINT_LIBPACIO_H
	#define LIBPACIO_PRINT_LIBPACIO_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Prints all information about LibPacIO.
	void libpacio_print();

	// Prints the name of the project.
	void libpacio_print_name();

	// Prints the version of the project.
	void libpacio_print_version();

	// Prints the disclaimer of the project.
	void libpacio_print_disclaimer();

	#ifdef __cplusplus
		}
	#endif

#endif
