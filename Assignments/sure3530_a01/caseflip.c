/*
-------------------------------------
File:    caseflip.c
Project: sure3530_a01
-------------------------------------
Author:  Sanjae Suresh Kumar
ID:      120523530
Email:   sure3530@mylaurier.ca
Version  2020-01-16
-------------------------------------
 */

#include <stdio.h>
int main() {
  
  setvbuf(stdout, NULL, _IONBF, 0); //or setbuf(stdout, NULL); 
    
  char c = 0, temp;
  
  do {
    printf("Please enter a character\n");
    scanf(" %c", &c); //this is to get a character input from keyboard stdin.

    if (c >= 'a' && c <= 'z'){
        printf("%c:%c\n", c, c-32);
    } else if (c >= 'A' && c <= 'Z'){
        printf("%c:%c\n", c, c+32);
    } else if (c == '*'){
        break;
    } else printf("%c:invalid\n", c);;
      
  } while (c != '*');
  
  printf("*:quit");
  return 0;
}