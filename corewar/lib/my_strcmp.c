/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two strings // return 0 if equal // 1 if s1 > s2 // -1 if s1 < s2
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if ((s1 == NULL) || (s2 == NULL))
        return (84);
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i = i + 1;
    if (s1[i] < s2[i])
        return (-1);
    else if (s1[i] > s2[i])
        return (1);
    return (0);
}
