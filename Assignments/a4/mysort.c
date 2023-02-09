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

void swap(float *a, float *b){
    float temp = *b;
    *b = *a;
    *a = temp;
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
            swap(a+k, a+i);
        }
    }
}

void quick_sort(float *a, int left, int right){
    int i, j, pivot;
    float key, temp;
    int loop = 0;

    if (left < right){
        pivot = (left + right) / 2; //pivot
        key = *(a+pivot);

        i = left - 1;
        j = right + 1;
        
        while (loop){
            do{ //shift right
                i++;
            } while(*(a+j) < key);

            do{ //shift left
                j--;
            } while (*(a+j) > key);

            if (i >= j){
                loop = false;
            }else{
                swap(a+i, a+j);
            }
        }

        quick_sort (a, left, j-1);
        quick_sort(a, j+1, right);
    }
}

enum BOOLEAN is_sorted(int *a, int left, int right)
{
    // your implementation
    enum BOOLEAN result = true;
    int left_ind = left;
    
    while(result && left<right){
        if(*(a+left_ind) > *(a+left_ind+1)){
            result = false;
        }
        left_ind++;
    }
    
    return result;
}





