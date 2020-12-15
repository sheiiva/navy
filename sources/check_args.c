/*
** EPITECH PROJECT, 2018
** SOURCES
** File description:
** check_args.c
*/

#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "macro.h"

int check_opened_map(int fd)
{
    int i = 1;
    char *stock = malloc(sizeof(char) * 31);

    if ((stock == NULL) || (read(fd, stock, 31) == -1))
        return (84);
    while (i < 4) {
        if (stock[(8 * i) - 1] != '\n') {
            free(stock);
            return (84);
        }
            i = i + 1;
    }
    if (stock[8 * i - 1] != '\0') {
        free(stock);
        return (84);
    }
    free(stock);
    return (0);
}

int check_pid(char *ptr)
{
    while (*ptr != '\0') {
        if (my_isnum(*ptr) == 0)
            return (84);
        ptr++;
    }
    return (0);
}

int check_args(_UNUSED_ int ac, char **av)
{
    char *ptr = av[1];
    int fd = 0;

    if (((fd = open(av[ac - 1], O_RDONLY)) == -1)
        || (check_opened_map(fd) == 84)
        || (close(fd) == -1))
        return (84);
    if (ac == 3) {
        if (check_pid(ptr) == 84)
            return (84);
    }
    return (0);
}