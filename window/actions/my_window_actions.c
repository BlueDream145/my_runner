/*
** EPITECH PROJECT, 2017
** my_window_actions.c
** File description:
**
*/

#include "runner.h"

void progressive_speed_jump(struct game *game)
{
	if (game->player->y <= game->action->height_limit - 50)
		game->action->jump_speed = 8;
	if (game->player->y <= game->action->height_limit - 100)
			game->action->jump_speed = 7;
	if (game->player->y <= game->action->height_limit - 150)
		game->action->jump_speed = 6;
	if (game->player->y <= game->action->height_limit - 200)
		game->action->jump_speed = 4;
	if (game->player->y <= game->action->height_limit - 250)
		game->action->jump_speed = 3;
	if (game->player->y <= game->action->height_limit - 299)
		game->action->jump_speed = 2;
}

void progressive_speed_fall(struct game *game)
{
	if (game->player->y <= game->action->height_limit - 50)
		game->action->jump_speed = 6;
	if (game->player->y <= game->action->height_limit - 100)
		game->action->jump_speed = 7;
	if (game->player->y <= game->action->height_limit - 150)
		game->action->jump_speed = 8;
	if (game->player->y <= game->action->height_limit - 200)
		game->action->jump_speed = 9;
	if (game->player->y <= game->action->height_limit - 250)
		game->action->jump_speed = 10;
}