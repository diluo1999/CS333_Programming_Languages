/**
 * CS333 Project 6
 * task2_3.c
 * Signal handling in C : a program that can handle a segmentation fault error
 * 
 * Di Luo
 * 05/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signal){
    printf("Segmentation fault error\n");
    exit(-1);
}

int main(){
    signal(SIGSEGV, *handler);
    const char *s = NULL;
    printf("%c\n",s[0]);
    return 0;
}
