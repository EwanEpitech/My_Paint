/*
** EPITECH PROJECT, 2024
** on_click_circle.c
** File description:
** handle click on circle
*/

#include "my_paint.h"

void on_click_size_plus(void *data)
{
    int *circle_size = &((paint_t *)data)->tools->pencil->circle->size;
    int *square_size = &((paint_t *)data)->tools->pencil->square->size;
    bool *is_square = &((paint_t *)data)->pencil_buttons->is_square;
    bool *is_circle = &((paint_t *)data)->pencil_buttons->is_circle;

    if (*is_circle == true) {
        *circle_size += 2;
        if (*circle_size > 50)
            *circle_size = 50;
    }
    if (*is_square == true) {
        *square_size += 2;
        if (*square_size > 50)
            *square_size = 50;
    }
}
