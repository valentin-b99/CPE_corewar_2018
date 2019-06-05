/*
** EPITECH PROJECT, 2019
** length
** File description:
** mystrlen with chosen char
*/

#include "my.h"

int length_last(char const *str, char to_stop, int i)
{
    int count = my_strlen(str);

    while (str[count] != to_stop && count >= 0) {
        count -= 1;
    }
    if (i != 1)
        return (count);
    else
        return (my_strlen(str) - count - 1);
}

int length(char const *str, char to_stop)
{
    int count = 0;

    while (str[count] != to_stop && str[count] != '\0') {
        count += 1;
    }
    return (count);
}
