/**
 * CS333 Project 8
 * task1.c
 * Write a function that sorts an array
 * 
 * Di Luo
 * 05/15/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "my_timing.h"

typedef struct {
    int *arr;
    int start;
    int extent;
} ThreadInfo;

int comparator (const void *p, const void *q) {
	int l = *(const int *)p;
	int r = *(const int *)q;
    return (l - r);
}

void *thread_sort (void *thread_info) {
    ThreadInfo *ti = (ThreadInfo *)thread_info;
    
    qsort(ti->arr + ti->start, ti->extent, sizeof(int), comparator);

    pthread_exit(NULL);
}

int main (int argc, char** argv) {
    int N = 20000;
    int a[N];
    for (int i = 0; i < N; i++) 
        a[i] = rand() % 20000; 
    
    double t1, t2;
    ThreadInfo ti[9];
    pthread_t thread[9];

    // single thread
    ti[0].arr = a;
    ti[0].start = 0;
    ti[0].extent = N;

    t1 = get_time_sec();

    pthread_create(&thread[0], NULL, thread_sort, &ti[0]);

    pthread_join(thread[0], NULL);

    t2 = get_time_sec();

    printf("1 thread: %f seconds\n", t2 - t1);

    // two threads
    for (int i = 0; i < N; i++) 
        a[i] = rand() % 20000;

    ti[1].arr = a;
    ti[1].start = 0;
    ti[1].extent = N/2;
    ti[2].arr = a;
    ti[2].start = N/2;
    ti[2].extent = N/2;
    ti[3].arr = a;
    ti[3].start = 0;
    ti[3].extent = N;
    

    t1 = get_time_sec();
    for (int i = 1; i < 3; i++) {
        pthread_create(&thread[i], NULL, thread_sort, &ti[i]);
    }

    for (int i = 1; i < 3; i++) {
        pthread_join(thread[i], NULL);
    }

    // sort the whole array
    pthread_create(&thread[3], NULL, thread_sort, &ti[3]);
    pthread_join(thread[3], NULL);

    t2 = get_time_sec();

    printf("2 threads: %f seconds\n", t2 - t1);
 

    // four threads
    for (int i = 0; i < N; i++) 
        a[i] = rand() % 10000;

    for (int i=4; i<8; i++){ 
        ti[i].arr = a;
        ti[i].start = 0 + (i-4)*N/4;
        ti[i].extent = N/4;
    }

    t1 = get_time_sec();

    for (int i = 4; i < 8; i++) {
        pthread_create(&thread[i], NULL, thread_sort, &ti[i]);
    }

    for (int i = 4; i < 8; i++) {
        pthread_join(thread[i], NULL);
    }

    pthread_create(&thread[8], NULL, thread_sort, &ti[8]);
    pthread_join(thread[8], NULL);

    t2 = get_time_sec();

    printf("4 threads: %f seconds\n", t2 - t1);

    return EXIT_SUCCESS;
}