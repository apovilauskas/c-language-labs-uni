#ifndef SORT_H
#define SORT_H

#define CMAX 100000
#define EXPS 100 //experiments

extern long long comparisons;
extern long long swaps;

//sorting algorithms
void bubbleSort(int array[]);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void insertionSort(int arr[]);
void selectionSort(int arr[]);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

//utility functions
void resetCounters();
void fill(int *arr);
void print(int *arr);
int checkIfSorted(int *sorted);

#endif