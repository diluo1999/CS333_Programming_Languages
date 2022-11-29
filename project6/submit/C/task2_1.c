/**
 * CS333 Project 6
 * task2_1.c
 * Signal handling in C : a program that can respond to a cntl-C (interrupt)
 * 
 * Di Luo
 * 05/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int quit = 0;

void handler(int signal){
    printf("cntl-C is pressed");
    quit = 1;
    exit(-1);
}

int main(){
    signal(SIGINT, *handler);
    int i = 0;
    while (!quit){
        // printf("%d\n",i);
        i++;
    }
    return 0;
}
