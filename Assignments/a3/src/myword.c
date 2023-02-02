/*
-------------------------------------
File:    myword.c
Project: sure3530_a03
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-01-29
-------------------------------------
 */
 
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"


int process_word(char *filename, WORD *words, WORDSTATS *wordstats) {
   const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
   char line[300];
   char *tempWords = NULL;
   FILE *file = fopen(filename, "r");
   int index = 0;

   if (file == NULL) perror("Error opening file"); //catch I/O error

   while (fgets(line, MAX_LINE_LEN, file) != NULL){
      wordstats -> line_count++;
      
      str_trim(line); //required func
      lower_case(line); //required func

      tempWords = (char *) strtok(line, delimiters);

      while (tempWords != NULL){
         wordstats -> total_word_count++;

         int ind = 0;

         while (ind < wordstats -> distinct_word_count && strcmp(tempWords, words[ind].word)){
            ind++;
         }

         if (ind < wordstats -> distinct_word_count){ //word in arr found
            words[ind].frequency++;
         } else { //insert new word
            strcpy(words[ind].word, tempWords);

            words[ind].frequency = 1;
            wordstats -> distinct_word_count++;
         }

         tempWords = (char *) strtok(NULL, delimiters); //next word
      }

      tempWords = (char *) NULL;
   }

   fclose(file);
   return 0;
}

int save_file(char *filename, WORD *words, WORDSTATS *wordstats) {
   FILE *file = fopen(filename, "w");
   int j = 0;

   fprintf(file, "\nword stats:value");
   fprintf(file, "\nline count: %d", wordstats -> line_count);
   fprintf(file, "\ntotal word count: %d", wordstats -> total_word_count);
   fprintf(file, "\ndistinct word count: %d", wordstats -> distinct_word_count);

   fprintf(file, "\n\ndistinct words:frequency");

   for (int i = 0; i < wordstats->distinct_word_count; i++) {
      fprintf(file, "\n%s:%d", words[i].word, words[i].frequency);
   }

   fclose(file);
   return 0;
}