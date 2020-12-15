/*
** EPITECH PROJECT, 2019
** LIBRARY's FUNCTIONS PROTOTYPES
** File description:
** lib.h
*/

#ifndef BASICS_H_
    #define BASICS_H_

    void free_tab(char **tab);
    int my_isnum(char c);
    void my_printab(char **tab);
    void my_putchar(char c);
    int my_put_nbr_base(int base, int nb);
    void my_putstr(char const *str);
    char *my_revstr(char *str);
    char *my_realloc(char *str, char c);
    int my_strlen(char const *src);
    int my_strcomp(char *source, char *compared);
    char *my_strdup(char *str);
    int my_getnbr(char *str);

#endif /* !BASICS_H_ */
