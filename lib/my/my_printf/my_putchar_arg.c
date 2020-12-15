/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_put_char_arg.c
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar_arg(va_list ap)
{
    char c = (char)va_arg(ap, int);

    write(1, &c, 1);
}