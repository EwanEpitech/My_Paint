/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-ewan.tirlemont
** File description:
** create_color_view_return
*/

#include "my_paint.h"

rectangle_shape_t *create_color_view_return(void)
{
    rectangle_shape_t *color_view_return = my_calloc(1,
    sizeof(rectangle_shape_t));

    if (color_view_return == NULL)
        return NULL;
    color_view_return->rect = sfRectangleShape_create();
    color_view_return->position = (sfVector2f){800, 30};
    color_view_return->size = (sfVector2f){100, 100};
    color_view_return->color = sfBlack;
    sfRectangleShape_setSize(color_view_return->rect,
    color_view_return->size);
    sfRectangleShape_setPosition(color_view_return->rect,
    color_view_return->position);
    sfRectangleShape_setFillColor(color_view_return->rect,
    color_view_return->color);
    sfRectangleShape_setOutlineColor(color_view_return->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(color_view_return->rect, 5);
    return color_view_return;
}
