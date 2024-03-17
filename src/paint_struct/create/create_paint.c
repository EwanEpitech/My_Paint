/*
** EPITECH PROJECT, 2024
** create_paint.c
** File description:
** create struct paint
*/

#include "my_paint.h"

void init_rectangle_shape(sfVector2f pos, slider_t **slider)
{
    (*slider)->rect = sfRectangleShape_create();
    (*slider)->rect_position = pos;
    (*slider)->rect_size = (sfVector2f){255, 20};
    (*slider)->rect_color = sfWhite;
    sfRectangleShape_setSize((*slider)->rect, (*slider)->rect_size);
    sfRectangleShape_setPosition((*slider)->rect, (*slider)->rect_position);
    sfRectangleShape_setFillColor((*slider)->rect, (*slider)->rect_color);
    sfRectangleShape_setOutlineColor((*slider)->rect, sfBlack);
    sfRectangleShape_setOutlineThickness((*slider)->rect, 2);
}

bool init_slider(slider_t *slider, sfColor color, sfVector2f position)
{
    init_rectangle_shape(position, &slider);
    slider->circle = sfCircleShape_create();
    slider->circle_size = (sfVector2f){25, 25};
    slider->circle_pos = (sfVector2f){position.x - (slider->circle_size.x / 2),
    position.y - (slider->circle_size.y - slider->rect_size.y) / 2};
    slider->circle_color = color;
    slider->rect_ = sfRectangleShape_create();
    slider->rect_position_ = position;
    slider->rect_size_ = (sfVector2f){0, 20};
    slider->rect_color_ = color;
    slider->color_value = 0;
    sfRectangleShape_setSize(slider->rect_, slider->rect_size_);
    sfRectangleShape_setPosition(slider->rect_, slider->rect_position_);
    sfRectangleShape_setFillColor(slider->rect_, slider->rect_color_);
    sfCircleShape_setRadius(slider->circle, slider->circle_size.x / 2);
    sfCircleShape_setPosition(slider->circle, slider->circle_pos);
    sfCircleShape_setFillColor(slider->circle, slider->circle_color);
    sfCircleShape_setOutlineColor(slider->circle, sfBlack);
    sfCircleShape_setOutlineThickness(slider->circle, 2);
    return true;
}

bool init_sliders(paint_t *paint)
{
    init_slider(&paint->slider[RED_], sfRed, (sfVector2f){960, 30});
    init_slider(&paint->slider[GREEN_], sfGreen, (sfVector2f){960, 70});
    init_slider(&paint->slider[BLUE_], sfBlue, (sfVector2f){960, 110});
    return true;
}

paint_t *create_paint(void)
{
    paint_t *paint = my_calloc(1, sizeof(paint_t) + 1);

    if (paint == NULL)
        return NULL;
    paint->screen = create_window_struct(WIDTH, HEIGHT, "My_Paint");
    paint->drawing = create_drawing_part();
    paint->tools = create_tools();
    paint->cursor = create_cursor();
    paint->pencil_buttons = create_pencil_buttons();
    paint->color_view_return = create_color_view_return();
    if (init_buttons(paint) == false || init_sliders(paint) == false)
        return NULL;
    if (PAINT_NULL_1 || PAINT_NULL_2 || PAINT_NULL_3 || PAINT_NULL_4) {
        free(paint);
        return NULL;
    }
    sf_set_screen(paint);
    sf_set_drawing(paint);
    return paint;
}
