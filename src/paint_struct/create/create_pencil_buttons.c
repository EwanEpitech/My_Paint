/*
** EPITECH PROJECT, 2024
** create_pencil_buttons
** File description:
** init pencil_buttons struct
*/

#include "my_paint.h"

void create_pencil_buttons_part_two(pencil_buttons_t **pencil_buttons)
{
    (*pencil_buttons)->buttons[CIRCLE] = button_part_two(
    (*pencil_buttons)->buttons[CIRCLE], (sfVector2f){110, 50}, GREY);
    (*pencil_buttons)->buttons[SQUARE] = button_part_two(
    (*pencil_buttons)->buttons[SQUARE], (sfVector2f){110, 50}, GREY);
    (*pencil_buttons)->buttons[SIZE_PLUS] = button_part_two(
    (*pencil_buttons)->buttons[SIZE_PLUS], (sfVector2f){50, 50}, GREY);
    (*pencil_buttons)->buttons[SIZE_MINUS] = button_part_two(
    (*pencil_buttons)->buttons[SIZE_MINUS], (sfVector2f){50, 50}, GREY);
}

pencil_buttons_t *create_pencil_buttons(void)
{
    pencil_buttons_t *pencil_buttons = my_calloc(1, sizeof(pencil_buttons_t));

    if (pencil_buttons == NULL)
        return NULL;
    pencil_buttons->buttons[CIRCLE] = create_button("CIRCLE",
    &on_click_circle, (sfVector2f){500, 0});
    pencil_buttons->buttons[SQUARE] = create_button("SQUARE",
    &on_click_square, (sfVector2f){610, 0});
    pencil_buttons->buttons[SIZE_PLUS] = create_button("+",
    &on_click_size_plus, (sfVector2f){600, 50});
    pencil_buttons->buttons[SIZE_MINUS] = create_button("-",
    &on_click_size_minus, (sfVector2f){550, 50});
    create_pencil_buttons_part_two(&pencil_buttons);
    pencil_buttons->is_square = false;
    pencil_buttons->is_circle = true;
    return pencil_buttons;
}
