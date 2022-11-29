/**
 * CS333 Project 1
 * Extension1.c 
 * Find the floating point number in C to which adding one would return the same number
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>

/* Find the floating point number in C to which adding one would return the same number
 */ 
int main () {

    float a = 1e+12;
    float b = 1.0;

    printf( "The value of floating number a is %f.\n", a); // 999999995904.000000
    printf( "The value of a + 1.0 is %f.\n", a + b); // 999999995904.000000

    return 0;
}