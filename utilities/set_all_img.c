/*
** EPITECH PROJECT, 2023
** set_all_img
** File description:
** set_all_img
*/
#include "structs.h"
#include "my_hunter.h"

all_images set_all_img(void)
{
    l_img_sheet *lst_sheet = add_images_sheet_to_lst();
    l_img *lst_img = add_images_to_lst();
    all_images all;

    all.l_sheet = lst_sheet;
    all.l_img = lst_img;
    return all;
}
