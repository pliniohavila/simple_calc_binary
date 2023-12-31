#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


int		usage()
{
    printf("usage: bin_math number1 number2\n");
    return EXIT_FAILURE;
}

int			main(int argc, char **argv)
{
    char	nb1[MAX_LEN + 1];
    char	nb2[MAX_LEN + 1];
    char    *sum_result;
    char    *sub_result;
    
    if (argc < 3)
        return usage();

    complete(nb1, argv[1]);
    complete(nb2, argv[2]);

    printf("NB1: %s\n", nb1);
    printf("NB2: %s\n\n", nb2);
    
    sum_result = sum(nb1, nb2);
    sub_result = sub(nb1, nb2);
    
    printf("SUM: %s\n", sum_result);
    printf("SUB: %s\n", sub_result);

    free(sum_result);
    free(sub_result);

    return (0);
}

