/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** critest_count_number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "cri_func.h"
#include "macro.h"
#include "proto_tests.h"

char **good_map_maker(void)
{
    char **map = malloc(sizeof(char *) * 11);

    if (map == NULL)
        return (NULL);
    map[0] = my_strdup(" |A B C D E F G H\0");
    map[1] = my_strdup("-+---------------\0");
    map[2] = my_strdup("1|. 2 2 . . . . 5\0");
    map[3] = my_strdup("2|. . . . . . . 5\0");
    map[4] = my_strdup("3|. . 3 . . . . 5\0");
    map[5] = my_strdup("4|. . 3 . . . . 5\0");
    map[6] = my_strdup("5|. . 3 . . . . 5\0");
    map[7] = my_strdup("6|. . . . . . . .\0");
    map[8] = my_strdup("7|. . 4 4 4 4 . .\0");
    map[9] = my_strdup("8|. . . . . . . .\0");
    map[10] = NULL;
    return (map);
}

char **bad_map_maker(void)
{
    char **map = malloc(sizeof(char *) * 11);

    if (map == NULL)
        return (NULL);
    map[0] = my_strdup(" |A B C D E F G H\0");
    map[1] = my_strdup("-+---------------\0");
    map[2] = my_strdup("1|. 2 2 . . . . 5\0");
    map[3] = my_strdup("2|. . . . . . . 5\0");
    map[4] = my_strdup("3|. . 3 . . . . 5\0");
    map[5] = my_strdup("4|. . 3 . . . . 5\0");
    map[6] = my_strdup("5|. 4 4 4 4 . . 5\0");
    map[7] = my_strdup("6|. . . . . . . .\0");
    map[8] = my_strdup("7|. . . . . . . .\0");
    map[9] = my_strdup("8|. . . . . . . .\0");
    map[10] = NULL;
    return (map);
}

Test(count_number, good_map)
{
    char **good_map = good_map_maker();
    int toy = count_number(good_map);

    cr_assert_eq(toy, 0);
}

Test(count_number, bad_map)
{
    char **bad_map = bad_map_maker();
    int toy = count_number(bad_map);

    cr_assert_eq(toy, 84);
}

Test(check_nb_ships, good_map)
{
    char **good_map = good_map_maker();
    int toy = check_nb_ships(good_map);

    cr_assert_eq(toy, 0);
}


Test(check_nb_ships, bad_map)
{
    char **bad_map = bad_map_maker();
    int toy = check_nb_ships(bad_map);

    cr_assert_eq(toy, 84);
}