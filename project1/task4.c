/**
 * CS333 Project 1
 * Task 4: Make a struct that has 3-4 different variables
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>

/*Set up the structure so it uses an odd number of bytes
 */
struct s {
    char a; //1 byte
    short b; //2 bytes
    short c; //2 bytes
    int d; //4 bytes
};

int main (int arg, char *argv[]) {
    struct s odd;
    //Assign values to each fields in the struct
    odd.a = 'a';
    odd.b = 1;
    odd.c = 2;
    odd.d = 3;

    //go through each byte in the struct with for loop
    unsigned char *ptr;
    ptr = (unsigned char *)&(odd);
    for(int i=0; i<sizeof(struct s); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}
    return 0;
}
