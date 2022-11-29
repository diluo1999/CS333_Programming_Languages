/**
 * CS333 Project 3
 * cstk.c
 * implement a stack by using an array
 * contains the implementation of the member functions declared in the cstk.h file
 * 
 * Di Luo
 * 03/04/2020
 */

#include "cstk.h"

int CSTK_MAX = 50;

// creates a stack with the size specified by the int value
Stack *stk_create(int i){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->stack = (int*)malloc(i);
    s->top = -1;
    CSTK_MAX = i;

    return s;
}

// recycles a stack
void stk_destroy (Stack* s){
    free(s->stack);
    free(s);
}

// adds a new value to the top of the stack
void stk_push(Stack* s, int i){
    s->top += 1;
    if (s->top >= CSTK_MAX){
        printf("Could not insert data, Stack is full.\n");
    }
    else{
        s->stack[s->top] = i;
    }
}

// removes a value from the top of the stack
int stk_pop(Stack* s){
    int i;
    if (s->top > -1){
        i = s->stack[s->top];
        s->top -= 1;
    }
    else{
        printf("Could not retrieve data, Stack is empty.\n");
        return INT_MIN;
    }

    return i;
}

// prints out the list in the reverse order if the int value is 1,
// otherwise, prints out in the original order
void stk_display(Stack* s, int i){
    int j;
    if (i == 1){
        for (j = s->top; j > -1; j--){
            printf("%d ", s->stack[j]);
        }
    }
    else{
        for (j = 0; j <= s->top ; j++){
            printf("%d ", s->stack[j]);
        }
    }
}

// Extension
// return the top element of the stack
int stk_peek(Stack* s){
    int i;
    if (s->top > -1){
        i = s->stack[s->top];
    }
    else{
        printf("Could not peek, Stack is empty.\n");
        return INT_MIN;
    }

    return i;
}

// check if the stack is empty
void stk_isempty(Stack* s){
   if(s->top == -1){
       printf("The stack is empty.\n");
   }
   else{
       printf("The stack is not empty.\n");
   }
}
   
// check if the stack is full
void stk_isfull(Stack* s){
    if(s->top == CSTK_MAX - 1){
        printf("The stack is full.\n");
    }
    else{
        printf("The stack is not full.\n");
    }
}

// checks and returns the number of current occupied spots in the stack
int stk_size(Stack* s){
    printf("Currently %d spots in stack are occupied.\n", s->top+1);

    return s->top+1;
}