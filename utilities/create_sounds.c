/*
** EPITECH PROJECT, 2023
** create_sounds
** File description:
** create_sounds
*/
#include "my_hunter.h"

all_sounds create_sounds(void)
{
    all_sounds all_sound;

    all_sound.l_music = add_musics();
    all_sound.l_sounds = add_sounds();
    return all_sound;
}
