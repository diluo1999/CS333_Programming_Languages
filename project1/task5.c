/**
 * CS333 Project 1
 * Task 5: Demonstrate how to overwrite a decision variable within 
 * the function by passing a string that is slightly too long to a 
 * function if the function uses strcpy to copy the parameter to a 
 * local character array of fixed length.
 *
 * Di Luo
 * 02/19/2020 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*A struct with a fixed size string and an int in the struct
 */
struct variables{
    char testarr[5];
    int a;
};

void teststring(char *string){
    //Assigning values to each field in the struct
    struct variables v;
    v.a = 0;
    //copy the parameter to a local haracter array of fixed length
    strcpy(v.testarr,string);


    if (v.a==0){
        printf("safe");
        //If the decision variable has the value 0, the function prints out safe
    }
    else{
        printf("hacked");
    }
}

/* Demonstrate how to overwrite a decision variable within the 
 * function by passing a string that is slightly too long to a function
 */
int main (int arg, char *argv[]) {
    if (arg < 1 ){
    teststring("Hello World! Hello World! Hello World! Hello World! Hello World! Hello World!");
    //enter a string that is too long to the function (comparing to the size of the array)
    }

    // Extension: Make the safe/hacked program use a string from the command line
    char* init_d = argv[1];
    // Assign the string from the command line to the init_d variable
    printf("%s\n", init_d);
    teststring(init_d);

    return 0;
}