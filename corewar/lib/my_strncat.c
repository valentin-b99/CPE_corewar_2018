/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** description
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = my_strlen(dest);

    for (int i = 0; src[i] != '\0' && i < nb; i++) {
        dest[size] = src[i];
        size++;
    }
    dest[size] = '\0';
    return (dest);
}
