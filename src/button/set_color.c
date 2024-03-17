/*
** EPITECH PROJECT, 2024
** set_color.c
** File description:
** change the color of the RectangleShape
*/

#include "my_paint.h"

void condition_color_button(paint_t *paint, int i, sfVector2i mouse)
{
    if (paint->buttons[i].is_active == true) {
        paint->buttons[i].color = LIGHT_BLUE;
        button_hover(&paint->buttons[i], mouse, i);
    } else {
        paint->buttons[i].color = GREY;
        button_hover(&paint->buttons[i], mouse, i);
    }
}

void set_color_button(paint_t *paint)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(SCREEN_WNDW,
        sfMouse_getPositionRenderWindow(SCREEN_WNDW), SCREEN_VIEW);

    for (int i = 0; i < 3; i++)
        condition_color_button(paint, i, (sfVector2i){mouse.x, mouse.y});
}
