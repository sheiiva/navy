/*
** EPITECH PROJECT, 2019
** STUCTURES
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct coord_s coord_t;
    struct coord_s {
        int beg_x;
        int end_x;
        int beg_y;
        int end_y;
    };

    typedef struct maps_s maps_t;
    struct maps_s {
        char **map_player;
        char **map_enemy;
        int pid_ennemy;
    };


    #endif /* !STRUCT_H_ */