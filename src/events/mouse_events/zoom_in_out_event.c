/*
** EPITECH PROJECT, 2024
** zoom_in_out_event.c
** File description:
** event for scrolling
*/

#include "my_paint.h"

void zoom_in_out_event(paint_t *paint, sfEvent *event)
{
    if (event->mouseWheelScroll.delta > 0)
        DRAWING->zoom += 0.05;
    else
        DRAWING->zoom -= 0.05;
    if (DRAWING->zoom < 0.5)
        DRAWING->zoom = 0.5;
    if (DRAWING->zoom > 2.5)
        DRAWING->zoom = 2.5;
    zoom_dezoom(paint);
}
