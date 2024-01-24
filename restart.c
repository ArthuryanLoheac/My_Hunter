/*
** EPITECH PROJECT, 2023
** restart
** File description:
** restart
*/
#include "structs.h"
#include "my_hunter.h"
#include "my.h"
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void stock_max_score(game *game)
{
    int file = 0;
    char *str_nb;

    if (game->points > game->score_max) {
        game->score_max = game->points;
        file = open("score_max/score_max", O_WRONLY);
        str_nb = pts_to_str(game->score_max);
        write(file, str_nb, my_strlen(str_nb));
    }
}

static void check_game_over(game *game, l_img_sheet *lst_sheet,
    l_img *lst_img, all_sounds all_sound)
{
    if (game->pv > 0) {
        update_pos(lst_sheet, game, lst_img, all_sound.l_sounds);
    } else {
        stock_max_score(game);
        launch_game_over(lst_sheet, lst_img, all_sound.l_music);
    }
}

static void set_pos_robots(l_img_sheet *lst_sheet)
{
    for (int i = 10; i < 17; i++) {
        lst_sheet[i].image.position.x = 0;
        lst_sheet[i].image.position.y = -10000;
        lst_sheet[i].image.in_game = -1;
        lst_sheet[i].image.time_to_wait = -1;
    }
}

static void reset_game(game *game)
{
    game->game_over = 0;
    game->points = 0;
    game->start = 1;
    game->streak = 0;
    game->palier = 0;
    game->pv = 1;
    game->time_freeze = 0;
    game->freeze = 10;
    game->pause = 0;
    game->pause_time = 0;
}

static void restart(game *game, l_img_sheet *lst_sheet,
    l_img *l_img, sfMusic **l_music)
{
    time_t time_seed;

    reset_game(game);
    set_pos(&l_img[11], -10000, -10000);
    set_pos(&l_img[42], -10000, -10000);
    set_pos_robots(lst_sheet);
    set_pos(&l_img[25], 5, 5);
    lst_sheet[1].image.position.x = 0;
    lst_sheet[1].image.position.y = -10000;
    time(&time_seed);
    srand(time_seed);
    lst_sheet[10].image.time_to_wait =
        (float)((rand() % 475 + 25) / 100);
    lst_sheet[10].image.in_game = 0;
    start_random_music(l_music);
}

void check_go_restart(all_images *images,
    game *game, all_sounds all_sound)
{
    sfEvent event;

    if (analyse_events(&event, images, all_sound, game) == 1) {
        restart(game, images->l_sheet, images->l_img, all_sound.l_music);
    }
    check_game_over(game, images->l_sheet, images->l_img, all_sound);
}
