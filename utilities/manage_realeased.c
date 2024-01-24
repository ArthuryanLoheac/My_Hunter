/*
** EPITECH PROJECT, 2023
** manage_realeased
** File description:
** manage_realeased
*/
#include "my_hunter.h"

static void check_close_options(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (event->x >= lst_image[4].image.position.x && event->x <=
            lst_image[4].image.position.x + lst_image[4].image.width &&
        event->y >= lst_image[4].image.position.y && event->y <=
            lst_image[4].image.position.y + lst_image[4].image.height) {
        for (int i = 3; i <= 12; i++) {
            lst_image[i].image.position.x = -10000;
            lst_image[i].image.position.y = -10000;
        }
    }
}

static void reduce_volume(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (event->x >= lst_image[5].image.position.x && event->x <=
            lst_image[5].image.position.x + lst_image[5].image.width &&
        event->y >= lst_image[5].image.position.y && event->y <=
            lst_image[5].image.position.y + lst_image[5].image.height) {
        if (lst_image[7].image.rect.left != 0) {
            lst_image[7].image.rect.left -= lst_image[7].image.width;
        }
    }
}

static void up_volume(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (event->x >= lst_image[6].image.position.x && event->x <=
            lst_image[6].image.position.x + lst_image[6].image.width &&
        event->y >= lst_image[6].image.position.y && event->y <=
            lst_image[6].image.position.y + lst_image[6].image.height) {
        if (lst_image[7].image.rect.left != 2040) {
            lst_image[7].image.rect.left += lst_image[7].image.width;
        }
    }
}

static void reduce_volume_snd(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (event->x >= lst_image[8].image.position.x && event->x <=
            lst_image[8].image.position.x + lst_image[8].image.width &&
        event->y >= lst_image[8].image.position.y && event->y <=
            lst_image[8].image.position.y + lst_image[8].image.height) {
        if (lst_image[10].image.rect.left != 0) {
            lst_image[10].image.rect.left -= lst_image[10].image.width;
        }
    }
}

static void up_volume_snd(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (event->x >= lst_image[9].image.position.x && event->x <=
            lst_image[9].image.position.x + lst_image[9].image.width &&
        event->y >= lst_image[9].image.position.y && event->y <=
            lst_image[9].image.position.y + lst_image[9].image.height) {
        if (lst_image[10].image.rect.left != 2040) {
            lst_image[10].image.rect.left += lst_image[10].image.width;
        }
    }
}

static void sound_button(sfMouseButtonEvent *event, l_img *lst_image)
{
    if (lst_image[8].image.clicked == 1) {
        reduce_volume_snd(event, lst_image);
        lst_image[8].image.clicked = 0;
    }
    if (lst_image[9].image.clicked == 1) {
        up_volume_snd(event, lst_image);
        lst_image[9].image.clicked = 0;
    }
    if (lst_image[5].image.clicked == 1) {
        reduce_volume(event, lst_image);
        lst_image[5].image.clicked = 0;
    }
    if (lst_image[6].image.clicked == 1) {
        up_volume(event, lst_image);
        lst_image[6].image.clicked = 0;
    }
}

static int check_start_restart(l_img *lst_image,
    sfMusic **l_music)
{
    if (lst_image[12].image.clicked == 1) {
        close_window_in_game(lst_image, l_music);
        lst_image[12].image.clicked = 0;
        return 1;
    }
    if (lst_image[24].image.clicked == 1) {
        lst_image[24].image.clicked = 0;
        return 1;
    }
    return 0;
}

static void accept_decline_freeze(l_img *lst_image,
    game *game)
{
    if (lst_image[43].image.clicked == 1) {
        game->points -= 1000;
        set_pos(&lst_image[42], 1920 - (70 * 1.5) - 10, 1080 - (70 * 1.5)- 10);
        set_pos(&lst_image[43], -10000, -10000);
        set_pos(&lst_image[44], -10000, -10000);
        set_pos(&lst_image[45], -10000, -10000);
        lst_image[43].image.clicked = 0;
    }
    if (lst_image[44].image.clicked == 1) {
        set_pos(&lst_image[43], -10000, -10000);
        set_pos(&lst_image[44], -10000, -10000);
        set_pos(&lst_image[45], -10000, -10000);
        lst_image[44].image.clicked = 0;
    }
}

static void check_accept_decline(l_img *lst_image,
    game *game)
{
    if (lst_image[39].image.clicked == 1) {
        game->points -= 500;
        game->pv += 1;
        set_pos(&lst_image[38], -10000, -10000);
        set_pos(&lst_image[39], -10000, -10000);
        set_pos(&lst_image[40], -10000, -10000);
        lst_image[39].image.clicked = 0;
    }
    if (lst_image[40].image.clicked == 1) {
        set_pos(&lst_image[38], -10000, -10000);
        set_pos(&lst_image[39], -10000, -10000);
        set_pos(&lst_image[40], -10000, -10000);
        lst_image[40].image.clicked = 0;
    }
    accept_decline_freeze(lst_image, game);
}

int manage_realeased(sfMouseButtonEvent *event, l_img *lst_image,
    game *game, sfMusic **l_music)
{
    if (event->button == sfMouseLeft) {
        lst_image[0].image.rect.left = 0;
        if (lst_image[4].image.clicked == 1) {
            check_close_options(event, lst_image);
            lst_image[4].image.clicked = 0;
        }
        sound_button(event, lst_image);
        if (lst_image[11].image.clicked == 1) {
            sfRenderWindow_close(game->window);
            lst_image[11].image.clicked = 0;
        }
        check_accept_decline(lst_image, game);
        if (check_start_restart(lst_image, l_music) == 1) {
            return 1;
        }
    }
    return 0;
}
