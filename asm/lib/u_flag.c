/*
** EPITECH PROJECT, 2018
** u flag
** File description:
** u flag for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int u_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'u')
        my_put_unsigned_nbr(va_arg(ap, unsigned int));
}
