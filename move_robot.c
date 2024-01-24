/*
** EPITECH PROJECT, 2023
** move_robot
** File description:
** move_robot
*/
#include "structs.h"

void move_robot(img_sheet *robot, float delta_time)
{
    if ((robot->in_game == 1 && robot->type == 'r')
        || robot->type == 'e') {
        robot->position.x += (robot->speed_a * delta_time);
        robot->position.y -= (robot->speed_b * delta_time);
        robot->speed_b -= (600 * delta_time);
    }
}
