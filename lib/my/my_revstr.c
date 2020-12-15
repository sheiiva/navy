/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_revstr.c
*/

#include <stddef.h>

char *my_revstr(char *str)
{
    int i = 0;
    int e = 0;
    char cntnr;

    if (!str)
        return (NULL);
    while (str[i] != '\0')
        i = i + 1;
    i = i - 1;
    while (e < i) {
        cntnr = str[e];
        str[e] = str[i];
        str[i] = cntnr;
        i = i - 1;
        e = e + 1;
    }
    return (str);
}
