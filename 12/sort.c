#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

long long comparisons = 0;
long long swaps = 0;

void bubbleSort(int array[]){

    for(int i=0; i<CMAX-1; ++i){
        for(int j=0; j<CMAX-1-i; ++j){
            comparisons++;
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swaps ++;
            }
        }
    }
}

/* * Partition function:
 * This function takes the last element as the pivot, places
 * the pivot element at its correct position in sorted array,
 * and places all smaller (smaller than pivot) to left of
 * pivot and all greater elements to right of pivot.
 */
int partition(int arr[], int low, int high){
    int pivot = arr[high]; //pivot is last element
    int i = (low-1); //first index

    for(int j=low; j<high; j++){ 
        comparisons++;
        if(arr[j] < pivot){
            i++;
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j] =temp;
            swaps++;
        }
    }

    int temp = arr[i+1]; 
    arr[i+1] = arr[high];
    arr[high] = temp;
    swaps++;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[]){
    for(int i=1; i<CMAX; i++){
        int temp = arr[i]; //element we are currently comparing
        int j = i - 1;
        while(j>= 0 && arr[j]>temp){ //move greater elements before this one to one position forward
            arr[j+1] = arr[j];
            j = j - 1;
            comparisons++;
            swaps++;
        }
        if(j >= 0) comparisons++;
        arr[j+1] = temp; //put into correct position
    }
}

void selectionSort(int arr[]){
    for(int i=0; i<CMAX-1; i++){
        int mini = i; //assumed index of smallest element
        for(int j=i+1; j<CMAX; j++){ //find actual smallest
            comparisons++;
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
        swaps++;
    }
}

void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1 = m - l +1; //calculate subarrays lengths
    int n2 = r - m;

    int L[n1], R[n2]; //create temporary subarrays

    for(i=0; i<n1; i++){ //copy data from arr to the subarrays
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }

    i=0; //indexes of subarrays
    j=0;
    k=l;

    while(i<n1 && j<n2){ //compare elements in L and R and place smaller into arr[k]
        comparisons++;
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r - l) / 2; //find the middle
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void resetCounters() {
    comparisons = 0;
    swaps = 0;
}

void fill(int *arr){
    for(int i=0; i<CMAX; ++i){
        arr[i] = rand()%100+1; //1 - 100
    }
}

void print(int *arr){
    for(int i=0; i<CMAX; ++i){
        printf("%d ", arr[i]);
    }
}

int checkIfSorted(int *sorted){

    for(int i=0; i<CMAX-1; ++i){
        if(sorted[i] > sorted[i+1])return 0; //wrong (should be min-->max)
    }
    return 1; //good 
}