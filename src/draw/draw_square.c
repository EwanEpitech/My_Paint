/*
** EPITECH PROJECT, 2024
** draw_square.c
** File description:
** draw a square on a given rendertexture
*/

#include "my_paint.h"

void loop_square(paint_t *paint, sfVector2f last_pt, sfVector2f dir, float len)
{
    int size_sqr = SQUARE_SIZE;
    sfVector2f point = {0, 0};
    sfRectangleShape *square = NULL;
    sfVector2f square_pos = {0, 0};

    dir = (sfVector2f){dir.x / len, dir.y / len};
    for (int i = 0; i < len; i++) {
        square = sfRectangleShape_create();
        point = (sfVector2f){last_pt.x + dir.x * i, last_pt.y + dir.y * i};
        sfRectangleShape_setSize(square, (sfVector2f){size_sqr, size_sqr});
        sfRectangleShape_setFillColor(square, SQUARE_COLOR);
        square_pos = (sfVector2f){point.x - size_sqr / 2,
        point.y - size_sqr / 2};
        sfRectangleShape_setPosition(square, square_pos);
        if (point.x >= 0 && point.x <= SFRTGS(DRAWING->texture).x
            && point.y >= 0 && point.y <= SFRTGS(DRAWING->texture).y)
            sfRenderTexture_drawRectangleShape(DRAWING->texture, square, NULL);
        sfRectangleShape_destroy(square);
    }
}

void draw_square(paint_t *paint)
{
    static sfVector2f last_pt = {0, 0};
    static sfBool mouse_down = sfFalse;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
    SCREEN_WNDW, mouse, SCREEN_VIEW);
    sfVector2f dir = {world.x - last_pt.x, world.y - last_pt.y};
    float len = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_down) {
            dir = (sfVector2f){world.x - last_pt.x, world.y - last_pt.y};
            len = sqrt(dir.x * dir.x + dir.y * dir.y);
            loop_square(paint, last_pt, dir, len);
        }
        last_pt = world;
        mouse_down = sfTrue;
    } else
        mouse_down = sfFalse;
    sfRenderTexture_setView(DRAWING->texture, SCREEN_VIEW);
}
