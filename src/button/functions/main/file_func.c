/*
** EPITECH PROJECT, 2024
** screen_loop.c
** File description:
** loop for my_paint
*/

#include "my_paint.h"

void file_func(void *data)
{
    bool *active_or_not = (bool *)data;

    if (*active_or_not == true)
        *active_or_not = false;
    else if (*active_or_not == false)
        *active_or_not = true;
}
