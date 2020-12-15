/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** ping_counter.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "my_signal.h"
#include "global.h"
#include "macro.h"

void handler(int signum, _UNUSED_ siginfo_t *loi, _UNUSED_ void *sabel)
{
    static size_t last = 1;

    if (elem == NULL)
        return;
    if (signum == SIGUSR1) {
        if (last == 2)
            elem[2] = 1;
        ++elem[0];
        last = 1;
    }
    if (signum == SIGUSR2) {
        ++elem[1];
        last = 2;
    }
}

int sign_counter(void)
{
    struct sigaction sa;

    elem[0] = 0;
    elem[1] = 0;
    elem[2] = 0;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &handler;
    if (sigaction(10, &sa, NULL) == -1)
        return (84);
    if (sigaction(12, &sa, NULL) == -1)
        return (84);
    while (elem[2] == 0);
    return (0);
}