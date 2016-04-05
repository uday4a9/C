#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 

/*
This file contains whole c string library  functions.

Implemented Functions:
01. strlen_es -> just plain implementation
02. fgets_es  -> Normal fgets function, reads at most n-1 characters
    and it'll consider newline('\n') also as character.
    To avoid this we need to write our own version of this function.
*/

// Enable below line for assertion statement result
//#define DEBUG 1

int strlen_es(const char *str)
{
    const char *sp;
#if DEBUG == 1
    assert(str != NULL);
#else
    if(str == NULL)
        return -1;
#endif

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

int strindex(char *mstr, char *sstr)
{
    // returns the index of sstr in mstr
    int i, j, k;

    for(i=0; *(mstr + i); i++) {
        for(j=0, k=i; *(mstr + k) == *(sstr + j); j++, k++);
        if( !*(sstr + j))
            return i;
    }
    return -1;
}

int main()
{
    char src[128], dst[128];
    char dummy[6];
    int ind;
    puts("This whole string library implementation");

#if 0
    printf("Enter a string : ");
    __fpurge(stdin);
    fgets(dummy, 6, stdin);
    printf("STRLEN(%s) : %d\n", dummy, strlen_es(dummy));

    printf("Enter a string : ");
    __fpurge(stdin);
    fgets_es(dummy, 6);
    printf("STRLEN(%s) : %d\n", dummy, strlen_es(dummy));

    printf("Enter a string : ");
    fgets(src, 127, stdin);
    printf("STRLEN(%s) : %d\n", src, strlen_es(src));

    printf("length of NULL: %d\n", strlen_es(NULL));
#endif

    ind =  strindex("he", "hello");
    printf("Index : %d\n", ind); 

    return 0;
}
