#include <stdio.h>
#include <assert.h>
#include <unistd.h>

struct udef{
    int val;
};

void comm(void *arg)
{
    int val;
    val = ((struct udef *)(arg))->val;
    printf("val : %d \n", val);
}

int main(int argc, char **argv)
{
    int a = 20 + 3;
    struct udef s = {a};
//   comm((void*) &s);
    assert(argc == 2);

    a = access(argv[1], F_OK);
    if(a == -1) 
        perror(argv[1]);
    else
        printf("Directory exists\n");
    return 0;
}
