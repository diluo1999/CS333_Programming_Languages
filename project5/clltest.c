/*
	Bruce Maxwell
	Fall 2012
	CS 333

	Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Part 1: Integer
// function that prints an integer
void printInt(void *i) {
	int *a = (int *)i;

	printf("value: %d\n", *a);
}

// function that squares an integer
void squareInt(void *i) {
	int *a = (int *)i;

	*a = *a * *a;
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
	int *a = (int *)i;
	int *b = (int *)j;

	return(*a == *b);
}

// Part 2: Float
// function that prints a float
void printFloat(void *i) {
	float *a = (float *)i;

	printf("value: %f\n", *a);
}

// function that squares a float
void squareFloat(void *i) {
	float *a = (float *)i;

	*a = *a * *a;
}

// function that compares two floats and returns 1 if they are equal
int compFloat(void *i, void *j) {
	float *a = (float *)i;
	float *b = (float *)j;

	return(*a == *b);
}

// test function for the various linked list functions
int main(int argc, char *argv[]) {
	LinkedList *l;
	int *a;
	int *target;
	int i;

	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<20;i+=2) {
		a = malloc(sizeof(int));
		*a = i;

		ll_push(l, a);
	}

	// printing the list and testing map
	printf("Part 1: Integer\n");
	printf("After initialization\n");
	ll_map(l, printInt);

	ll_map(l, squareInt);

	printf("\nAfter squaring\n");
	ll_map(l, printInt);

	// testing removing data
	target = malloc(sizeof(int));

	*target = 16;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	*target = 11;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	printf("\nAfter removals\n");
	ll_map(l, printInt);

	// testing appending data
	ll_append(l, target);

	printf("\nAfter append\n");
	ll_map(l, printInt);

	// test clearing
	ll_clear(l, free);

	printf("\nAfter clear\n");
	ll_map(l, printInt);

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		a = malloc(sizeof(int));
		*a = i;
		ll_append(l, a);
	}

	printf("\nAfter appending\n");
	ll_map(l, printInt);

	a = ll_pop(l);
	printf("\npopped: %d\n", *a);
	free(a);

	a = ll_pop(l);
	printf("popped: %d\n", *a);
	free(a);

	printf("\nAfter popping\n");
	ll_map(l, printInt);

	printf("\nList size: %d\n", ll_size(l) );




	printf("\n\nPart 2: Float\n");
	float *b;
	float *target2;
	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<20;i+=2) {
		b = malloc(sizeof(float));
		*b = i + 0.5;

		ll_push(l, b);
	}

	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printFloat);

	ll_map(l, squareFloat);

	printf("\nAfter squaring\n");
	ll_map(l, printFloat);

	// testing removing data
	target2 = malloc(sizeof(float));

	*target2 = 20.25;
	b = ll_remove(l, target2, compFloat);
	if(b != NULL)
		printf("\nremoved: %f\n", *b);
	else
		printf("\nNo instance of %f\n", *target2);

	*target2 = 11.5;
	b = ll_remove(l, target2, compFloat);
	if(b != NULL)
		printf("\nremoved: %f\n", *b);
	else
		printf("\nNo instance of %f\n", *target2);

	printf("\nAfter removals\n");
	ll_map(l, printFloat);

	// testing appending data
	ll_append(l, target2);

	printf("\nAfter append\n");
	ll_map(l, printFloat);

	// test clearing
	ll_clear(l, free);

	printf("\nAfter clear\n");
	ll_map(l, printFloat);


	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		b = malloc(sizeof(float));
		*b = i+0.5;
		ll_append(l, b);
	}

	printf("\nAfter appending\n");
	ll_map(l, printFloat);

	b = ll_pop(l);
	printf("\npopped: %f\n", *b);
	free(b);

	b = ll_pop(l);
	printf("popped: %f\n", *b);
	free(b);

	printf("\nAfter popping\n");
	ll_map(l, printFloat);

	printf("\nList size: %d\n", ll_size(l) );

	// Testing ll_delete()
	printf("\nRestore the list to the state before append and pop\n");
	ll_clear(l, free);
	for(i=0;i<5;i++) {
		b = malloc(sizeof(float));
		*b = i+0.5;
		ll_append(l, b);
	}
	ll_map(l, printFloat);
	b = ll_delete(l, 2);
	printf("\ndeleted: %f\n", *b);
	printf("\nAfter deleting\n");
	ll_map(l, printFloat);
	free(b);

	// Testing ll_isEmpty()
	printf("\nCheck if the list is empty\n");
	i = ll_isEmpty(l);
	if (i!=0)
		printf("\nList is empty\n");
	else
		printf("\nList is not empty\n");

	// Testing ll_indexOf()
	printf("\nCheck the index of 4.50000\n");
	*target2 = 4.5;
	i = ll_indexOf(l, target2, compFloat);
	if (i==-1)
		printf("\n4.5 is not in the list\n");
	else
		printf("\n4.5 is in the list with index %d\n", i);
	
	return(0);
}