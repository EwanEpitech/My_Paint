/*
** EPITECH PROJECT, 2024
** is_clicked.c
** File description:
** check if button_click or not
*/

#include "my_paint.h"

void pencil_button_click(button_t *button, sfVector2i mouse, paint_t *paint)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
        && mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
        if (button->func == NULL)
            return;
        button->func(paint);
        return;
    }
}

void button_click(button_t *button, sfVector2i mouse, paint_t *paint, int i)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width
        && mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
        if (button->func == NULL)
            return;
        if (i < 3)
            button->func(&paint->buttons[i].is_active);
        else
            button->func(paint);
    }
}

bool event_button_click(paint_t *p, sfVector2f world)
{
    for (int i = 0; i < 3; i++)
        button_click(&p->buttons[i], (sfVector2i){world.x, world.y}, p, i);
    if (p->buttons[FILE_BUTTON].is_active == true) {
        for (int i = 3; i < 6; i++)
            button_click(&p->buttons[i], (sfVector2i){world.x, world.y}, p, i);
    }
    if (p->buttons[EDIT_BUTTON].is_active == true) {
        for (int i = 6; i < 8; i++)
            button_click(&p->buttons[i], (sfVector2i){world.x, world.y}, p, i);
    }
    if (p->buttons[EDIT_BUTTON].is_active == true) {
        for (int i = 0; i < REAL_NB_PENCIL_BUTTONS; i++)
            pencil_button_click(&p->pencil_buttons->buttons[i],
            (sfVector2i){world.x, world.y}, p);
    }
    return true;
}
