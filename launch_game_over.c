/*
** EPITECH PROJECT, 2023
** launch_game_over
** File description:
** launch_game_over
*/
#include "structs.h"
#include "my_hunter.h"
#include "constants.h"

void launch_game_over(l_img_sheet *lst_sheet,
    l_img *lst_img, sfMusic **l_music)
{
    if (lst_img[3].image.position.x == -10000) {
        set_pos_sheet(&lst_sheet[1], (1920 / 2) -
            (lst_sheet[1].image.width / 2),
            (1080 / 2) - (lst_sheet[1].image.height / 2));
        set_pos(&lst_img[12], lst_sheet[1].image.position.x + 40,
            lst_sheet[1].image.position.y + lst_sheet[1].image.height + 20);
        set_pos(&lst_img[11], lst_sheet[1].image.position.x +
            lst_img[11].image.width + 50,
            lst_sheet[1].image.position.y + lst_sheet[1].image.height + 20);
    } else {
        set_pos_sheet(&lst_sheet[1], -10000, -10000);
    }
    if (sfMusic_getStatus(l_music[0]) == sfStopped) {
        for (int i = 0; i < NB_MUSICS; i++) {
            sfMusic_stop(l_music[i]);
        }
        sfMusic_play(l_music[0]);
    }
}
