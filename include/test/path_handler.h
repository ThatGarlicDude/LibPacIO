// TODO: Maybe have this whole thing put and packaged into LibPacIO as a shared library.

#ifndef LIBPACIO_PATH_HANDLER_H
	#define LIBPACIO_PATH_HANDLER_H

	#ifdef __cplusplus
		extern "C" {
	#endif

	#define DEFAULT_PATH "."

	extern char* path;

	// Sets the file path for the LibPacIO test. Fails if the path is invalid.
	int libpacio_set_path(const char* new_path);

	// Gets the file path for the LibPacIO test.
	const char* libpacio_get_path(void);

	// Clears and frees the file path for the LibPacIO test.
	void libpacio_clear_path(void);

	#ifdef __cplusplus
		}
	#endif

#endif
