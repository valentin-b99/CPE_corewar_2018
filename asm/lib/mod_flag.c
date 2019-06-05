/*
** EPITECH PROJECT, 2018
** modulo flag for my_printf
** File description:
** if %% then my_printf %
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int mod_flag(char *s, va_list ap, int i)
{
    if (s[i] == '%')
        my_putchar('%');
}
