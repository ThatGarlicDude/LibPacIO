#ifndef PACERROR_H
	#define PACERROR_H

	#ifdef __cplusplus
		extern "C" {
	#endif

	// Prints info on the terminal.
	void pac_info(const char* function_name, const char* message);

	// Prints a warning on the terminal.
	void pac_warn(const char* function_name, const char* message);

	// Prints an error message on the terminal.
	void pac_error(const char* function_name, const char* message);

	#ifdef __cpluscplus
		}
	#endif

#endif
