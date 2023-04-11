/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct gol {
        int rows;
        int cols;
        char **board;
        char **new_board;
        int iterations;
    } gol_t;
#endif
