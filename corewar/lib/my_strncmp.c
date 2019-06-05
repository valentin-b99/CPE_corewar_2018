/*
** EPITECH PROJECT, 2018
** my_stncmp
** File description:
** compare two strings // return 0 if equal // 1 if s1 > s2 // -1 if s1 < s2
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
        i = i + 1;
    if (s1[i] < s2[i])
        return (-1);
    else if (s1[i] > s2[i])
        return (1);
    return (0);
}
