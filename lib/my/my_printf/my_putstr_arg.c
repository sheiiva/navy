/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_putstr_arg.c
*/

#include "lib.h"
#include <stdarg.h>

void my_putstr_arg(va_list ap)
{
    char *str = va_arg(ap, char *);
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}