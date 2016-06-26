#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(size_t val)
{
    printf("val : %zu, %lu\n", val, sizeof(val));
}

int main()
{
    fun(3);
    fun(-3);

    return 0;
}
