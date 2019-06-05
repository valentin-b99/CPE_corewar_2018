/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** task01
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    char stock = 0;

    stock = *a;
    *a = *b;
    *b = stock;
}
