/*
** EPITECH PROJECT, 2017
** my_window_mouse_pressed.c
** File description:
**
*/

#include "runner.h"

void mouse_pressed_start(struct game *game, const sfVector2f mouse)
{
	const int size = 256;

	if (window_contain_point(game->gui->sprites->select,
		mouse, size) == 1) {
		list_maps(game);
		game->step = 4;
	}
	if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
		set_sprite_position(game->player->sprite, 170, 674);
		free_all_obstacles(game);
		game->score = 0;
		game->step = 1;
		play_random_music(game);
	}
	if (window_contain_point(game->gui->sprites->leave, mouse, size) == 1)
		window_dispose(game);
	mouse_pressed_start_ext(game, mouse);
}

void mouse_pressed_start_ext(struct game *game, const sfVector2f mouse)
{
	const int au_size = 64;
	const int p_size = 77;

	if (window_contain_point(game->gui->sprites->sound_off, mouse, au_size)
		== 1 || window_contain_point(game->gui->sprites->sound_on,
		mouse, au_size) == 1)
		mute_music(game);
	if (window_contain_point(game->player->sprite, mouse, p_size)) {
		free(game->player->sprite);
		set_next_block(game->player, game);
	}
}

void mouse_pressed_maps(struct game *game, const sfVector2f mouse)
{
	const int au_size = 64;
	const int p_size = 77;
	const int b_size = 72;

	if (window_contain_point(game->gui->sprites->back, mouse, b_size) == 1)
		game->step = 0;
	if (window_contain_point(game->gui->sprites->sound_off, mouse, au_size)
		== 1 || window_contain_point(game->gui->sprites->sound_on,
		mouse, au_size) == 1)
		mute_music(game);
	if (window_contain_point(game->player->sprite, mouse, p_size)) {
		free(game->player->sprite);
		set_next_block(game->player, game);
	}
	for (int i = 0; i < game->maps_len; i++)
		if (window_contain_map(game->gui->texts->maps_fields[i],
			mouse))
			map_selected(game, i);
}

void mouse_pressed_end(struct game *game, const sfVector2f mouse)
{
	const int size = 256;

	game->won = 0;
	if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
		free_all_obstacles(game);
		game->score = 0;
		sfText_setString(game->gui->texts->score, my_itc(game->score));
		game->step = 1;
		play_random_music(game);
		if (game->options->custom == 1)
			parse_map(game);
	}
	if (window_contain_point(game->gui->sprites->menu, mouse, size) == 1) {
		free_all_obstacles(game);
		game->score = 0;
		game->step = 0;
		game->options->custom = 0;
	}
}

void mouse_pressed_break(struct game *game, const sfVector2f mouse)
{
	const int au_size = 64;
	const int b_size = 72;
	const int size = 256;

	if (window_contain_point(game->gui->sprites->sound_off, mouse, au_size)
		== 1 || window_contain_point(game->gui->sprites->sound_on,
		mouse, au_size) == 1)
		mute_music(game);
	if (window_contain_point(game->gui->sprites->back, mouse, b_size) == 1)
		game->step = 1;
	if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
		free_all_obstacles(game);
		game->score = 0;
		sfText_setString(game->gui->texts->score, my_itc(game->score));
		game->step = 1;
		play_random_music(game);
		if (game->options->custom == 1)
			parse_map(game);
	}
	mouse_pressed_break_ext(game, mouse);
}