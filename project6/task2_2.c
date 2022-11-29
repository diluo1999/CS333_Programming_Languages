/**
 * CS333 Project 6
 * task2_2.c
 * Signal handling in C : a program that can handle a floating point exception
 * 
 * Di Luo
 * 05/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signal){
    printf("Inappropriate floating point usage\n");
    exit(-1);
}

int main(){
    signal(SIGFPE, *handler);
    int a = 3;
    int b = 0;
    int c = a/b;
    return 0;
}
