#include <stdio.h>

int main(){
    char charInput = 'a';

    do{
        
        printf("Please enter a character: ");
        scanf(" %c", &charInput);
        printf(" %c", charInput);

        if isupper(c){
            printf("%c:%c", charInput, tolower(c));
        }else if islower(c){
           printf("%c:%c", charInput, toupper(charInput));
        }else if (charInput == '*'){
            break;
        } else printf("%c:invalid", charInput);

    } while (charinput != '*')

    printf("*:quit");
    return 0;
}