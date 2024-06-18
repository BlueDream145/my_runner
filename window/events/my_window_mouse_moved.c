/*
** EPITECH PROJECT, 2017
** my_window_mouse_moved.c
** File description:
**
*/

#include "runner.h"

void mouse_moved_start(struct game *game, const sfVector2f mouse)
{
	const int size = 256;

	if (window_contain_point(game->gui->sprites->play, mouse, size) == 1)
		sfText_setStyle(game->gui->texts->play_field, sfTextBold);
	else
		sfText_setStyle(game->gui->texts->play_field, sfTextRegular);
	if (window_contain_point(game->gui->sprites->leave, mouse, size) == 1)
		sfText_setStyle(game->gui->texts->leave_field, sfTextBold);
	else
		sfText_setStyle(game->gui->texts->leave_field, sfTextRegular);
	if (window_contain_point(game->gui->sprites->select, mouse, size) == 1)
		sfText_setStyle(game->gui->texts->select_field, sfTextBold);
	else
		sfText_setStyle(game->gui->texts->select_field, sfTextRegular);
}

void mouse_moved_end(struct game *game, const sfVector2f mouse)
{
	const int size = 256;

	if (window_contain_point(game->gui->sprites->play, mouse, size) == 1)
		sfText_setStyle(game->gui->texts->try_field, sfTextBold);
	else
		sfText_setStyle(game->gui->texts->try_field, sfTextRegular);
	if (window_contain_point(game->gui->sprites->menu, mouse, size) == 1)
		sfText_setStyle(game->gui->texts->menu_field, sfTextBold);
	else
		sfText_setStyle(game->gui->texts->menu_field, sfTextRegular);
}

void mouse_pressed_break_ext(struct game *game, const sfVector2f mouse)
{
	const int size = 256;

	if (window_contain_point(game->gui->sprites->menu, mouse, size) == 1) {
		free_all_obstacles(game);
		game->score = 0;
		game->step = 0;
		game->options->custom = 0;
	}
}