/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** error handling for signals
*/

#include <unistd.h>
#include <sys/wait.h>

void error_handling(int wait_for_status, int *returned_value)
{
    if (WTERMSIG(wait_for_status) == 8) {
        write(2, "Floating exception", 18);
        (*returned_value) += 8;
    }
    if (WTERMSIG(wait_for_status) == 11) {
        write(2, "Segmentation fault", 18);
        (*returned_value) += 11;
    }
    if (WCOREDUMP(wait_for_status) == 128) {
        write(2, " (core dumped)", 14);
        (*returned_value) += 128;
    }
    if (WTERMSIG(wait_for_status) > 0)
        write(2, "\n", 1);
}
