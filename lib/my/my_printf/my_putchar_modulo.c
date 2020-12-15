/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** put_char_modulo.c
*/

#include "lib.h"
#include <stdarg.h>

void my_putchar_modulo(va_list ap)
{
    (void)(ap);
    char a = '%';

    my_putchar(a);
}