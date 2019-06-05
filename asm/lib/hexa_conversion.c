/*
** EPITECH PROJECT, 2018
** hexa_conversion
** File description:
** convert decimal in hexa for my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int time_by_16(unsigned int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 16;
        i++;
    }
    return (i);
}

int nb_hexa_low(unsigned int nb)
{
    int size = time_by_16(nb);
    char *str = malloc(sizeof(char)*(size + 1));
    char *base = "0123456789abcdef";

    str[size] = '\0';
    size--;
    while (nb > 0) {
        str[size] = base[nb % 16];
        size--;
        nb = nb / 16;
    }
    my_putstr(str);
    free(str);
    return (0);
}

int nb_hexa_cap(unsigned int nb)
{
    int size = time_by_16(nb);
    char *str = malloc(sizeof(char)*(size + 1));
    char *base = "0123456789ABCDEF";

    str[size] = '\0';
    size--;
    while (nb > 0) {
        str[size] = base[nb % 16];
        size--;
        nb = nb / 16;
    }
    my_putstr(str);
    free(str);
    return (0);
}
