/*
** EPITECH PROJECT, 2023
** draw_points
** File description:
** draw_points
*/
#include "structs.h"
#include <stdlib.h>
#include "my.h"
#include "my_hunter.h"

static int len_num(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = -nb;
        len ++;
    }
    for (int j = 1; nb / j > 0; j *= 10) {
        len ++;
    }
    return len;
}

static void special_case(int *points, char *str, int *len_nb, int *i)
{
    if (*points < 0) {
        (*i)++;
        str[0] = '-';
        *points = -(*points);
        (*len_nb)--;
    }
    if (*points == 0) {
        str[0] = '0';
        str[1] = '\0';
    }
}

char *pts_to_str(int points)
{
    char *str;
    int len_nb = len_num(points);
    int i = 0;

    str = malloc(len_nb + 1);
    for (int a = 0; a < len_nb + 1; a++) {
        str[a] = '\0';
    }
    special_case(&points, str, &len_nb, &i);
    for (int j = my_compute_power_rec(10, len_nb - 1); j > 0; j /= 10) {
        str[i] = (points / j) + '0';
        i++;
        points -= (points / j) * j;
    }
    str[i] = '\0';
    return str;
}

static void draw_zero(l_img *l_img)
{
    l_img[13].image.rect.left = 28;
    set_pos(&l_img[13], (1920 / 2) - (l_img[13].image.width / 2), 25);
    for (int i = 1; i < 11; i++) {
        set_pos(&l_img[13 + i], -10000, -10000);
    }
}

static void draw_else(l_img *l_img, int len, char *str_pts)
{
    for (int i = 0; i < len; i++) {
        if (str_pts[i] == '-') {
            l_img[13 + i].image.rect.left = 0;
        } else {
            l_img[13 + i].image.rect.left = (28) *
                (str_pts[i] - '0' + 1);
        }
        set_pos(&l_img[13 + i], (1920 / 2) -
            ((len * 28) / 2) + (i * 28), 25);
    }
    for (int i = len; i < 11; i++) {
        set_pos(&l_img[13 + i], -10000, -10000);
    }
}

static void draw_else_mx(l_img *l_img, int len, char *str_pts)
{
    for (int i = 0; i < len; i++) {
        if (str_pts[i] == '-') {
            l_img[26 + i].image.rect.left = 0;
        } else {
            l_img[26 + i].image.rect.left = (28) *
                (str_pts[i] - '0' + 1);
        }
        set_pos(&l_img[26 + i], (1920 / 2) -
            ((len * 14) / 2) + (i * 14) - 4, 75);
    }
    for (int i = len; i < 11; i++) {
        set_pos(&l_img[26 + i], -10000, -10000);
    }
}

static void draw_streak(game *game, l_img *l_img)
{
    if (game->streak == 0) {
        l_img[25].image.rect.left = 0;
    }
    if (game->streak == 1) {
        l_img[25].image.rect.left = 112;
    }
    if (game->streak == 2) {
        l_img[25].image.rect.left = 224;
    }
    if (game->streak == 3) {
        l_img[25].image.rect.left = 336;
    }
    if (game->streak == 4) {
        l_img[25].image.rect.left = 448;
    }
    if (game->streak >= 5) {
        l_img[25].image.rect.left = 560;
    }
}

static void draw_life(game *game, all_images images)
{
    if (game->pv == 0) {
        images.l_img[37].image.rect.left = 0;
    }
    if (game->pv == 1) {
        images.l_img[37].image.rect.left = 112;
    }
    if (game->pv == 2) {
        images.l_img[37].image.rect.left = 224;
    }
    if (game->pv == 3) {
        images.l_img[37].image.rect.left = 336;
    }
    if (game->pv == 4) {
        images.l_img[37].image.rect.left = 448;
    }
    if (game->pv == 5) {
        images.l_img[37].image.rect.left = 560;
    }
    set_pos(&images.l_img[37], 1920 - 180, 10);
}

void draw_points(game *game, l_img *l_img,
    all_images images, all_sounds *all_sound)
{
    char *str_pts = pts_to_str(game->points);
    char *str_pts_mx = pts_to_str(game->score_max);
    int len = my_strlen(str_pts);
    int len_mx = my_strlen(str_pts_mx);

    draw_streak(game, l_img);
    check_points(game, images, all_sound->l_sounds);
    if (game->start != 0) {
        if (game->points == 0) {
            draw_zero(l_img);
            draw_else_mx(l_img, len_mx, str_pts_mx);
        } else {
            draw_else(l_img, len, str_pts);
            draw_else_mx(l_img, len_mx, str_pts_mx);
        }
        draw_life(game, images);
    }
}
