/*
** EPITECH PROJECT, 2023
** fs_get_number_from_first_line
** File description:
** fs_get_number_from_first_line
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0 || nb > 2147483647 || p > 2147483647)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}

static int caluclate_len(char *buffer)
{
    int len = 0;
    int starting = 0;

    for (int i = 0; i < 12; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            starting = 1;
        }
        if (starting == 0) {
            len++;
        }
    }
    return len;
}

static int is_superior_max(char *buffer)
{
    char max_int[] = "2147483647";

    for (int i = 0; i < 10; i++) {
        if (buffer[i] > max_int[i]) {
            return -1;
        }
    }
    return 0;
}

static int calculate_nbr(int len, char *buffer)
{
    int value = 0;

    if (len > 10 || len == 0) {
        return -1;
    }
    if (len == 10) {
        if (is_superior_max(buffer) == -1) {
            return -1;
        }
    }
    for (int i = 0; i < len; i++) {
        value += (buffer[i] - '0') * my_compute_power_rec(10, (len - i - 1));
    }
    return value;
}

int fs_get_number_from_first_line(char const *filepath)
{
    int fichier = open(filepath, O_RDONLY);
    char buffer[12];
    int value_read = 0;
    int len = 0;
    int value = -1;

    if (fichier != -1) {
        value_read = read(fichier, buffer, 11);
        if (value_read != -1) {
            len = caluclate_len(buffer);
            value = calculate_nbr(len, buffer);
        }
    }
    close(fichier);
    return value;
}
