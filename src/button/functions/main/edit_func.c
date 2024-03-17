/*
** EPITECH PROJECT, 2024
** screen_loop.c
** File description:
** loop for my_paint
*/

#include "my_paint.h"

void edit_func(void *data)
{
    bool *active_or_not = (bool *)data;

    change_button_state(active_or_not);
}
