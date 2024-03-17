/*
** EPITECH PROJECT, 2024
** my_paint.c
** File description:
** paint main part (like a main)
*/

#include "my_paint.h"

int my_paint(void)
{
    paint_t *paint = create_paint();
    int status = 0;

    if (paint == NULL)
        return 84;
    status = paint_loop(paint);
    destroy_paint(paint);
    if (status == 84)
        return 84;
    return 0;
}
