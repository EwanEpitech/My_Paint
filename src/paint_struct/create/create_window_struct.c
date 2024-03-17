/*
** EPITECH PROJECT, 2024
** create_paint.c
** File description:
** create struct paint
*/

#include "my_paint.h"

window_t *verif_window_struct(window_t *window)
{
    if (window->window == NULL) {
        sfView_destroy(window->view);
        free(window);
        return NULL;
    } else if (window->view == NULL) {
        sfRenderWindow_destroy(window->window);
        free(window);
        return NULL;
    }
    return window;
}

window_t *create_window_struct(int width, int height, char *title)
{
    window_t *window = my_calloc(1, sizeof(window_t) + 1);

    if (window == NULL)
        return NULL;
    window->window = create_window(width, height, title);
    window->view = create_view();
    window->width = width;
    window->height = height;
    if (verif_window_struct(window) == NULL)
        return NULL;
    return window;
}
