/**
 * CS333 Project 7
 * my_timing.c
 * .c file for timer that returns the time in second
 * 
 * Di Luo
 * 05/15/2020
 */

#include <sys/time.h> // for get_time_sec
#include <time.h>

// Return the time in seconds
// Note: it doesn't work to return a float - it must be a double.
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
} // end get_time_sec