/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** gnl
*/

#include "my.h"

char *my_strcat_gnl(char *dest, char const *src)
{
    int i = 0;
    int s = 0;
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    char *stock = malloc(sizeof(char) * (size_dest + size_src + 1));

    while (dest[i] != '\0') {
        stock[i] = dest[i];
        i = i + 1;
    }
    s = i;
    i = 0;
    free(dest);
    while (src[i] != '\0') {
        stock[s] = src[i];
        i = i + 1;
        s = s + 1;
    }
    stock[s] = '\0';
    return (stock);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * 2);
    char *buff = malloc(sizeof(char) * 2);
    int return_read = 0;

    if (str == NULL || buff == NULL)
        return (NULL);
    my_memset(2, str, '\0');
    my_memset(2, buff, '\0');
    if (fd != -1) {
        while ((return_read = (read(fd, buff, 1))) == 1 && buff[0] != '\n')
            str = my_strcat_gnl(str, buff);
        if (return_read == 0 && str[0] == '\0') {
            free(str);
            free(buff);
            return (NULL);
        }
    }
    free(buff);
    return (str);
}
