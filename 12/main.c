#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

typedef struct {
    char name[20];
    long long total_comparisons;
    long long total_swaps;
    double total_time;
} SortStats;

void printStatistics(SortStats stats[], int count) {
    printf("%-20s %-15s %-15s %-15s\n", "Algorithm", "Time (seconds)", "Comparisons", "Swaps");
    printf("-----------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-15.6f %-15lld %-15lld\n", 
               stats[i].name, 
               stats[i].total_time,
               stats[i].total_comparisons, 
               stats[i].total_swaps);
    }
    
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    int array[CMAX];
    int copy[CMAX];
    SortStats stats[5];
    int stat_count = 0;
    
    clock_t start, end;
    double cpu_time;
    
    // Generate random array
    fill(array);
    
    // Bubble Sort
    memcpy(copy, array, sizeof(array));
    resetCounters();
    start = clock();
    bubbleSort(copy);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    strcpy(stats[stat_count].name, "Bubble Sort");
    stats[stat_count].total_comparisons = comparisons;
    stats[stat_count].total_swaps = swaps;
    stats[stat_count].total_time = cpu_time;
    stat_count++;
    printf("Bubble Sort: %s\n", checkIfSorted(copy) ? "Sorted correctly" : "ERROR");
    
    // Quick Sort
    memcpy(copy, array, sizeof(array));
    resetCounters();
    start = clock();
    quickSort(copy, 0, CMAX-1);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    strcpy(stats[stat_count].name, "Quick Sort");
    stats[stat_count].total_comparisons = comparisons;
    stats[stat_count].total_swaps = swaps;
    stats[stat_count].total_time = cpu_time;
    stat_count++;
    printf("Quick Sort: %s\n", checkIfSorted(copy) ? "Sorted correctly" : "ERROR");
    
    // Insertion Sort
    memcpy(copy, array, sizeof(array));
    resetCounters();
    start = clock();
    insertionSort(copy);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    strcpy(stats[stat_count].name, "Insertion Sort");
    stats[stat_count].total_comparisons = comparisons;
    stats[stat_count].total_swaps = swaps;
    stats[stat_count].total_time = cpu_time;
    stat_count++;
    printf("Insertion Sort: %s\n", checkIfSorted(copy) ? "Sorted correctly" : "ERROR");
    
    // Selection Sort
    memcpy(copy, array, sizeof(array));
    resetCounters();
    start = clock();
    selectionSort(copy);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    strcpy(stats[stat_count].name, "Selection Sort");
    stats[stat_count].total_comparisons = comparisons;
    stats[stat_count].total_swaps = swaps;
    stats[stat_count].total_time = cpu_time;
    stat_count++;
    printf("Selection Sort: %s\n", checkIfSorted(copy) ? "Sorted correctly" : "ERROR");
    
    // Merge Sort
    memcpy(copy, array, sizeof(array));
    resetCounters();
    start = clock();
    mergeSort(copy, 0, CMAX-1);
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    strcpy(stats[stat_count].name, "Merge Sort");
    stats[stat_count].total_comparisons = comparisons;
    stats[stat_count].total_swaps = swaps;
    stats[stat_count].total_time = cpu_time;
    stat_count++;
    printf("Merge Sort: %s\n", checkIfSorted(copy) ? "Sorted correctly" : "ERROR");
    
    printStatistics(stats, stat_count);
    
    return 0;
}