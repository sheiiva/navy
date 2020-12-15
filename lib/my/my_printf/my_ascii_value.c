/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_ascii_value.c
*/

#include "lib.h"
#include <stdarg.h>

void my_sp_putchar(unsigned char c)
{
    my_putchar('\\');
    if (c < 32) {
        my_putchar('0');
        if (c <= 7)
            my_putchar('0');
    }
    my_put_nbr_base(8, (int)c);
}

void my_ascii_value(va_list ap)
{
    unsigned char *str = va_arg(ap, unsigned char *);
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] >= 32 && str[a] <= 127)
            my_putchar(str[a]);
        else
            my_sp_putchar(str[a]);
        a++;
    }
}