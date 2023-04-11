/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** handling_error
*/

#include "../include/gameoflife.h"

int error_from_line(char const *filepath)
{
    if (check_all_character(filepath) == 84) {
        write(2, "A character differs from '.' or 'X'\n", 37);
        return 84;
    }
    if (check_all_line_equal(filepath) == 84) {
        write(2, "Number of cols not equal\n", 26);
        return 84;
    }
    return 0;
}

int error_case(char const *filepath)
{
    if (check_existence_file(filepath) == 84)
        return 84;
    if (error_empty_file(filepath) == 84)
        return 84;
    if (error_from_line(filepath) == 84)
        return 84;
    return 0;
}
