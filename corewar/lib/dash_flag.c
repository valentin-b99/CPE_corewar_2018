/*
** EPITECH PROJECT, 2018
** dash flag
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int dash_flag(char *s, va_list ap, int i)
{
    if (s[i] == '#') {
        i++;
        if (s[i] == 'o') {
            my_putchar('0');
            nb_octal(va_arg(ap, int));
        }
        if (s[i] == 'x') {
            my_putstr("0x");
            nb_hexa_low(va_arg(ap, int));
        }
        if (s[i] == 'X') {
            my_putstr("0x");
            nb_hexa_cap(va_arg(ap, int));
        }
    }
    return (i);
}
