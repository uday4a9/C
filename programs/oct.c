#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int num;

    printf("Enter a number : ");
    scanf("%o", &num);

    printf("%d : %o\n", num, num);

    return 0;
}
