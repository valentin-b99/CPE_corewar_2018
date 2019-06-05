/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** task03 marche pas
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int y = my_strlen(str) - 1;
    char c;

    while (i < my_strlen(str) / 2) {
        c = str[i];
        str[i] = str[y];
        str[y] = c;
        i++;
        y--;
    }
    return (str);
}
