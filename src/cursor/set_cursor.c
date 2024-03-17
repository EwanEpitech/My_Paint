/*
** EPITECH PROJECT, 2024
** set_cursor.c
** File description:
** set the cursor
*/

#include "my_paint.h"

bool set_cursor(paint_t *paint)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
    SCREEN_WNDW, mouse, SCREEN_VIEW);
    sfFloatRect size = sfSprite_getGlobalBounds(paint->cursor->sprite);
    sfVector2f pos = (sfVector2f){world.x - size.width / 2,
    world.y - size.height / 2};

    sfRenderWindow_setMouseCursorVisible(SCREEN_WNDW, sfFalse);
    sfSprite_setPosition(paint->cursor->sprite, (sfVector2f){pos.x, pos.y});
    return true;
}
