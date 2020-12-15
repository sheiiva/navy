/*
** EPITECH PROJECT, 2019
** map_maker
** File description:
** map_maker
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include "proto_tests.h"
#include "cri_func.h"

Test(map_maker, simple_test, .init = redirect_all_std)
{
    int test[] = {2, 3, 4, 4, 4, 3, 8, 1, 8, 3, 4, 4, 6, 7, 6, 5, 1, 1, 5, 1};
    char **yolo = map_maker(test);
    size_t i = 0;

    while (yolo[i] != NULL) {
        my_putstr(yolo[i]);
        my_putchar('\n');
        ++i;
    }
    cr_assert_stdout_eq_str(" |A B C D E F G H\n"
                            "-+---------------\n"
                            "1|5 5 5 5 5 . . 3\n"
                            "2|. . . . . . . 3\n"
                            "3|. . . . . . . 3\n"
                            "4|. . 2 2 . . . .\n"
                            "5|. . . . . . . .\n"
                            "6|. . . 4 4 4 4 .\n"
                            "7|. . . . . . . .\n"
                            "8|. . . . . . . .\n");
}

Test(map_maker, simple_failed_test, .init = redirect_all_std)
{
    int test[] = {2, 3, 4, 4, 4, 3, 8, 1, 8, 3, 4, 4, 6, 7, 6, 5, 1, 1, 5, 1};
    char **yolo = map_maker(test);
    size_t i = 0;

    while (yolo[i] != NULL) {
        my_putstr(yolo[i]);
        my_putchar('\n');
        ++i;
    }
    cr_assert_stdout_neq_str("lol no");
}

Test(map_maker, null_int_array)
{
    char **yolo = map_maker(NULL);

    cr_assert_null(yolo);
}