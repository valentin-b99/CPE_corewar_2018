/*
** EPITECH PROJECT, 2018
** c_flag
** File description:
** c flag for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int c_flag(char *s, va_list ap, int i)
{
    if (s[i] == 'c')
        my_putchar(va_arg(ap, int));
}
