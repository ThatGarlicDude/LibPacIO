#include "filePathArray.h"

#ifndef FILE_PATH_TRIMMER_H
#define FILE_PATH_TRIMMER_H

	void trimFilePathArray(FilePathArray* filePathArray, int offset, int amount);

	void trimFilePathArrayByFirstNull(FilePathArray* filePathArray);

#endif
