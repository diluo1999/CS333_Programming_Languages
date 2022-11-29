/**
 * CS333 Project 5
 * llist.c
 * Functions of single-linked list in C
 * 
 * Di Luo
 * 04/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList *ll_create(){
    // creates a new LinkedList struct, initializes it, and returns it
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

void ll_push(LinkedList *l, void *data){
    // adds a node to the front of the list, storing the given data in the node
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
    l->size++;
}

void *ll_pop(LinkedList *l){
    // removes the node at the front of the list and returns the associated data
    void *data;
    Node *remove_node = l->head;

    // check if list is empty
    if (l->head == NULL){
        return NULL;
    }

    data = remove_node->data;
    l->head = remove_node->next;
    l->size--;
    free(remove_node);
    return data;
}

void ll_append(LinkedList *l, void *data){
    // adds a node to the end of the list, storing the given data in the node
    // allocate a new memory for a new node
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // give the address of the first node
    Node *last_Node = l->head;

    // if list is empty, add the node to be the first one
    if (l->head == NULL){
        l->head = new_node;
        l->size++;
    }

    // otherwise, find the address of the last node
    else{
        for (int i=0; i<l->size-1; i++){
            last_Node = last_Node->next;
        }
        //assign last node address
        // printf("original last node data: %d\n", *(int*)(last_Node->data));
        last_Node->next = new_node;
        l->size++;
        // printf("new last node data: %d\n", *(int*)(((node*)(last_Node->next))->data));
    }
}

void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
    // removes the first node in the list whose data matches target given the 
    // comparison function. The function returns the pointer to the data
    Node *current;
    Node *previous;
    current = l->head;
    previous = NULL;

    while (current != NULL){
        if (compfunc(target,current->data)==1){
            if (previous == NULL){
                l->head = current->next;
                //if the head is what we want to remove
            }
            else{
                previous->next = current->next;
                //otherwise, connect the previous node with the node after current node
            }
            l->size--;
            return current->data;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

int ll_size(LinkedList *l){
    // returns the size of the list
    return l->size;
}

void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    // removes all of the nodes from the list, freeing the associated data 
    // using the given function
    Node *temp;

    while(l->head != NULL){
        temp = l->head;
        l->head = temp->next;

        freefunc(temp->data);
        free(temp);
    }
    l->head = NULL;
    l->size = 0;
}

void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    // traverses the list and applies the given function to the data at each node
    Node *temp = l->head;
    while (temp != NULL){
        mapfunc(temp->data);
        temp = temp->next;
    }
}

// Extension: delete method
void *ll_delete(LinkedList *l, int idx){
    // deletes the node indicated by the index and return the data
    Node *previous;
    Node *current;
    current = l->head;
    previous = NULL;
    
    if (idx > l->size - 1){
        // out of range
        return NULL;
    }

    previous = l->head;
    if (idx == 0){
        return ll_pop(l);
    }
    for (int i=0; i<idx-1; i++){
        previous = previous->next;
    }
    current = previous->next;
    previous->next = current->next;
    l->size--;
    return current->data;
}

// Extension: isEmpty method
int ll_isEmpty(LinkedList *l){
    // check if the list is empty
    return l->size==0;
}

int ll_indexOf(LinkedList *l,void *target, int (*compfunc)(void *, void *)){
    // find the index of the target in the list if target is in the list
    // return -1 otherwise
    int count = 0;
    Node *current = l->head;

    while (current != NULL){
        if (compfunc(current->data,target)==1){
            return count;
        }
        count++;
        current = current->next;
    }
    return -1; // target is not found
}