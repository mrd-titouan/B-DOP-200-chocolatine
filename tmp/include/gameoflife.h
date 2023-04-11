/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** include
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <limits.h>
    #include <string.h>
    #include "sys/wait.h"
    #include "sys/types.h"
    #include <errno.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "struct.h"

    // file.c
    int get_rows(char const * filepath);
    int get_cols(char const * filepath);
    char **load_2d_array_from_file(char **av);

    // count_neighbors.c
    int count_neighbors(gol_t *gol, int row, int col);

    // next_generation.c
    void next_generation(gol_t *gol);

    // utils.c
    void print_board(char **board, int rows, int cols);
    void start_iteration(gol_t *gol, int iterations);
    void free_struct(gol_t *gol);
    int my_str_isnum(char const *str);

    // my_second_str_to_word_array.c
    char **my_second_str_to_word_array(char* str, char sep);

    // handling_error.c
    int error_from_line(char const *filepath);
    int error_case(char const *filepath);

    // error_case.c
    int check_all_line_equal(char const *filepath);
    int check_all_character(char const *filepath);
    int check_if_character_is_present(int fd);
    int check_existence_file(char const *filepath);
    int error_empty_file(char const *filepath);
#endif
