/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** help.c
*/

#include "lib.h"
#include "source.h"
#include <unistd.h>

int help(void)
{
    char *str_help = "USAGE\n"
    "     ./navy [first_player_pid] navy_positions\n\n"
    "DESCRIPTION\n"
    "     first_player_pid:  only for the 2nd player."
    " pid of the first player.\n"
    "     navy_positions:"
    "  file representing the positions of the ships.";

    if (write(1, str_help, my_strlen(str_help)) == -1)
        return (84);
    return (0);
}