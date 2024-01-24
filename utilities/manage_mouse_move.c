/*
** EPITECH PROJECT, 2023
** manage_mouse_move
** File description:
** manage_mouse_move
*/
#include "my_hunter.h"
#include "structs.h"

static void test_if_on(int i, l_img *lst_image, sfMouseMoveEvent event)
{
    if (event.x >= lst_image[i].image.position.x && event.x <=
            lst_image[i].image.position.x + lst_image[i].image.width &&
        event.y >= lst_image[i].image.position.y && event.y <=
            lst_image[i].image.position.y + lst_image[i].image.height &&
        lst_image[i].image.clicked == 0) {
        lst_image[i].image.rect.left = lst_image[i].image.width;
    } else {
        lst_image[i].image.rect.left = 0;
    }
}

void manage_mouse_move(sfMouseMoveEvent event, l_img *lst_image)
{
    lst_image[0].image.position.x = event.x - (lst_image[0].image.width / 2);
    lst_image[0].image.position.y = event.y - (lst_image[0].image.height / 2);
    for (int i = 4; i <= 6; i++) {
        test_if_on(i, lst_image, event);
    }
    test_if_on(8, lst_image, event);
    test_if_on(9, lst_image, event);
    test_if_on(11, lst_image, event);
    test_if_on(12, lst_image, event);
    test_if_on(24, lst_image, event);
    test_if_on(39, lst_image, event);
    test_if_on(40, lst_image, event);
    test_if_on(43, lst_image, event);
    test_if_on(44, lst_image, event);
}
