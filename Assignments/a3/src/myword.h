/*
-------------------------------------
File:    myword.h
Project: sure3530_a03
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-01-29
-------------------------------------
 */
 
#ifndef MYWORD_H
#define MYWORD_H

#define MAX_WORD 30
#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

typedef struct word {
    char word[MAX_WORD];
    int frequency;
} WORD;

typedef struct words {
    int line_count;
    int total_word_count;
    int distinct_word_count;
} WORDSTATS;

int process_word(char *filename, WORD *words, WORDSTATS *wordstats);
int save_file(char *filename, WORD *words, WORDSTATS *wordstats);

#endif