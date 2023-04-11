/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** main
*/

#include "../include/gameoflife.h"

int init_variables(gol_t *gol, char **av)
{
    if (!my_str_isnum(av[2])) {
        free(gol);
        return 84;
    }
    if ((gol->cols = get_cols(av[1])) == 84) {
        free(gol);
        return 84;
    }
    if ((gol->rows = get_rows(av[1])) == 84) {
        free(gol);
        return 84;
    }
    gol->iterations = atoi(av[2]);
    gol->board = load_2d_array_from_file(av);
    if (gol->board == NULL) {
        free(gol);
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    gol_t *gol = malloc(sizeof(gol_t));

    if (ac != 3) {
        free(gol);
        return 84;
    }
    if (error_case(av[1]) == 84)
        return 84;
    if (init_variables(gol, av) == 84)
        return 84;
    start_iteration(gol, gol->iterations);
    free_struct(gol);
    return 0;
}
