#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEOF(X) ((char*)(&x + 1) - (char*)(&X))
#if 0
    #undef SIZEOF
    #define SIZEOF(X) ((&x + 1) - (&X))
#endif

int main()
{
    short x;
    int arr[5];

    //printf("size : %ld\n", SIZEOF(x));
    //printf("sz : %d\n", (&x+1) - (&x));
    printf("diff : %ld\n", (char*)(&arr[0]+1) - (char*)&arr[0]);

    return 0;
}
