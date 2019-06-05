/*
** EPITECH PROJECT, 2019
** str to word array
** File description:
** split a string into words
*/

#include <stdio.h>
#include "my.h"

int find_nb_of_words_space(char const *str)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i = i + 1;
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t')
        && str[i - 1] != ' ' && str[i - 1] != '\t')
            nb_words = nb_words + 1;
        i = i + 1;
    }
    if (str[i - 1] != ' ' && str[i - 1] != '\t')
        nb_words = nb_words + 1;
    return (nb_words);
}

char *set_line_space(char const *str, int *c)
{
    int i = *c;
    int t = *c;
    char *line;

    while (str[t] != '\0' && str[t] != ' ' && str[t] != '\t')
        t = t + 1;
    line = malloc(sizeof(char) * (t - i + 1));
    for (int f = 0; f < (t - i + 1); f = f + 1)
        line[f] = '\0';
    for (int h = 0; i < t; h = h + 1) {
        line[h] = str[i];
        i = i + 1;
    }
    *c = i;
    return (line);
}

char **my_str_to_word_array_space(char const *str)
{
    int i = 0;
    int nb_words = find_nb_of_words_space(str);
    char **stock = malloc(sizeof(char *) * (nb_words + 1));

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i = i + 1;
    for (int j = 0; j < nb_words; j = j + 1) {
        stock[j] = set_line_space(str, &i);
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
            i = i + 1;
    }
    stock[nb_words] = NULL;
    return (stock);
}
