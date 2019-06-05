/*
** EPITECH PROJECT, 2019
** asm.h
** File description:
** *
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <endian.h>
#include "../lib/my.h"
#include "op.h"

#ifndef ASM_H_
#define ASM_H_

//défining a node in the list
typedef struct dlist_node
{
    int *nb_byte;
    int *stock;
    int label;
    int typ_des;
    char *lign;
    char **word;
    struct dlist_node *next;
    struct dlist_node *back;
}dlist_node;

//défining the list
typedef struct dlist
{
    int length;
    struct dlist_node *begin;
    struct dlist_node *end;
}dlist;

typedef struct check_s
{
    int no_name;
    int no_comment;
}check_t;

//PROTO : FONCTIONS LISTE CHAINEE//

//init_linked_list.c
dlist *new_dlist(void);

//insert_element_in_linked_list.c
int insert_end(dlist *li, char *str);
int insert_begin(dlist *li, char *str);

//delete_element_in_linked_list.c
int check_to_delete(dlist *li, dlist_node *to_delete);
dlist *delete_last(dlist *li);
dlist *delete_first(dlist *li);
dlist *delete_middle(dlist *li, dlist_node *to_delete);

//display_and_clear_linked_list.c
void display_dlist(dlist *li);
void clear_dlist(dlist *li);

//PROTO : FONCTIONS PROJET//

//header_and_checks_for_it.c
void asm_header(char **av, dlist *file_list);
char *replace_tab_by_space(char *str);
int check_if_empty_file(char *str);
void instructions_steps(dlist *file_list, header_t *h, check_t *ch, char **av);
void check_rest_of_the_str(char *str, int i);

//check_quotes.c
void check_before_quote(char *str, char const *macro);
void check_if_quote(char *str);

//header_name_and_comment.c
int count_size(char const *str, int command);
void find_name_or_comment(dlist *file_list, header_t *h, check_t *ch);
void put_it_in_header_st(dlist_node *tmp, header_t *h, char w, int i);
int compare_till(char const *s1, char const *s2, int t);

//check_errors_name.c
void check_place_name_nd_comment(dlist *file_list);
void check_right_way_to_write(dlist_node *temp, check_t *ch);

//separate_elem_in_list.c
void check_what_follow_param(dlist_node *temp);
void separate_elements(dlist *file_list);

//labels.c
void check_if_label(dlist *file_list);
void check_error_label(dlist *file_list, dlist_node *temp);
int check_label_chars(dlist_node *temp, int fine, int i);

//find_instruction_check_td.c
void browse_list_to_find_instruction(dlist *file_list);
void get_instruction(dlist_node *temp);
void check_if_type_descriptor(dlist_node *temp, int i);
char check_type_value(char *str);

//getting_type_descriptor.c
int get_type_descriptor(dlist_node *temp, int i);
int get_type_nbr_value(char *str);

//pointers
void search_pointers(dlist *file_list);
void direct_nd_label_or_label(dlist_node *temp, int add, int i, char *pointer);
int search_label(dlist_node *temp, char *str);
int other_side(dlist_node *temp, dlist_node *save, int add, char *str);
void label(dlist_node *temp, int add, int i, char *pointer);

//pointers_next.c
int tab_len(char **tab);
int compare_label(char *s1, char *s2);
void reverse_and_place(dlist_node *temp, int j, int nb);
int check_syntax_next_direct(int i, char *str);
void get_parameters(dlist_node *temp, int j, int i);

//write_and_check_if_empty.c
char *find_name_and_cat_cor(char **av);
void write_function(dlist *file_list, header_t *h, char **av);
void check_if_name_function(check_t *ch);
void free_function(check_t *ch, header_t *h, dlist *file_list);

char **my_str_to_word_array_cor(char const *str);
#endif
