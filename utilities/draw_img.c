/*
** EPITECH PROJECT, 2023
** draw_img
** File description:
** draw_img
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "structs.h"
#include "my_hunter.h"
#include "constants.h"

static void draw_img(img *image, sfRenderWindow *window)
{
    update_image(image);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

static void draw_img_sheet(img_sheet *image,
    sfRenderWindow *window, l_img *lst_image)
{
    update_image_sheet(image, lst_image);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

static void draw_if_in_layer(int i, int j, l_img *lst_img,
    sfRenderWindow *window)
{
    if (lst_img[j].layer == i) {
        draw_img(&lst_img[j].image, window);
    }
}

static void draw_if_in_layer_sheet(int value[2],
    l_img_sheet *lst_sheet, sfRenderWindow *window, l_img *lst_img)
{
    if (lst_sheet[value[0]].layer == value[1]) {
        draw_img_sheet(&lst_sheet[value[0]].image, window, lst_img);
    }
}

void draw_all_images(l_img_sheet *lst_sheet,
    l_img *lst_img, sfRenderWindow *window)
{
    int values[2];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < NB_IMG; j++) {
            draw_if_in_layer(i, j, lst_img, window);
        }
        for (int j = 1; j < NB_IMG_SHEET; j++) {
            values[0] = j;
            values[1] = i;
            draw_if_in_layer_sheet(values, lst_sheet, window, lst_img);
        }
    }
}
