#ifndef FILE_PATH_ARRAY_H
#define FILE_PATH_ARRAY_H

	#include <stdio.h>

	typedef struct {
		const char** filePaths;
		size_t size;
	} FilePathArray;

	FilePathArray newFilePathArray(size_t size);

	FilePathArray newEmptyFilePathArray();

	void freeFilePaths(FilePathArray* filePathArray);

#endif
