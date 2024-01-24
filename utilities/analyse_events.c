/*
** EPITECH PROJECT, 2023
** analyse_events
** File description:
** analyse_events
*/
#include "my_hunter.h"

static void close_window(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static int return_value(int return_val)
{
    if (return_val != 0) {
        return_val = 0;
        return 1;
    }
    return 0;
}

static void mouse_move(sfEvent *event, l_img *lst_image)
{
    if (event->type == sfEvtMouseMoved) {
        manage_mouse_move(event->mouseMove, lst_image);
    }
}

static void click(sfEvent *event, all_images *all,
    all_sounds all_sound, game *game)
{
    if (event->type == sfEvtMouseButtonPressed) {
        manage_click(&event->mouseButton, all, all_sound.l_sounds, game);
    }
}

static void buttons(sfEvent *event, l_img *lst_image,
    game *game, all_sounds all_sound)
{
    if (event->type == sfEvtKeyPressed) {
        manage_buttons(&event->key, lst_image, game, all_sound.l_sounds);
    }
}

int analyse_events(sfEvent *event, all_images *images,
    all_sounds all_sound, game *game)
{
    int return_val = 0;

    while (sfRenderWindow_pollEvent(game->window, event)) {
        close_window(event, game->window);
        mouse_move(event, images->l_img);
        click(event, images, all_sound, game);
        buttons(event, images->l_img, game, all_sound);
        if (event->type == sfEvtMouseButtonReleased) {
            return_val += manage_realeased(&event->mouseButton, images->l_img,
                game, all_sound.l_music);
        }
        if (sfRenderWindow_hasFocus(game->window) == sfFalse) {
            open_options(images->l_img);
        }
    }
    return return_value(return_val);
}
