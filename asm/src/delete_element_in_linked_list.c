/*
** EPITECH PROJECT, 2019
** delete elem
** File description:
** delete first, last or a precise element
*/

#include "../include/asm.h"

dlist *delete_first(dlist *li)
{
    dlist_node *next = NULL;
    dlist_node *tmp = li->begin;

    if (!tmp)
        return (NULL);
    next = li->begin->next;
    li->begin = next;
    if (next)
        next->back = NULL;
    li->length -= 1;
    free(tmp->lign);
    free(tmp);
    return (li);
}

dlist *delete_last(dlist *li)
{
    dlist_node *back = NULL;
    dlist_node *tmp = li->end;

    if (!tmp)
        return (NULL);
    back = li->end->back;
    li->end = back;
    if (back)
        back->next = NULL;
    li->length -= 1;
    return (li);
}

int check_to_delete(dlist *li, dlist_node *to_delete)
{
    if (to_delete == li->begin)
        delete_first(li);
    else if (to_delete == li->end)
        delete_last(li);
    else
        return (1);
    return (0);
}

dlist *delete_middle(dlist *li, dlist_node *to_delete)
{
    if (li == NULL)
        return (NULL);
    if (check_to_delete(li, to_delete) == 1) {
        if (li->begin == li->end) {
            free(li->begin->word);
            free(li->begin);
            free(li);
            li = NULL;
            return (li);
        } else {
            to_delete->next->back = to_delete->back;
            to_delete->back->next = to_delete->next;
            li->length = li->length - 1;
            return (li);
        }
    }
    return (li);
}
