/*
** EPITECH PROJECT, 2024
** button_hover.c
** File description:
** change state of button when mouse passed on it
*/

#include "my_paint.h"

void button_click_hover(button_t *button, sfVector2i mouse, bool edit_active)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse.x >= rec.left && mouse.x <= rec.left + rec.width &&
        mouse.y >= rec.top && mouse.y <= rec.top + rec.height
        && edit_active == true) {
            button->color = HOVER_GREY;
            sfRectangleShape_setFillColor(button->rect, button->color);
    } else {
        button->color = GREY;
        sfRectangleShape_setFillColor(button->rect, button->color);
    }
}

void button_hover(button_t *button, sfVector2i mouse, int i)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (mouse.x >= rec.left && mouse.x <= rec.left + rec.width &&
        mouse.y >= rec.top && mouse.y <= rec.top + rec.height) {
        if (i < 3 && button->is_active == true) {
            button->color = BLUE;
            return;
        }
        button->color = HOVER_GREY;
        sfRectangleShape_setFillColor(button->rect, button->color);
    } else {
        if (i < 3 && button->is_active == true) {
            button->color = LIGHT_BLUE;
            return;
        }
        button->color = GREY;
    }
}
