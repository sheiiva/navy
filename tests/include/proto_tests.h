/*
** EPITECH PROJECT, 2019
** prototypes for tests
** File description:
** proto_tests
*/

#ifndef PROTO_TESTS_H_
    #define PROTO_TESTS_H_

    #include <stddef.h>
    #include "struct.h"

    void my_putchar(char c);
    int my_put_nbr_base(int base, int nb);
    void my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_realloc(char *str, char c);
    int my_strlen(char const *src);
    void my_printf(char const *s, ...);
    int *parser(char *path);
    char *get_next_line(int fd);
    char **map_maker(int *coord);
    int sign_counter(void);
    maps_t *attack_enemy(maps_t *map, pid_t pid);
    int data_pinger(pid_t pid, int usr_one, int usr_two);
    char get_result(void);
    int count_number(char **map);
    char *my_strdup(char *str);
    int check_nb_ships(char **map);

#endif /* !PROTO_TESTS_H_ */
