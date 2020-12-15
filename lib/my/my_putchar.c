/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** put_char.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
