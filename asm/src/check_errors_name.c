/*
** EPITECH PROJECT, 2019
** check errors name
** File description:
** *
*/

#include "../include/asm.h"

void check_place_name_nd_comment(dlist *file_list)
{
    dlist_node *temp = file_list->begin;

    if (compare_till(temp->lign, NAME_CMD_STRING, my_strlen \
    (NAME_CMD_STRING)) != 0)
        exit(84);
    if (compare_till(temp->next->lign, COMMENT_CMD_STRING, my_strlen \
    (COMMENT_CMD_STRING)) != 0)
        exit(84);
}

void check_right_way_to_write(dlist_node *temp, check_t *ch)
{
    if (temp->lign[0] == '.' && compare_till(temp->lign, \
    COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) != 0 && \
    compare_till(temp->lign, NAME_CMD_STRING, my_strlen \
    (NAME_CMD_STRING)) != 0)
        exit(84);
    if (ch->no_comment > ch->no_name)
        exit(84);
}
