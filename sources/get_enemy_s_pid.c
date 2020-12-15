/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** get_enemy_s_pid.c
*/

#include "lib.h"
#include "global.h"

int get_enemy_s_pid(int ac, char **av)
{
    int pid = 0;

    if (ac == 3) {
        pid = my_getnbr(av[1]);
    } else {
        pid = elem[1];
    }
    return (pid);
}