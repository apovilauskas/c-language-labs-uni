#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int* fillArray(int size){
    int *arr = (int*)malloc((size+1) * sizeof(int));
    arr[0] = size;
    for(int i=1; i<=size; i++){
        arr[i] = rand()%(101);
    }
    return arr;
}

void printArray(int *arr){
    for(int i=1; i<=arr[0]; i++){
        printf("%d ", arr[i]);
    }

}

int main() {
    
    int *m1 = fillArray(50);
    int *m2 = fillArray(50);
    int *m3 = fillArray(50);

    saveToFile(m1, "file1.bin");
    saveToFile(m3, "file1.bin");
    loadFromFile(m1, "file1.bin");
    saveToFile(m2, "file2.bin");
    loadFromFile(m3, "file2.bin");
    loadFromFile(m2, "file2.bin");

    if(readCount == 3 && writeCount == 3){
        printf("all good\n");
    } else {
        printf("something's wrong\n");
    }
    
    free(m1);
    free(m2);
    free(m3);
    
    return 0;
}