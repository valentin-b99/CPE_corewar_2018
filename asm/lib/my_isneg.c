/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** task04
*/

#include "my.h"

int	my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
