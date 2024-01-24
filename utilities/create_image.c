/*
** EPITECH PROJECT, 2023
** create_image
** File description:
** create_image
*/
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "structs.h"
#include "my_hunter.h"

static sfIntRect set_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

img create_image(char *path, int width, int height)
{
    img image;

    image.texture = sfTexture_createFromFile(path, NULL);
    image.sprite = sfSprite_create();
    image.width = width;
    image.height = height;
    image.position.x = 0;
    image.position.y = 0;
    image.rect = set_rect(0, 0, width, height);
    return image;
}

img_sheet create_sprite_sheet(char *path, int width,
    int height, char c)
{
    img_sheet image;

    image.clock = sfClock_create();
    image.rect = set_rect(0, 0, width, height);
    image.texture = sfTexture_createFromFile(path, NULL);
    image.sprite = sfSprite_create();
    image.animation_time = 1.;
    image.position.x = 0;
    image.position.y = 0;
    image.width = width;
    image.height = height;
    image.type = c;
    return image;
}
