/*
** EPITECH PROJECT, 2023
** check_points
** File description:
** check_points
*/
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "my.h"
#include "my_hunter.h"

static void launch_robot_level(int level, all_images images)
{
    time_t time_seed;

    time(&time_seed);
    srand(time_seed);
    images.l_sheet[level].image.time_to_wait =
        (float)((rand() % 475 + 25) / 100);
    images.l_sheet[level].image.in_game = 0;
}

static void first_levels(game *game, all_images images, sfMusic **sounds)
{
    if (game->points >= 750 && images.l_sheet[11].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(11, images);
    }
    if (game->points >= 2500 && images.l_sheet[12].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(12, images);
    }
    if (game->points >= 5000 && images.l_sheet[13].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(13, images);
    }
}

static void extra_life(game *game, all_images images)
{
    if (game->pv < 5) {
        set_pos(&images.l_img[38], (1920 / 2) -
            (images.l_img[38].image.width / 2),
            (1080 / 2) - (images.l_img[38].image.height / 2));
        set_pos(&images.l_img[39], images.l_img[38].image.position.x - 35,
            images.l_img[38].image.position.y +
            images.l_img[38].image.height + 5);
        set_pos(&images.l_img[40], images.l_img[38].image.position.x +
            images.l_img[38].image.width / 2 + 5,
            images.l_img[38].image.position.y +
            images.l_img[38].image.height + 5);
    }
}

static void freeze_card(all_images images)
{
    set_pos(&images.l_img[45], (1920 / 2) -
        (images.l_img[45].image.width / 2),
        (1080 / 2) - (images.l_img[45].image.height / 2));
    set_pos(&images.l_img[43], images.l_img[45].image.position.x - 35,
        images.l_img[45].image.position.y +
        images.l_img[45].image.height + 5);
    set_pos(&images.l_img[44], images.l_img[45].image.position.x +
        images.l_img[45].image.width / 2 + 5,
        images.l_img[45].image.position.y +
        images.l_img[45].image.height + 5);
}

void check_palier(game *game, all_images images)
{
    time_t time_seed;
    int random;

    images = images;
    time(&time_seed);
    random = rand() % 5;
    if (game->points >= ((game->palier * 1000) + 1000)) {
        game->palier += 1;
        srand(time_seed);
        if (random <= 3) {
            extra_life(game, images);
        }
        if (random == 4 && images.l_img[42].image.position.x == -10000) {
            freeze_card(images);
        }
    }
}

void check_points(game *game, all_images images, sfMusic **sounds)
{
    check_palier(game, images);
    first_levels(game, images, sounds);
    if (game->points >= 10000 && images.l_sheet[14].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(14, images);
    }
    if (game->points >= 15000 && images.l_sheet[15].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(15, images);
    }
    if (game->points >= 30000 && images.l_sheet[16].image.in_game == -1) {
        sfMusic_play(sounds[4]);
        launch_robot_level(16, images);
    }
}
