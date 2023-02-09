/*
 * your program signature
 */ 
 
#ifndef MYRECORD_H
#define MYRECORD_H 

typedef struct {
  char name[40];
  float score;
} RECORD;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

char letter_grade(float score);
int import_data(char *infilename, RECORD *records); 
STATS process_data(RECORD *records, int count);   
int report_data(char *outfilename,  RECORD *records, STATS stats);
 
#endif