/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** main.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "lib.h"
#include "my_signal.h"
#include "source.h"
#include "macro.h"
#include "global.h"
#include "struct.h"
#include "my_printf.h"

int navy(int ac, char **av)
{
    maps_t *maps = NULL;
    int *coord = NULL;
    int player = ac - 1;

    if (((maps = malloc(sizeof(*maps))) == NULL)
        || ((coord = parser(av[player])) == NULL)
        || ((maps->map_player = map_maker(coord)) == NULL)
        || ((maps->map_enemy = make_empty_map()) == NULL)
        || ((maps->pid_ennemy = ping_me(ac, av)) == -1)
        || ((maps->pid_ennemy = get_enemy_s_pid(ac, av)) == -1)
        || ((maps = main_loop(maps, player)) == NULL)) {
        free_struct(maps, coord);
        return (84);
    }
    free_struct(maps, coord);
    return (0);
}

int init_global(void)
{
    elem = malloc(sizeof(int) * 3);
    if (elem == NULL)
        return (84);
    elem[0] = 0;
    elem[1] = 0;
    elem[2] = 0;
    return (0);
}

int main(int ac, char **av)
{
    if ((ac > 3) || (ac < 2)) {
        write(2, "Wrong inputs. Please retry with -h.\0", 35);
        return (84);
    } else if ((ac == 2) && (my_strcomp("-h", av[1]))) {
        if (help() == 84)
            return (84);
    } else {
        if ((check_args(ac, av) == 84)
            || (init_global() == 84)
            || (navy(ac, av) == 84)) {
            return (84);
        }
    }
    return (0);
}