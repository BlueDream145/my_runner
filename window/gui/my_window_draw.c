/*
** EPITECH PROJECT, 2017
** my_window_draw.c
** File description:
**
*/

#include "runner.h"

void window_draw(struct game *game)
{
	sfRenderWindow_clear(game->gui->window, sfBlack);
	if (game->step == 0)
		window_draw_start(game);
	if (game->step == 1)
		window_draw_game(game);
	if (game->step == 2)
		window_draw_end(game);
	if (game->step == 3)
		window_draw_break(game);
	if (game->step == 4)
		display_map_menu(game);
	sfRenderWindow_display(game->gui->window);
}

void window_draw_start(struct game *game)
{
	set_sprite_position(game->gui->sprites->play, 650, 350);
	set_sprite_position(game->player->sprite, 400, 13);
	set_sprite_position(game->gui->sprites->select, 300, 350);
	set_sprite_position(game->gui->sprites->leave, 1000, 350);
	display_anim(game);
	display_obstacles(game);
	display_menu(game);
}

void window_draw_game(struct game *game)
{
	set_sprite_position(game->player->sprite,
		game->player->x, game->player->y);
	display_anim(game);
	display_obstacles(game);
	draw_sprite(game, game->player->sprite);
	draw_text(game, game->gui->texts->score_field);
	draw_text(game, game->gui->texts->score);
}

void window_draw_break(struct game *game)
{
	set_sprite_position(game->gui->sprites->back, 1415, 13);
	display_anim(game);
	display_obstacles(game);
	draw_sprite(game, game->player->sprite);
	draw_sprite(game, game->gui->sprites->back);
	draw_text(game, game->gui->texts->back);
	draw_text(game, game->gui->texts->sound_field);
	draw_text(game, game->gui->texts->score_field);
	draw_text(game, game->gui->texts->score);
	if (game->options->sound == 1)
		draw_sprite(game, game->gui->sprites->sound_on);
	else
		draw_sprite(game, game->gui->sprites->sound_off);
}

void window_draw_end(struct game *game)
{
	display_anim(game);
	draw_sprite(game, game->player->sprite);
	draw_text(game, game->gui->texts->title);
	draw_text(game, game->gui->texts->game_over);
	draw_text(game, game->gui->texts->score_field);
	draw_text(game, game->gui->texts->score);
	if (game->options->custom == 0) {
		draw_text(game, game->gui->texts->highest);
		draw_text(game, game->gui->texts->highest_field);
	}
	display_obstacles(game);
	display_end_menu(game);
}