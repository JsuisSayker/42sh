/*
** EPITECH PROJECT, 2023
** end_of_the_word
** File description:
** my str to word array side function
*/

void end_of_the_word(char **array_words, int i, int *char_in_str, int *count)
{
    array_words[i][(*char_in_str)] = '\0';
    (*count) += 1;
    (*char_in_str) = 0;
}
