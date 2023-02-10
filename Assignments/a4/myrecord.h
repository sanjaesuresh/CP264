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

/*
This function converts a float score to a letter grade according to ranges  S=[90, 100], A=[80, 90), B=[70, 80), C=[60, 70), D=[50,60), F=[0,50), and returns the letter grade.
*/
char letter_grade(float score);

/*
This function imports record data from file of name passed by infilename, and retrieves and stores all record entries in the RECORD array passed by records, and returns the number of record count.
*/
int import_data(char *infilename, RECORD *records); 

/*
This function takes the RECORD array passed by records and the number of record count as input, computes the average score, standard deviation, median of the score values of the record data, and returns the results in STATS type. 
*/
STATS process_data(RECORD *records, int count);   

/*
This function takes output file name passed by outfilename, RECORD array passed by records, and STATS value passed by stats, and output stats information, and processed record data to files in required format. It returns 0 if all operations are successful, otherwise 0. 
*/
int report_data(char *outfilename,  RECORD *records, STATS stats);
 
#endif