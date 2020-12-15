/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** wait.c
*/

#include <unistd.h>
#include "struct.h"
#include "source.h"
#include "global.h"
#include "my_printf.h"

int check_hit_or_not(char **map)
{
    if (map[elem[1] + 1][(elem[0] - 1) * 2] != '.'
        && map[elem[1] + 1][(elem[0] - 1) * 2] != ' '
        && map[elem[1] + 1][(elem[0] - 1) * 2] != 'o')
            return (1);
    return (0);
}

char get_attacked(pid_t pid, char **map)
{
    int hit = -1;
    char result = 0;

    sign_counter();
    my_printf("%c%d: ", (elem[0] + '@' - 1), elem[1]);
    hit = check_hit_or_not(map);
    if (hit == 0) {
        result = 'o';
        my_printf("missed\n\n");
        data_pinger(pid, 0, 9);
    } else if (hit == 1) {
        result = 'x';
        my_printf("hit\n\n");
        data_pinger(pid, 0, 10);
    }
    return (result);
}

maps_t *wait_ennemy(maps_t *maps, int pid)
{
    char result = 0;

    my_printf("waiting for enemy's attack...\n");
    result = get_attacked(pid, maps->map_player);
    maps->map_player[elem[1] + 1][(elem[0] - 1) * 2] = result;
    return (maps);
}