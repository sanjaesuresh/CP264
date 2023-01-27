/*
-------------------------------------
File:    fibonacci.c
Project: sure3530_a02
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2023-01-26
-------------------------------------
 */

#include "matrix.h"

float vsum(int *v, int n){
    float sum;

    for (int i = 0; i < n; i++){
        sum += *(v + i);
    } 
}

float msum(float *m, int n){
    float sum;

    for (int i = 0; i < n; i++){
        sum += *(m + i);
    }
}

void transpose_matrix(float *m1, float *m2, int n){
    int row, col;

    for (row = 0; row < n; row++){
        for (col = 0; col < n; col++){
            *(m2 + col*n + row) = *(m1 + row*n + col);
        }
    }
}

void multiply_matrix(float *m1, float *m2, float *m3, int n){
    int row, col, k, sum;

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += *(m1 + row*n + k) * *(m2 + k*n + col);
            }
            *(m3 + row * n + col) = sum;
        }
    }

}

void multiply_vector(float *m, float *v1, float *v2, int n){
    int row, col, sum;
    for (row = 0; row < n; row++) {
        sum = 0;
        for (col = 0; col < n; col++) {
            sum += *(m + row*n + col) * *(v1 + col);
            //printf("%d:%d\n", *(m1 + row*n + k), *(m2 + k*n + j));
        }
        *(v2 + row) = sum;
    }
}
