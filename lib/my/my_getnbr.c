/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_getnbr.c
*/

int my_isnuma(char c)
{
    if ('0' <= c && c <= '9') {
        return (1);
    }
    return (0);
}

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str[i] == '-')
        return (84);
    if (str[i] == '\0')
        return (84);
    while (str[i] != '\0' && str[i] != '\n') {
        if (my_isnuma(str[i]) == 0 && str[i] != '\n')
            return (84);
        nb = nb * 10 + (str[i] - '0');
        i = i + 1;
    }
    nb = nb * neg;
    return (nb);
}