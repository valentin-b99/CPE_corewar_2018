/*
** EPITECH PROJECT, 2019
** init
** File description:
** initialization double chained list
*/

#include "../include/asm.h"

dlist *new_dlist(void)
{
    dlist *list = malloc(sizeof(dlist));

    if (list == NULL)
        return (NULL);
    list->length = 0;
    list->begin = NULL;
    list->end = NULL;
    return (list);
}
