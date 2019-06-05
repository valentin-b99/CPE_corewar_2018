/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** .h for lib
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include"../include/asm.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_unsigned_nbr(unsigned int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_printf(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int time_by_16(unsigned int nb);
int time_by_8(unsigned int nb);
int time_by_2(unsigned int nb);
int nb_hexa_low(unsigned int nb);
int nb_hexa_cap(unsigned int nb);
int nb_octal(unsigned int nb);
int nb_binary(unsigned int nb);
int s_flag(char *str);
void s_flag_cond(char *str, int count);
int my_printf(char *s, ...);
int p_flag(char *s, va_list ap, int i);
int c_flag(char *s, va_list ap, int i);
int i_and_d_flag(char *s, va_list ap, int i);
int u_flag(char *s, va_list ap, int i);
int s_lower_flag(char *s, va_list ap, int i);
int s_cap_flag(char *s, va_list ap, int i);
int o_flag(char *s, va_list ap, int i);
int x_flag(char *s, va_list ap, int i);
int x_cap_flag(char *s, va_list ap, int i);
int b_flag(char *s, va_list ap, int i);
int dash_flag(char *s, va_list ap, int i);
int mod_flag(char *s, va_list ap, int i);
int delete_space(char *s, va_list ap, int i);
void call_function(char *s, va_list ap, int i);
int my_getnbr(char const *str);
char *get_next_line(int fd);
void *my_memset(size_t size, void *str_v, char char_to_replace_by);

char **my_str_to_word_array_space(char const *str);
char *set_line_space(char const *str, int *c);
int find_nb_of_words_space(char const *str);

int find_nb_of_words(char const *str, char limit);
char *set_line(char const *str, int *c, char limit);
char **my_str_to_word_array(char const *str, char limit);

char *my_strdup(char const *src);
int length(char const *str, char to_stop);
int length_last(char const *str, char to_stop, int i);
char *my_strcat_gnl(char *dest, char const *src);

#endif
