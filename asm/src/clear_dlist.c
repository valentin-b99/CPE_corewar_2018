/*
** EPITECH PROJECT, 2019
** display_clear
** File description:
** display and clear the list
*/

#include "../include/asm.h"

void clear_dlist(dlist *li)
{
    while (li != NULL)
        li = delete_first(li);
}
