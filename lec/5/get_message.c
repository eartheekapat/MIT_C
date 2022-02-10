#include <stdio.h>

char msg[] = "Aren't pointers fun?";

char * get_message ();

int main () {
    char * string = get_message();
    puts(string);
    return 0;
}

char * get_message() {
    return msg;
}