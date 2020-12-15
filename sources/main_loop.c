/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** main_loop.c
*/

#include <unistd.h>
#include "lib.h"
#include "struct.h"
#include "source.h"
#include "my_printf.h"

int check_x_in_map(char **map)
{
    int i = 2;
    int j = 2;
    int count = 0;

    while (map[j] != NULL) {
        while (map[j][i] != '\0') {
            if (map[j][i] == 'x')
                count = count + 1;
            i = i + 1;
        }
        i = 2;
        j = j + 1;
    }
    if (count == 14)
        return (0);
    else
        return (1);
}

int check_end(maps_t *maps)
{
    if (check_x_in_map(maps->map_player) == 0) {
        my_printf("Enemy won\n");
        return (0);
    } else if (check_x_in_map(maps->map_enemy) == 0) {
        my_printf("I won\n");
        return (0);
    }
    return (1);
}

void print_game(maps_t *maps)
{
    my_printf("my positions:\n");
    my_printab(maps->map_player);
    my_printf("\nenemy's positions:\n");
    my_printab(maps->map_enemy);
    my_printf("\n");
}

maps_t *main_loop(maps_t *maps, int player)
{
    while (1) {
        if (player == 1) {
            print_game(maps);
            if (check_end(maps) == 0)
                return (maps);
            maps = attack_enemy(maps, maps->pid_ennemy);
            if (check_end(maps) == 0)
                return (maps);
            maps = wait_ennemy(maps, maps->pid_ennemy);
        } else if (player == 2) {
            print_game(maps);
            if (check_end(maps) == 0)
                return (maps);
            maps = wait_ennemy(maps, maps->pid_ennemy);
            if (check_end(maps) == 0)
                return (maps);
            maps = attack_enemy(maps, maps->pid_ennemy);
        }
    }
    return (maps);
}