/*
** EPITECH PROJECT, 2024
** zoom_dezoom.c
** File description:
** function that zoom and dezoom my rendertexture by using a sfview
*/

#include "my_paint.h"

void zoom_dezoom(paint_t *paint)
{
    sfVector2u size = sfRenderWindow_getSize(SCREEN_WNDW);
    sfVector2f set_size = {size.x * DRAWING->zoom, size.y * DRAWING->zoom};

    sfView_setCenter(DRAWING->view, DRAWING->center);
    sfView_setSize(DRAWING->view, set_size);
    sfRenderTexture_setView(DRAWING->texture, DRAWING->view);
    sfRenderWindow_setView(SCREEN_WNDW, DRAWING->view);
    DRAWING->view_size = sfView_getSize(DRAWING->view);
}
