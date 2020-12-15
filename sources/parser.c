/*
** EPITECH PROJECT, 2019
** SOURCES
** File description:
** parser.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int *feed_and_check_map(int *coord, char *line, int *e, int loop)
{
    if ((((coord[(*e)++] = line[0] - '0') != (loop + 2)))
        || (line[1] != ':')
        || ((coord[*e] = line[2] - '@') < 1 || (coord[(*e)++] > 8))
        || ((coord[*e] = line[3] - '0') < 1 || (coord[(*e)++] > 8))
        || (line[4] != ':')
        || ((coord[*e] = line[5] - '@') < 1 || (coord[(*e)++] > 8))
        || ((coord[*e] = line[6] - '0') < 1 || (coord[(*e)++] > 8))
        || (line[7] != '\n'))
        return (NULL);
    return (coord);
}

int *my_mem_set(int *coord, int size, int value)
{
    int i = 0;

    while (i < size) {
        coord[i] = value;
        i = i + 1;
    }
    return (coord);
}

int *parser(char *path)
{
    int fd = open(path, O_RDONLY);
    int *coord = malloc(sizeof(int) * 20);
    char *line = malloc(sizeof(char) * 8);
    size_t loop = 0;
    int e = 0;
    int err_read = -2;

    coord = my_mem_set(coord, 20, -1);
    while (loop < 4) {
        err_read = read(fd, line, 8);
        if (err_read <= 0 || coord == NULL || line == NULL)
            return (NULL);
        if ((coord = feed_and_check_map(coord, line, &e, loop)) == NULL)
            return (NULL);
        ++loop;
    }
    free(line);
    if (close(fd) == -1)
        return (NULL);
    return (coord);
}