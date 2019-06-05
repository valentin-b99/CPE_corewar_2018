##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile lib
##

SRC	= ./binary_conversion.c \
	  ./hexa_conversion.c \
	  ./my_compute_power_rec.c \
	  ./my_compute_square_root.c \
	  ./my_find_prime_sup.c \
	  ./my_is_prime.c \
	  ./my_isneg.c \
	  ./my_put_nbr.c \
	  ./my_put_other_nbr.c \
	  ./my_putchar.c \
	  ./my_putstr.c \
	  ./my_putstr_printf.c \
	  ./my_revstr.c \
	  ./my_showmem.c \
	  ./my_showstr.c \
	  ./my_str_isalpha.c \
	  ./my_str_islower.c \
	  ./my_str_isnum.c \
	  ./my_str_isprintable.c \
	  ./my_str_isupper.c \
	  ./my_strcapitalize.c \
	  ./my_strcat.c \
	  ./my_strcmp.c \
	  ./my_strcpy.c \
	  ./my_strlen.c \
	  ./my_strlowcase.c \
	  ./my_strncat.c \
	  ./my_strncmp.c \
	  ./my_strncpy.c \
	  ./my_strstr.c \
	  ./my_strupcase.c \
	  ./my_swap.c \
	  ./octal_conversion.c \
	  ./s_flag.c \
	  ./p_flag.c \
	  ./c_flag.c \
	  ./i_and_d_flag.c \
	  ./u_flag.c \
	  ./s_lower_flag.c \
	  ./s_cap_flag.c \
	  ./o_flag.c \
	  ./x_flag.c \
	  ./x_cap_flag.c \
	  ./b_flag.c \
	  ./dash_flag.c \
	  ./mod_flag.c \
	  ./delete_space.c \
	  ./my_getnbr.c	\
	  ./get_next_line.c \
	  ./my_memset.c \
	  ./my_str_to_word_array_space.c \
	  ./my_str_to_word_array.c \
	  ./my_strdup.c \
	  ./length.c	\
	  ./my_printf.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

all:	$(NAME)	clean

$(NAME):	$(OBJ)
			ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all clean

auteur:
		echo $(USER) > Manon
