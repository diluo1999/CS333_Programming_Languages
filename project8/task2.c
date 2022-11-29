/**
 * CS333 Project 8
 * task2.c
 * Write a program that reads an image and applies a pixel-wise operator to it
 * 
 * Di Luo
 * 05/15/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "my_timing.h"
#include "ppmIO.h"


typedef struct{
    int start;
    int extent;
} ThreadInfo;

Pixel *src;

void *thread_filter (void *thread_info) {
    ThreadInfo *ti = (ThreadInfo *)thread_info;

	for (int i = ti->start; i < ti->start + ti->extent; i++) {
        int color = ((src[i].r + src[i].g + src[i].b) / 3);
		src[i].r = color;
		src[i].g = color;
		src[i].b = color;
	}
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int rows, cols, colors;
	int i;
    double t1, t2;
    ThreadInfo ti[7];
    pthread_t thread[7];

	if( argc < 2 ) {
		printf("Usage: %s <image filename>\n", argv[0]);
		exit(-1);
	}

	src = ppm_read( &rows, &cols, &colors, argv[1] );

	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	// 1 thread
    ti[0].start = 0;
    ti[0].extent = rows * cols;

    t1 = get_time_sec();

    pthread_create(&thread[0], NULL, thread_filter, &ti[0]);

    pthread_join(thread[0], NULL);

    t2 = get_time_sec();

	ppm_write( src, rows, cols, colors, "thread_1.ppm" );

    printf("\n1 thread\nTime: %f seconds\n", t2 - t1);


    // two threads
    ti[1].start = 0;  
    ti[1].extent = rows * cols/2;
    ti[2].start = rows * cols/2;
    ti[2].extent = rows * cols/2;

    t1 = get_time_sec();

    for (int i = 1; i < 2; i++) {
        pthread_create(&thread[i], NULL, thread_filter, &ti[i]);
    }

    for (int i = 1; i < 2; i++) {
        pthread_join(thread[i], NULL);
    }

    t2 = get_time_sec();

	ppm_write( src, rows, cols, colors, "thread_2.ppm" );
    printf("\n2 threads\nTime: %f seconds\n", t2 - t1);

    // 4 threads
    for (int i = 3; i < 7; i++){ 
        ti[i].start = 0 + (i-3) * rows * cols / 4;
        ti[i].extent = rows * cols / 4;
    }

    t1 = get_time_sec();

    for (int i = 3; i < 7; i++) {
        pthread_create(&thread[i], NULL, thread_filter, &ti[i]);
    }

    for (int i = 3; i < 7; i++) {
        pthread_join(thread[i], NULL);
    }

    t2 = get_time_sec();

	ppm_write( src, rows, cols, colors, "thread_4.ppm" );
    printf("\n4 threads\nTime: %f seconds\n", t2 - t1);

    free(src);
    
	return(0);
}