/*
** EPITECH PROJECT, 2023
** manage_click
** File description:
** manage_click
*/
#include "my_hunter.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>

static void check_clicked(sfMouseButtonEvent *event, int i,
    l_img *lst_image, sfMusic **l_sounds)
{
    if (event->x >= lst_image[i].image.position.x && event->x <=
            lst_image[i].image.position.x + lst_image[i].image.width &&
        event->y >= lst_image[i].image.position.y && event->y <=
            lst_image[i].image.position.y + lst_image[i].image.height) {
            lst_image[i].image.clicked = 1;
            lst_image[i].image.rect.left = 0;
            sfMusic_play(l_sounds[3]);
    }
}

static void set_explosion(l_img_sheet *lst_sheet, int i)
{
    lst_sheet[i - 7].image.position.x = lst_sheet[i].image.position.x -
        (lst_sheet[i - 7].image.width / 4) + 10;
    lst_sheet[i - 7].image.position.y = lst_sheet[i].image.position.y -
        (lst_sheet[i - 7].image.height / 4) + 16;
    lst_sheet[i - 7].image.status_image = 0;
    lst_sheet[i - 7].image.rect.left = 0;
    lst_sheet[i - 7].image.rect.top = 0;
    lst_sheet[i - 7].image.speed_a = lst_sheet[i].image.speed_a;
    lst_sheet[i - 7].image.speed_b = lst_sheet[i].image.speed_b;
}

static void give_points(game *game)
{
    game->streak += 1;
    if (game->streak >= 5) {
        game->points += 75;
    } else {
        game->points += 50;
    }
}

static void remove_points(game *game, int clicked)
{
    if (game->game_over == 0 && clicked == 0) {
        game->points -= 25;
        game->streak = 0;
    }
}

static void click_on_robot(sfMouseButtonEvent *event,
    l_img_sheet *lst_sheet, sfMusic **l_sounds, game *game)
{
    time_t time_seed;
    int clicked = 0;

    for (int i = 10; i < 17; i++) {
        if (is_clicked_sheet(event->x, event->y,
            &lst_sheet[i]) == 1 && game->game_over == 0) {
            clicked++;
            give_points(game);
            set_explosion(lst_sheet, i);
            lst_sheet[i].image.position.x = 0;
            lst_sheet[i].image.position.y = -10000;
            time(&time_seed);
            srand(time_seed);
            lst_sheet[i].image.time_to_wait =
                (float)((rand() % 475 + 25) / 100);
            lst_sheet[i].image.in_game = 0;
            sfMusic_play(l_sounds[0]);
        }
    }
    remove_points(game, clicked);
}

static void impact_ball(sfMouseButtonEvent *event, l_img_sheet *lst_sheet)
{
    sfClock_restart(lst_sheet[2].image.clock);
    lst_sheet[2].image.status_image = 0;
    lst_sheet[2].image.rect.top = 0;
    lst_sheet[2].image.rect.left = 0;
    lst_sheet[2].image.position.x = event->x - lst_sheet[2].image.width / 2;
    lst_sheet[2].image.position.y = event->y - lst_sheet[2].image.height / 2;
}

static void play_good_sound(sfMusic **l_sounds)
{
    if (sfMusic_getStatus(l_sounds[1]) == sfPlaying) {
        sfMusic_play(l_sounds[2]);
    } else {
        sfMusic_play(l_sounds[1]);
    }
}

void manage_click(sfMouseButtonEvent *event, all_images *all,
    sfMusic **l_sounds, game *game)
{
    int numbers[9] = {8, 9, 11, 12, 24, 39, 40, 43, 44};

    if (event->button == sfMouseLeft) {
        all->l_img[0].image.rect.left = 62;
        if (all->l_img[3].image.position.x == -10000 &&
            all->l_sheet[1].image.position.y == -10000 &&
            all->l_img[38].image.position.x == -10000 &&
            all->l_img[45].image.position.x == -10000) {
            click_on_robot(event, all->l_sheet, l_sounds, game);
            impact_ball(event, all->l_sheet);
            play_good_sound(l_sounds);
        }
        for (int i = 4; i <= 6; i++) {
            check_clicked(event, i, all->l_img, l_sounds);
        }
        for (int i = 0; i < 9; i++) {
            check_clicked(event, numbers[i], all->l_img, l_sounds);
        }
    }
}
