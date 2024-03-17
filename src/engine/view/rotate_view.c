/*
** EPITECH PROJECT, 2024
** rotate_view.c
** File description:
** rotate the view
*/

#include "my_paint.h"

void rotate_drawing(paint_t *paint, int angle)
{
    static int rotation = 0;

    rotation += angle;
    if (rotation >= 360)
        rotation = 0;
    sfView_setRotation(DRAWING->view, rotation);
    sfRenderTexture_setView(DRAWING->texture, DRAWING->view);
    sfRenderWindow_setView(SCREEN_WNDW, DRAWING->view);
}
