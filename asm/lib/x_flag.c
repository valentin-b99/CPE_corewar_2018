/*
** EPITECH PROJECT, 2018
** x flag
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int x_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'x')
        nb_hexa_low(va_arg(ap, int));
}
