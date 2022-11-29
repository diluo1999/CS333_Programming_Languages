/**
 * CS333 Project 5
 * linkedlist.h
 * Declare structs and functions for linked list
 * 
 * Di Luo
 * 04/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // hold an arbitary pointer and a next pointer
    void *data;
    void *next;
} Node; 

typedef struct {
    // single-linked list
    Node *head;
    int size;
} LinkedList; 

LinkedList *ll_create();

void ll_push(LinkedList *l, void *data);

void *ll_pop(LinkedList *l);

void ll_append(LinkedList *l, void *data);

void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

int ll_size(LinkedList *l);

void ll_clear(LinkedList *l, void (*freefunc)(void *));

void ll_map(LinkedList *l, void (*mapfunc)(void *));

void *ll_delete(LinkedList *l, int idx);

int ll_isEmpty(LinkedList *l);

int ll_indexOf(LinkedList *l,void *target, int (*compfunc)(void *, void *));
