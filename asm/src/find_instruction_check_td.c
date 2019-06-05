/*
** EPITECH PROJECT, 2019
** find and get instructions and check if type descriptor
** File description:
** *
*/

#include "../include/asm.h"

void browse_list_to_find_instruction(dlist *file_list)
{
    dlist_node *temp = file_list->begin;

    while (temp != NULL) {
        get_instruction(temp);
        temp = temp->next;
    }
}

void get_instruction(dlist_node *temp)
{
    int i = 0;

    for (i = 0; op_tab[i].mnemonique != NULL && temp->word != NULL; i += 1) {
        if (my_strcmp(temp->word[temp->label], op_tab[i].mnemonique) == 0) {
            temp->nb_byte[0] = 1;
            temp->stock[0] = op_tab[i].code;
            check_if_type_descriptor(temp, i);
            break;
        }
    }
    if (op_tab[i].mnemonique == NULL && temp->word != NULL
    && (temp->word[temp->label] != NULL
    && temp->word[temp->label][0] != COMMENT_CHAR))
        exit(84);
}

void check_if_type_descriptor(dlist_node *temp, int i)
{
    int j = 1 + temp->label;

    if (((tab_len(temp->word) - 1 - temp->label) < op_tab[i].nbr_args)
    || (((tab_len(temp->word) - 1 - temp->label) > op_tab[i].nbr_args)
    && temp->word[op_tab[i].nbr_args + temp->label + 1][0] != COMMENT_CHAR))
        exit(84);
    if (i != 0 && i != 8 && i != 11 && i != 14) {
        temp->typ_des = 1;
        temp->nb_byte[1] = 1;
        temp->stock[1] = get_type_descriptor(temp, i);
    }
    for (j = j; j <= op_tab[i].nbr_args + temp->label; j += 1) {
        if ((check_type_value(temp->word[j])
        & op_tab[i].type[j - temp->label - 1]) == 0)
            exit(84);
        get_parameters(temp, j, i);
    }
}

char check_type_value(char *str)
{
    if (str[0] == 'r')
        return (T_REG);
    else if (str[0] == DIRECT_CHAR && str[1] != ' ')
        return (T_DIR);
    else
        return (T_IND);
}
