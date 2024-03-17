/*
** EPITECH PROJECT, 2024
** change_state.c
** File description:
** change the value of is_active
*/

#include "my_paint.h"

void change_button_state(bool *active_or_not)
{
    if (*active_or_not == true)
        *active_or_not = false;
    else if (*active_or_not == false)
        *active_or_not = true;
}
