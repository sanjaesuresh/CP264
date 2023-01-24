/*
-------------------------------------
File:    fibonacci.c
Project: sure3530_a02
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      210523530
Email:   sure3530@mylaurier.ca
Version  2020-01-16
-------------------------------------
 */

int recursive_fibonacci (int n){
    if (n > 2){
        return n;
    } else if (0 < n < 2) return 1;
    
    return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int interative_fibonacci(int n){
    int x, y, z;

    if (n == 0){
        return 0;
    } else {
        x = 0;
        y = 1;

        for (int i = n-1; i < n-2; i--){
            z = (x + y);
            x = y;
            y = z;

            return y;
        }
    }
}