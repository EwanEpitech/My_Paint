/*
** EPITECH PROJECT, 2024
** save_func.c
** File description:
** save the rendertexture into a sfimage that the function transform in a file
*/

#include "my_paint.h"

void save_func(void *data)
{
    paint_t *paint = (paint_t *)data;

    save_drawing(paint);
}
