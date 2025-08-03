#ifndef LIBPACIO_FLAG_HANDLER_H
	#define LIBPACIO_FLAG_HANDER_H

	#ifdef __cplusplus
		extern "C" {
	#endif

	#define FLAG_VERSION "-v"
	#define FLAG_PATH "-p"
	#define FLAG_HELP "--help"

	extern int libpacio_index;

	// Handle the command-line options for the LibPacIO Test.
	int libpacio_handle_flags(int argc, char* argv[]);

	#ifdef __cplusplus
		}
	#endif

#endif
