/*
** EPITECH PROJECT, 2018
** delete spaces
** File description:
** delete spaces and print % if backslah n
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int delete_space(char *s, va_list ap, int i)
{
    if (s[i] == ' ') {
        for (int c = 0; s[i] == ' '; c++)
            i++;
    }
    if (s[i] == '\n')
        my_putchar('%');
    return (i);
}
