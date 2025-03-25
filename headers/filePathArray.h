#ifndef FILE_PATH_ARRAY_H
#define FILE_PATH_ARRAY_H

	typedef struct {
		const char** filePaths;
		size_t size;
	} FilePathArray;

	FilePathArray newFilePathArray(size_t size);

	FilePathArray newEmptyFilePathArray();

	const char** getFilePaths(FilePathArray* filePathArray);

	size_t getSize(FilePathArray* filePathArray);

#endif
