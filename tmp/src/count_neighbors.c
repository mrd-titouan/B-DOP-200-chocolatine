/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** count_neighbors
*/

#include "../include/gameoflife.h"

int count_neighbors2(gol_t *gol, int row, int col, int i)
{
    int count = 0;

    for (int j = col - 1; j <= col + 1; j++) {
        if (i == row && j == col)
            continue;
        if (i < 0 || i >= gol->rows || j < 0 || j >= gol->cols)
            continue;
        if (gol->board[i][j] == 'X')
            count++;
    }
    return count;
}

int count_neighbors(gol_t *gol, int row, int col)
{
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++)
        count += count_neighbors2(gol, row, col, i);
    return count;
}
