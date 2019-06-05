/*
** EPITECH PROJECT, 2019
** insert_ldc
** File description:
** insert begin and end list double chained
*/

#include "../include/asm.h"

void init_nb_byte_and_stock(dlist_node *element)
{
    element->nb_byte = malloc(sizeof(int) * 6);
    element->stock = malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i += 1) {
        element->nb_byte[i] = -1;
        element->stock[i] = -1;
    }
}

int insert_end(dlist *li, char *str)
{
    dlist_node *element;

    if ((element = malloc(sizeof(*element))) == NULL)
        return (84);
    element->label = 0;
    element->typ_des = 0;
    element->lign = my_strdup(str);
    element->next = NULL;
    element->back = NULL;
    if (li->begin == NULL) {
        li->begin = element;
        li->end = element;
    } else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->length = li->length + 1;
    init_nb_byte_and_stock(element);
    return (0);
}
