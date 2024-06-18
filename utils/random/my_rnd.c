/*
** EPITECH PROJECT, 2017
** my_rnd.c
** File description:
**
*/

#include "runner.h"

int crand(int a, int b)
{
	return (rand() % (b - a) + a);
}

char *get_random_sentence(const int won)
{
	char *sentence_1 = "Game over\n      I'm sure you can't";
	char *sentence_2 = "Game over\n      You shall not pass";
	char *sentence_3 = "Game over\n      Probably, you are noob";
	char *sentence_win = "You won\n      You are really good";
	int rnd = crand(1, 4);

	if (won)
		return (sentence_win);
	if (rnd == 1)
		return (sentence_1);
	if (rnd == 2)
		return (sentence_2);
	if (rnd == 3)
		return (sentence_3);
	return (sentence_1);
}

void get_random_entity(struct entity *entity, struct game *game)
{
	char path[30] = "resources/obstacles/obs_1.png";
	char path_e[27] = "resources/enemy/enemy_1.png";

	if (entity->skin == 3) {
		path_e[22] = crand(1, 4) + '0';
		entity->sprite = get_sprite(path_e);
	}
	else {
		path[24] = entity->skin + '0';
		entity->sprite = get_sprite(path);
	}
	sfSprite_setPosition(entity->sprite, get_position(entity->x,
	entity->y));
	if (entity->skin == 2)
		sfSprite_setColor(entity->sprite,
	get_color_background(game));
	game->obstacles[game->obstacles_len] = entity;
	game->obstacles_len++;
}

void set_next_block(struct entity *entity, struct game *game)
{
	char block_path[28] = "resources/block/block_6.png";

	if (entity->skin == 6)
		entity->skin = 1;
	else
		entity->skin++;
	block_path[22] = game->player->skin + '0';
	game->player->sprite = get_sprite(block_path);
	sfSprite_setColor(game->player->sprite, get_color_block());
}