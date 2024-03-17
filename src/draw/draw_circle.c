/*
** EPITECH PROJECT, 2024
** draw_circle
** File description:
** display circle on rendertexture
*/

#include "my_paint.h"

void loop_circle(paint_t *paint, sfVector2f last_pt, sfVector2f dir, float len)
{
    int radius = CIRCLE_SIZE;
    sfVector2f point = {0, 0};
    sfCircleShape* circle = NULL;
    sfVector2f circle_pos = {0, 0};

    dir = (sfVector2f){dir.x / len, dir.y / len};
    for (float i = 0; i < len; i += 1) {
        circle = sfCircleShape_create();
        point = (sfVector2f){last_pt.x + dir.x * i, last_pt.y + dir.y * i};
        sfCircleShape_setRadius(circle, radius);
        sfCircleShape_setFillColor(circle, CIRCLE_COLOR);
        circle_pos = (sfVector2f){point.x - radius, point.y - radius};
        sfCircleShape_setPosition(circle, circle_pos);
        if (point.x >= 0 && point.x <= SFRTGS(DRAWING->texture).x
            && point.y >= 0 && point.y <= SFRTGS(DRAWING->texture).y)
            sfRenderTexture_drawCircleShape(DRAWING->texture, circle, NULL);
        sfCircleShape_destroy(circle);
    }
}

void draw_circle(paint_t *paint)
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
            loop_circle(paint, last_pt, dir, len);
        }
        last_pt = world;
        mouse_down = sfTrue;
    } else
        mouse_down = sfFalse;
    sfRenderTexture_setView(DRAWING->texture, SCREEN_VIEW);
}
