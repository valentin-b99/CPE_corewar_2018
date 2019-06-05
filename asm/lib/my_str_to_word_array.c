/*
** EPITECH PROJECT, 2019
** str to word array
** File description:
** split a string into words
*/

#include <stdio.h>
#include "my.h"

int find_nb_of_words(char const *str, char limit)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0' && str[i] == limit)
        i = i + 1;
    while (str[i] != '\0') {
        if ((str[i] == limit)
            && str[i - 1] != limit)
            nb_words = nb_words + 1;
        i = i + 1;
    }
    if (str[i - 1] != limit)
        nb_words = nb_words + 1;
    return (nb_words);
}

char *set_line(char const *str, int *c, char limit)
{
    int i = *c;
    int t = *c;
    int h = 0;
    char *line;

    while (str[t] != '\0' && str[t] != limit)
        t = t + 1;
    line = malloc(sizeof(char) * (t - i + 1));
    for (int f = 0; f < (t - i + 1); f = f + 1)
        line[f] = '\0';
    for (h = 0; i < t; h = h + 1) {
        line[h] = str[i];
        i = i + 1;
    }
    *c = i;
    return (line);
}

char **my_str_to_word_array(char const *str, char limit)
{
    int i = 0;
    int nb_words = find_nb_of_words(str, limit);
    char **stock = malloc(sizeof(char *) * (nb_words + 1));

    while (str[i] != '\0' && str[i] == limit)
        i = i + 1;
    for (int j = 0; j < nb_words; j = j + 1) {
        stock[j] = set_line(str, &i, limit);
        while (str[i] != '\0' && str[i] == limit)
            i = i + 1;
    }
    stock[nb_words] = NULL;
    return (stock);
}
