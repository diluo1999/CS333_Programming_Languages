/**
 * CS333 Project 7
 * task2.c
 * Investigation on relation between memory management call and the 
 * number of allocation and free operations the program has executed
 * 
 * Di Luo
 * 05/15/2020
 */

#include <stdio.h> 
#include <stdlib.h>
#include "my_timing.h"

int timing(long size) {
    double t1, t2;
    double alloc_time, free_time;

    for (int i = 0; i < 10; i++) {
        alloc_time = 0;
        free_time = 0;
        for (int j = 0; j < 100; j++) {
            t1 = get_time_sec();
            int *ptr = (int *)malloc(size*sizeof(int));
            t2 = get_time_sec();
            alloc_time += t2 - t1;
            
            t1 = get_time_sec();
            free(ptr);
            t2 = get_time_sec();
            free_time += t2 - t1;
        }
        printf("%d\nAllocating 100 times takes: %lf", i, alloc_time);
        printf("\nFreeing 100 times takes: %lf\n", free_time);
    }
    
    return 0;
}

int main() {
    printf("Small Size Memory:\n");
    int small_size = 10;
    timing(small_size);

    printf("\nMedium Size Memory:\n");
    int medium_size = 1000000;
    timing(medium_size);

    printf("\nLarge Size Memory:\n");
    long large_size = 1e11;
    timing(large_size);
}