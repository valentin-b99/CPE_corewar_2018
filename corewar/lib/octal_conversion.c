/*
** EPITECH PROJECT, 2018
** octal conversion
** File description:
** convert decimal in octal for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int time_by_8(unsigned int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 8;
        i++;
    }
    return (i);
}

int nb_octal(unsigned int nb)
{
    int size = time_by_8(nb);
    char *str = malloc(sizeof(char)*(size + 1));
    char *base = "01234567";

    str[size] = '\0';
    size--;
    while (nb > 0) {
        str[size] = base[nb % 8];
        size--;
        nb = nb / 8;
    }
    my_putstr(str);
    free(str);
    return (0);
}
