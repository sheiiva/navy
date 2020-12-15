/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** attack.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "global.h"
#include "struct.h"
#include "my_printf.h"
#include "source.h"
#include "macro.h"

char *get_attack(char *player_inputs)
{
    int size = 1;

    if ((player_inputs = malloc(sizeof(char) * 2)) == NULL)
        return (NULL);
    player_inputs[0] = '\0';
    player_inputs[1] = '\0';
    read(0, (player_inputs + (size - 1)), 1);
    while (player_inputs[size - 1] != '\n') {
        if ((player_inputs = my_realloc(player_inputs, '\0')) == NULL)
            return (NULL);
        size = size + 1;
        read(0, (player_inputs + (size - 1)), 1);
    }
    player_inputs[size - 1] = '\0';
    if (check_inputs(player_inputs) == -1) {
        free(player_inputs);
        my_printf("wrong position\nattack: ");
        if ((player_inputs = get_attack(player_inputs)) == NULL)
            return (NULL);
    }
    return (player_inputs);
}

char *lets_attack(pid_t pid)
{
    char *player_inputs = NULL;

    my_printf("attack:\t");
    if ((player_inputs = get_attack(player_inputs)) == NULL)
        return (NULL);
    data_pinger(pid, (player_inputs[0] - '@'),
        (player_inputs[1] - '0'));
    my_printf("%c%c: ", player_inputs[0], player_inputs[1]);
    return (player_inputs);
}

char get_result(void)
{
    char result = 0;

    sign_counter();
    if (elem[1] == 9) {
        result = 'o';
        my_printf("missed\n\n");
    } else if (elem[1] == 10) {
        result = 'x';
        my_printf("hit\n\n");
    }
    return (result);
}

maps_t *attack_enemy(maps_t *map, pid_t pid)
{
    char *player_inputs = NULL;
    char result = 0;
    int x = 0;
    int y = 0;

    if ((player_inputs = lets_attack(pid)) == NULL)
        return (NULL);
    if ((result = get_result()) == 0)
        return (NULL);
    x = (player_inputs[0] - '@') * 2;
    y = player_inputs[1] - '0' + 1;
    map->map_enemy[y][x] = result;
    free(player_inputs);
    return (map);
}