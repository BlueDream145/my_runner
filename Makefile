##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

UTILS	=	utils

WIN	=	window

PARSER	=	parser

SRC	=	$(PARSER)/map_parser_path.c \
		$(PARSER)/map_parser.c \
		$(PARSER)/score_parser.c \
		$(UTILS)/color/my_color.c \
		$(UTILS)/draw/my_draw.c \
		$(UTILS)/error/my_report.c \
		$(UTILS)/instances/my_get.c \
		$(UTILS)/number/my_itc.c \
		$(UTILS)/random/my_rnd.c \
		$(UTILS)/string/my_str.c \
		$(WIN)/actions/my_window_actions.c \
		$(WIN)/actions/my_window_game.c \
		$(WIN)/entities/my_window_enemies.c \
		$(WIN)/entities/my_window_entities.c \
		$(WIN)/entities/my_window_obstacles.c \
		$(WIN)/entities/my_window_player.c \
		$(WIN)/events/my_window_events.c \
		$(WIN)/events/my_window_mouse_moved.c \
		$(WIN)/events/my_window_mouse_pressed.c \
		$(WIN)/gui/my_window_display.c \
		$(WIN)/gui/my_window_components.c \
		$(WIN)/gui/my_window_draw.c \
		$(WIN)/gui/my_window_resources.c \
		$(WIN)/instances/my_window_dispose.c \
		$(WIN)/instances/my_window_get.c \
		$(WIN)/music/my_window_music.c \
		$(WIN)/time/my_window_clock.c \
		$(WIN)/my_window.c \
		main.c

CFLAGS	=	-Wall -Wextra -lc_graph_prog

INCLUDE =	-I include -o

LIB	=	-g -lm

NAME	=	my_runner

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
