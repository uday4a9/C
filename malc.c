#include <stdio.h>
#include <assert.h>

#undef malloc

void* mallc(size_t size)
{
    char cmd[128];
    printf("Malloc invoked : %s \n", __builtin_FUNCTION ());
    printf("Malloc invoked : %s \n", __PRETTY_FUNCTION__);
    printf("add : %p \n", mallc);
    void *p = __builtin_return_address (0);
    printf(" val : %p \n", __builtin_return_address (0));
    printf(" val : %p \n", __builtin_return_address (1));
    snprintf(cmd, sizeof(cmd), "addr2line -e %s -f %p", "malc", p);
    system(cmd);
    return NULL;
}

int main(int argc, char **argv)
{
    char str[12] = "Hello World";
    mallc(12);

//    printf("TYPE : %s\n", typeof(12) == int); 

//    printf(" val : %p \n", __builtin_return_address (0));
    printf("addr : %p \n", main);
    return 0;
}
