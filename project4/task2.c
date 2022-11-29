/**
 * CS333 Project 4
 * task2.c
 * Write a function that takes in an integer argument and returns its factorial value as an integer
 * 
 * Di Luo
 * 03/11/2020
 */

#include <stdio.h>
#include <stdlib.h>

// function that takes in an integer argument and returns its factorial value as an integer
int factorial(int i){
    int a, b= 1;

    for (a=1; a<=i; a++){
        b = a * b;
    }

    return b;
}

int main (int argc, char **argv) {
    int N;
    if (argc > 1){
        N = atoi(argv[1]);
    }
    else{
        N = 5;
    }
    int d;
    int (*calc)(const int);

    calc = factorial;

    d = calc(N);

    printf("Factorial of %d = %d\n", N, d);
    return 0;
}