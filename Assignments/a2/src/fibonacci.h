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

#define _FIBONACCI_H_

int recursive_fibonacci (int n){
    if (n <= 2){
        return 1;
    } else 
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int iterative_fibonacci(int n){
    int first = 0, second = 1, fib, temp;

    for (int i = 3; i <= n; i++){
        temp = second;
        second += first;
        first = temp;
    }

    return second;
}