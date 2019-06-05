/*
** EPITECH PROJECT, 2018
** putstr for my_printf
** File description:
** description
*/

#include "my.h"

int my_putstr_printf(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
