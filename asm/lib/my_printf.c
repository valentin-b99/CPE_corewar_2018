/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void call_function(char *s, va_list ap, int i)
{
    c_flag(s, ap, i);
    s_lower_flag(s, ap, i);
    s_cap_flag(s, ap, i);
    i_and_d_flag(s, ap, i);
    u_flag(s, ap, i);
    o_flag(s, ap, i);
    x_flag(s, ap, i);
    x_cap_flag(s, ap, i);
    b_flag(s, ap, i);
    p_flag(s, ap, i);
    mod_flag(s, ap, i);
}

int my_printf(char *s, ...)
{
    va_list(ap);
    va_start(ap, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            i = delete_space(s, ap , i);
            call_function(s, ap, i);
            i = dash_flag(s, ap, i);
        }
        else
            my_putchar(s[i]);
    }
    va_end(ap);
}
