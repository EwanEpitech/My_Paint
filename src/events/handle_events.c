/*
** EPITECH PROJECT, 2024
** handle_events.c
** File description:
** handle all events from the loop program
*/

#include "my_paint.h"

static void draw_event(paint_t *paint)
{
    if (paint->pencil_buttons->is_circle == true)
        draw_circle(paint);
    if (paint->pencil_buttons->is_square == true)
        draw_square(paint);
}

static void screen_event(paint_t *paint, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(SCREEN_WNDW);
    if (event->type == sfEvtMouseWheelScrolled)
        zoom_in_out_event(paint, event);
    if (event->type == sfEvtResized)
        resize_event(paint, event);
    else
        draw_event(paint);
    if (KEY_PRESSED && KEY_CODE == sfKeyR)
        rotate_drawing(paint, 45);
}

static void handle_color_event(paint_t *paint)
{
    if (paint->pencil_buttons->is_circle == true
        && paint->tools->is_eraser == false)
        CIRCLE_COLOR = RGB_COLOR;
    if (paint->pencil_buttons->is_square == true
        && paint->tools->is_eraser == false)
        SQUARE_COLOR = RGB_COLOR;
}

static void update_pencil_buttons_color(paint_t *paint)
{
    update_pencil_circle(paint);
    update_pencil_square(paint);
}

bool handle_screen_events(paint_t *paint, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
    SCREEN_WNDW, mouse, SCREEN_VIEW);

    for (int i = 0; i < NB_SLIDERS; i++)
        if (event_sliders(paint, world, i) == false)
            return true;
    if (event_button(paint, world, event) == true)
        return true;
    update_pencil_buttons_color(paint);
    handle_color_event(paint);
    screen_event(paint, event);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderTexture_clear(DRAWING->texture, sfWhite);
    if (KEY_PRESSED && KEY_CODE == sfKeyS && KEYBOARD_PRESSED(sfKeyLControl))
        return save_drawing(paint);
    return true;
}
