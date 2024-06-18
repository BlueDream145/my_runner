/*
** EPITECH PROJECT, 2017
** my_window.c
** File description:
**
*/

#include "runner.h"

void window_run(struct game *game)
{
	sfEvent event;
	sfClock *game_clock = sfClock_create();
	sfClock *obs_clock = sfClock_create();

	game->player = get_entity(1, 170, 674, 0);
	game->player->skin = crand(1, 7);
	window_load_components(game);
	read_score(game);
	while (sfRenderWindow_isOpen(game->gui->window)) {
		while (sfRenderWindow_pollEvent(game->gui->window, &event))
			window_events(event, game);
		if (game->step == 0 || game->step == 4)
			window_run_start(game_clock, obs_clock, game);
		else if (game->step == 1)
			window_run_game(game_clock, obs_clock, game);
		else
			window_draw(game);
	}
}

void window_run_start(sfClock *game_clock, sfClock *obs_clock,
struct game *game)
{
	game->speed = 4;
	if (manage_scrolling(game_clock, game) == 1 ||
	spawn_obstacles(obs_clock, game) == 1)
		window_draw(game);
}

void window_run_game(sfClock *game_clock, sfClock *obs_clock,
struct game *game)
{
	game->speed = 19;
	if (manage_scrolling(game_clock, game) == 1 ||
	manage_player_move(game_clock, game) == 1 ||
	spawn_obstacles(obs_clock, game) == 1)
		window_draw(game);
}

void window_dispose(struct game *game)
{
	sfRenderWindow_close(game->gui->window);
	if (game->step == 1 || game->step == 3)
		stop_music(game);
	sfSprite_destroy(game->player->sprite);
	free(game->player);
	free_all_obstacles(game);
	free(game->obstacles);
	dispose_gui(game);
	free(game->gui);
	free(game->action);
	free(game->options);
	free(game);
	exit(0);
}