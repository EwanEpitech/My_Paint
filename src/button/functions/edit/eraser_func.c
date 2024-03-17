/*
** EPITECH PROJECT, 2024
** eraser_func.c
** File description:
** change CIRCLE and SQUARE color by white
*/

#include "my_paint.h"

void eraser_func(void *data)
{
    paint_t *paint = (paint_t *)data;
    bool *is_eraser = &paint->tools->is_eraser;

    CIRCLE_COLOR = sfWhite;
    SQUARE_COLOR = sfWhite;
    *is_eraser = true;
}
