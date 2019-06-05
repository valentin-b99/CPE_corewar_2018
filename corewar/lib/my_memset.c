/*
** EPITECH PROJECT, 2019
** fill_str
** File description:
** fill a string with a char to choose
*/

#include "my.h"

void *my_memset(size_t size, void *str_v, char char_to_replace_by)
{
    char *str = str_v;

    if (size == 0)
        return (NULL);
    for (int c = 0; c < size; c = c + 1)
        str[c] = char_to_replace_by;
    return (str_v);
}
