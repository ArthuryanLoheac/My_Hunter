/*
** EPITECH PROJECT, 2023
** close_winfw
** File description:
** close_window
*/
#include "my_hunter.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>

void close_window_in_game(l_img *lst_image, sfMusic **l_music)
{
    for (int i = 3; i <= 12; i++) {
        lst_image[i].image.position.x = -10000;
        lst_image[i].image.position.y = -10000;
    }
    sfMusic_stop(l_music[0]);
    sfMusic_play(l_music[0]);
}
