#include <stdio.h>
#include <stdlib.h>

int writeCount=0;
int readCount=0;

void saveToFile(int *arr, char *filename){
    FILE *write = fopen(filename, "wb");
    if (write == NULL) return;

    int size = arr[0];
    fwrite(arr, sizeof(int), size+1, write);
    fclose(write);
    writeCount++;
}

void loadFromFile(int *arr, char *filename){
    FILE *read = fopen(filename, "rb");
    if (read == NULL) return;

    fread(&arr[0],sizeof(int), 1, read);
    int size = arr[0];
    fread(&arr[1], sizeof(int), size, read);
    fclose(read);
    readCount++;
}