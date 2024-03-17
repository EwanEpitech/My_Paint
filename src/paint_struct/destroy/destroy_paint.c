/*
** EPITECH PROJECT, 2024
** destroy_paint.c
** File description:
** destroy struct paint
*/

#include "my_paint.h"

static void destroy_buttons(paint_t *paint)
{
    for (int i = 0; i < 8; i++) {
        sfRectangleShape_destroy(paint->buttons[i].rect);
    }
}

static void destroy_sliders(paint_t *paint)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(paint->slider[i].rect);
        sfRectangleShape_destroy(paint->slider[i].rect_);
        sfCircleShape_destroy(paint->slider[i].circle);
    }
}

static void destroy_pencil_buttons(paint_t *paint)
{
    sfTexture_destroy(paint->pencil_buttons->texture);
    sfSprite_destroy(paint->pencil_buttons->sprite);
    for (int i = 0; i < 4; i++)
        sfRectangleShape_destroy(paint->pencil_buttons->buttons[i].rect);
}

void free_paint(paint_t *paint)
{
    free(paint->color_view_return);
    free(paint->pencil_buttons);
    free(paint->tools->pencil->circle);
    free(paint->tools->pencil->square);
    free(paint->tools->pencil);
    free(paint->cursor);
    free(paint->screen);
    free(paint->drawing);
    free(paint->tools);
    free(paint);
}

void destroy_paint(paint_t *paint)
{
    destroy_buttons(paint);
    destroy_sliders(paint);
    destroy_pencil_buttons(paint);
    sfRectangleShape_destroy(paint->color_view_return->rect);
    sfSprite_destroy(paint->cursor->sprite);
    sfTexture_destroy(paint->cursor->texture);
    sfSprite_destroy(paint->drawing->sprite);
    sfRenderTexture_destroy(paint->drawing->texture);
    sfTexture_destroy(paint->drawing->background_texture);
    sfView_destroy(paint->drawing->view);
    sfView_destroy(paint->screen->view);
    sfRenderWindow_destroy(paint->screen->window);
    free_paint(paint);
}
