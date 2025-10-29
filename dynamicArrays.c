#include <stdio.h>
#include <stdlib.h>

void dynamic1(int n, double **arr){ //double pointer is to be able to change the same pointer as is in main, not a copy
    *arr = (double*)malloc(n * (sizeof(double))); //malloc() allocates memory in the heap, big enough for n doubles. It returns the address of the first element.
    for(int i=0; i<n; ++i){
        (*arr)[i] = i+1;
    }
}

double *dynamic2(int n){ 
    double *arr = (double*)malloc(n * (sizeof(double))); 
    for(int i=0; i<n; ++i){ 
       arr[i] = i+1;   
    }
    return arr;
}

int main() {
    
    double *arr = NULL;
    int n = 5;
    dynamic1(n, &arr);

    for(int i=0; i<n; i++){
        printf("%.1lf ", arr[i]);
    }

    free(arr);
    
    return 0;
}