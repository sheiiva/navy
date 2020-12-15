/*
** EPITECH PROJECT, 2018
** critest
** File description:
** TEST !
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

void dat_test(int sig, _UNUSED_ siginfo_t *info, _UNUSED_ void *context)
{
    static int i = 0;
    static int j = 0;

    if (sig == 10) {
        my_printf("sig = 10\nloop :: i = %d\n", i);
        i = i + 1;
    }
    if (sig == 12) {
        my_printf("sig = 12\nloop :: j = %d\n", j);
        j = j + 1;
    }

}

Test(data_pinger, with_7_3 , .init = redirect_all_std)
{
    struct sigaction sa;
    char *result = "sig = 10\nloop :: i = 0\nsig = 10\nloop :: i = 1\n"
    "sig = 10\nloop :: i = 2\nsig = 10\nloop :: i = 3\nsig = 10\n"
    "loop :: i = 4\nsig = 10\nloop :: i = 5\nsig = 10\nloop :: i = 6\n"
    "sig = 12\nloop :: j = 0\nsig = 12\nloop :: j = 1\nsig = 12\n"
    "loop :: j = 2\nsig = 10\nloop :: i = 7\n";
    
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = dat_test;
    sigaction(10, &sa, NULL);
    sigaction(12, &sa, NULL);
    data_pinger(getpid(), 7, 3);
    cr_assert_stdout_eq_str(result);
}