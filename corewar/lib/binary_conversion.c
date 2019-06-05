/*
** EPITECH PROJECT, 2018
** binary conversion
** File description:
** binary conversion for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int time_by_2(unsigned int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 2;
        i++;
    }
    return (i);
}

int nb_binary(unsigned int nb)
{
    int size = time_by_2(nb);
    char *str = malloc(sizeof(char)*(size + 1));
    char *base = "01";

    str[size] = '\0';
    size--;
    while (nb > 0) {
        str[size] = base[nb % 2];
        size--;
        nb = nb / 2;
    }
    my_putstr(str);
    free(str);
    return (0);
}
