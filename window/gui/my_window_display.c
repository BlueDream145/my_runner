/*
** EPITECH PROJECT, 2017
** my_window_display.c
** File description:
**
*/

#include "runner.h"

void display_anim(struct game *game)
{
	draw_sprite(game, game->gui->sprites->bg2);
	draw_sprite(game, game->gui->sprites->bg);
	draw_sprite(game, game->gui->sprites->floor);
	draw_sprite(game, game->gui->sprites->floor2);
}

void display_obstacles(struct game *game)
{
	for (int i = 0; i < game->obstacles_len; i++)
		draw_sprite(game, game->obstacles[i]->sprite);
}

void display_menu(struct game *game)
{
	draw_sprite(game, game->gui->sprites->select);
	draw_sprite(game, game->gui->sprites->play);
	draw_sprite(game, game->gui->sprites->leave);
	draw_text(game, game->gui->texts->title);
	draw_text(game, game->gui->texts->select_field);
	draw_text(game, game->gui->texts->play_field);
	draw_text(game, game->gui->texts->leave_field);
	draw_text(game, game->gui->texts->sound_field);
	draw_text(game, game->gui->texts->choose_field);
	draw_text(game, game->gui->texts->highest);
	draw_text(game, game->gui->texts->highest_field);
	draw_sprite(game, game->player->sprite);
	if (game->options->sound == 1)
		draw_sprite(game, game->gui->sprites->sound_on);
	else
		draw_sprite(game, game->gui->sprites->sound_off);
}

void display_end_menu(struct game *game)
{
	set_sprite_position(game->gui->sprites->play, 500, 420);
	set_sprite_position(game->gui->sprites->menu, 900, 420);
	draw_sprite(game, game->gui->sprites->play);
	draw_sprite(game, game->gui->sprites->menu);
	draw_text(game, game->gui->texts->try_field);
	draw_text(game, game->gui->texts->menu_field);
}

void display_map_menu(struct game *game)
{
	display_anim(game);
	display_obstacles(game);
	set_sprite_position(game->player->sprite, 400, 13);
	set_sprite_position(game->gui->sprites->back, 1415, 13);
	draw_text(game, game->gui->texts->sound_field);
	draw_text(game, game->gui->texts->choose_field);
	draw_text(game, game->gui->texts->back);
	draw_sprite(game, game->gui->sprites->back);
	draw_sprite(game, game->player->sprite);
	if (game->options->sound == 1)
		draw_sprite(game, game->gui->sprites->sound_on);
	else
		draw_sprite(game, game->gui->sprites->sound_off);
	for (int i = 0; i < game->maps_len; i++)
		draw_text(game, game->gui->texts->maps_fields[i]);
}