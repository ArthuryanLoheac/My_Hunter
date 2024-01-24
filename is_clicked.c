/*
** EPITECH PROJECT, 2023
** is_clicked
** File description:
** is_clicked
*/
#include "structs.h"

int is_clicked(int mouse_x, int mouse_y, l_img *img)
{
    if (mouse_x >= img->image.position.x &&
        mouse_x <= (img->image.position.x + img->image.width) &&
        mouse_y >= img->image.position.y &&
        mouse_y <= (img->image.position.y + img->image.height)) {
        return 1;
    }
    return 0;
}

int is_clicked_sheet(int mouse_x, int mouse_y, l_img_sheet *img)
{
    if (mouse_x >= img->image.position.x &&
        mouse_x <= (img->image.position.x + img->image.width) &&
        mouse_y >= img->image.position.y &&
        mouse_y <= (img->image.position.y + img->image.height)) {
        return 1;
    }
    return 0;
}
