/*
** EPITECH PROJECT, 2024
** create_view
** File description:
** idem
*/

#include "my_paint.h"

sfView *create_view(void)
{
    sfView *view = sfView_create();

    if (view == NULL)
        return NULL;
    return view;
}
