/*
** EPITECH PROJECT, 2018
** PRINTF LIB
** File description:
** my_put_nbr_base.c
*/

#include "lib.h"
#include <stdlib.h>

char my_x_upper_ten(int nb, char letter)
{
    char str_a[7] = "abcdef\0";
    char str_A[7] = "ABCDEF\0";

    if (nb > 9) {
        if (letter == 'a')
            return (str_a[nb - 10]);
        if (letter == 'A')
            return (str_A[nb - 10]);
    }
    else
        return (nb + '0');
    return (0);
}

char *my_calc_str(int base, int nb, char *res)
{
    int i = 0;
    int stock = base;

    if (base == 165)
        base = 16;
    while (nb != 0) {
        if (stock == 16)
            res[i++] = my_x_upper_ten((nb % base), 'a');
        else if (stock == 165)
            res[i++] = my_x_upper_ten((nb % base), 'A');
        else
            res[i++] = (nb % base) + '0';
        res = my_realloc(res, res[i]);
        nb = nb / base;
    }
    return (res);
}

int my_put_nbr_base(int base, int nb)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = '\0';
    res[1] = '\0';
    res = my_revstr(my_calc_str(base, nb, res));
    my_putstr(res);
    free(res);
    return (0);
}