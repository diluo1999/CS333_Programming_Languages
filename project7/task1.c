/**
 * CS333 Project 7
 * task1.c
 * Investigation on the average time per call to 
 * allocate a certain amount of memory in C
 * 
 * Di Luo
 * 05/15/2020
 */

#include <stdio.h> 
#include <stdlib.h>
#include "my_timing.h"

int timing(long size, int N) {
    double t1, t2;
    double total_time = 0;
    for (int i = 0; i < N; i++) {
        t1 = get_time_sec();
        int *ptr = (int *)malloc(size*sizeof(int));
        t2 = get_time_sec();
        total_time += t2 - t1;
        free(ptr);
    }
    printf("Average Time: %lf", total_time / N);
    return 0;
}

int main(int argc, char *argv[]) {
    int N = 1000;
    printf("Small Size Memory:");
    int small_size = 10;
    timing(small_size, N);

    printf("\nMedium Size Memory:");
    long medium_size = 100000000;
    timing(medium_size, N);

    printf("\nLarge Size Memory:");
    long large_size = 1e11;
    timing(large_size, N);
}