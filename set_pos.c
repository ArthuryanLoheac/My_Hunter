/*
** EPITECH PROJECT, 2023
** set_pos
** File description:
** set_pos
*/
#include "structs.h"
#include "my.h"

void set_pos(l_img *img, int x, int y)
{
    img->image.position.y = y;
    img->image.position.x = x;
}

void set_pos_sheet(l_img_sheet *img, int x, int y)
{
    img->image.position.y = y;
    img->image.position.x = x;
}
