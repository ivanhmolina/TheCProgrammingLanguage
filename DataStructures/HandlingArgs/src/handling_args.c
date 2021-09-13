#include <stdio.h>
#include "handling_args.h"

void print_args(int argc, char **argv)
{
    unsigned short int i;
    for(i = 1; --argc > 0; i++)
    {
        printf("argv%d: %s\n", i, *(argv+i));
    }
    
}

int main(int argc, char *argv[])
{
    printf("argc : %d\n", argc);
    print_args(argc, argv);
}