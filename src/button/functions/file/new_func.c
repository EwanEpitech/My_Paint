/*
** EPITECH PROJECT, 2024
** new_func.c
** File description:
** new file
*/

#include "my_paint.h"

void new_func(void *data)
{
    paint_t *paint = (paint_t *)data;

    sfRectangleShape_setFillColor(paint->buttons[NEW_BUTTON].rect, LIGHT_BLUE);
    sfRectangleShape_setFillColor(paint->buttons[OPEN_BUTTON].rect, GREY);
    sfRectangleShape_setFillColor(paint->buttons[SAVE_BUTTON].rect, GREY);
    sfRenderTexture_clear(paint->drawing->texture, sfWhite);
}
