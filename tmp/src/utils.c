/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** utils
*/

#include "../include/gameoflife.h"

void print_board(char **board, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

void start_iteration(gol_t *gol, int iterations)
{
    if (iterations == 0) {
        for (int i = 0; gol->board[i]; i++)
            printf("%s\n", gol->board[i]);
    }
    for (int i = 0; i < iterations; i++) {
        next_generation(gol);
        if (i == iterations - 1)
            print_board(gol->board, gol->rows, gol->cols);
    }
}

void free_struct(gol_t *gol)
{
    for (int i = 0; i < gol->rows; i++)
        free(gol->board[i]);
    free(gol->board);
    free(gol);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}
