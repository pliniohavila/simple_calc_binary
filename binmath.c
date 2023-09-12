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
    
    if (argc < 3)
        return usage();
    complete(nb1, argv[1]);
    
    complete(nb2, argv[2]);
    printf("NB1: %s \n", nb1);
    printf("NB1: %s - NB2: %s\n\n", nb1, nb2);
    sum_result = sum(nb1, nb2);
    // printf("SUM: %s\n", sum_result);
    // two_complement(nb2);
    // printf(nb2);

    free(sum_result);
    // free(nb2);
    return (0);
}

