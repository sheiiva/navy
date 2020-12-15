/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** critest_parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "proto_tests.h"
#include "cri_func.h"

Test(parser, open_simple_path)
{
    int *test = parser("./files/pos1");

    cr_assert_not_null(test);
}

Test(parser, open_errored_path)
{
    int *test = parser("./files/pas1");

    cr_assert_null(test);
}

Test(parser, verif_int_array, .init = redirect_all_std)
{
    int *tested = parser("./files/pos1");
    size_t i = 0;

    while (i != 20) {
        my_printf("%d", tested[i]);
        ++i;
    }
    my_putchar('\n');
    cr_assert_stdout_eq_str("23444381834568652161\n");
    free(tested);
}

Test(parser, verif_NULL_path, .init = redirect_all_std)
{
    int *tested = parser(NULL);

    cr_assert_null(tested);
}