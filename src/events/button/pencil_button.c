/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-ewan.tirlemont
** File description:
** pencil_button
*/

#include "my_paint.h"

void update_pencil_circle(paint_t *paint)
{
    if (paint->pencil_buttons->is_circle == true
        && paint->tools->is_eraser == false) {
        if (paint->pencil_buttons->is_square == true) {
            sfRectangleShape_setFillColor(
            paint->pencil_buttons->buttons[SQUARE].rect, GREY);
        }
        sfRectangleShape_setFillColor(
        paint->pencil_buttons->buttons[CIRCLE].rect, LIGHT_BLUE);
    } else {
        if (paint->pencil_buttons->is_square == true)
            sfRectangleShape_setFillColor(
            paint->pencil_buttons->buttons[0].rect, GREY);
        sfRectangleShape_setFillColor(paint->pencil_buttons->buttons[1].rect,
        LIGHT_BLUE);
    }
}

void update_pencil_square(paint_t *paint)
{
    if (paint->pencil_buttons->is_square == true
        && paint->tools->is_eraser == false) {
        if (paint->pencil_buttons->is_circle == true) {
            sfRectangleShape_setFillColor(
            paint->pencil_buttons->buttons[CIRCLE].rect, GREY);
        }
        sfRectangleShape_setFillColor(
        paint->pencil_buttons->buttons[SQUARE].rect, LIGHT_BLUE);
    } else {
        if (paint->pencil_buttons->is_circle == true)
            sfRectangleShape_setFillColor(
            paint->pencil_buttons->buttons[1].rect, GREY);
        sfRectangleShape_setFillColor(paint->pencil_buttons->buttons[0].rect,
        LIGHT_BLUE);
    }
}
