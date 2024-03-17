/*
** EPITECH PROJECT, 2024
** event_button.c
** File description:
** events handing for buttons
*/

#include "my_paint.h"

bool event_button(paint_t *paint, sfVector2f world, sfEvent *event)
{
    for (int i = 0; i < REAL_NB_BUTTONS; i++)
        button_hover(&paint->buttons[i], (sfVector2i){world.x, world.y}, i);
    for (int i = 0; i < REAL_NB_PENCIL_BUTTONS; i++)
        button_hover(&paint->pencil_buttons->buttons[i],
        (sfVector2i){world.x, world.y}, i);
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button ==
        sfMouseLeft && event_button_click(paint, world) == true)
        return true;
    return false;
}
