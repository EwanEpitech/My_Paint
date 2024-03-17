/*
** EPITECH PROJECT, 2024
** screen_loop.c
** File description:
** loop for my_paint
*/

#include "my_paint.h"

void help_func(void *data)
{
    bool *active_or_not = (bool *)data;

    if (*active_or_not == true) {
        *active_or_not = false;
    } else if (*active_or_not == false) {
        help_message_func(active_or_not);
        *active_or_not = true;
    }
}
