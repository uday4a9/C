#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEOF(X) ((char*)(&x + 1) - (char*)(&X))

int main()
{
    short x;

    printf("size : %ld\n", SIZEOF(x));

    return 0;
}
