#include <stdio.h>
#include <stdlib.h>

int main () 
{
    char c;

    scanf("%c", &c);


    if (c >= 'a' && c <= 'z') {
        printf("Character variable c is a lower case letter.\n");
    } else if (c >= 'A' && c <= 'Z') {
        printf("Character variable c is an upper case letter.\n");
    } else if (c >= '0' && c <= '9') {
        printf("Character variable c is a digit.\n");
    } else if (c == '\n' || c == 't' || c == ' ') {
        printf("Character variable c is a white space.\n");
    }

    return 0;          
}