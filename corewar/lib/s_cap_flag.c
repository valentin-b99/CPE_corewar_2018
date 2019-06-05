/*
** EPITECH PROJECT, 2018
** s cap flag
** File description:
** description
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int s_cap_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'S')
        s_flag(va_arg(ap, char *));
}
