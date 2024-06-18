/*
** EPITECH PROJECT, 2017
** file.h
** File description:
** 
*/

#ifndef runner_
#define runner_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define error_file ("Fatal error: can't open file.\n")
#define error_malloc ("Fatal error: malloc failed.\n")
#define error_syntax_char ("Fatal error: unknown char in file.\n")
#define error_usage ("Bad usage.\n")
#define error_syntax ("Bad syntax.\n")
#define select_path ("resources/buttons/player_button.png")
#define play_path ("resources/buttons/play_button.png")
#define leave_path ("resources/buttons/leave_button.png")
#define home_path ("resources/buttons/menu_button.png")
#define on_path ("resources/buttons/music_on_button.png")
#define off_path ("resources/buttons/music_off_button.png")
#define back_path ("resources/buttons/back_button.png")
#define font_path ("resources/fonts/pixelates.ttf")

struct game {
	struct entity *player;
	struct entity **obstacles;
	struct gui *gui;
	struct action *action;
	struct options *options;
	sfMusic *music;
	int score;
	int won;
	int speed;
	int step;
	int highest;
	int obstacles_len;
	int maps_len;
	int exit;
};

struct gui {
	struct gui_sprites *sprites;
	struct gui_texts *texts;
	sfRenderWindow *window;
	sfFont *pixel_font;
	char *name;
	int color;
	int bg_abs;
	int floor_abs;
	int width;
	int height;
};

struct gui_sprites {
	sfSprite *bg;
	sfSprite *bg2;
	sfSprite *floor;
	sfSprite *floor2;
	sfSprite *play;
	sfSprite *leave;
	sfSprite *select;
	sfSprite *menu;
	sfSprite *sound_on;
	sfSprite *sound_off;
	sfSprite *back;
};

struct gui_texts {
	sfText *title;
	sfText *play_field;
	sfText *select_field;
	sfText *leave_field;
	sfText *score_field;
	sfText *try_field;
	sfText *menu_field;
	sfText *sound_field;
	sfText *choose_field;
	sfText *game_over;
	sfText *score;
	sfText *back;
	sfText *highest;
	sfText *highest_field;
	sfText **maps_fields;
};

struct options {
	char *custom_path;
	int sound;
	int custom;
};

struct entity {
	sfSprite *sprite;
	int id;
	int x;
	int y;
	int value;
	int skin;
};

struct action {
	int height_limit;
	int jump_speed;
	int fall_speed;
	int rotate;
};

// main.c
void run(struct game *game);
int check(struct game *game, const int ac, char **as);
void get_help(void);

// parser/map_parser_path.c
char *prepare_path(const char *file, const char *directory);
void map_selected(struct game *game, const int i);
char *my_strcat(char *dest, const char *src);

// parser/map_parser.c
void parse_map(struct game *game);
void parse_line(struct game *game, const char *line, const int len,
	const int y);
void check_char(struct game *game, const char c);
void list_maps(struct game *game);
int window_contain_map(const sfText *text, const sfVector2f pos);

// parser/score_parser.c
void save_score(struct game *game);
void read_score(struct game *game);
void append_score(struct game *game, const char *buf, FILE *file);

// utils/color/my_color.c
sfColor get_color_background(struct game *game);
sfColor get_color_ground(struct game *game);
sfColor get_color_block(void);

// utils/draw/my_draw.c
void draw_text(struct game *game, const sfText *text);
void draw_sprite(struct game *game, const sfSprite *sprite);
void set_text_position(sfText *text, const int x, const int y);
void set_sprite_position(sfSprite *sprite, const int x,
	const int y);

// utils/error/my_report.c
void report_error(const char *str);

// utils/instances/my_get.c
struct game *get_game_instance(const int width, const int height, char *name);
struct gui *get_gui_instance(const int width, const int height, char *name);
struct entity *get_entity(const int id, const int x, const int y,
	const int value);
struct action *get_action(const int height_limit);
struct options *get_options(void);

// utils/number/my_itc.c
char *my_itc(int nbr);
int my_atoi(char *str);
int number_digits(int nbr);

// utils/random/my_rnd.c
int crand(int a, int b);
void get_random_entity(struct entity *entity, struct game *game);
char *get_random_sentence(const int won);
void set_next_block(struct entity *entity, struct game *game);

// utils/string/my_str.c
void my_put_char(char c);
int my_put_str(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, char const *src, int n);

// window/actions/my_window_actions.c
void progressive_speed_jump(struct game *game);
void progressive_speed_fall(struct game *game);

// window/actions/my_window_game.c
void game_ended_colision(struct game *game);
void game_won(struct game *game);

// window/entities/my_window_enemies.c
void spawn_random_enemy(struct game *game, int height);
void get_random_enemy(struct entity *entity, struct game *game);

// window/entities/my_window_entities.c
int entity_colision(struct game *game, struct entity *entity);

// window/entities/my_window_obstacles.c
void spawn_random_obstacle(struct game *game);
int spawn_obstacles(sfClock *obs_clock, struct game *game);
int randomize_obs(struct game *game, int block, const int start_abs);
void free_all_obstacles(struct game *game);
void free_first_obstacle(struct game *game);

// window/entities/my_window_player.c
int manage_player_move(sfClock *game_clock, struct game *game);
void manage_player_jump(struct game *game, const int height_limit);
void manage_progressive_speed(struct game *game);
int block_below_player(struct game *game);
int block_on_player(struct game * game);

// window/events/my_window_events.c
void window_events(sfEvent event, struct game *game);
void window_key_pressed(sfEvent event, struct game *game);
void window_mouse_pressed(sfEvent event, struct game *game);
void window_mouse_moved(sfEvent event, struct game *game);
int window_contain_point(sfSprite *sprite, const sfVector2f pos,
	const int size);

// window/events/my_window_mouse_moved.c
void mouse_moved_start(struct game *game, const sfVector2f mouse);
void mouse_moved_end(struct game *game, const sfVector2f mouse);
void mouse_pressed_break_ext(struct game *game, const sfVector2f mouse);

// window/events/my_window_mouse_pressed.c
void mouse_pressed_start(struct game *game, const sfVector2f mouse);
void mouse_pressed_start_ext(struct game *game, const sfVector2f mouse);
void mouse_pressed_end(struct game *game, const sfVector2f mouse);
void mouse_pressed_break(struct game *game, const sfVector2f mouse);
void mouse_pressed_maps(struct game *game, const sfVector2f mouse);

// window/gui/my_window_components.c
void window_load_components(struct game *game);
void window_load_sprites(struct game *game);
void window_load_texts(struct game *game);
void window_load_extented_texts(struct game *game);
void window_load_fonts(struct game *game);

// window/gui/my_window_display.c
void display_anim(struct game *game);
void display_obstacles(struct game *game);
void display_menu(struct game *game);
void display_end_menu(struct game *game);
void display_map_menu(struct game *game);

// window/gui/my_window_draw.c
void window_draw(struct game *game);
void window_draw_start(struct game *game);
void window_draw_game(struct game *game);
void window_draw_break(struct game *game);
void window_draw_end(struct game *game);

// window/gui/my_window_resources.c
void resources_load_bg(struct game *game);
void resources_load_blocks(struct game *game);
void resources_load_floors(struct game *game);
void resources_load_fonts(struct game *game);
void ressources_load_gui(struct game *game);

// src/window/instances/my_window_dispose.c
void dispose_gui(struct game *game);
void dispose_sprites(struct game *game);
void dispose_texts(struct game *game);

// src/window/instances/my_window_get.c
sfSprite *get_sprite(const char *file_path);
sfVector2f get_position(const int x, const int y);
sfIntRect get_rect(const int top, const int left, const int width,
	const int height);
sfText *get_text(sfVector2f pos, const char *value, const int size,
	sfFont *font);

// src/window/music/my_window_music.c
void play_random_music(struct game *game);
void mute_music(struct game *game);
void stop_music(struct game *game);
void play_music(struct game *game);
void pause_music(struct game *game);

// window/time/my_window_clock.c
int manage_scrolling(sfClock *game_clock, struct game *game);
void manage_obstacles_scrolling(struct game *game);

// window/my_window.c
void window_run(struct game *game);
void window_run_start(sfClock *game_clock, sfClock *obs_clock,
struct game *game);
void window_run_game(sfClock *game_clock, sfClock *obs_clock,
struct game *game);
void window_dispose(struct game *game);

#endif /* runner */
