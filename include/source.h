/*
** EPITECH PROJECT, 2019
** SOURCE's FUNCTIONS PROTOTYPES
** File description:
** source.h
*/

#ifndef SOURCE_H_
    #define SOURCE_H_

    #include <unistd.h>
    #include "macro.h"
    #include "struct.h"

    maps_t *attack_enemy(maps_t *map, int PID);
    int check_args(_UNUSED_ int ac, char **av);
    int check_inputs(char *inputs);
    int check_nb_ships(char **map);
    int free_struct(maps_t *maps, int *coord);
    int data_pinger(pid_t pid, int usr_one, int usr_two);
    int get_enemy_s_pid(int ac, char **av);
    int help(void);
    int main(int ac, char **av);
    maps_t *main_loop(maps_t *maps, int player);
    char **make_empty_map(void);
    char **map_maker(int *coord);
    int *parser(char *path);
    int ping_me(int ac, char **av);
    int sign_counter(void);
    maps_t *wait_ennemy(maps_t *maps, int pid);

    #endif /* !SOURCE_H_ */