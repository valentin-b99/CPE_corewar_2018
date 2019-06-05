/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** des
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int s = 0;
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    char *stock = malloc(sizeof(char) * (size_dest + size_src + 1));

    while (dest[i] != '\0') {
        stock[i] = dest[i];
        i = i + 1;
    }
    s = i;
    i = 0;
    while (src[i] != '\0') {
        stock[s] = src[i];
        i = i + 1;
        s = s + 1;
    }
    stock[s] = '\0';
    return (stock);
}
