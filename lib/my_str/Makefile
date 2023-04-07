##
## EPITECH PROJECT, 2023
## makefile of root
## File description:
## Makefile
##

SRC	=	my_strncmp.c\
		my_swap.c\
		my_compute_power_rec.c\
		my_isneg.c\
		my_strcmp.c\
		my_strstr.c\
		my_strcpy.c\
		my_strlowcase.c\
		my_strncpy.c\
		my_str_is_alphanum.c\
		my_strupcase.c\
		my_strlen.c\
		len_of_an_str.c\
		count_words_in_str.c\
		not_a_char_in_str.c\
		is_sep_is_option.c\
		count_words_in_args.c\
		my_str_to_word_array.c\
		end_of_the_word.c\
		my_char_isalpha.c


DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

CPPFLAGS	=	-I include -ggdb3

NAME	=	../libmy_str.a

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
