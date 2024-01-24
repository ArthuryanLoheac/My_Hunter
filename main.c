/*
** EPITECH PROJECT, 2023
** initiation graphic
** File description:
** initiation graphic
*/
#include "structs.h"
#include "my_hunter.h"
#include <time.h>
#include <stdlib.h>
#include "constants.h"
#include "my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

static void initialise(sfMusic **l_music, all_images images)
{
    sfMusic_play(l_music[0]);
    set_pos_sheet(&images.l_sheet[1], 10000, 10000);
    set_pos(&images.l_img[11], (1920 / 2) -
        images.l_img[11].image.width / 2, (1080 / 2));
    set_pos(&images.l_img[24], (1920 / 2) -
        images.l_img[24].image.width / 2, (1080 / 2) -
        images.l_img[24].image.height);
}

static game create_game(sfRenderWindow *window)
{
    game game;

    game.points = 0;
    game.streak = 0;
    game.pv = 1;
    game.palier = 0;
    game.game_over = 0;
    game.time_freeze = 5;
    game.freeze = 5;
    game.pause = 0;
    game.pause_time = 0;
    game.game_over = 0;
    game.score_max =
        fs_get_number_from_first_line("score_max/score_max");
    game.window = window;
    game.start = 0;
    game.clock_game = sfClock_create();
    return game;
}

static void print_menu(game *game, all_images images)
{
    if (game->start == 0 && images.l_img[3].image.position.x == -10000) {
        set_pos(&images.l_img[11], (1920 / 2) -
            images.l_img[11].image.width / 2, (1080 / 2));
        set_pos(&images.l_img[24], (1920 / 2) -
            images.l_img[24].image.width / 2, (1080 / 2) -
            images.l_img[24].image.height);
    } else {
        set_pos(&images.l_img[24], -10000, -10000);
    }
}

static void game_loop(sfRenderWindow *window)
{
    game game = create_game(window);
    all_sounds all_sound = create_sounds();
    all_images images = set_all_img();

    initialise(all_sound.l_music, images);
    while (sfRenderWindow_isOpen(game.window)) {
        check_go_restart(&images, &game, all_sound);
        print_menu(&game, images);
        update_music(all_sound.l_music, images.l_img, all_sound.l_sounds);
        sfRenderWindow_clear(window, sfColor_fromRGBA(0, 0, 0, 255));
        draw_all_images(images.l_sheet, images.l_img, game.window);
        sfRenderWindow_display(game.window);
        draw_points(&game, images.l_img, images, &all_sound);
    }
    destroy_all(images, all_sound.l_music,
        game.clock_game, all_sound.l_sounds);
}

static void start_game(void)
{
    sfRenderWindow *window = create_window(1920, 1080);

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 165);
    game_loop(window);
    sfRenderWindow_destroy(window);
}

static int check_help(char **argv)
{
    if (my_strlen(argv[1]) == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            print_help();
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (check_help(argv) == 1) {
            return 0;
        } else {
            return 84;
        }
    }
    if (argc == 1) {
        start_game();
        return 0;
    } else {
        return 84;
    }
}
