/*
** EPITECH PROJECT, 2023
** start_random_music
** File description:
** start_random_music
*/
#include "my_hunter.h"
#include <SFML/Audio/Music.h>
#include "constants.h"
#include "structs.h"
#include <time.h>
#include <stdlib.h>

void start_random_music(sfMusic **l_music)
{
    time_t time_seed;
    int a = 0;

    for (int i = 0; i < NB_MUSICS; i++) {
        sfMusic_stop(l_music[i]);
    }
    time(&time_seed);
    srand(time_seed);
    a = (rand() % (NB_MUSICS - 1)) + 1;
    sfMusic_play(l_music[a]);
}
