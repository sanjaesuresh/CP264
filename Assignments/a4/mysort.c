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

#include "mysort.h"

void swap(float *a, int n1, int n2){
    float temp = a[n1];
    a[n1] = a[n2];
    a[n2]  = temp;
}

void select_sort(float *a, int left, int right){
    int i, k;
    float temp;
    int n = right - left + 1;

    for (i = 0; i < n; ++i){
        k = i;
        for (int j = i + 1; j < n; ++j){
            if (*(a+j) < *(a+k)){
                k = j;
            }
        }
        if (i != k){
            swap(a, k, i);
        }
    }
}

void quick_sort(float *a, int left, int right){
    int i, j;
    int pivot, temp;

    if (left < right){
        pivot = left;
        i = left;
        j = right;

        while (i < j){
            while (a[i] <= a[pivot] && i < right) i++;
            while (a[j] > a[pivot]) j--;
            if (i < j){
                swap(a, i, j);
            }
        }

        swap(a, pivot, j);
        quick_sort (a, left, j-1);
        quick_sort(a, j+1, right);
    }
}

enum BOOLEAN is_sorted(float *a, int left, int right){
    // your implementation
    enum BOOLEAN result = true;
    
    for (int i = 0; i < sizeof(a); i++){
        if (a[i] >= a[i+1])
            result = false;
            break;
    }
    
    return result;
}





