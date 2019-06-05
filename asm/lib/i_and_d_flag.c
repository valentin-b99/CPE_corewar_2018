/*
** EPITECH PROJECT, 2018
** i and d flags
** File description:
** i and d flags for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int i_and_d_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'i' || s[i] == 'd')
        my_put_nbr(va_arg(ap, int));
}
