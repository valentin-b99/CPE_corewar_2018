/*
** EPITECH PROJECT, 2018
** o flag for my_printf
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int o_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'o')
        nb_octal(va_arg(ap, int));
}
