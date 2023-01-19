/**
--------------------------------------------------
Project: cp264-a1q2
File:    factorial.c
Author:  Sanjae Suresh Kumar
Version: 2022-01-18
--------------------------------------------------
*/
#include <stdio.h>

int main(){
    int n=0, x, f=1;
    
    scanf("%d",&n); 
  
    if (n > 1 && n <= 12) {
        
        for (int i = 2; i <= n; i++){
            f *= i;
        }
        printf("%d:%d", n, f);
       
    } else if (n > 12) {
        printf("%d:overflow", n);
    
        
    } else if (n == 0 || n == 1){ 
        printf("%d:1", n);
    
    } else printf("%d:invalid\n", n);
    
  return 0;
} return factorial;
}