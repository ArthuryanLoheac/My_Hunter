/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** Write an recursive function that returns
** the first argument raised to the power p
*/
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0 || nb > 2147483647 || p > 2147483647)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
