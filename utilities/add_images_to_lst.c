/*
** EPITECH PROJECT, 2023
** add_images_to_lst
** File description:
** add_images_to_lst
*/
#include <stdlib.h>
#include "my_hunter.h"
#include "constants.h"

static void create_button(int nb, l_img *lst)
{
    lst[nb].layer = 10;
    lst[nb].image.position.x = -10000;
    lst[nb].image.position.y = -10000;
    lst[nb].image.clicked = 0;
}

static void add_buttons(l_img *lst)
{
    lst[7].image = create_image("images/Volume.png", 204, 40);
    create_button(7, lst);
    lst[7].image.rect.left = 1020;
    lst[6].image = create_image("images/Right_button.png", 32, 36);
    create_button(6, lst);
    lst[5].image = create_image("images/Left_button.png", 32, 36);
    create_button(5, lst);
    lst[10].image = create_image("images/Volume.png", 204, 40);
    create_button(10, lst);
    lst[10].image.rect.left = 1020;
    lst[9].image = create_image("images/Right_button.png", 32, 36);
    create_button(9, lst);
    lst[8].image = create_image("images/Left_button.png", 32, 36);
    create_button(8, lst);
    lst[4].image = create_image("images/Close_button.png", 52, 52);
    create_button(4, lst);
}

static void add_quit_button(l_img *lst)
{
    lst[11].image = create_image("images/quit_button.png", 256, 68);
    create_button(11, lst);
    lst[39].image = create_image("images/accept.png", 196, 52);
    create_button(39, lst);
    lst[40].image = create_image("images/decline.png", 196, 52);
    create_button(40, lst);
    lst[38].image = create_image("images/Extra_life.png", 320, 408);
    lst[38].layer = 3;
    lst[38].image.position.x = -10000;
    lst[38].image.position.y = -10000;
    lst[43].image = create_image("images/accept.png", 196, 52);
    create_button(43, lst);
    lst[44].image = create_image("images/decline.png", 196, 52);
    create_button(44, lst);
    lst[45].image = create_image("images/freeze_card.png", 320, 408);
    lst[45].layer = 3;
    lst[45].image.position.x = -10000;
    lst[45].image.position.y = -10000;
}

static void add_background(l_img *lst)
{
    sfVector2f factors;

    factors.x = 1.5;
    factors.y = 1.5;
    lst[1].image = create_image("images/background_back.png", 1920, 1080);
    lst[1].layer = 0;
    lst[2].image = create_image("images/background_front.png", 1920, 1080);
    lst[2].layer = 3;
    lst[37].image = create_image("images/life-Sheet.png", 112, 30);
    lst[37].layer = 10;
    lst[37].image.position.x = -10000;
    lst[37].image.position.y = -10000;
    sfSprite_scale(lst[37].image.sprite, factors);
}

static void add_buttons_next(l_img *lst)
{
    sfVector2f factors;
    sfColor col = sfColor_fromRGBA(255, 255, 255, 122);

    factors.x = 1.5;
    factors.y = 1.5;
    lst[12].image = create_image("images/Restart_button.png", 256, 68);
    create_button(12, lst);
    lst[24].image = create_image("images/start_button.png", 256, 68);
    create_button(24, lst);
    lst[41].image = create_image("images/freeze_back.png", 1920, 1080);
    create_button(41, lst);
    lst[42].image = create_image("images/freeze-Shee.png", 70, 70);
    create_button(42, lst);
    sfSprite_scale(lst[42].image.sprite, factors);
    sfSprite_setColor(lst[41].image.sprite, col);
    lst[41].layer = 9;
}

static void add_numbers_and_streak(l_img *lst)
{
    sfVector2f factors;

    factors.x = 0.5;
    factors.y = 0.5;
    for (int i = 13; i < 24; i++) {
        lst[i].image = create_image("images/font.png", 28, 48);
        lst[i].layer = 12;
        lst[i].image.position.x = -10000;
        lst[i].image.position.y = -10000;
        lst[i + 13].image = create_image("images/font.png", 28, 48);
        lst[i + 13].layer = 12;
        lst[i + 13].image.position.x = -10000;
        lst[i + 13].image.position.y = -10000;
        sfSprite_scale(lst[i + 13].image.sprite, factors);
    }
    lst[25].image = create_image("images/streak.png", 112, 30);
    create_button(25, lst);
    factors.x = 1.5;
    factors.y = 1.5;
    sfSprite_scale(lst[25].image.sprite, factors);
}

l_img *add_images_to_lst(void)
{
    l_img *lst;

    lst = malloc(sizeof(l_img) * NB_IMG);
    lst[0].image = create_image("images/crosshair-Sheet.png", 62, 62);
    lst[0].layer = 15;
    add_background(lst);
    lst[3].image = create_image("images/options_menu_back.png", 512, 296);
    lst[3].layer = 10;
    lst[3].image.position.x = -10000;
    lst[3].image.position.y = -10000;
    add_buttons(lst);
    add_quit_button(lst);
    add_buttons_next(lst);
    add_numbers_and_streak(lst);
    return lst;
}
