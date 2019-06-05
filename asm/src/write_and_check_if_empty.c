/*
** EPITECH PROJECT, 2019
** write and check if empty
** File description:
** *
*/

#include "../include/asm.h"

char *find_name_and_cat_cor(char **av)
{
    char *str = av[1];

    str = &str[length_last(str, '/', 0) + 1];
    str[my_strlen(str) -2] = '\0';
    str = my_strcat(str, ".cor");
    return (str);
}

void write_function(dlist *file_list, header_t *h, char **av)
{
    dlist_node *temp = file_list->begin;
    char *name = find_name_and_cat_cor(av);
    int fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0666);

    h->magic = be32toh(COREWAR_EXEC_MAGIC);
    while (temp != NULL) {
        for (int i = 0; temp->nb_byte[i] != -1; i += 1) {
            h->prog_size = temp->nb_byte[i] + h->prog_size;
        }
        temp = temp->next;
    }
    h->prog_size = be32toh(h->prog_size);
    write(fd, h, sizeof(header_t));
    temp = file_list->begin;
    while (temp != NULL) {
        for (int i = 0; temp->nb_byte[i] != -1; i += 1)
            write(fd, &temp->stock[i], temp->nb_byte[i]);
        temp = temp->next;
    }
    close(fd);
}

void check_if_name_function(check_t *ch)
{
    if ((ch->no_name == -1) || (ch->no_name > 0))
        exit(84);
    if (ch->no_comment > 0)
        exit(84);
}

void free_function(check_t *ch, header_t *h, dlist *file_list)
{
    free(h);
    free(ch);
    clear_dlist(file_list);
}
