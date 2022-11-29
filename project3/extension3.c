/**
 * CS333 Project 3
 * extension3.c
 * Comparison code for extension3.js
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

#include <stdio.h>
#include <stdlib.h>

// scope & data type declaration
// C has block scope
void Var(){
    int i = 1;
    for (int i=0; i<3; i++){
        printf("i value in loop is %d\n", i);
    }
    printf("i value out of loop is %d", i);
}

int main(){
    Var();
}

