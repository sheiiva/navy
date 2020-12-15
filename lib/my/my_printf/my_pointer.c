/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_pointer.c
*/

#include "lib.h"
#include <stdlib.h>
#include <stdarg.h>

char my_upper_than_ten(int a)
{
    char str[6] = "abcdef";

    if (a > 9)
        return (str[a - 10]);
    else
        return (a + '0');
    return ('0');
}

void my_hexa_long_int(unsigned long int value)
{
    char *rest = malloc(sizeof(char) * 1);

    rest[0] = '\0';
    while (value != 0) {
        rest = my_realloc(rest, my_upper_than_ten(value % 16));
        value = value / 16;
    }
    rest = my_revstr(rest);
    my_putstr(rest);
    free(rest);
}

void my_pointer(va_list ap)
{
    unsigned long int value = (unsigned long int)va_arg(ap, void *);
    char const *str = "Ox";

    my_putstr(str);
    my_hexa_long_int(value);
}