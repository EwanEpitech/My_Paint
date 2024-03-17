/*
** EPITECH PROJECT, 2024
** create_paint.c
** File description:
** create struct paint
*/

#include "my_paint.h"

tools_t *free_circle(tools_t *tools)
{
    free(tools->pencil->circle);
    free(tools->pencil);
    free(tools);
    return NULL;
}

tools_t *free_square(tools_t *tools)
{
    free(tools->pencil->square);
    free(tools->pencil);
    free(tools);
    return NULL;
}

tools_t *create_tools(void)
{
    tools_t *tools = my_calloc(1, sizeof(tools_t) + 1);

    if (tools == NULL)
        return NULL;
    tools->pencil = my_calloc(1, sizeof(pencil_t) + 1);
    if (tools->pencil == NULL) {
        free(tools);
        return NULL;
    }
    tools->pencil->circle = my_calloc(1, sizeof(circle_t) + 1);
    tools->pencil->square = my_calloc(1, sizeof(square_t) + 1);
    if (tools->pencil->circle == NULL)
        return free_circle(tools);
    if (tools->pencil->square == NULL)
        return free_square(tools);
    tools->pencil->circle->color = sfBlack;
    tools->pencil->circle->size = 10;
    tools->pencil->square->color = sfBlack;
    tools->pencil->square->size = 10;
    return tools;
}
