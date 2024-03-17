/*
** EPITECH PROJECT, 2024
** create_window
** File description:
** idem
*/

#include "my_paint.h"

sfRenderWindow *create_window(int width, int height, char *title)
{
    sfRenderWindow *w = sfRenderWindow_create((sfVideoMode){width, height, 32},
    title, sfDefaultStyle, NULL);

    if (w == NULL)
        return NULL;
    return w;
}
