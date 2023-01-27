/*
-------------------------------------
File:    polynomial.h
Project: sure3530_a02
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2022-01-26
-------------------------------------
 */

#define POLYNOMIAL_H

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6


float horner(float p[], int n, float x){
    float r;
    
    for (int i = 0; i < n; i++){
        r += p[i] * pow(x,(n-(i+1)));
    } 

    return r;
}

void derivative(float p[], int n, float d[]){
    
    for (int i = 0; i < n-1; i++){
        d[i] = p[i] * (n-(i+1));
    }
}

float newton(float p[], int n, float x0){
    float x=x0, px, d[n-1];\
    derivative(p, n, d);

    do{
        px = horner(p, n, x);
        x = x0 - (px / horner(d, n-1, x));
        x0 = x;
    }while ((fabs(px) > EPSILON) || (fabs(x-x0) > EPSILON));
    
    return x;
}