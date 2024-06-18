/*
** EPITECH PROJECT, 2017
** my_window_clock.c
** File description:
**
*/

#include "runner.h"

int manage_scrolling(sfClock *game_clock, struct game *game)
{
	const int interval_scroll = 30000;
	const int scre = 1920;
	int bg_abs = game->gui->bg_abs;
	int floor_abs = game->gui->floor_abs;

	if (sfClock_getElapsedTime(game_clock).microseconds <= interval_scroll)
		return (0);
	sfClock_restart(game_clock);
	game->gui->bg_abs += 1.75;
	game->gui->floor_abs += game->speed;
	set_sprite_position(game->gui->sprites->bg, - bg_abs, 0);
	set_sprite_position(game->gui->sprites->bg2, scre - bg_abs, 0);
	set_sprite_position(game->gui->sprites->floor, - floor_abs, 750);
	set_sprite_position(game->gui->sprites->floor2, scre - floor_abs, 750);
	if (game->gui->bg_abs >= scre)
		game->gui->bg_abs = 0;
	if (game->gui->floor_abs >= scre)
		game->gui->floor_abs = 0;
	manage_obstacles_scrolling(game);
	return (1);
}

void manage_obstacles_scrolling(struct game *game)
{
	int i;

	if (game->options->custom == 1 && game->step == 1 &&
		game->obstacles_len == 0)
		game_won(game);
	for (i = 0; i < game->obstacles_len; i++) {
		game->obstacles[i]->x -= game->speed;
		set_sprite_position(game->obstacles[i]->sprite,
			game->obstacles[i]->x, game->obstacles[i]->y);
	}
	while (game->obstacles_len > 0 && game->obstacles[0]->x <= -77)
		free_first_obstacle(game);
}