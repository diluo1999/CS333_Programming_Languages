/**
 * CS333 Project 1
 * Task 3: Repeatedly allocates a small amount of memory in a loop 
 * and watch the memory requirements for the program grow
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>

/* Repeatedly allocates a small amount of memory in a loop 
 * and watch the memory requirements for the program grow
 */ 
int main (int arg, char *argv[]) {

    //Declare a pointer
    unsigned char *ptr;

    //variable to point to the memory
    for (int i=0; i<1000000000;i++){
        ptr = (unsigned char *) malloc(sizeof(unsigned char));
        //allocate a small amount of memory
        free(ptr);
    }
    return 0;
}