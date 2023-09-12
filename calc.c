#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h"


void    filling(char *vector, int size)
{
	int     i;

	i = 0;
    while (i < size)
        vector[i++] = '0';
    vector[i] = '\0';
}

char*    sum(char *n1, char *n2)
{
    char    *result;
    int     carry;
    int     bit1;
    int     bit2;
	int		sum;
    int     i;
	
    result = (char*)malloc((MAX_LEN + 1) * sizeof(char));
    if (result == NULL) 
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    filling(result, (MAX_LEN + 1));
    carry = 0;
    i = MAX_LEN;
    while (i > 0)
    {
        bit1 = n1[i - 1] - 48;
        bit2 = n2[i - 1] - 48;
		sum = bit1 + bit2 + carry;
        result[i] = (char)((sum % 2) + 48);		
        carry = sum / 2;
			i--;
    }
		i++;
    if (carry == 1)
		result[i] = '1';
    return (result);
}

void    two_complement(char *n)
{
    int     i;

    i = 0;
    while(n[i] != '\0')
    {
        if (n[i] == '0')
            n[i] = '1';
        else 
            n[i] = '0';
        i++;
    }
    sum(n, "00000001");
}

void    complete(char *end, char *start)
{
    int	    i;
    int     len_start;

    i = 0;
    len_start = strlen(start);

    while (i < (MAX_LEN - len_start))
        end[i++] = '0';
    strcat(end, start);
    end[MAX_LEN+1] = '\0';
}

