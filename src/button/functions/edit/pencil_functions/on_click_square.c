/*
** EPITECH PROJECT, 2024
** on_click_circle.c
** File description:
** handle click on circle
*/

#include "my_paint.h"

void on_click_square(void *data)
{
    bool *is_square = &((paint_t *)data)->pencil_buttons->is_square;
    bool *is_circle = &((paint_t *)data)->pencil_buttons->is_circle;

    if (*is_square == true) {
        *is_square = false;
        *is_circle = true;
    } else {
        *is_square = true;
        *is_circle = false;
    }
}
