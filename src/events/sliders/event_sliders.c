/*
** EPITECH PROJECT, 2024
** event_sliders.c
** File description:
** handle slider color event
*/

#include "my_paint.h"

bool is_mouse_over_slider(slider_t slider, sfVector2f mouse)
{
    sfFloatRect rect;

    if (slider.circle == NULL)
        return false;
    rect = sfCircleShape_getGlobalBounds(slider.circle);
    if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width &&
        mouse.y >= rect.top && mouse.y <= rect.top + rect.height)
        return true;
    return false;
}

static void color_value_under_zero(paint_t *paint, int i)
{
    sfCircleShape_setPosition(paint->slider[i].circle,
    (sfVector2f){sfRectangleShape_getPosition(paint->slider[i].rect).x
    - (paint->slider[i].circle_size.x / 2),
    paint->slider[i].circle_pos.y});
    paint->slider[i].color_value = 0;
    sfRectangleShape_setSize(paint->slider[i].rect_,
    (sfVector2f){paint->slider[i].color_value, 20});
}

static void color_value_above_255(paint_t *paint, int i)
{
    sfCircleShape_setPosition(paint->slider[i].circle,
    (sfVector2f){sfRectangleShape_getPosition(paint->slider[i].rect).x
    + paint->slider[i].rect_size.x - (paint->slider[i].circle_size.x / 2),
    paint->slider[i].circle_pos.y});
    paint->slider[i].color_value = paint->slider[i].rect_size.x;
    sfRectangleShape_setSize(paint->slider[i].rect_,
    (sfVector2f){paint->slider[i].color_value, 20});
}

static void color_value_moved(paint_t *paint, int i, int x)
{
    sfCircleShape_setPosition(paint->slider[i].circle,
    (sfVector2f){sfRectangleShape_getPosition(paint->slider[i].rect).x
    + x - (paint->slider[i].circle_size.x / 2),
    paint->slider[i].circle_pos.y});
    sfRectangleShape_setSize(paint->slider[i].rect_,
    (sfVector2f){paint->slider[i].color_value, 20});
}

bool handling_color_value(paint_t *paint, sfVector2f mouse, int i)
{
    int x = 0;
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(
    (const sfCircleShape *)paint->slider[i].circle);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        x = mouse.x - sfRectangleShape_getPosition(paint->slider[i].rect).x;
        paint->slider[i].color_value = x;
        if (paint->slider[i].color_value > paint->slider[i].rect_size.x) {
            color_value_above_255(paint, i);
            return true;
        }
        if (paint->slider[i].color_value < 0)
            color_value_under_zero(paint, i);
        else
            color_value_moved(paint, i, x);
    }
    return true;
}

bool event_sliders(paint_t *paint, sfVector2f mouse, int i)
{
    if (is_mouse_over_slider(paint->slider[i], mouse) == true)
        if (handling_color_value(paint, mouse, i) == true)
            return true;
    return true;
}
