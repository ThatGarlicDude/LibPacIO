#ifndef PACLIMITS_H
	#define PACLIMITS_H

	#include <stdint.h>

	#ifdef __cplusplus
		extern "C" {
	#endif

	// The maximum length of a filename used for both ROMs and ROM sets.
	#define PAC_NAME_MAX 32

	// The maximum length of a filepath used for both ROMs and ROM sets.
	#define PAC_PATH_MAX 256

	// The maximum amount of ROMs in a ROM set.
	#define PAC_ROMS_MAX 32

	// Returns the maximum filename length.
	const uint8_t get_pac_name_max(void);

	// Returns the maximum filepath length.
	const uint8_t get_pac_path_max(void);

	// Returns the maximum amount of ROMs in a ROM set.
	const uint8_t get_pac_roms_max(void);

	#ifdef __cplusplus
		}
	#endif

#endif
