/*
** EPITECH PROJECT, 2017
** my_report.c
** File description:
**
*/

#include "runner.h"

void report_error(const char *str)
{
	int len = 0;

	for (len = 0; str[len]; len++);
	write(2, str, len);
	exit(84);
}

void report_bad_usage(void)
{
	report_error(error_usage);
}

void report_bad_syntax(void)
{
	report_error(error_syntax);
}