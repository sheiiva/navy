/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** free_struct.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "struct.h"
#include "lib.h"

int free_struct(maps_t *maps, int *coord)
{
    if (maps == NULL)
        return (84);
    if (maps->map_player != NULL)
        free_tab(maps->map_player);
    if (maps->map_enemy != NULL)
        free_tab(maps->map_enemy);
    if (coord != NULL)
        free(coord);
    free(maps);
    return (0);
}