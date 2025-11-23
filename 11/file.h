#ifndef FILE_H
#define FILE_H

extern int writeCount;
extern int readCount;

// writes binary into the res.bin file, where the 
// first element is the size of the array
void saveToFile(int *arr, char *filename);

// reads a binary file and puts it into an array
// where the first element is the size of the array
void loadFromFile(int *arr, char *filename);

#endif