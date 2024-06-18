/*
** EPITECH PROJECT, 2017
** my_window_components.c
** File description:
**
*/

#include "runner.h"

void window_load_components(struct game *game)
{
	game->gui->color = crand(1, 4);
	window_load_sprites(game);
	window_load_fonts(game);
	window_load_texts(game);
	window_load_extented_texts(game);
}

void window_load_sprites(struct game *game)
{
	resources_load_bg(game);
	resources_load_blocks(game);
	resources_load_floors(game);
	ressources_load_gui(game);
}

void window_load_texts(struct game *game)
{
	game->gui->texts->title = get_text(get_position(275, 140),
		"My Amazing Runner", 80, game->gui->pixel_font);
	game->gui->texts->select_field = get_text(get_position(290, 620),
		"Select map", 40, game->gui->pixel_font);
	game->gui->texts->play_field = get_text(get_position(680, 620),
		"Infinity", 40, game->gui->pixel_font);
	game->gui->texts->leave_field = get_text(get_position(1040, 620),
		"Leave", 40, game->gui->pixel_font);
	game->gui->texts->try_field = get_text(get_position(485, 720),
		"Try again", 40, game->gui->pixel_font);
	game->gui->texts->menu_field = get_text(get_position(980, 720),
		"Menu", 40, game->gui->pixel_font);
	game->gui->texts->score_field = get_text(get_position(10, 0),
		"Score", 30, game->gui->pixel_font);
	game->gui->texts->score = get_text(get_position(165, 0),
		"0", 30, game->gui->pixel_font);
	game->gui->texts->game_over = get_text(get_position(350, 300),
		get_random_sentence(game->won), 45, game->gui->pixel_font);
}

void window_load_extented_texts(struct game *game)
{
	game->gui->texts->sound_field = get_text(get_position(95, 775),
		"Sound", 40, game->gui->pixel_font);
	game->gui->texts->choose_field = get_text(get_position(17, 25),
		"Select a skin", 40, game->gui->pixel_font);
	game->gui->texts->back = get_text(get_position(1400, 80),
		"Back", 40, game->gui->pixel_font);
	game->gui->texts->highest = get_text(get_position(1000, 25),
		"Highest score", 40, game->gui->pixel_font);
	game->gui->texts->highest_field = get_text(get_position(1425, 25),
		"0", 40, game->gui->pixel_font);
}

void window_load_fonts(struct game *game)
{
	resources_load_fonts(game);
}