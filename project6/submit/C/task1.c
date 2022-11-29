/**
 * CS333 Project 6
 * task1.c
 * Word counter that can count the number of occurrences of every word in a text file
 * 
 * Di Luo
 * 05/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"

typedef struct wordcounter {
    int wordcount;
    char word[50];
}WordCounter; 

// create a new WordCounter
WordCounter *wc_create(){
    WordCounter *wc = (WordCounter*)malloc(sizeof(WordCounter));
    wc->wordcount = 0;
    return wc;
}

// Process word in file
void process(char *word){
    int len = strlen(word);
    if (((int)word[len-1] < 97) || (int)word[len-1] > 122){
        word[len-1] = '\0';
    }
}

// Increment word count
void increment(WordCounter wc[], char word[], int *n){
    strcpy(wc[*n].word, word);
    wc[*n].wordcount = 1;
    (*n)++;
}

// Analyze the file with addWord 
void analyze(FILE *file, WordCounter wc[], int *n){
    char word[50];
    int found = 0;
    int test = 0;
    while (fscanf(file,"%s", word) == 1){
        int i = 0;
        while(word[i]){
            word[i] = tolower(word[i]);
            i++;
        }
        process(word);
        for (int j = 0; j < *n; j++){
            if (strcmp(wc[j].word, word) == 0){
                found = 1;
                wc[j].wordcount++;
            }
        }
        if (found == 0){
            increment(wc,word,n);
        }
        found = 0;
    }
}

// Comparator function in descending order
int comparator(const void *p, const void *q) {
    WordCounter a = *(WordCounter *)p;
    WordCounter b = *(WordCounter *)q;
    return (b.wordcount - a.wordcount);
}

// Sort the wordcount array by using qsort
void top20(WordCounter wc[], int *n){
    qsort((void *) wc, *n, sizeof(WordCounter), comparator);
    for (int i=0; i<20; i++){
        printf("%s:%d \n", wc[i].word, wc[i].wordcount);
    }
}

int main(int argc, char *argv[]){
    FILE *fp;
    WordCounter wc[100];
    int numElem = 0;
    if (argc == 1){
        printf("Missing input. Filename is needed.");
        exit(-1);
    }
    else{
        if ((fp = fopen(*++argv, "r"))== NULL){
            printf("The file %s cannot be opened\n", *argv);
            return 1;
        }
        else{
        analyze(fp,wc,&numElem);
        top20(wc,&numElem);
        fclose(fp);
        }
    }
}