/*
** EPITECH PROJECT, 2024
** create_button.c
** File description:
** create a button
*/

#include "my_paint.h"

button_t button_part_two(button_t button, sfVector2f size, sfColor c)
{
    button.size = size;
    button.color = c;
    if (button.rect == NULL)
        return (button_t){0};
    sfRectangleShape_setPosition(button.rect, button.position);
    sfRectangleShape_setFillColor(button.rect, c);
    sfRectangleShape_setSize(button.rect, size);
    return button;
}

button_t create_button(char *text, button_func_t func, sfVector2f position)
{
    button_t *button = my_calloc(1, sizeof(button_t) + 1);
    button_t button_ = {0};

    if (button == NULL)
        return (button_t){0};
    button->text = text;
    button->is_active = false;
    button->func = func;
    button->rect = sfRectangleShape_create();
    button->position = position;
    if (button->rect == NULL)
        return (button_t){0};
    sfRectangleShape_setPosition(button->rect, position);
    button_ = *button;
    free(button);
    return button_;
}
