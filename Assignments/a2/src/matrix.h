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
#ifndef MATRIX_H
#define MATRIX_H
/*
 * Computes and returns the sum of all elements of n-dimensional vector v
*/
float vsum(int *v, int n); 

/*
 * Computes and returns the sum of all elements of the n-by-n matrix m.
*/
float msum(float *m, int n); 

/*
 * Transposes the n-by-n matrix m1 and save the resulted matrix in m2.
*/
void transpose_matrix(float *m1, float *m2, int n);

/*
 * Computes the matrix multiplication m1*m2 and saves the resulted matrix in m3.
*/
void multiply_matrix(float *m1, float *m2, float *m3, int n);

/*
 * Computes n-by-n matrix multiplies n-vector m*v1 and saves the result vector in v2.
*/
void multiply_vector(float *m, float *v1, float *v2, int n);

#endif