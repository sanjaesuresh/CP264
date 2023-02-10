/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"

#define MAX_LINE 100

char letter_grade(float s){
    char grade;

    if (s >= 90) grade = 'S';
    else if (s >= 80) grade = 'A';
    else if (s >= 70) grade = 'B';
    else if (s >= 60) grade = 'C';
    else if (s >= 50) grade = 'D';
    else grade = 'F';

    return grade;
}


STATS process_data(RECORD *dataset, int n) {    
    float totalScore = 0, avg, sd, median, sdNum = 0;
    STATS stats;

    for (int i = 0; i < sizeof(dataset); i++){ //average + total
        totalScore += dataset[i].score;
    }

    avg = totalScore / n;

    if (sizeof(dataset) % 2 == 0)
        median = dataset[sizeof(dataset)/2].score;
    else
        median = (dataset[sizeof(dataset)/2] + dataset[(sizeof(dataset)/2)+1]) / 2;
    



    



    stats = STATS {.count = n, .mean = avg, .stddev = sd, .median = median};
    return stats;
}

int import_data(char *infilename, RECORD *records) {
    char *tempwords;

    FILE *file = fopen(infilename, "r");

    if (file == NULL) perror("Error opening file"); //catch I/O error

    while (fgets(line, MAX_LINE_LEN, file) != NULL){
        tempWords = (char *) strtok(line, ',');

        *records = (RECORD) {.name = tempWords[0], .score = letter_grade((float) tempWords[1])}
        records++;
    }
    
}


int report_data(char *outfilename, RECORD *records, STATS stats) {
// your implementation
}