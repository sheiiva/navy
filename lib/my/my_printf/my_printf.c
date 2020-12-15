/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_printf.c
*/

#include "lib.h"
#include "my_printf.h"

int nothing_fit(int i)
{
    if (i == 11) {
            return (1);
        }
    return (0);
}

void function_ptr(char c, va_list ap)
{
    void (*ptr[11])(va_list) = {
        my_putchar_arg, my_put_nbr_arg, my_put_nbr_arg,
        my_binary_arg, my_putstr_arg, my_octal_arg,
        my_hexa_x, my_hexa_x_upper, my_pointer, my_ascii_value,
        my_putchar_modulo};
    char dict[12] = "cdibsoxXpS%\0";
    int i  = 0;

    while (dict[i] != c && dict[i] != '\0')
        i++;
    if (nothing_fit(i) == 0)
        ptr[i](ap);
    else if (nothing_fit(i) == 1) {
        my_putchar('%');
        my_putchar(c);
        }
}

void my_printf(char const *s, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, s);
    while (s[i] != '\0') {
        if (s[i] == '%'){
            function_ptr(s[i + 1], ap);
            i = i + 1;
        }
        else
            my_putchar(s[i]);
        i = i + 1;
    }
    va_end(ap);
}