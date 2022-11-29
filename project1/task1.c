/**
 * CS333 Project 1
 * Task 1: Memory access
 * Declare a variable of each of the basic types (char, short, int, 
 * long, float, double) and assigns each one a value. Declare an 
 * unsigned char and then go through each data type and look how 
 * it is stored in memory.
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>

/* Declare a variable of each of the basic types and explore
 * how they are stored in memory
 */ 
int main (int arg, char *argv[]) {
        
    // Declare a variable of each of the basic types and assign values
    char c = 'c';
    short s = 1;
    int in = 0x01234567;
    long l = 3;
    float f = 4.1;
    double d = 5.1;
    int i = 0;

    // Declare an unsigned char * that go through each data type
    unsigned char *ptr;

    //char
    printf("%s", "How char is stored in memory\n");
    ptr = (unsigned char *)&(c);
    for(i=0; i<sizeof(char); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

    //short
    printf("%s", "How short is stored in memory\n");
    ptr = (unsigned char *)&(s);
    for(i=0; i<sizeof(short); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

    //int
    printf("%s", "How int is stored in memory\n");
    ptr = (unsigned char *)&(in);
    for(i=0; i<sizeof(int); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

    //long
    printf("%s", "How long is stored in memory\n");
    ptr = (unsigned char *)&(l);
    for(i=0; i<sizeof(long); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

    //float
    printf("%s", "How float is stored in memory\n");
    ptr = (unsigned char *)&(f);
    for(i=0; i<sizeof(float); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

    //double
    printf("%s", "How double is stored in memory\n");
    ptr = (unsigned char *)&(d);
    for(i=0; i<sizeof(double); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}
        
    return 0;
}