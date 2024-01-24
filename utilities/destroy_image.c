/*
** EPITECH PROJECT, 2023
** destroy_image
** File description:
** destroy_image
*/
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Music.h>
#include "structs.h"
#include "constants.h"
#include <stdlib.h>

static void destroy_image(img *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
}

static void destroy_image_sheet(img_sheet *image)
{
    sfClock_destroy(image->clock);
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
}

void destroy_all(all_images images, sfMusic **l_music,
    sfClock *clock, sfMusic **l_sounds)
{
    l_img_sheet *lst_sheet = images.l_sheet;
    l_img *lst_img = images.l_img;

    sfClock_destroy(clock);
    for (int i = 1; i < NB_IMG_SHEET; i++) {
        destroy_image_sheet(&lst_sheet[i].image);
    }
    for (int i = 0; i < NB_IMG; i++) {
        destroy_image(&lst_img[i].image);
    }
    for (int i = 0; i < NB_MUSICS; i++) {
        sfMusic_destroy(l_music[i]);
    }
    for (int i = 0; i < NB_SOUNDS; i++) {
        sfMusic_destroy(l_sounds[i]);
    }
    free(lst_sheet);
    free(lst_img);
}
