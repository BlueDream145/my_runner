/*
** EPITECH PROJECT, 2017
** my_window_resources.c
** File description:
**
*/

#include "runner.h"

void resources_load_bg(struct game *game)
{
	char bg_path[22] = "resources/bg/bg_1.png";
	char ext_bg_path[22] = "resources/bg/bg_10.png";

	if (crand(0, 2) == 1) {
		bg_path[16] = crand(1, 9) + '0';
		game->gui->sprites->bg = get_sprite(bg_path);
		game->gui->sprites->bg2 = get_sprite(bg_path);
	} else {
		ext_bg_path[17] = crand(0, 7) + '0';
		game->gui->sprites->bg = get_sprite(ext_bg_path);
		game->gui->sprites->bg2 = get_sprite(ext_bg_path);
	}
	sfSprite_setColor(game->gui->sprites->bg, get_color_background(game));
	sfSprite_setColor(game->gui->sprites->bg2, get_color_background(game));
}

void resources_load_blocks(struct game *game)
{
	char block_path[28] = "resources/block/block_6.png";

	block_path[22] = game->player->skin + '0';
	game->player->sprite = get_sprite(block_path);
	sfSprite_setColor(game->player->sprite, get_color_block());
	sfSprite_setPosition(game->player->sprite, get_position(game->player->x
	, game->player->y));
}

void resources_load_floors(struct game *game)
{
	char floor_path[28] = "resources/floor/floor_1.png";

	floor_path[22] = crand(1, 8) + '0';
	game->gui->sprites->floor = get_sprite(floor_path);
	game->gui->sprites->floor2 = get_sprite(floor_path);
	sfSprite_setColor(game->gui->sprites->floor, get_color_ground(game));
	sfSprite_setColor(game->gui->sprites->floor2, get_color_ground(game));
}

void ressources_load_gui(struct game *game)
{
	game->gui->sprites->sound_on = get_sprite(on_path);
	game->gui->sprites->sound_off = get_sprite(off_path);
	game->gui->sprites->select = get_sprite(select_path);
	game->gui->sprites->play = get_sprite(play_path);
	game->gui->sprites->leave = get_sprite(leave_path);
	game->gui->sprites->menu = get_sprite(home_path);
	game->gui->sprites->back = get_sprite(back_path);
	set_sprite_position(game->gui->sprites->sound_on, 10, 770);
	set_sprite_position(game->gui->sprites->sound_off, 10, 770);
}

void resources_load_fonts(struct game *game)
{
	game->gui->pixel_font = sfFont_createFromFile(
		font_path);
}