/*
** EPITECH PROJECT, 2023
** add_musics
** File description:
** add_musics
*/
#include <SFML/Audio/Music.h>
#include <stdlib.h>
#include "constants.h"

sfMusic **add_musics(void)
{
    sfMusic **l_music;

    l_music = malloc(sizeof(sfMusic *) * NB_MUSICS);
    l_music[0] = sfMusic_createFromFile("musics/Menu.ogg");
    sfMusic_setLoop(l_music[0], sfTrue);
    l_music[1] = sfMusic_createFromFile("musics/Aqueos.ogg");
    l_music[2] = sfMusic_createFromFile("musics/GORGON.ogg");
    l_music[3] = sfMusic_createFromFile("musics/Insurgence.ogg");
    l_music[4] = sfMusic_createFromFile("musics/Isaac.ogg");
    l_music[5] = sfMusic_createFromFile("musics/Mutant.ogg");
    return l_music;
}

sfMusic **add_sounds(void)
{
    sfMusic **l_music;

    l_music = malloc(sizeof(sfMusic *) * NB_SOUNDS);
    l_music[0] = sfMusic_createFromFile("musics/Robot_Explosion.wav");
    l_music[1] = sfMusic_createFromFile("musics/gunshot.wav");
    l_music[2] = sfMusic_createFromFile("musics/gunshot.wav");
    l_music[3] = sfMusic_createFromFile("musics/Click.ogg");
    l_music[4] = sfMusic_createFromFile("musics/Next_Level.wav");
    l_music[5] = sfMusic_createFromFile("musics/Error.wav");
    l_music[6] = sfMusic_createFromFile("musics/Freeze.wav");
    return l_music;
}
