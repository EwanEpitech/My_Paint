/*
** EPITECH PROJECT, 2024
** window_draw.c
** File description:
** display on renderwindow
*/

#include "my_paint.h"

static int draw_pencil_button(sfRenderWindow *window, button_t *button)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/ttf.ttf");

    if (font == NULL)
        return 84;
    sfText_setFont(text, font);
    sfText_setString(text, button->text);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){button->position.x + 25,
    button->position.y + 10});
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    return 0;
}

static int draw_button(sfRenderWindow *window, button_t *button)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/ttf.ttf");

    if (font == NULL)
        return 84;
    sfText_setFont(text, font);
    sfText_setString(text, button->text);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){button->position.x + 25,
    button->position.y + 10});
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRectangleShape_setFillColor(button->rect, button->color);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    return 0;
}

static int draw_buttons(paint_t *paint)
{
    int return_value = 0;

    for (int i = 0; i < 3; i++)
        return_value = draw_button(SCREEN_WNDW, &paint->buttons[i]);
    if (paint->buttons[FILE_BUTTON].is_active == true) {
        for (int i = 3; i < 6; i++)
            return_value = draw_button(SCREEN_WNDW, &paint->buttons[i]);
    }
    if (paint->buttons[EDIT_BUTTON].is_active == true) {
        for (int i = 6; i < 8; i++)
            return_value = draw_button(SCREEN_WNDW, &paint->buttons[i]);
    }
    if (return_value == 84)
        return 84;
    return 0;
}

static int draw_pencil_buttons(paint_t *paint)
{
    int return_value = 0;

    if (paint->buttons[EDIT_BUTTON].is_active == true) {
        for (int i = 0; i < 2; i++)
            return_value = draw_pencil_button(SCREEN_WNDW,
            &paint->pencil_buttons->buttons[i]);
        for (int i = 2; i < 4; i++)
            return_value = draw_button(SCREEN_WNDW,
            &paint->pencil_buttons->buttons[i]);
        if (return_value == 84)
            return 84;
        sfRectangleShape_setFillColor(paint->color_view_return->rect,
        RGB_COLOR);
        sfRenderWindow_drawRectangleShape(SCREEN_WNDW,
        paint->color_view_return->rect, NULL);
    }
    return 0;
}

static void draw_sliders(paint_t *paint)
{
    if (paint->buttons[EDIT_BUTTON].is_active == true) {
        for (int i = 0; i < 3; i++) {
            sfRenderWindow_drawRectangleShape(SCREEN_WNDW,
            paint->slider[i].rect, NULL);
            sfRenderWindow_drawRectangleShape(SCREEN_WNDW,
            paint->slider[i].rect_, NULL);
            sfRenderWindow_drawCircleShape(SCREEN_WNDW,
            paint->slider[i].circle, NULL);
        }
    }
}

int sf_drawing_part(paint_t *paint)
{
    sfRenderWindow_clear(SCREEN_WNDW, NAVY);
    sfRenderTexture_display(DRAWING->texture);
    sfRenderWindow_setView(SCREEN_WNDW, DRAWING->view);
    sfRenderWindow_drawSprite(SCREEN_WNDW, DRAWING->sprite, NULL);
    if (draw_buttons(paint) == 84)
        return 84;
    if (draw_pencil_buttons(paint) == 84)
        return 84;
    draw_sliders(paint);
    if (paint->buttons[EDIT_BUTTON].is_active == true)
        display_brush_size(paint);
    sfRenderWindow_drawSprite(SCREEN_WNDW, paint->cursor->sprite, NULL);
    sfRenderWindow_setView(SCREEN_WNDW, SCREEN_VIEW);
    sfRenderWindow_display(SCREEN_WNDW);
    return 0;
}
