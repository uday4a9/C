#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This file contains whole c string library  functions.

Implemented Functions:
01. strlen_es -> just plain implementation
02. fgets_es  -> Normal fgets function, reads at most n-1 characters
    and it'll consider newline('\n') also as character.
    To avoid this we need to write our own version of this function.
*/

int strlen_es(const char *str)
{
    const char *sp;
    if(str == NULL)
        return -1;
    sp = str;
    while(*str && str++);
    return str - sp;
}

char* fgets_es(char *str, ssize_t size)
{
    int i = 0;
    char ch;

    for(i=0; (i < size-1) && ((ch= getchar()) != EOF) && ch != '\n'; i++)
        str[i] = ch;
    str[i] = '\0';

    return str;
}

int main()
{
    char src[128], dst[128];
    char dummy[6];
    puts("This whole library contains string own library");

    printf("Enter a string : ");
    __fpurge(stdin);
    fgets(dummy, 6, stdin);
    printf("STRLEN(%s) : %d\n", dummy, strlen_es(dummy));

    printf("Enter a string : ");
    __fpurge(stdin);
    fgets_es(dummy, 6);
    printf("STRLEN(%s) : %d\n", dummy, strlen_es(dummy));

    //fgets(src, 127, stdin);
    printf("STRLEN(%s) : %d\n", src, strlen_es(src));

    return 0;
}
