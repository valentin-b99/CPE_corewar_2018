/*
** EPITECH PROJECT, 2018
** my_put_other_nbr
** File description:
** display a nb given as parameter
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    unsigned int result;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            result = (nb % 10);
            nb = (nb - result) / 10;
            my_put_nbr(nb);
            my_putchar(result + 48);
        } else {
            my_putchar((nb % 10) + 48);
        }
    }
    if (nb == -2147483648) {
        my_putstr("2147483648");
    }
    return (0);
}
