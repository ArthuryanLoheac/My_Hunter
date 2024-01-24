/*
** EPITECH PROJECT, 2023
** update_pos
** File description:
** update_pos
*/
#include "structs.h"
#include "my_hunter.h"
#include "constants.h"
#include <time.h>
#include <stdlib.h>

static void check_game_over(l_img_sheet *lst_sheet,
    int i, game *game, sfMusic **sounds)
{
    time_t time_seed;

    if ((lst_sheet[i].image.position.y > 1080 ||
        lst_sheet[i].image.position.x > 1920 ||
        lst_sheet[i].image.position.x < -(lst_sheet[i].image.width)) &&
        lst_sheet[i].image.type == 'r') {
        game->pv -= 1;
        time(&time_seed);
        srand(time_seed);
        lst_sheet[i].image.position.x = 0;
        lst_sheet[i].image.position.y = -10000;
        lst_sheet[i].image.time_to_wait =
            (float)((rand() % 475 + 25) / 100);
        lst_sheet[i].image.in_game = 0;
        sfMusic_play(sounds[5]);
    }
}

static void check_counter_first(game *game, l_img *lst_image)
{
    if (game->time_freeze <= 0) {
        lst_image[42].image.rect.left = 0;
    }
    if (game->time_freeze >= 9) {
        lst_image[42].image.rect.left = 70;
    }
    if (game->time_freeze >= 8 && game->time_freeze < 9) {
        lst_image[42].image.rect.left = 140;
    }
    if (game->time_freeze >= 7 && game->time_freeze < 8) {
        lst_image[42].image.rect.left = 210;
    }
}

static void check_counter(game *game, l_img *lst_image)
{
    if (game->time_freeze >= 6 && game->time_freeze < 7) {
        lst_image[42].image.rect.left = 280;
    }
    if (game->time_freeze >= 5 && game->time_freeze < 6) {
        lst_image[42].image.rect.left = 350;
    }
    if (game->time_freeze >= 4 && game->time_freeze < 5) {
        lst_image[42].image.rect.left = 420;
    }
    if (game->time_freeze >= 3 && game->time_freeze < 4) {
        lst_image[42].image.rect.left = 490;
    }
    if (game->time_freeze >= 2 && game->time_freeze < 3) {
        lst_image[42].image.rect.left = 560;
    }
    if (game->time_freeze >= 1 && game->time_freeze < 2) {
        lst_image[42].image.rect.left = 630;
    }
    if (game->time_freeze >= 0 && game->time_freeze < 1)
        lst_image[42].image.rect.left = 700;
}

static void freeze(game *game, l_img *lst_image, float seconds_game)
{
    if (game->game_over != 1 && lst_image[3].image.position.x ==
        -10000 && lst_image[38].image.position.x == -10000 &&
        lst_image[45].image.position.x == -10000) {
        game->time_freeze -= seconds_game;
        game->pause_time -= seconds_game;
        sfSprite_setColor(lst_image[41].image.sprite,
            sfColor_fromRGBA(255, 255, 255, (game->time_freeze * 100) - 70));
        if (game->pause_time <= 0) {
            game->pause = 0;
            lst_image[41].image.position.x = -10000;
        }
    }
    check_counter_first(game, lst_image);
    check_counter(game, lst_image);
}

void update_pos(l_img_sheet *lst_sheet,
    game *game, l_img *lst_image, sfMusic **l_sounds)
{
    sfTime time_game = sfClock_getElapsedTime(game->clock_game);
    float seconds_game = time_game.microseconds / 1000000.0;

    sfClock_restart(game->clock_game);
    freeze(game, lst_image, seconds_game);
    if (game->game_over != 1 && lst_image[3].image.position.x ==
        -10000 && lst_image[38].image.position.x == -10000 &&
        game->pause == 0 && lst_image[45].image.position.x == -10000
        && lst_image[41].image.position.x != 0) {
        for (int i = 1; i < NB_IMG_SHEET; i++) {
            move_robot(&lst_sheet[i].image, seconds_game);
            check_game_over(lst_sheet, i, game, l_sounds);
        }
        sfClock_restart(game->clock_game);
    }
}
