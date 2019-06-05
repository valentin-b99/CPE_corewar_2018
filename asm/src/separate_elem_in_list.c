/*
** EPITECH PROJECT, 2019
** separate_elem
** File description:
** *
*/

#include "../include/asm.h"

void check_what_follow_param(dlist_node *temp)
{
    for (int i = 0; temp->word[i] != NULL; i+= 1) {
        if (temp->word[i][0] == DIRECT_CHAR && temp->word[i][1] == '\0')
            exit(84);
    }
}

void separate_elements(dlist *file_list)
{
    dlist_node *temp = file_list->begin;
    int c = 0;

    while (temp != NULL) {
        for (c = 0; temp->lign[c] == ' '; c += 1);
        if (temp->lign[c] != COMMENT_CHAR && temp->lign[c] != '.')
            temp->word = my_str_to_word_array_cor(temp->lign);
        else
            temp->word = NULL;
        temp = temp->next;
    }
    temp = file_list->begin;
    while (temp != NULL) {
        if (temp->word != NULL)
            check_what_follow_param(temp);
        temp = temp->next;
    }
}
