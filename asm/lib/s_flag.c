/*
** EPITECH PROJECT, 2018
** %S for my_printf
** File description:
** display non printable ASCI value as \ followed by char's value in octal bas
*/

#include "my.h"

int s_flag(char *str)
{
    int count = 0;
    int i = 3;
    char *temp = malloc(sizeof(char)*i);

    while (str[count] != '\0') {
        if (str[count] < 32 || str[count] >= 127) {
            s_flag_cond(str, count);
        } else
            my_putchar(str[count]);
        count++;
    }
    return (0);
}

void s_flag_cond(char *str, int count)
{
    if (str[count] >= 0 && str[count] < 8)
        my_putstr("\\00");
    else if (str[count] > 7 && str[count] < 32)
        my_putstr("\\0");
    else
        my_putchar('\\');
    nb_octal(str[count]);
}
