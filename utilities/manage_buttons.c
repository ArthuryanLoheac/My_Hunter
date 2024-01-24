/*
** EPITECH PROJECT, 2023
** manage_buttons
** File description:
** manage_buttons
*/
#include "my_hunter.h"
#include "structs.h"
#include "my.h"

static void tp_options_out(l_img *lst_image)
{
    for (int i = 3; i <= 12; i++) {
        lst_image[i].image.position.x = -10000;
        lst_image[i].image.position.y = -10000;
    }
}

static void set_volume(l_img *lst_image)
{
    lst_image[5].image.position.x =
        lst_image[3].image.position.x + 220;
    lst_image[5].image.position.y =
        lst_image[3].image.position.y + 192;
    lst_image[6].image.position.x =
        lst_image[3].image.position.x + 464;
    lst_image[6].image.position.y =
        lst_image[3].image.position.y + 192;
    lst_image[7].image.position.x =
        lst_image[3].image.position.x + 256;
    lst_image[7].image.position.y =
        lst_image[3].image.position.y + 190;
}

static void set_volume_snd(l_img *lst_image)
{
    lst_image[8].image.position.x =
        lst_image[3].image.position.x + 220;
    lst_image[8].image.position.y =
        lst_image[3].image.position.y + 192 + 50;
    lst_image[9].image.position.x =
        lst_image[3].image.position.x + 464;
    lst_image[9].image.position.y =
        lst_image[3].image.position.y + 192 + 50;
    lst_image[10].image.position.x =
        lst_image[3].image.position.x + 256;
    lst_image[10].image.position.y =
        lst_image[3].image.position.y + 190 + 50;
    lst_image[24].image.position.x = -10000;
    lst_image[24].image.position.y = -10000;
}

static void set_pos_buttons(l_img *lst_image)
{
    lst_image[4].image.position.x = lst_image[3].image.position.x +
        lst_image[3].image.width - lst_image[4].image.width - 8;
    lst_image[4].image.position.y =
        lst_image[3].image.position.y + 8;
    set_volume(lst_image);
    set_volume_snd(lst_image);
    lst_image[12].image.position.x = lst_image[3].image.position.x;
    lst_image[12].image.position.y = lst_image[3].image.height +
        lst_image[3].image.position.y;
    lst_image[11].image.position.x = lst_image[3].image.position.x
        + lst_image[3].image.width / 2;
    lst_image[11].image.position.y = lst_image[3].image.height +
        lst_image[3].image.position.y;
}

static void key_a(l_img *lst_image, game *game, sfMusic **sounds)
{
    lst_image[41].image.position.x = 0;
    lst_image[41].image.position.y = 0;
    sfMusic_play(sounds[6]);
    game->time_freeze = game->freeze;
    game->pause = 1;
    game->pause_time = 1.5;
}

void manage_buttons(sfKeyEvent *event, l_img *lst_image,
    game *game, sfMusic **sounds)
{
    if (event->code == sfKeyEscape) {
        if (lst_image[3].image.position.x == -10000 &&
            lst_image[3].image.position.y == -10000) {
            lst_image[3].image.position.x = (1920 / 2)
                - (lst_image[3].image.width / 2);
            lst_image[3].image.position.y = (1080 / 2)
                - (lst_image[3].image.height / 2);
            set_pos_buttons(lst_image);
        } else {
            tp_options_out(lst_image);
        }
    }
    if (event->code == sfKeyA && game->time_freeze <= 0 &&
        lst_image[42].image.position.x != -10000) {
        key_a(lst_image, game, sounds);
    }
}

void open_options(l_img *lst_image)
{
    lst_image[3].image.position.x = (1920 / 2)
        - (lst_image[3].image.width / 2);
    lst_image[3].image.position.y = (1080 / 2)
        - (lst_image[3].image.height / 2);
    set_pos_buttons(lst_image);
}
