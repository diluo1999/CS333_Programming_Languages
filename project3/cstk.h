/**
 * CS333 Project 3
 * cstk.h
 * implement a stack by using an array
 * The .h file that contains the necessary sturctures and the declarations of the member functions
 * 
 * Di Luo
 * 03/04/2020
 */

#ifndef cstk_h
#define cstk_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int CSTK_MAX;

typedef struct stack {
		int* stack;
		int top;
} Stack;

Stack *stk_create(int i);

void stk_destroy (Stack* s);

void stk_push(Stack* s, int i);

int stk_pop(Stack* s);

void stk_display(Stack* s, int i);

// Extension
int stk_peek(Stack* s);
void stk_isempty(Stack* s);
void stk_isfull(Stack* s);
int stk_size(Stack* s);

#endif /* cstk_h */