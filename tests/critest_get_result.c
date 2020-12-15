/*
** EPITECH PROJECT, 2019
** attack.c // get_result()
** File description:
** Critests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "global.h"
#include "proto_tests.h"

void init_global_elem(void)
{
    elem = malloc(sizeof(int) * 3);
    elem[0] = 0;
    elem[1] = 0;
    elem[2] = 0;
}

Test(get_result, with_hit_ignal, .init = init_global_elem)
{
    data_pinger(getpid(), 0, 10);
    cr_assert_eq(get_result, 'x');
    free(elem);
}

Test(get_result, with_missed_signal, .init = init_global_elem)
{
    data_pinger(getpid(), 0, 9);
    cr_assert_eq(get_result, 'o');
    free(elem);
}

Test(get_result, with_other_signal, .init = init_global_elem)
{
    data_pinger(getpid(), 0, 2);
    cr_assert_eq(get_result, 0);
    free(elem);
}