/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_strlen.c
*/

int my_strlen(char const *src)
{
    int i = 0;

    if (!src)
        return (-1);
    while (src[i] != '\0')
        i = i + 1;
    return (i);
}
