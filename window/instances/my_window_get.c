/*
** EPITECH PROJECT, 2017
** my_window_get.c
** File description:
**
*/

#include "runner.h"

sfSprite *get_sprite(const char *file_path)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, sfTexture_createFromFile(
		file_path, NULL), sfTrue);
	return (sprite);
}

sfVector2f get_position(const int x, const int y)
{
	sfVector2f vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfIntRect get_rect(const int top, const int left, const int width,
	const int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfText *get_text(sfVector2f pos, const char *value,
	const int size, sfFont *font)
{
	sfText *text = sfText_create();

	sfText_setPosition(text, pos);
	sfText_setString(text, value);
	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfText_setCharacterSize(text, size);
	return (text);
}