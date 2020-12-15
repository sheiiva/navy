/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** check_inputs.c
*/

#include "lib.h"
#include <stddef.h>

int check_inputs(char *inputs)
{
    if ((inputs == NULL)
        || (my_strlen(inputs) != 2)
        || ((inputs[0] < 'A') || (inputs[0] > 'H'))
        || ((inputs[1] < '1') || (inputs[1] > '8')))
        return (-1);
    return (0);
}