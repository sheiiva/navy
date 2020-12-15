/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** connect_players.c
*/

#include <stdlib.h>
#include "my_signal.h"
#include "macro.h"
#include "my_printf.h"
#include "global.h"
#include "lib.h"

void ping_ennemy(_UNUSED_ int sig, siginfo_t *info, _UNUSED_ void *context)
{
    kill(info->si_pid, 12);
    elem[1] = info->si_pid;
    my_printf("enemy connected\n\n");
    elem[2] = 0;
}

void who_sig_me(_UNUSED_ int sig, _UNUSED_ siginfo_t *info,
    _UNUSED_ void *context)
{
    my_printf("successfully connected\n\n");
    elem[2] = 0;
}

int ping_me(int ac, char **av)
{
    struct sigaction sa;
    pid_t pid = getpid();

    elem[2] = 1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (ac == 2) {
        sa.sa_sigaction = ping_ennemy;
        my_printf("my_pid:\t%d\nwaiting for enemy connection...\n\n\0", pid);
        if (sigaction(10, &sa, NULL) == -1)
            return (-1);
    } else {
        sa.sa_sigaction = who_sig_me;
        my_printf("my_pid:\t%d\n\0", pid);
        if (sigaction(12, &sa, NULL) == -1)
            return (-1);
        kill(my_getnbr(av[1]), 10);
    }
    while (elem[2]);
    return (elem[1]);
}