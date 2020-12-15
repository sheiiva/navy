/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_realloc.c
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    size_t j = 0;

    if ((tab) && (tab != NULL)) {
        while (j < 10)
            free(tab[j++]);
        free(tab);
    }
}