/*
** EPITECH PROJECT, 2023
** add_images_sheet_to_lst
** File description:
** add_images_sheet_to_lst
*/
#include <stdlib.h>
#include "my_hunter.h"
#include "constants.h"

void set_animations_settings(l_img_sheet *img,
    int nb_images, int nb_images_width, int nb_images_height)
{
    img->image.animation_time = .15;
    img->image.nb_images_width = nb_images_width;
    img->image.nb_images_height = nb_images_height;
    img->image.nb_images = nb_images;
    img->image.status_image = 0;
}

static void initialise_impact(l_img_sheet *lst)
{
    lst[2].image = create_sprite_sheet("images/Impact_ball-Sheet.png",
        62, 62, 'i');
    set_animations_settings(&lst[2], 5, 3, 2);
    lst[2].layer = 9;
    lst[2].image.animation_time = 0.03;
    lst[2].image.position.x = -10000;
}

static void initialise_explosion(l_img_sheet *lst)
{
    for (int i = 3; i < 10; i++) {
        lst[i].image = create_sprite_sheet("images/Explosion-Sheet.png",
            180, 186, 'e');
        set_animations_settings(&lst[i], 11, 4, 3);
        lst[i].layer = 1;
        lst[i].image.animation_time = 0.05;
        lst[i].image.position.x = -10000;
        lst[i].image.position.y = -10000;
    }
}

static void add_robots(l_img_sheet *lst)
{
    for (int i = 10; i < 17; i++) {
        lst[i].image = create_sprite_sheet("images/Drone-Sheet.png",
            108, 118, 'r');
        set_animations_settings(&lst[i], 24, 24, 1);
        lst[i].layer = 2;
        lst[i].image.animation_time = .05;
        lst[i].image.position.x = 0;
        lst[i].image.position.y = -10000;
        lst[i].image.in_game = -1;
        lst[i].image.time_to_wait = -1;
    }
}

l_img_sheet *add_images_sheet_to_lst(void)
{
    l_img_sheet *lst;

    lst = malloc(sizeof(l_img_sheet) * NB_IMG_SHEET);
    add_robots(lst);
    lst[1].image = create_sprite_sheet("images/Game_over-Sheet.png",
        580, 256, 'g');
    set_animations_settings(&lst[1], 18, 5, 4);
    lst[1].layer = 9;
    initialise_impact(lst);
    initialise_explosion(lst);
    return lst;
}
