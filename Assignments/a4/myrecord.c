/*
-------------------------------------
File:    mysort.c
Project: sure3530_a04
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-02-06
-------------------------------------
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

int compare(const void *a, const void *b) {
    float score_a = ((RECORD *) a)->score;
    float score_b = ((RECORD *) b)->score;
    return (score_a > score_b) - (score_a < score_b);
}

STATS process_data(RECORD *dataset, int n) {    
    float totalScore = 0, avg, sd, median, sdNum = 0;
    STATS stats;

    RECORD *sortedDataset = (RECORD *) malloc(sizeof(RECORD) * n);
    memcpy(sortedDataset, dataset, sizeof(RECORD) * n);
    qsort(sortedDataset, n, sizeof(RECORD), compare);

    for (int i = 0; i < n; i++){ //average + total
        totalScore += dataset[i].score;
    }

    avg = totalScore / n;

    //median
    if (n % 2 == 0){
        median = (sortedDataset[(int)floor(n/2)-1].score + sortedDataset[((int)floor(n/2))].score) / 2;
    }else
        median = sortedDataset[n/2].score;

    //sd
    for (int i = 0; i < n; i++){
        sdNum += pow((dataset[i].score - avg), 2);
    }

    sd = sqrt(sdNum/n-1);

    stats = (STATS) {.count = n, .mean = avg, .stddev = sd, .median = median};
    free(sortedDataset);
    return stats;
}

int import_data(char *infilename, RECORD *records) {
    // your implementation
    FILE *fp = fopen(infilename, "r");
    char delimiters[] = " ,\n\r";
    char line[100];
    int i = 0; // record counter
    char *token = NULL;

    while (fgets (line, sizeof(line), fp) != NULL ) {
        token = (char *) strtok(line, delimiters);
        strcpy(records[i].name, token); // copy string char array
        token = (char *) strtok(NULL, delimiters);
        records[i].score = atof(token); // convert string to float
        i++;
    }
    fclose(fp);
    return i;
}

int report_data(char *outfilename, RECORD *records, STATS stats) {
    if (stats.count == 0 || records == NULL){
        return 0;
    }else{
        printf("\nstats:value");
        printf("\ncount:%d", stats.count);
        printf("\nmean:%.1f", stats.mean);
        printf("\nstddev:%.1f", stats.stddev);
        printf("\nmedian:%.1f", stats.median);

        printf("\n\nname:score,grade");
        for (int i = 0; i < stats.count; i++){
            printf("\n%s,%.1f", (*records).name, (*records).score);
            records++;
        }

        return 1;
    }
}