/*
** EPITECH PROJECT, 2023
** print_help
** File description:
** print_help
*/
#include <unistd.h>

void print_help(void)
{
    write(1, "\n ------ WELCOME TO MY HUNTER ------ \n", 39);
    write(1, "The goal of this game is simple: drones jump onto ", 51);
    write(1, "the screen and you have to kill them by shooting them.\n", 56);
    write(1, "Every 1000 points, a card trade appears on the screen:", 55);
    write(1, " you can choose to accept or refuse.\n", 38);
    write(1, "Each card has its own cost and unique power, ", 46);
    write(1, "described on the card.\n", 24);
    write(1, "You also have a killstreak: if you shoot 5 robots ", 51);
    write(1, "without missing, you earn more points for ", 43);
    write(1, "as long as you have the maximum at the killstreak.\n", 52);
    write(1, "GOOD LUCK !\n\nCONTROLS :\n", 25);
    write(1, " - Shoot : left click\n - Options : ", 36);
    write(1, "echap\n - Freeze power : A\n\nCREDITS :\n - Musics : Antracto / boomopera / TheQLon / ", 83);
    write(1, "Infraction / Deodo / Micrah on Envato.com\n - Arts : Arthuryan Lohéac\n", 71);
}
