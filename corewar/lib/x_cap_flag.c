/*
** EPITECH PROJECT, 2018
** X flag for my_printf
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int x_cap_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'X')
        nb_hexa_cap(va_arg(ap, int));
}
