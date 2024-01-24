/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display the number in parameter
*/
#include "my.h"
#include <unistd.h>

static int my_isneg_print(int n)
{
    if (n < 0) {
        my_putchar('-');
        return 1;
    } else {
        return 0;
    }
}

static int divide_and_remove(int nb, int divisible,
    int *debut, int *nb_char_print)
{
    int value;

    value = nb / divisible;
    if (value < 0) {
        value = -value;
    }
    if ((value != 0 && *debut == 8) || divisible == 1) {
        *debut = divisible;
    }
    if (*debut != 8) {
        my_putchar(value + '0');
        *nb_char_print += 1;
    }
    return value;
}

int my_put_nbr(int nb)
{
    int debut;
    int nb_char_print = 0;

    debut = 8;
    nb_char_print += my_isneg_print(nb);
    for (int i = 1000000000; i >= 1; i = i / 10) {
        if (nb < 0) {
            nb = nb + (divide_and_remove(nb, i, &debut, &nb_char_print) * i);
        } else {
            nb = nb - (divide_and_remove(nb, i, &debut, &nb_char_print) * i);
        }
    }
    return nb_char_print;
}
