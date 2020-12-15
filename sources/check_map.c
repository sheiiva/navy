/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** check_map.c
*/

#include "lib.h"
#include <unistd.h>

int final_check(int *num)
{
    int expected[9] = {1, 3, 4, 5, 6, 1, 1, 1, -1};
    size_t i = 0;

    while (expected[i] != -1) {
        if (expected[i] != num[i])
            return (84);
        i = i + 1;
    }
    return (0);
}

int count_number(char **map)
{
    int num[9] = {0, 0, 0, 0, 0, 0, 0, 0, -1};
    size_t i = 0;
    size_t j = 2;

    while (map[j] != NULL) {
        while (map[j][i] != '\0') {
            if (my_isnum(map[j][i]) == 1
                && (map[j][i] > '0' && map[j][i] <= '9'))
                num[map[j][i] - '0' - 1]++;
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    if (final_check(num) == 84)
        return (84);
    return (0);
}

int check_nb_ships(char **map)
{
    size_t i = 2;
    size_t j = 2;

    if (map == NULL)
        return (84);
    while (map[j] != NULL) {
        while (map[j][i] != '\0') {
            if (my_isnum(map[j][i]) == 0
                && map[j][i] != '.'
                && map[j][i] != ' ') {
                return (84);
            }
            i = i + 1;
        }
        i = 2;
        j = j + 1;
    }
    if (count_number(map) == 84)
        return (84);
    return (0);
}