/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** *
*/

#include "../include/asm.h"

int main(int ac, char **av)
{
    dlist *file_list;
    header_t *h = malloc(sizeof(header_t));
    check_t *ch = malloc(sizeof(check_t));

    if (!h || !ch)
        return (84);
    my_memset(sizeof(header_t), h, '\0');
    if ((file_list = new_dlist()) == NULL)
        return (84);
    if (ac == 1)
        return (84);
    asm_header(av, file_list);
    instructions_steps(file_list, h, ch, av);
}
