/*
** EPITECH PROJECT, 2018
** lower case s flag for my_printf
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int s_lower_flag(char *s, va_list ap, int i)
{
    if (s[i] == 's')
        my_putstr_printf(va_arg(ap, char *));
}
