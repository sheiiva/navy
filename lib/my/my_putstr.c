/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "lib.h"

void my_putstr(char const *str)
{
    if (!str)
        return ;
    write(1, str, my_strlen(str));
}