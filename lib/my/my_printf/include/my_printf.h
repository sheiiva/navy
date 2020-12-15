/*
** EPITECH PROJECT, 2019
** lib printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

    void my_putchar_arg(va_list ap);
    void my_put_nbr_arg(va_list ap);
    void my_binary_arg(va_list ap);
    void my_putstr_arg(va_list ap);
    void my_octal_arg(va_list ap);
    void my_hexa_x(va_list ap);
    void my_hexa_x_upper(va_list ap);
    void my_pointer(va_list ap);
    void my_ascii_value(va_list ap);
    void my_putchar_modulo(va_list ap);
    void my_printf(char const *s, ...);

#endif /* !MY_PRINTF_H_ */
