/*
** EPITECH PROJECT, 2017
** my_window_player.c
** File description:
**
*/

#include "runner.h"

int manage_player_move(sfClock *game_clock, struct game *game)
{
	const int interval_move = 9000;
	int height_limit = block_below_player(game);

	if (block_on_player(game) == 1)
		game_ended_colision(game);
	if (game->action != NULL && game->player->value == 0 && game->player->y
		< height_limit)
		game->player->value = 2;
	if (game->player->value == 0 && game->action != NULL &&
		game->player->y < game->action->height_limit)
		game->player->value = 2;
	if (sfClock_getElapsedTime(game_clock).microseconds <= interval_move ||
		game->player->value == 0)
		return (0);
	manage_player_jump(game, height_limit);
	return (1);
}

void manage_player_jump(struct game *game, const int height_limit)
{
	const int jump_height = 350;

	manage_progressive_speed(game);
	if (game->player->value == 1)
		game->player->y -= game->action->jump_speed;
	else if (game->player->value == 2) {
		if (game->player->y + game->action->fall_speed > height_limit)
			game->player->y = height_limit;
		else
			game->player->y += game->action->fall_speed;
	}
	if (game->player->value == 2 && game->player->y >= height_limit) {
		game->player->y = height_limit;
		game->player->value = 0;
	}
	if (game->player->y <= game->action->height_limit - jump_height)
		game->player->value = 2;
}

void manage_progressive_speed(struct game *game)
{
	float rotation = sfSprite_getRotation(game->player->sprite);

	if (game->player->value == 1) {
		progressive_speed_jump(game);
		if (rotation != 300 && rotation != 0)
			sfSprite_setRotation(game->player->sprite,
			rotation + 1);
	}
	rotation = sfSprite_getRotation(game->player->sprite);
	if (game->player->value == 2) {
		progressive_speed_fall(game);
		if (rotation > 3 && rotation < 357)
			sfSprite_setRotation(game->player->sprite,
			rotation + 2.5);
		else
			sfSprite_setRotation(game->player->sprite, 0);
		rotation = sfSprite_getRotation(game->player->sprite);
		if (rotation > 3 && rotation < 357 &&
			game->player->y >= block_below_player(game) - 2)
			sfSprite_setRotation(game->player->sprite, 0);
	}
}

int block_below_player(struct game *game)
{
	const int size = 77;
	int i;
	int height_limit = 674;
	struct entity *entity;

	for (i = 0; i < game->obstacles_len; i++) {
		entity = game->obstacles[i];
		if (((entity->x - 1 < game->player->x && game->player->x <
		entity->x + size + 1) || (entity->x - 1 < game->player->x +
		size && game->player->x + size < entity->x + size + 1)) &&
		entity->y - size < height_limit && game->player->y + 77
		<= entity->y && entity->skin == 1)
			height_limit = entity->y - size;
	}
	return (height_limit);
}

int block_on_player(struct game *game)
{
	int i;
	struct entity *entity;

	for (i = 0; i < game->obstacles_len; i++) {
		entity = game->obstacles[i];
		if (game->player->value == 0
			&& entity_colision(game, entity) == 1)
			return (1);
		if (entity->skin == 3 && entity_colision(game, entity) == 1)
			return (1);
	}
	return (0);
}