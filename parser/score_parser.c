/*
** EPITECH PROJECT, 2017
** score_parser.c
** File description:
**
*/

#include "runner.h"

void save_score(struct game *game)
{
	const char *path = "config.txt";
	FILE *file = fopen(path, "w");
	char *highest = my_itc(game->highest);
	int len = my_strlen(highest) + 2;
	char *result = malloc(sizeof(char) * len);

	if (result == NULL)
		report_error(error_malloc);
	result[0] = (my_strlen(highest) + '0');
	for (int i = 0; i < my_strlen(highest); i++)
		result[i + 1] = highest[i];
	result[my_strlen(highest) + 1] = '\0';
	fwrite(result, sizeof(char), len, file);
	fclose(file);
	free(highest);
}

void read_score(struct game *game)
{
	const char *path = "config.txt";
	const int chunk = 4;
	char buf[chunk];
	FILE *file;
	size_t nread;

	file = fopen(path, "r");
	if (file) {
		while ((nread = fread(buf, 1, sizeof buf, file)) > 0);
		if (ferror(file))
			return;
		if (!(buf[0] >= '0' && buf[0] <= '9'))
			return;
		append_score(game, buf, file);
	}
}

void append_score(struct game *game, const char *buf, FILE *file)
{
	char *result;
	int len;

	len = (buf[0] - '0') + 1;
	result = malloc(sizeof(char) * len);
	if (result == NULL)
		report_error(error_malloc);
	for (int i = 0; i < len; i++)
		result[i] = buf[i + 1];
	result[len - 1] = '\0';
	game->highest = my_atoi(result);
	sfText_setString(game->gui->texts->highest_field, result);
	fclose(file);
}