/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** Find the number of rows and cols on the file.
** Load a file in an array.
*/

#include "../include/gameoflife.h"
#include <fcntl.h>

int get_rows(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int rows = 0;
    char buf;

    if (fd == -1)
        return 84;
    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n')
            rows++;
    }
    close(fd);
    return rows;
}

int get_cols(char const * filepath)
{
    char buff[1] = {0};
    int result = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return 84;
    while (read(fd, buff, 1) != 0 && buff[0] != '\n')
        result++;
    close(fd);
    return result;
}

char **load_2d_array_from_file(char **av)
{
    char *buffer = NULL;
    char **array;
    int size = 0;
    int read_val = 0;
    int fd = open(av[1], O_RDONLY);
    struct stat buf;

    if (fd == -1)
        return (NULL);
    if (stat(av[1], &buf) == -1)
        return (NULL);
    size = buf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if ((read_val = read(fd, buffer, size)) == -1)
        return (NULL);
    buffer[read_val] = '\0';
    array = my_second_str_to_word_array(buffer, '\n');
    close(fd);
    free(buffer);
    return (array);
}
