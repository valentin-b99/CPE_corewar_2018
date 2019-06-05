/*
** EPITECH PROJECT, 2019
** pointers.c
** File description:
** *
*/

#include "../include/asm.h"

void search_pointers(dlist *file_list)
{
    dlist_node *temp = file_list->begin;
    char *pointer = NULL;
    int add = 0;

    while (temp != NULL) {
        for (int i = 0; temp->word != NULL && temp->word[i] != NULL
        && temp->word[i][0] != COMMENT_CHAR; i += 1) {
            direct_nd_label_or_label(temp, add, i, pointer);
        }
        temp = temp->next;
    }
}

void direct_nd_label_or_label(dlist_node *temp, int add, int i, char *pointer)
{
    if (temp->word[i][0] == DIRECT_CHAR
    && temp->word[i][1] == LABEL_CHAR) {
        pointer = &(temp->word[i])[2];
        add = search_label(temp, pointer);
        if (temp->nb_byte[i + temp->typ_des - temp->label] != 1)
            add = be32toh(add);
        if (temp->nb_byte[i + temp->typ_des - temp->label] == 2)
            add = (add << 16) | (add >> 16);
        temp->stock[i + temp->typ_des - temp->label] = add;
    } else if (temp->word[i][0] == LABEL_CHAR) {
        label(temp, add, i, pointer);
    }
}

int search_label(dlist_node *temp, char *str)
{
    dlist_node *save = temp;
    int add = 0;

    while (temp != NULL) {
        if (temp->label == 1 && (compare_label(temp->word[0], str) == 0))
            break;
        for (int i = 0; temp->nb_byte[i] != -1; i += 1)
            add = temp->nb_byte[i] + add;
        temp = temp->next;
    }
    if (temp == NULL) {
        add = 0;
        return (other_side(temp, save, add, str));
    }
    else if (temp != NULL)
        return (add);
    return (0);
}

int other_side(dlist_node *temp, dlist_node *save, int add, char *str)
{
    temp = save->back;
    while (temp != NULL) {
        for (int i = 0; temp->nb_byte[i] != -1; i += 1)
            add = add - temp->nb_byte[i];
        if (temp->label == 1 && (compare_label(temp->word[0], str) == 0))
            break;
        temp = temp->back;
    }
    if (temp != NULL)
        return (add);
    exit(84);
}

void label(dlist_node *temp, int add, int i, char *pointer)
{
    pointer = &(temp->word[i])[1];
    add = search_label(temp, pointer);
    if (temp->nb_byte[i + temp->typ_des - temp->label] != 1)
        add = be32toh(add);
    if (temp->nb_byte[i + temp->typ_des - temp->label] == 2)
        add = (add << 16) | (add >> 16);
    temp->stock[i + temp->typ_des - temp->label] = add;
}
