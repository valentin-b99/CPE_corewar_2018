/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** D8_task01
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int size = my_strlen(src);

    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    while (i < size) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
