/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_
    #define MY_HUNTER_

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio/Music.h>
    #include "structs.h"

sfRenderWindow* create_window(int width, int height);
int analyse_events(sfEvent *event, all_images *images,
    all_sounds all_sound, game *game);
img_sheet create_sprite_sheet(char *path, int width,
    int height, char c);
img create_image(char *path, int width, int height);
void destroy_all(all_images images, sfMusic **l_music,
    sfClock *clock, sfMusic **l_sounds);
void update_image(img *image);
void update_image_sheet(img_sheet *image, l_img *lst_image);
void draw_all_images(l_img_sheet *lst_sheet,
    l_img *lst_img, sfRenderWindow *window);
l_img *add_images_to_lst(void);
l_img_sheet *add_images_sheet_to_lst(void);
void set_pos_sheet(l_img_sheet *img, int x, int y);
void set_pos(l_img *img, int x, int y);
int is_clicked(int mouse_x, int mouse_y, l_img *img);
int is_clicked_sheet(int mouse_x, int mouse_y, l_img_sheet *img);
void launch_robot(img_sheet *robot);
void move_robot(img_sheet *robot, float delta_time);
void launch_game_over(l_img_sheet *lst_sheet,
    l_img *lst_img, sfMusic **l_music);
void update_pos(l_img_sheet *lst_sheet,
    game *game, l_img *lst_image, sfMusic **l_sounds);
void print_help(void);
sfMusic **add_musics(void);
sfMusic **add_sounds(void);
void update_music(sfMusic **l_music, l_img *lst_img, sfMusic **l_sounds);
void manage_buttons(sfKeyEvent *event, l_img *lst_image,
    game *game, sfMusic **sounds);
void manage_mouse_move(sfMouseMoveEvent event, l_img *lst_image);
void manage_click(sfMouseButtonEvent *event, all_images *all,
    sfMusic **l_sounds, game *game);
int manage_realeased(sfMouseButtonEvent *event, l_img *lst_image,
    game *game, sfMusic **l_music);
all_sounds create_sounds(void);
all_images set_all_img(void);
void draw_points(game *game, l_img *l_img,
    all_images images, all_sounds *all_sound);
void check_points(game *game, all_images images, sfMusic **sounds);
void start_random_music(sfMusic **l_music);
void check_go_restart(all_images *images,
    game *game, all_sounds all_sound);
int fs_get_number_from_first_line(char const *filepath);
char *pts_to_str(int points);
void open_options(l_img *lst_image);
void close_window_in_game(l_img *lst_image, sfMusic **l_music);

#endif /* !MY_HUNTER_ */
