/*
** EPITECH PROJECT, 2017
** my_draw.c
** File description:
**
*/

#include "runner.h"

void draw_text(struct game *game, const sfText *text)
{
	sfRenderWindow_drawText(game->gui->window,
	text,
	NULL);
}

void draw_sprite(struct game *game, const sfSprite *sprite)
{
	sfRenderWindow_drawSprite(game->gui->window,
	sprite,
	NULL);
}

void set_text_position(sfText *text, const int x, const int y)
{
	sfText_setPosition(text,
	get_position(x, y));
}

void set_sprite_position(sfSprite *sprite, const int x, const int y)
{
	sfSprite_setPosition(sprite,
	get_position(x, y));
}