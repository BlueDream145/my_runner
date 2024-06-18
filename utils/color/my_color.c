/*
** EPITECH PROJECT, 2017
** my_color.c
** File description:
**
*/

#include "runner.h"

sfColor get_color_background(struct game *game)
{
	if (game->gui->color == 1)
		return (sfColor_fromRGB(255, 204, 204));
	if (game->gui->color == 2)
		return (sfColor_fromRGB(204, 204, 255));
	if (game->gui->color == 3)
		return (sfColor_fromRGB(204, 255, 204));
	return (sfColor_fromRGB(255, 204, 204));
}

sfColor get_color_ground(struct game *game)
{
	if (game->gui->color == 1)
		return (sfColor_fromRGB(255, 153, 153));
	if (game->gui->color == 2)
		return (sfColor_fromRGB(153, 153, 255));
	if (game->gui->color == 3)
		return (sfColor_fromRGB(153, 255, 153));
	return (sfColor_fromRGB(255, 153, 153));
}

sfColor get_color_block(void)
{
	return (sfColor_fromRGB(255, 178, 102));
}