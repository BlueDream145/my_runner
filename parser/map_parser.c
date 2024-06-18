/*
** EPITECH PROJECT, 2017
** map_parser.c
** File description:
**
*/

#include "runner.h"

void list_maps(struct game *game)
{
	const int max_maps = 99;
	const char *map_directory = "./maps";
	DIR *rep = opendir(map_directory);
	struct dirent *reader;
	int i = 0;

	game->gui->texts->maps_fields = malloc(sizeof(sfText *) * max_maps);
	game->maps_len = 0;
	if (game->gui->texts->maps_fields == NULL)
		report_error(error_malloc);
	while ((reader = readdir(rep))) {
		if (reader->d_name[0] == '.')
			continue;
		game->gui->texts->maps_fields[game->maps_len] =
			get_text(get_position(300, 180 + (70 * i)),
			reader->d_name, 40, game->gui->pixel_font);
		game->maps_len++;
		i++;
	}
	closedir(rep);
}

void parse_map(struct game *game)
{
	const int cell_size = 77;
	FILE *fp = fopen(game->options->custom_path, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int y = -19;

	if (fp == NULL)
		report_error(error_file);
	while ((read = getline(&line, &len, fp)) != -1) {
		parse_line(game, line, read, y);
		y += cell_size;
	}
	if (line)
		free(line);
	fclose(fp);
}

void parse_line(struct game *game, const char *line, const int len,
	const int y)
{
	const int cell_size = 77;
	int x = 0;
	struct entity *entity;

	if (len <= 1)
		return;
	for (int i = 0; i < len; i++)
	{
		check_char(game, line[i]);
		if (line[i] == '2' || line[i] == '3' || line[i] == '4') {
			entity = get_entity(game->obstacles_len, x, y, 0);
			entity->skin = (line[i] - 1) - '0';
			get_random_entity(entity, game);
		}
		x += cell_size;
	}
}

void check_char(struct game *game, const char c)
{
	const char *allowed_chars = "1234\n ";
	const int allowed_len = 6;
	int i;

	for (i = 0; i < allowed_len; i++)
		if (allowed_chars[i] == c)
			return;
	stop_music(game);
	report_error(error_syntax_char);
}

int window_contain_map(const sfText *text, const sfVector2f pos)
{
	const int height_size = 80;
	const int width_size = 600;
	sfVector2f text_pos = sfText_getPosition(text);

	if (pos.x >= text_pos.x && pos.x <= text_pos.x + width_size &&
		pos.y >= text_pos.y && pos.y <= text_pos.y + height_size)
		return (1);
	else
		return (0);
}