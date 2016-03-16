#include <string.h>
#include <stdio.h>

char *rev(char *start, char *end)
{
    char c, *cp;
    cp = start;
    while(start < end) {
        c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;
    }
    return cp;
}

char *altrev( char *str)
{
    char *op, *tmp, *tmp1, *a, *o;
    int alt = 0;

    op = rev(str, str + (strlen(str) - 1));

    tmp = op;
    o = op;
    while(tmp) {
        tmp1 = strchr(op, ' ');
        if(tmp1 == NULL) {
            if(!alt)
                rev(op, op + strlen(op) - 1);
            break;
        }
        a = tmp1;
        if(!alt) {
            rev(op, tmp1-1);
            alt = 1;
        }
        else
            alt = 0;
        op = a + 1;
    }

    return o;
}


int main()
{
    char arr[]="Hello world how are you";

    puts(arr);
    puts(altrev(arr));

    return 0;
}
