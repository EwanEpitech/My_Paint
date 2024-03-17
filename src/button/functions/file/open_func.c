/*
** EPITECH PROJECT, 2024
** open_func.c
** File description:
** open (png, jpg, bmp and tga) file and replace actual rendertexture
** by the image file
*/

#include "my_paint.h"

char *get_file(void)
{
    char *filepath = NULL;
    size_t len = 0;

    my_putstr("Enter the file path: ");
    if (getline(&filepath, &len, stdin) == -1)
        return NULL;
    if (filepath == NULL)
        return NULL;
    if (filepath[my_strlen(filepath) - 1] == '\n')
        filepath[my_strlen(filepath) - 1] = '\0';
    if (open(filepath, O_RDONLY) == -1) {
        write(2, "File not found\n", 15);
        return NULL;
    }
    return filepath;
}

void open_func(void *data)
{
    paint_t *paint = (paint_t *)data;
    char *filepath = get_file();

    (void)paint;
    if (filepath == NULL)
        return;
    return;
}
