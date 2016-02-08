#include <stdio.h>
#include <assert.h>
#include <getopt.h>
/*
   To create files of given size in form of bytes
*/

int main(int argc, char **argv)
{
    FILE *fp;

    assert(argc == 3);

    fp = fopen(argv[1], "w");
    assert(fp != NULL);

    if( fseek(fp, atoi(argv[2]) - 1 , SEEK_SET) == -1) {
        perror("ftell");
        return -1;
    }
    //printf("offset value : %ld\n", ftell(fp));
    fprintf(fp, "%d", 1);
    printf("File succesfully created\n");

    fclose(fp);

    return 0;
}
