/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "runner.h"

int main(int ac, char **as)
{
	const int screen_width = 1536;
	const int screen_height = 865;
	char *app_name = "My Amazing Runner";
	struct game *game = get_game_instance(screen_width, screen_height,
	app_name);

	check(game, ac, as);
	window_run(game);
	window_dispose(game);
	return (0);
}

int check(struct game *game, const int ac, char **as)
{
	if (ac != 1 && ac != 2)
		report_error(error_usage);
	if (ac == 2) {
		if (as[1][0] == 'h' || as[1][1] == 'h')
			get_help();
		if (as[1][0] == 'i' || as[1][1] == 'i')
			run(game);
		if (game->step != 1) {
			game->options->custom_path = as[1];
			game->options->custom = 1;
			run(game);
			parse_map(game);
		}
	}
	return (0);
}

void run(struct game *game)
{
	free_all_obstacles(game);
	game->score = 0;
	game->step = 1;
	play_random_music(game);
}

void get_help(void)
{
	const char *header = "Finite runner created with CSFML.\n\n";
	const char *usage = "USAGE\n  ./my_runner map.txt  use a custom map\n"
	"  ./my_runner          display main menu\n\n\n";
	const char *options = "OPTIONS\n"
	"  -i       launch the game in infinity mode.\n"
	"  -h       print the usage and quit.\n\n\n";
	const char *interactions = "USER INTERACTIONS\n"
	"  SPACE_KEY       jump.\n"
	"  ESCAPE_KEY      pause/resume.\n";

	my_put_str(header);
	my_put_str(usage);
	my_put_str(options);
	my_put_str(interactions);
	exit(0);
}