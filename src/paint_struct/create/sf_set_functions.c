/*
** EPITECH PROJECT, 2024
** set_functions
** File description:
** set data into data
*/

#include "my_paint.h"

void sf_set_drawing(paint_t *paint)
{
    sfVector2u size = sfRenderTexture_getSize(DRAWING->texture);
    float width_draw = size.x / DRAWING->zoom;
    float height_draw = size.y / DRAWING->zoom;

    sfView_setCenter(DRAWING->view, DRAWING->center);
    sfView_setSize(DRAWING->view, (sfVector2f){width_draw, height_draw});
    sfSprite_setTexture(DRAWING->sprite,
    sfRenderTexture_getTexture(DRAWING->texture), sfTrue);
    sfRenderTexture_clear(DRAWING->texture, sfWhite);
}

void sf_set_screen(paint_t *paint)
{
    sfVector2u size = sfRenderWindow_getSize(SCREEN_WNDW);
    unsigned int width_ = size.x / 2.0f;
    unsigned int height_ = size.y / 2.0f;

    DRAWING->zoom = 1.0f;
    DRAWING->view_size = (sfVector2f){size.x, size.y};
    DRAWING->center = (sfVector2f){width_, height_};
    sfView_setCenter(SCREEN->view, (sfVector2f){width_, height_});
    sfView_setSize(SCREEN->view, (sfVector2f){size.x, size.y});
    sfRenderWindow_setView(SCREEN->window, SCREEN->view);
}
