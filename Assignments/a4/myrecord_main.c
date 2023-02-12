/*
--------------------------------------------------
Project: CP264-a4q2
File:    myrecord_main.c  public test driver
Author:  HBF
Version: 2023-02-01
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#define MAX_REC 100
 
int main(int argc, char *args[]) {  
  char infilename[40] = "marks.txt";            //default input file name
  char outfilename[40] = "record_report.txt";   //default output file name
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  
  RECORD dataset[MAX_REC]; // declare array of RECORD to store record data
  int record_count = import_data(infilename, dataset); 

  if (record_count >=1) {
    STATS stats = process_data(dataset, record_count);
    report_data(outfilename, dataset, stats);
   } else 
     printf("no record");
  
  return 0;
}
