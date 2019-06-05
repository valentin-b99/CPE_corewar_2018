/*
** EPITECH PROJECT, 2019
** header and checks for it
** File description:
** *
*/

#include "../include/asm.h"

void asm_header(char **av, dlist *file_list)
{
    int fd = open(av[1], O_RDONLY);
    char *str = get_next_line(fd);
    int i = 0;
    int loop = 0;
    int empty = 0;

    while (str != NULL) {
        loop += 1;
        for (i = 0; str[i] == '\t'; i += 1);
        str = &str[i];
        str = replace_tab_by_space(str);
        if (str[0] != '\0' && str[0] != COMMENT_CHAR)
            insert_end(file_list, str);
        if (check_if_empty_file(str) == -1)
            empty += 1;
        str = get_next_line(fd);
    }
    close(fd);
    if (empty == loop)
        exit(84);
}

char *replace_tab_by_space(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    for (i = 0; str[i] == ' '; i += 1);
    str = &str[i];
    return (str);
}

int check_if_empty_file(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i += 1) {
        if (str[i] == ' ')
            space += 1;
    }
    if (str[0] == '\0' || space == my_strlen(str))
        return (-1);
    return (0);
}

void instructions_steps(dlist *file_list, header_t *h, check_t *ch, char **av)
{
    separate_elements(file_list);
    ch->no_name = -1;
    ch->no_comment = -1;
    find_name_or_comment(file_list, h, ch);
    check_if_label(file_list);
    search_pointers(file_list);
    check_if_name_function(ch);
    write_function(file_list, h, av);
    free_function(ch, h, file_list);
}

void check_rest_of_the_str(char *str, int i)
{
    while (str[i] == ' ' || str[i] == COMMENT_CHAR)
        i += 1;
    if (str[i] != '\0')
        exit(84);
}
