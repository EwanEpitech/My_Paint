/*
** EPITECH PROJECT, 2024
** pencil_func.c
** File description:
** active the pencil -> set the color to black
*/

#include "my_paint.h"

void pencil_func(void *data)
{
    paint_t *paint = (paint_t *)data;
    bool *is_eraser = &paint->tools->is_eraser;

    CIRCLE_COLOR = sfBlack;
    SQUARE_COLOR = sfBlack;
    *is_eraser = false;
}
