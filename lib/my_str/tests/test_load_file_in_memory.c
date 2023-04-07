/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_load_file_in_memory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_str.h"

Test(load_file_in_memory, basic) {
    char *tkt = my_load_file_in_memory("Makefile");
    char *Makfefile_info = "##\n\
## EPITECH PROJECT, 2023\n\
## makefile\n\
## File description:\n\
## makefile\n\
##\n\
\n\
SRC     =\tmy_count_nb_char_in_str.c\t\t\t\t\t\\\n\
\t\t\tmy_is_alpha.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_is_lower.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_is_num.c\t\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_is_printable.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_is_upper.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_load_file_in_array.c\t\t\t\t\t\t\\\n\
\t\t\tmy_load_file_in_memory.c\t\t\t\t\t\\\n\
\t\t\tmy_put_char.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_put_str.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_rev_str.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_show_word_array.c\t\t\t\t\t\t\\\n\
\t\t\tmy_str_capitalize.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_cat.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_cmp.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_cpy.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_is_alpha.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_is_lower.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_is_num.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_is_printable.c\t\t\t\t\t\t\\\n\
\t\t\tmy_str_is_upper.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_len.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_low_case.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_n_cat.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_n_cmp.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_n_cpy.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_str.c\t\t\t\t\t\t\t\t\\\n\
\t\t\tmy_str_up_case.c\t\t\t\t\t\t\t\\\n\
\t\t\tspliter/add_word.c\t\t\t\t\t\t\t\\\n\
\t\t\tspliter/change_begin_str.c\t\t\t\t\t\\\n\
\t\t\tspliter/generate_tab.c\t\t\t\t\t\t\\\n\
\t\t\tspliter/str_only_contain_str_delimiter.c\t\\\n\
\t\t\tspliter/spliter.c\t\t\t\t\t\t\t\\\n\
\t\t\tmy_swap.c\t\t\t\t\t\t\t\t\t\\\n\
\n\
DIR_SRC\t=\t\t$(addprefix src/, $(SRC))\n\
\n\
TEST\t=\ttest_my_put_char.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_load_file_in_memory.c\t\t\t\t\t\\\n\
\t\t\ttest_my_put_str.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_rev_str.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_show_word_array.c\t\t\t\t\t\\\n\
\t\t\ttest_my_str_capitalize.c\t\t\t\t\t\\\n\
\t\t\ttest_my_str_cat.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_cmp.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_cpy.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_is_alpha.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_is_lower.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_is_num.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_is_printable.c\t\t\t\t\t\\\n\
\t\t\ttest_my_str_is_upper.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_len.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_low_case.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_n_cat.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_n_cmp.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_n_cpy.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_str.c\t\t\t\t\t\t\t\\\n\
\t\t\ttest_my_str_up_case.c\t\t\t\t\t\t\\\n\
\t\t\ttest_my_swap.c\t\t\t\t\t\t\t\t\\\n\
\t\t\ttest_spliter.c\t\t\t\t\t\t\t\t\\\n\
\n\
DIR_TESTS\t=\t\t$(addprefix tests/, $(TEST))\n\
\n\
OBJ\t\t\t=\t\t$(DIR_SRC:.c=.o)\n\
\n\
OBJ_TESTS\t=\t\t$(DIR_TESTS:.c=.o)\n\
\n\
CPPFLAGS\t= -I include\n\
\n\
NAME\t\t=\t\t../libmy_str.a\n\
\n\
$(NAME):\t\t$(OBJ)\n\
\tar rcs $(NAME) $(OBJ)\n\
\n\
all: $(NAME)\n\
\n\
clean:\n\
\trm -f $(OBJ)\n\
\n\
fclean: clean\n\
\trm -rf unit_tests\n\
\trm -rf *.gcov\n\
\trm -f $(NAME)\n\
\n\
re: fclean all\n\
\n\
unit_tests: re\n\
\tmkdir unit_tests\n\
\t\tgcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS) -I include/\\\n\
\t\t--coverage -lcriterion\n\
\n\
tests_run:\tunit_tests\n\
\t\t\t./unit_tests/unit_tests\n\
\n\
.PHONY: all clean fclean re tests_run\n\
";
    cr_assert_str_eq(tkt, Makfefile_info);
    free(tkt);
}

Test(load_file_in_memory, rigor) {
    char *str = NULL;
    cr_assert_eq(my_put_str(str), -1);
}
