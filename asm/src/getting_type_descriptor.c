/*
** EPITECH PROJECT, 2019
** getting type descriptor
** File description:
** *
*/

#include "../include/asm.h"

int get_type_descriptor(dlist_node *temp, int i)
{
    int stock = 0;
    int pos = 1 + temp->label;

    for (pos = pos; pos <= op_tab[i].nbr_args + temp->label; pos += 1) {
        stock = stock + get_type_nbr_value(temp->word[pos]);
        stock = stock << 2;
    }
    while (pos < 4 + temp->label) {
        stock = stock << 2;
        pos += 1;
    }
    return (stock);
}

int get_type_nbr_value(char *str)
{
    if (str[0] == 'r' && (str[1] == LABEL_CHAR || str[1] == DIRECT_CHAR))
        exit(84);
    if (str[0] == 'r')
        return (1);
    if (str[0] == DIRECT_CHAR && (str[1] == 'r' || str[1] == ' '))
        exit(84);
    if (str[0] == DIRECT_CHAR)
        return (2);
    return (3);
}
