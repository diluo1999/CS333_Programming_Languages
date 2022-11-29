/**
 * CS333 Project 3
 * cstktest2.c
 * Another test code for Stack focusing on functions implemented for extension.
 * 
 * Di Luo
 * 03/04/2020
 */

#include "cstk.h"

int main (int argc, char **argv) {
    int i;
    int p;
    int size;

	Stack *s = stk_create(CSTK_MAX);

    printf("The list: ");
    stk_display(s, 0);

    // Test when empty
    p = stk_peek(s);
    printf("The top element of the stack is %d.\n", p);

    stk_isempty(s);
    stk_isfull(s);
    size = stk_size(s);

    // Add elements
	for(i = 0; i < 10; i++) {
		stk_push(s, i);
	} 
	
	printf("The list: ");
	stk_display(s, 0);
	
    // Test when empty
    p = stk_peek(s);
    printf("The top element of the stack is %d.\n", p);

    stk_isempty(s);
    stk_isfull(s);
    size = stk_size(s);
	
	stk_destroy(s);
	
	return 0;
}