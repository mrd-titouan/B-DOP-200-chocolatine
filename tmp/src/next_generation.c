/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** next_generation
*/

#include "../include/gameoflife.h"

void next_generation_condition(gol_t *gol, int count, int i, int j)
{
    if (gol->board[i][j] == 'X') {
        if (count <= 1 || count >= 4)
            gol->new_board[i][j] = '.';
        else
            gol->new_board[i][j] = 'X';
    } else {
        if (count == 3)
            gol->new_board[i][j] = 'X';
        else
            gol->new_board[i][j] = '.';
    }
}

void next_generation(gol_t *gol)
{
    int count = 0;

    gol->new_board = malloc(gol->rows * sizeof(char *));
    for (int i = 0; i < gol->rows; i++) {
        gol->new_board[i] = malloc(gol->cols * sizeof(char));
        for (int j = 0; j < gol->cols; j++) {
            count = count_neighbors(gol, i, j);
            next_generation_condition(gol, count, i, j);
        }
    }
    for (int i = 0; i < gol->rows; i++) {
        for (int j = 0; j < gol->cols; j++)
            gol->board[i][j] = gol->new_board[i][j];
    }
    for (int i = 0; i < gol->rows; i++)
        free(gol->new_board[i]);
    free(gol->new_board);
}
