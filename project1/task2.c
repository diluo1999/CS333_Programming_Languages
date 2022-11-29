/**
 * CS333 Project 1
 * Task 2: Access and print out the information in memory with a loop that has no stopping condition
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>

/* Access and print out the information in memory with a loop that has no stopping condition
 */ 
int main (int arg, char *argv[]) {
    //Declares and assigns some variables
    int a = 0x01234567;
    int b = 0x76543210;
    int i = 0;
    
    unsigned char *ptr;

    //Give the unsigned char * the address of itself
    ptr = (unsigned char *)&ptr;

    //Access and print out the information in memory with the pointer
    //in a for loop with no stopping condition
    for(i=0; i<1000000; i++) {
	    printf("%d: %02X ", i, ptr[i]);
	}
    return 0;
}