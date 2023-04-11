/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** error_case
*/

#include "../include/gameoflife.h"

int check_if_character_is_present(int fd)
{
    char buff[1];

    while (read(fd, buff, 1) != 0 && buff[0] != '\n')
        if (read(fd, buff, 1) == 0)
            return 84;
    return 0;
}

int check_all_character(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    char *tmp;
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return 84;
    tmp = malloc(sb.st_size);
    read(fd, tmp, sb.st_size);
    for (; tmp[i] != '\n'; i++);
    for (; i < sb.st_size; i++) {
        if (tmp[i] != '.' && tmp[i] != 'X' && tmp[i] != '\n') {
            free(tmp);
            return 84;
        }
    }
    free(tmp);
    return 0;
}

int check_all_line_equal(char const *filepath)
{
    int i = 0, len = 0, clen = 0, fd = open(filepath, O_RDONLY);
    char *tmp;
    struct stat sb;
    if (stat(filepath, &sb) == -1)
        return 84;
    tmp = malloc(sb.st_size);
    read(fd, tmp, sb.st_size);
    for (; tmp[i] != '\n'; i++);
    for (i++; tmp[i] != '\n'; i++)
        len++;
    for (i++; i < sb.st_size; i++) {
        clen++;
        if (tmp[i] == '\n' && (len != clen - 1)) {
            free(tmp);
            return 84;
        }
        if (tmp[i] == '\n') clen = 0;
    }
    free(tmp);
    return 0;
}

int check_existence_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "File doesn't exist\n", 20);
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int error_empty_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[1];

    if (read(fd, buff, 1) == 0) {
        write(2, "Error: Empty file\n", 19);
        return 84;
    }
    close(fd);
    return 0;
}
