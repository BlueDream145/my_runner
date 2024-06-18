/*
** EPITECH PROJECT, 2017
** my_window_obstacles.c
** File description:
**
*/

#include "runner.h"

int spawn_obstacles(sfClock *obs_clock, struct game *game)
{
	const int bg_interval_start = 5000000;
	const int bg_interval_game = 3000000;

	if ((game->step == 0 || game->step == 4) &&
	sfClock_getElapsedTime(obs_clock).microseconds <= bg_interval_start)
		return (0);
	if (game->step == 1 &&
	sfClock_getElapsedTime(obs_clock).microseconds <= bg_interval_game)
		return (0);
	sfClock_restart(obs_clock);
	spawn_random_obstacle(game);
	if (game->step == 1)
		game->score++;
	return (1);
}

void spawn_random_obstacle(struct game *game)
{
	const int block_size = 77;
	const int enemy_height = 366;
	int start_abs = 1600;
	int i;
	int len = crand(1, game->score + 2);
	int block = 0;

	if (game->options->custom == 1)
		return;
	if (crand(0, 7) == 1)
		spawn_random_enemy(game, enemy_height - block_size);
	for (i = 0; i < len; i++) {
		block = randomize_obs(game, block, start_abs);
		start_abs += block_size;
		block = 0;
	}
}

int randomize_obs(struct game *game, int block, const int start_abs)
{
	const int block_size = 77;
	const int true = 1;
	int last = 0;
	struct entity *entity;
	int height = 674 - (crand(0, 3) * block_size);

	while (height != 751) {
		entity = get_entity(game->obstacles_len, start_abs, height, 0);
		if (last != true && block == 0)
			entity->skin = crand(1, 3);
		else
			entity->skin = true;
		if (entity->skin == 2)
			block = true;
		else
			last = true;
		get_random_entity(entity, game);
		height += block_size;
	}
	return (block);
}

void free_all_obstacles(struct game *game)
{
	while (game->obstacles_len != 0)
		free_first_obstacle(game);
}

void free_first_obstacle(struct game *game)
{
	int i = 0;

	free(game->obstacles[0]->sprite);
	free(game->obstacles[0]);
	for (i = 0; i < game->obstacles_len; i++)
		if (i > 0)
			game->obstacles[i - 1] = game->obstacles[i];
	game->obstacles_len--;
	sfText_setString(game->gui->texts->score, my_itc(game->score));
}