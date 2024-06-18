/*
** EPITECH PROJECT, 2017
** my_str.c
** File description:
**
*/

#include "runner.h"

void my_put_char(char c)
{
	write (1, &c, 1);
}

int my_put_str(const char *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char(str[length]);
		length++;
	}
	return (0);
}

int my_strlen(const char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++);
	return (i);
}

char *my_strcpy(char *dest, const char *src)
{
	char *result = dest;

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (result);
}

char *my_strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	while (n > 0 && src[i] != '\0') {
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n > 0)
		dest[i++] = '\0';
	return (dest);
}