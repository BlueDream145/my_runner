/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "runner.h"

struct game *get_game_instance(const int width, const int height, char *name)
{
	const int obs_len = 500;
	struct game *game = malloc(sizeof(struct game));

	if (game == NULL)
		report_error(error_malloc);
	game->obstacles = malloc(sizeof(struct entity) * obs_len);
	if (game->obstacles == NULL)
		report_error(error_malloc);
	game->gui = get_gui_instance(width, height, name);
	game->options = get_options();
	game->won = 0;
	game->score = 0;
	game->step = 0;
	game->highest = 0;
	return (game);
}

struct gui *get_gui_instance(const int width, const int height, char *name)
{
	struct gui *gui = malloc(sizeof(struct gui));
	sfVideoMode mode = { width, height, 32 };

	if (gui == NULL)
		report_error(error_malloc);
	gui->window = sfRenderWindow_create(mode, name, sfTitlebar |
		sfClose, NULL);
	gui->sprites = malloc(sizeof(struct gui_sprites));
	gui->texts = malloc(sizeof(struct gui_texts));
	if (gui->sprites == NULL || gui->texts == NULL)
		report_error(error_malloc);
	gui->width = width;
	gui->height = height;
	gui->name = name;
	return (gui);
}

struct entity *get_entity(const int id, const int x, const int y,
	const int value)
{
	struct entity *entity = malloc(sizeof(struct entity));

	if (entity == NULL)
		report_error(error_malloc);
	entity->id = id;
	entity->x = x;
	entity->y = y;
	entity->value = value;
	return (entity);
}

struct action *get_action(const int height_limit)
{
	struct action *action = malloc(sizeof(struct action));

	if (action == NULL)
		report_error(error_malloc);
	action->height_limit = height_limit;
	action->jump_speed = 10;
	action->fall_speed = 2;
	action->rotate = 0;
	return (action);
}

struct options *get_options(void)
{
	struct options *options = malloc(sizeof(struct options));

	if (options == NULL)
		report_error(error_malloc);
	options->sound = 1;
	options->custom = 0;
	return (options);
}