/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** data_pinger.c
*/

#include "my_signal.h"

int data_pinger(pid_t pid, int usr_one, int usr_two)
{
    int i = 0;
    int j = 0;

    while (i++ < usr_one) {
        kill(pid, 10);
        usleep(10000);
    }
    while (j++ < usr_two) {
        kill(pid, 12);
        usleep(10000);
    }
    kill(pid, 10);
    return (0);
}