/*
** EPITECH PROJECT, 2017
** my_window_events.c
** File description:
**
*/

#include "runner.h"

void window_events(sfEvent event, struct game *game)
{
	if (event.type == sfEvtClosed)
		window_dispose(game);
	if (event.type == sfEvtKeyPressed)
		window_key_pressed(event, game);
	if (event.type == sfEvtMouseButtonPressed)
		window_mouse_pressed(event, game);
	if (event.type == sfEvtMouseMoved)
		window_mouse_moved(event, game);
}

void window_key_pressed(sfEvent event, struct game *game)
{
	float rotation = sfSprite_getRotation(game->player->sprite);

	if (event.key.code == sfKeySpace && game->player->value == 0 &&
		game->step == 1) {
		game->player->value = 1;
		game->action = get_action(block_below_player(game));
		sfSprite_setRotation(game->player->sprite, rotation + 1);
	}
	if (event.key.code == sfKeyEscape && game->step == 1) {
		pause_music(game);
		game->step = 3;
	}
	else if (event.key.code == sfKeyEscape && game->step == 3) {
		play_music(game);
		game->step = 1;
	}
}

void window_mouse_pressed(sfEvent event, struct game *game)
{
	sfVector2f mouse = get_position(
		event.mouseButton.x, event.mouseButton.y);

	if (game->step == 0)
		mouse_pressed_start(game, mouse);
	if (game->step == 2)
		mouse_pressed_end(game, mouse);
	if (game->step == 3)
		mouse_pressed_break(game, mouse);
	if (game->step == 4)
		mouse_pressed_maps(game, mouse);
}

void window_mouse_moved(sfEvent event, struct game *game)
{
	sfVector2f mouse = get_position(event.mouseMove.x, event.mouseMove.y);

	if (game->step == 0)
		mouse_moved_start(game, mouse);
	if (game->step == 2)
		mouse_moved_end(game, mouse);
}

int window_contain_point(sfSprite *sprite, const sfVector2f pos,
	const int size)
{
	sfVector2f sprite_pos = sfSprite_getPosition(sprite);

	if (pos.x >= sprite_pos.x && pos.x <= sprite_pos.x + size &&
		pos.y >= sprite_pos.y && pos.y <= sprite_pos.y + size)
		return (1);
	else
		return (0);
}