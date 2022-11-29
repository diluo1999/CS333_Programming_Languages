/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 *
 * CS333 Project 4
 * quicksort.c
 * Di Luo
 * 03/11/2020
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	// Your code here
	int m = *(const int*)p;
	int n = *(const int*)q;

	// & is bis wise
	if ((m&1) && (n&1)) // both odd
		return m-n; // smaller one stays in the front

	if (!(m&1) && !(n&1)) // both even
		return n-m; // greater one stays in the front

	if ((m&1) && !(n&1)) // m is odd and n is even
		return 1; // n stays in the front
	
	return -1; // the case when m is even and n is odd, m stays in the front
	
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}