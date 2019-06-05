/*
** EPITECH PROJECT, 2019
** check quotes
** File description:
** *
*/

#include "../include/asm.h"

void check_before_quote(char *str, char const *macro)
{
    int i = 0;

    str = &str[my_strlen(macro)];
    for (i = 0; str[i] == ' '; i += 1);
    if (str[i] != '"')
        exit(84);
}

void check_if_quote(char *str)
{
    int i = 0;
    int quote = 0;

    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '"')
            quote += 1;
        if (quote == 2 && str[i] == '"') {
            i += 1;
            check_rest_of_the_str(str, i);
        }
    }
    if (quote == 0 || quote == 1)
        exit(84);
}
