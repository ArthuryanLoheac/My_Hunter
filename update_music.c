/*
** EPITECH PROJECT, 2023
** update_music
** File description:
** update_music
*/
#include "my_hunter.h"
#include <SFML/Audio/Music.h>
#include "constants.h"

void update_music(sfMusic **l_music, l_img *lst_img, sfMusic **l_sounds)
{
    int nb_music_stopped = 0;

    for (int i = 0; i < NB_MUSICS; i++) {
        sfMusic_setVolume(l_music[i], (lst_img[7].image.rect.left /
            lst_img[7].image.width) * 10);
        if (sfMusic_getStatus(l_music[i]) == sfPlaying) {
            nb_music_stopped++;
        }
    }
    if (nb_music_stopped == 0) {
        start_random_music(l_music);
    }
    for (int i = 0; i < NB_SOUNDS; i++) {
        if (sfMusic_getStatus(l_sounds[i]) == sfStopped) {
            sfMusic_stop(l_sounds[i]);
        }
        sfMusic_setVolume(l_sounds[i], (lst_img[10].image.rect.left /
            lst_img[10].image.width) * 10);
    }
}
