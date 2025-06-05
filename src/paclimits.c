#include <stdint.h>
#include "paclimits.h"

// Returns the maximum filename length.
const uint8_t get_pac_name_max(void) {
	return PAC_NAME_MAX;
}

// Returns the maximum filepath length.
const uint8_t get_pac_path_max(void) {
	return PAC_PATH_MAX;
}

// Returns the maximum amount of ROMs in a ROM set.
const uint8_t get_pac_roms_max(void) {
	return PAC_ROMS_MAX;
}
