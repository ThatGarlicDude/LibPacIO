#ifndef FILE_PATH_EXTENDER_H
#define FILE_PATH_EXTENDER_H

	#include "filePathArray.h"

	void changeSize(FilePathArray* filePathArray, int size);

	void addFilePath(FilePathArray* filePathArray, const char* filePath, int index);

	void removeFilePath(FilePathArray* filePathArray, int index);

	void pushFilePath(FilePathArray* filePathArray, const char* filePath);

#endif
