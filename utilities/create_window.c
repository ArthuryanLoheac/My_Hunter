/*
** EPITECH PROJECT, 2023
** create_window
** File description:
** create_window
*/
#include <SFML/Graphics/RenderWindow.h>

sfRenderWindow* create_window(int width, int height)
{
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, "My_Hunter", sfClose, NULL);
}
