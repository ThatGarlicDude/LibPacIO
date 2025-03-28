#ifndef NULL_HANDLER_H
#define NULL_HANDLER_H

	#include <stdio.h>
	#include "filePathArray.h"

	const char* findFirstNull(FilePathArray* filePathArray);

	const char* findLastNull(FilePathArray* filePathArray);

#endif
