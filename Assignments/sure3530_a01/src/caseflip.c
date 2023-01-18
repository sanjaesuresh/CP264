#include <stdio.h>
#include <ctype.h>

int main(){
    char c;

    do {
        printf("\nPlease enter a character");
        scanf(" %c", &c);

        if (isupper(c)){
            printf("%c:%c", c, tolower(c));
        }else if(islower(c)) {
            printf("%c:%c", c, toupper(c));
        } else if (c != '*'){
            printf("%c:invalid", c);
        }

    } while (c != '*');

    printf("*:quit");
    return 0;
}