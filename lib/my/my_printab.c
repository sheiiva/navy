/*
** EPITECH PROJECT, 2019
** LIBRARY
** File description:
** my_printab.c
*/

#include <stddef.h>
#include "lib.h"

void my_printab(char **tab)
{
    size_t i = 0;

    if (!tab)
        return ;
    while (tab[i][0] == '\0')
            ++i;
    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        if (tab[i][0] != '\0')
            my_putstr("\n");
        ++i;
    }
}