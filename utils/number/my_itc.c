/*
** EPITECH PROJECT, 2017
** my_itc.c
** File description:
**
*/

#include "runner.h"

char *my_itc(int nbr)
{
	int len = number_digits(nbr);
	char *result;

	result = malloc(sizeof(char) * len);
	if (result == NULL)
		report_error(error_malloc);
	result[len] = '\0';
	while (len--) {
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int my_atoi(char *str)
{
	int val = 0;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			val *= 10;
			val += *str - '0';
		}
		else
			return (val);
		str++;
	}
	return (val);
}

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}