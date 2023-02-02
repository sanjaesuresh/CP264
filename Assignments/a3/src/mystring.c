/*
-------------------------------------
File:    mystring.c
Project: sure3530_a03
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-01-29
-------------------------------------
 */
 
#include "mystring.h"
#define NULL 0
#include <stdio.h>
#include <ctype.h>

int str_length(char *s) {
    int count = 0;

    if (s == NULL) return -1;
    char *p = s;

    while (*p){
        count++;
        p++; //index
    }

    return count;

}

int word_count(char *s) {
// your implementation
    int numWords = 0;
    char *copy = s;

    while (*copy){
        if (*copy == ' ' && *(copy-1) != ' ')
            numWords++;
            
        *copy++;
    }

    return numWords-1;
}

void lower_case(char *s) {
    int i = 0;
    
    for (int i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
}

void str_trim(char *s){
    int len = str_length(s);
    int first, last, k = 0;

    for (first = 0; first < len && (s[first] == ' '); first++);
    for (last = len - 1; last >= 0 && (s[last] == ' '); last--);

    for (int ind = first; ind <= last; ind++){
        if (s[ind] != ' ' || s[ind] == ' ' && s[ind-1] != ' '){
            s[k++] = s[ind];
        }
    }

    s[k] = '\0';
}