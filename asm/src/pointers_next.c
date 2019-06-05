/*
** EPITECH PROJECT, 2019
** pointers  next
** File description:
** *
*/

#include "../include/asm.h"

int tab_len(char **tab)
{
    int count = 0;

    for (count = 0; tab[count] != NULL; count += 1);
    return (count);
}

int compare_label(char *s1, char *s2)
{
    int i = 0;

    if ((s1 == NULL) || (s2 == NULL))
        return (84);
    while (s1[i] == s2[i] && s1[i] != LABEL_CHAR && s2[i] != '\0') {
        i = i + 1;
    }
    if ((s1[i] != LABEL_CHAR) || (s2[i] != '\0'))
        return (84);
    return (0);
}

void reverse_and_place(dlist_node *temp, int j, int nb)
{
    if (temp->nb_byte[j + temp->typ_des - temp->label] != 1)
        nb = be32toh(nb);
    if (temp->nb_byte[j + temp->typ_des - temp->label] == 2)
        nb = (nb << 16) | (nb >> 16);
    temp->stock[j + temp->typ_des - temp->label] = nb;
}

int check_syntax_next_direct(int i, char *str)
{
    if (str[0] == '-' || (str[0] > 47 && str[0] < 58)) {
        i += 1;
        if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
            exit(84);
    } else if (str[0] != LABEL_CHAR)
        exit(84);
    return (i);
}

void get_parameters(dlist_node *temp, int j, int i)
{
    char *str;
    int nb = 0;

    if (temp->word[j][0] == 'r') {
        str = &(temp->word[j])[1];
        temp->nb_byte[j + temp->typ_des - temp->label] = 1;
        if ((nb = my_getnbr(str)) <= 0 || nb > REG_NUMBER)
            exit(84);
    } else if (temp->word[j][0] == DIRECT_CHAR && temp->word[j][1] != ' ') {
        str = &(temp->word[j])[1];
        for (int i = 0; str[i] != '\0'; i += 1)
            i = check_syntax_next_direct(i, str);
        temp->nb_byte[j + temp->typ_des - temp->label] = DIR_SIZE;
        nb = my_getnbr(str);
        if ((i >= 8 && i <= 11) || (i >= 13 && i <= 14))
            temp->nb_byte[j + temp->typ_des - temp->label] = 2;
    } else {
        temp->nb_byte[j + temp->typ_des - temp->label] = IND_SIZE;
        nb = my_getnbr(temp->word[j]);
    }
    reverse_and_place(temp, j, nb);
}
