#include <stdio.h>
#include <assert.h>

#include <endian.h>

int main(int argc, char **argv)
{
    int val = 0x01234567, i;
    unsigned int res = 1;

    if(*(char*)&res == 1)
        puts("IT'S LITTLE ENDIAN MACHINE");
    else
        puts("IT'S BIG ENDIAN MACHINE");



    for(i=0; i<sizeof(int); ++i) {
        printf("%p : 0x%x\t\n", &val + i, *(&val + i));
        printf("%p : 0x%x\t\n", (char*) &val + i, *((char*) &val + i));
    }
    puts("");
    printf("value : %d \n", val & 0xf);
    printf("bigendian value : %x\n", htobe32(val));

    return 0;
}
