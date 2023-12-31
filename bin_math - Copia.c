#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 8

void    sum(char *n1, char *n2)
{
    char    *result;
    int     carry;
    int     bit1, bit2;
		int			sum;
    int     i;
		
		result = (char*)malloc(sizeof(char) * MAX_LEN);
		if (result == NULL)
			return;
		carry = 0;
    i = MAX_LEN;
	  while (i > 0)
    {
        bit1 = n1[i - 1] - 48;
        bit2 = n2[i - 1] - 48;
				sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + 48;
        carry = sum / 2;
			  i--;
    }
		i++;
    if (carry == 1)
				result[i] = '1';
    printf("Result (SUM): %s\n", result);
		free(result);
		return;
}

int		usage()
{
		printf("usage: bin_math [+|-|*] number1 number2\n");
		return EXIT_FAILURE;
}

void    complete(char *end, char *start)
{
    int		i;
    int   len_start;

    i = 0;
    len_start = strlen(start);
    while (i < (MAX_LEN - len_start))
        end[i++] = '0';
    strcat(end, start);
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

