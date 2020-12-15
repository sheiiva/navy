/*
** EPITECH PROJECT, 2019
** ping_counter.c // sign_counter()
** File description:
** Critests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include "global.h"
#include "proto_tests.h"

void init_global(void)
{
    elem = malloc(sizeof(int) * 3);
    elem[0] = 0;
    elem[1] = 0;
    elem[2] = 0;
}

Test(sign_counter, with_random_sign, .init = init_global)
{
    data_pinger(getpid(), 0, 10);
    sign_counter();
    cr_assert_eq(elem[0], 1);
    cr_assert_eq(elem[1], 10);
    cr_assert_eq(elem[2], 1);
    free(elem);
}

Test(sign_counter, with_no_sign, .init = init_global)
{
    data_pinger(getpid(), 0, 0);
    sign_counter();
    cr_assert_eq(elem[0], 1);
    cr_assert_eq(elem[1], 0);
    cr_assert_eq(elem[2], 1);
    free(elem);
}