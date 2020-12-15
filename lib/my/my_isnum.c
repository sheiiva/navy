/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_isnum.c
*/

int my_isnum(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}