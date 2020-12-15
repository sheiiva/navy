/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_realloc.c
*/

#include "lib.h"
#include <stdlib.h>

char *my_realloc(char *str, char c)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (!tmp)
        return (NULL);
    while (str[i] != '\0') {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = c;
    tmp[i + 1] = '\0';
    free(str);
    return (tmp);
}