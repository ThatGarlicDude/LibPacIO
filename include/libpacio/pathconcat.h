#ifndef LIBPACIO_PATHCONCAT_H
	#define LIBPACIO_PATHCONCAT_H

	#include <libpacio.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// TODO: Rework this function somehow. Maybe make it generic instead of relying on PacROMSet.

	// Concats a PacROMSet's path and a ROM's name together.
	char* pac_romset_concat(const pac_romset_t* romset, size_t index);

	#ifdef __cplusplus
		}
	#endif

#endif
