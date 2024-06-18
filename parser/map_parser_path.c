/*
** EPITECH PROJECT, 2017
** map_parser_path.c
** File description:
**
*/

#include "runner.h"

char *prepare_path(const char *file, const char *directory)
{
	int len = (my_strlen(file) + my_strlen(directory) + 2);
	char *full_path = malloc(sizeof(char) * len);

	if (full_path == NULL)
		report_error(error_malloc);
	my_strcpy(full_path, directory);
	my_strcat(full_path, "/");
	my_strcat(full_path, file);
	return (full_path);
}

void map_selected(struct game *game, const int i)
{
	game->options->custom_path = prepare_path((char *)
	sfText_getString(game->gui->texts->maps_fields[i]), "./maps");
	game->options->custom = 1;
	run(game);
	parse_map(game);
}

char *my_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest) {
		dest++;
	}
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (result);
}