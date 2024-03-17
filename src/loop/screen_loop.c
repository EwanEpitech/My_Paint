/*
** EPITECH PROJECT, 2024
** screen_loop.c
** File description:
** loop for my_paint
*/

#include "my_paint.h"

static char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c;

    while (str[i] != '\0')
        i++;
    i--;
    while (i > j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i--;
        j++;
    }
    return str;
}

static char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;

    if (str == NULL)
        return NULL;
    for (i = 0; nb > 0; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    return my_revstr(str);
}

void display_brush_size(paint_t *paint)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/ttf.ttf");
    char *str = NULL;

    if (font == NULL || text == NULL)
        return;
    if (paint->pencil_buttons->is_circle == true)
        str = int_to_str(CIRCLE_SIZE);
    if (paint->pencil_buttons->is_square == true)
        str = int_to_str(SQUARE_SIZE);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){590, 100});
    sfRenderWindow_drawText(SCREEN_WNDW, text, NULL);
    free(str);
    sfText_destroy(text);
    sfFont_destroy(font);
}

bool screen_events(paint_t *paint)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(SCREEN_WNDW, &event))
        if (!handle_screen_events(paint, &event))
            return false;
    return true;
}

int paint_loop(paint_t *paint)
{
    sfClock *clock = sfClock_create();

    if (clock == NULL)
        return 84;
    sfRenderWindow_setFramerateLimit(SCREEN_WNDW, 200);
    while (sfRenderWindow_isOpen(SCREEN_WNDW)) {
        if (screen_events(paint) == false)
            return 84;
        set_cursor(paint);
        set_color_button(paint);
        if (sf_drawing_part(paint) == 84)
            return 84;
    }
    sfClock_destroy(clock);
    return true;
}
