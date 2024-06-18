/*
** EPITECH PROJECT, 2017
** my_window_dispose.c
** File description:
**
*/

#include "runner.h"

void dispose_gui(struct game *game)
{
	dispose_sprites(game);
	dispose_texts(game);
	sfFont_destroy(game->gui->pixel_font);
	sfRenderWindow_destroy(game->gui->window);
}

void dispose_sprites(struct game *game)
{
	sfSprite_destroy(game->gui->sprites->bg);
	sfSprite_destroy(game->gui->sprites->bg2);
	sfSprite_destroy(game->gui->sprites->floor);
	sfSprite_destroy(game->gui->sprites->floor2);
	sfSprite_destroy(game->gui->sprites->play);
	sfSprite_destroy(game->gui->sprites->leave);
	sfSprite_destroy(game->gui->sprites->select);
	sfSprite_destroy(game->gui->sprites->menu);
	sfSprite_destroy(game->gui->sprites->sound_on);
	sfSprite_destroy(game->gui->sprites->sound_off);
	sfSprite_destroy(game->gui->sprites->back);
}

void dispose_texts(struct game *game)
{
	sfText_destroy(game->gui->texts->title);
	sfText_destroy(game->gui->texts->play_field);
	sfText_destroy(game->gui->texts->select_field);
	sfText_destroy(game->gui->texts->leave_field);
	sfText_destroy(game->gui->texts->score_field);
	sfText_destroy(game->gui->texts->try_field);
	sfText_destroy(game->gui->texts->menu_field);
	sfText_destroy(game->gui->texts->game_over);
	sfText_destroy(game->gui->texts->score);
	sfText_destroy(game->gui->texts->back);
	sfText_destroy(game->gui->texts->highest);
	sfText_destroy(game->gui->texts->highest_field);
	free(game->gui->texts->maps_fields);
}