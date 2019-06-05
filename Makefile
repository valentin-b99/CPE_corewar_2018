##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC_A		=	./asm/src/main.c								\
				./asm/src/op.c									\
				./asm/src/header_and_checks_for_it.c			\
				./asm/src/separate_elem_in_list.c				\
				./asm/src/labels.c								\
				./asm/src/find_instruction_check_td.c			\
				./asm/src/getting_type_descriptor.c				\
				./asm/src/pointers.c							\
				./asm/src/pointers_next.c						\
				./asm/src/write_and_check_if_empty.c			\
				./asm/src/init_linked_list.c					\
				./asm/src/insert_element_in_linked_list.c		\
				./asm/src/delete_element_in_linked_list.c		\
				./asm/src/clear_dlist.c							\
				./asm/src/str_to_word_array_cor.c				\
				./asm/src/check_quotes.c						\
				./asm/src/check_errors_name.c					\
				./asm/src/header_name_and_comment.c

SRC_C		=	./corewar/src/main.c

#OBJ		=		$(SRC:.c=.o)

NAME	=		asm/asm

all:	$(NAME)	clean

$(NAME):	$(SRC)
			(cd ./asm/lib && make)
			gcc -g3 -o $(NAME) $(SRC_A) -Lasm/lib/. -lmy -Wall -Wextra
			(cd ./corewar/lib && make)
			gcc -g3 -o corewar/corewar $(SRC_C) -Lcorewar/lib/. -lmy -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all clean

auteur:
		echo $(USER) > Manon
