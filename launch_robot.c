/*
** EPITECH PROJECT, 2023
** lauch_from_x_y
** File description:
** lauch_from_x_y
*/
#include "structs.h"
#include <stdlib.h>

void launch_robot(img_sheet *robot)
{
    int direction = 1;

    robot->position.x = rand() % (1920 - robot->width / 2) + robot->width / 2;
    if (robot->position.x >= 1920 / 2) {
        direction = -1;
    }
    robot->position.y = 1080;
    robot->speed_a = ((rand() % 700) + 100) * direction;
    robot->speed_b = (rand() % 500) + 600;
    robot->time_to_wait = -1;
    robot->in_game = 1;
}
