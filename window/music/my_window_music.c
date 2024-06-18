/*
** EPITECH PROJECT, 2017
** my_window_music.c
** File description:
**
*/

#include "runner.h"

void play_random_music(struct game *game)
{
	char music_path[28] = "resources/music/music_1.flac";

	if (game->options->sound == 0)
		return;
	music_path[22] = crand(1, 10) + '0';
	game->music = sfMusic_createFromFile(music_path);
	sfMusic_play(game->music);
}

void mute_music(struct game *game)
{
	if (game->options->sound == 1)
		game->options->sound = 0;
	else
		game->options->sound = 1;
}

void play_music(struct game *game)
{
	if (game->music == NULL) {
		play_random_music(game);
		return;
	}
	if (game->options->sound == 0)
		return;
	sfMusic_play(game->music);
}

void pause_music(struct game *game)
{
	if (game->music == NULL || game->options->sound == 0)
		return;
	sfMusic_pause(game->music);
}

void stop_music(struct game *game)
{
	if (game->music == NULL)
		return;
	if (game->options->sound != 0)
		sfMusic_stop(game->music);
	sfMusic_destroy(game->music);
}