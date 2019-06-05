/*
** EPITECH PROJECT, 2018
** p_flag
** File description:
** %p for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int p_flag(char *s, va_list ap, int i)
{
    unsigned int long p;

    if (s[i] == 'p') {
        p = (unsigned int long) va_arg(ap, void *);
        my_putstr("0x");
        nb_hexa_low(p);
    }
    return (0);
}
