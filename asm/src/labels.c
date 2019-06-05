/*
** EPITECH PROJECT, 2019
** labels
** File description:
** *
*/

#include "../include/asm.h"

void check_if_label(dlist *file_list)
{
    dlist_node *temp = file_list->begin;

    while (temp != NULL && temp->word == NULL)
        temp = temp->next;
    while (temp != NULL) {
        if (temp->word != NULL && temp->word[0][0] != '\0'
        && temp->word[0][my_strlen(temp->word[0]) - 1] == LABEL_CHAR) {
            check_error_label(file_list, temp);
            temp->label = 1;
        }
        temp = temp->next;
    }
    browse_list_to_find_instruction(file_list);
}

void check_error_label(dlist *file_list, dlist_node *temp)
{
    int fine = 0;
    dlist_node *browse = file_list->begin;

    for (int i = 0; temp->word[0][i] != '\0'; i += 1) {
        fine = check_label_chars(temp, fine, i);
    }
    if (fine != my_strlen(temp->word[0]) - 1)
        exit(84);
    while (browse != NULL) {
        if (browse->label == 1
        && my_strcmp(browse->word[0], temp->word[0]) == 0)
            exit(84);
        browse = browse->next;
    }
}

int check_label_chars(dlist_node *temp, int fine, int i)
{
    for (int j = 0; LABEL_CHARS[j] != '\0'; j += 1) {
        if (temp->word[0][i] == LABEL_CHARS[j])
            fine += 1;
    }
    return (fine);
}
