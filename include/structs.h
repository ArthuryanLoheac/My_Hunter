/*
** EPITECH PROJECT, 2023
** image
** File description:
** image
*/

#ifndef STRUCTS_
    #define STRUCTS_

    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Audio/Music.h>

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    int height;
    int width;

    sfClock *clock;
    sfTime time;
    float seconds;
    float animation_time;
    int nb_images_width;
    int nb_images_height;
    int nb_images;
    float time_to_wait;
    int status_image;

    int in_game;
    float speed_a;
    float speed_b;
    char type;
} img_sheet;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    int height;
    int width;
    int clicked;
} img;

typedef struct {
    img image;
    int layer;
} l_img;

typedef struct {
    img_sheet image;
    int layer;
} l_img_sheet;

typedef struct {
    l_img_sheet *l_sheet;
    l_img *l_img;
} all_images;

typedef struct {
    sfMusic **l_music;
    sfMusic **l_sounds;
} all_sounds;

typedef struct {
    int points;
    int game_over;
    int start;
    int pv;
    int score_max;
    int palier;
    sfRenderWindow *window;
    sfClock *clock_game;
    int streak;
    int pause;
    float pause_time;
    float freeze;
    float time_freeze;
} game;

#endif /* !STRUCTS_ */
