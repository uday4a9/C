#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// This program just to print the banner status
int main()
{
    char str[50];
    int i=0;

    putchar('[');
    while(i < 10) {
        i += 1;

        // form the string
        sprintf(str, "%c]", '%');

        // backspce to delete the last brace character
        fprintf(stdout, "%s\b", str);

        // make it as character buffered content
        fseek(stdout, 0, SEEK_CUR);
        sleep(1);
    }
    puts("");

    return 0;
}
