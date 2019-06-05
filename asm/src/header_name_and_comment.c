/*
** EPITECH PROJECT, 2019
** head name and comment
** File description:
** find the name and the comment in the list and fill op.h header struct
*/

#include "../include/asm.h"

int count_size(char const *str, int command)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
        if (count > command)
            exit(84);
    }
    return (count);
}

int compare_till(char const *s1, char const *s2, int t)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (t - 1))
        i = i + 1;
    if (s1[i] < s2[i])
        return (-1);
    else if (s1[i] > s2[i])
        return (1);
    return (0);
}

void find_name_or_comment(dlist *file_list, header_t *h, check_t *ch)
{
    dlist_node *temp = file_list->begin;

    while (temp != NULL) {
        if (compare_till(temp->lign, NAME_CMD_STRING, my_strlen \
        (NAME_CMD_STRING)) == 0) {
            put_it_in_header_st(temp, h, 'n', 0);
            ch->no_name += 1;
        }
        else if (temp->lign[0] == '.' && compare_till(temp->lign, \
        COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0) {
            check_place_name_nd_comment(file_list);
            put_it_in_header_st(temp, h, 'c', 0);
            ch->no_comment += 1;
        }
        check_right_way_to_write(temp, ch);
        temp = temp->next;
    }
}

void put_it_in_header_st(dlist_node *tmp, header_t *h, char w, int i)
{
    char *str = my_strdup(tmp->lign);
    char *str_save = str;

    check_if_quote(str);
    for (i = 0; str[i] != '"'; i += 1);
    str = &str[i + 1];
    for (i = 0; str[i] != '"'; i += 1);
    str[i] = '\0';
    for (int i = 0; str[i] != '"' && str[i] != '\0'; i += 1) {
        if (w == 'n') {
            count_size(str, PROG_NAME_LENGTH);
            check_before_quote(str_save, NAME_CMD_STRING);
            h->prog_name[i] = str[i];
        }
        else if (w == 'c') {
            count_size(str, COMMENT_LENGTH);
            check_before_quote(str_save, COMMENT_CMD_STRING);
            h->comment[i] = str[i];
        }
    }
}
