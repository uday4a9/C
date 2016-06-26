#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rev(char *str)
{
    char *end, *start, tmp;
    start = str;

    end = str + strlen(str)-1;
    while(str < end) {
        tmp = *str;
        *str = *end;
        *end = tmp;
        str++;
        end--;
    }

    return start;
}

char *join(char **argv, char *space)
{
    int i;
    char *new;

    new = (char*)calloc(1, strlen(argv[0]) + 1);
    if(new == NULL) {
        printf("malloc failed stop the program");
        exit(1);
    }
    strcat(new, argv[0]);

    for(i=1; argv[i]; i++) {
        // one char for joinable char and one more char for
        // '\0'
        new = realloc(new, strlen(argv[1] + 2));
        if(new == NULL) {
            printf("malloc failed stop the program");
            exit(1);
        }
        strcat(new, space); 
        strcat(new, argv[i]);
    }

    return new;
}

int main()
{
    char str[] = "Hello world ho,w are you?";
    char *sp, *res[127]={NULL}, *tmp;
    int i = 0, alt=0;

    puts(str);
    sp = strtok(str," ");
    while(sp){
        //res[i++] = sp;
        //puts(sp);
        if(!alt) {
            sp = rev(sp);
            alt = 1;
        }
        else
            alt = 0;
        //puts(sp);
        res[i++] = sp;
        sp = strtok(NULL, " ");
    }

#if 0
    for(i=0; res[i]; i++)
        puts(res[i]);
#endif

    puts(join(res, " "));
    return 0;
}
