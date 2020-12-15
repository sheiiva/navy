/*
** EPITECH PROJECT, 2019
** SOURCES
** File description:
** map_maker.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "source.h"
#include "struct.h"
#include "lib.h"

char **make_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 11);

    if (map == NULL)
        return (NULL);
    map[0] = my_strdup(" |A B C D E F G H\0");
    map[1] = my_strdup("-+---------------\0");
    map[2] = my_strdup("1|. . . . . . . .\0");
    map[3] = my_strdup("2|. . . . . . . .\0");
    map[4] = my_strdup("3|. . . . . . . .\0");
    map[5] = my_strdup("4|. . . . . . . .\0");
    map[6] = my_strdup("5|. . . . . . . .\0");
    map[7] = my_strdup("6|. . . . . . . .\0");
    map[8] = my_strdup("7|. . . . . . . .\0");
    map[9] = my_strdup("8|. . . . . . . .\0");
    map[10] = NULL;
    return (map);
}

void do_the_struct(coord_t *coord_struct, size_t ofst, int *coord)
{
    coord_struct->beg_x = coord[1 + ofst];
    coord_struct->end_x = coord[3 + ofst];
    coord_struct->beg_y = coord[2 + ofst];
    coord_struct->end_y = coord[4 + ofst];
}

void fill_boat(int *coord, char ***map)
{
    coord_t map_coord = {0, 0, 0, 0};
    size_t i = 0;
    size_t ofst = 0;
    char c = -1;

    while (i != 4) {
        c = coord[0 + ofst] + '0';
        do_the_struct(&map_coord, ofst, coord);
        while (map_coord.end_x > map_coord.beg_x) {
            map[0][map_coord.beg_y + 1][map_coord.beg_x * 2] = c;
            map_coord.beg_x += 1;
        }
        while (map_coord.end_y > map_coord.beg_y) {
            map[0][map_coord.beg_y + 1][map_coord.beg_x * 2] = c;
            map_coord.beg_y += 1;
        }
        ofst += 5;
        ++i;
    }
}

char **map_maker(int *coord)
{
    char **map = make_empty_map();
    size_t i = 0;
    size_t ofst = 0;
    char c = -1;

    if (map == NULL || coord == NULL)
        return (NULL);
    while (i != 4) {
        c = coord[0 + ofst] + '0';
        map[coord[2 + ofst] + 1][coord[1 + ofst] * 2] = c;
        map[coord[4 + ofst] + 1][coord[3 + ofst] * 2] = c;
        ofst += 5;
        ++i;
    }
    fill_boat(coord, &map);
    if (check_nb_ships(map) == 84)
        return (NULL);
    return (map);
}