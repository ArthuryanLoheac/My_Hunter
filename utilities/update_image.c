/*
** EPITECH PROJECT, 2023
** update_image
** File description:
** update_image
*/
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "structs.h"
#include "my_hunter.h"
#include "my.h"

static void move_rect(img_sheet *image)
{
    image->rect.left += image->width;
    image->status_image += 1;
    if (image->rect.left >= (image->width) * image->nb_images_width) {
        image->rect.left = 0;
        image->rect.top += image->height;
    }
    if (image->status_image >= image->nb_images) {
        image->rect.left = 0;
        image->rect.top = 0;
        image->status_image = 0;
        if (image->type == 'i' || image->type == 'e') {
            image->status_image = 0;
            image->position.x = 10000;
            image->position.y = 10000;
        }
    }
}

void update_image(img *image)
{
    sfSprite_setPosition(image->sprite, image->position);
}

static void update_clock(img_sheet *image, l_img *lst_image)
{
    image->time = sfClock_getElapsedTime(image->clock);
    image->seconds = image->time.microseconds / 1000000.0;
    if (image->seconds > image->animation_time) {
        move_rect(image);
        if (lst_image[41].image.position.x != 0) {
            image->time_to_wait -= image->seconds;
        }
        sfClock_restart(image->clock);
    }
}

void update_image_sheet(img_sheet *image, l_img *lst_image)
{
    if (lst_image[3].image.position.x == -10000 &&
        lst_image[38].image.position.x == -10000) {
        update_clock(image, lst_image);
    } else {
        sfClock_restart(image->clock);
    }
    if (image->time_to_wait <= 0 && image->in_game == 0 &&
        image->type == 'r') {
        launch_robot(image);
    }
    sfSprite_setPosition(image->sprite, image->position);
}
