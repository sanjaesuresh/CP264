#include <stdio.h>
#include <ctype.h>

int main(){
    int n, factorial;

    do{
        
    } while ()
}

int factorial(int n){
    int factorial;
    if (0 < n < 13){
        for (int i = 1; i <= n; i++){
            factorial *= i;
        }
    } else if (n < 0) return -1;
    else if (n == 0) return 1;
    else return 0;


    return factorial;
}