#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include "calc.h"


int		usage()
{
		printf("usage: bin_math number1 number2\n");
		return EXIT_FAILURE;
}

int			main(int argc, char **argv)
{
		char	*nb1;
		char	*nb2;
		
		if (argc < 3)
			return usage();
		nb1 = (char*)malloc(sizeof(char) * MAX_LEN);
		nb2 = (char*)malloc(sizeof(char) * MAX_LEN);
    if ((nb1 == NULL) || (nb2 == NULL))
			return EXIT_FAILURE;
		complete(nb1, argv[1]);
		complete(nb2, argv[2]);

		printf("NB1: %s - NB2: %s\n\n", nb1, nb2);
		sum(nb1, nb2);

		free(nb1);
		free(nb2);
    return 0;
}

