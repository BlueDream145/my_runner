/*
** EPITECH PROJECT, 2017
** my_window_game.c
** File description:
**
*/

#include "runner.h"

void game_ended_colision(struct game *game)
{
	stop_music(game);
	if (game->options->custom == 0 && game->score > game->highest) {
		game->highest = game->score;
		save_score(game);
		sfText_setString(game->gui->texts->highest_field,
			my_itc(game->highest));
	}
	game->step = 2;
	sfText_setString(game->gui->texts->game_over,
		get_random_sentence(game->won));
}

void game_won(struct game *game)
{
	stop_music(game);
	game->won = 1;
	sfText_setString(game->gui->texts->game_over,
		get_random_sentence(game->won));
	game->step = 2;
}