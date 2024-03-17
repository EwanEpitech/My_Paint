/*
** EPITECH PROJECT, 2024
** init_buttons.c
** File description:
** initialisations of all the buttons
*/

#include "my_paint.h"

bool init_buttons_edit(paint_t *paint)
{
    paint->buttons[PENCIL_BUTTON] = create_button("Pencil", &pencil_func,
    (sfVector2f){100, 50});
    paint->buttons[ERASER_BUTTON] = create_button("ERASER", &eraser_func,
    (sfVector2f){100, 100});
    paint->buttons[PENCIL_BUTTON] = button_part_two(
    paint->buttons[PENCIL_BUTTON], (sfVector2f){100, 50}, GREY);
    paint->buttons[ERASER_BUTTON] = button_part_two(
    paint->buttons[ERASER_BUTTON], (sfVector2f){100, 50}, GREY);
    if (paint->buttons[PENCIL_BUTTON].rect == NULL ||
        paint->buttons[ERASER_BUTTON].rect == NULL)
        return false;
    return true;
}

bool init_buttons_file(paint_t *paint)
{
    paint->buttons[NEW_BUTTON] = create_button("New File", &new_func,
    (sfVector2f){0, 50});
    paint->buttons[OPEN_BUTTON] = create_button("Open File", &open_func,
    (sfVector2f){0, 100});
    paint->buttons[SAVE_BUTTON] = create_button("Save File", &save_func,
    (sfVector2f){0, 150});
    paint->buttons[NEW_BUTTON] = button_part_two(paint->buttons[NEW_BUTTON],
    (sfVector2f){100, 50}, GREY);
    paint->buttons[OPEN_BUTTON] = button_part_two(paint->buttons[OPEN_BUTTON],
    (sfVector2f){100, 50}, GREY);
    paint->buttons[SAVE_BUTTON] = button_part_two(paint->buttons[SAVE_BUTTON],
    (sfVector2f){100, 50}, GREY);
    if (paint->buttons[NEW_BUTTON].rect == NULL ||
        paint->buttons[OPEN_BUTTON].rect == NULL ||
        paint->buttons[SAVE_BUTTON].rect == NULL
        || init_buttons_edit(paint) == false)
        return false;
    return true;
}

bool init_buttons(paint_t *paint)
{
    paint->buttons[FILE_BUTTON] = create_button("File", &file_func,
    (sfVector2f){0, 0});
    paint->buttons[EDIT_BUTTON] = create_button("Edit", &edit_func,
    (sfVector2f){100, 0});
    paint->buttons[HELP_BUTTON] = create_button("Help", &help_func,
    (sfVector2f){200, 0});
    paint->buttons[FILE_BUTTON] = button_part_two(paint->buttons[FILE_BUTTON],
    (sfVector2f){100, 50}, GREY);
    paint->buttons[EDIT_BUTTON] = button_part_two(paint->buttons[EDIT_BUTTON],
    (sfVector2f){100, 50}, GREY);
    paint->buttons[HELP_BUTTON] = button_part_two(paint->buttons[HELP_BUTTON],
    (sfVector2f){100, 50}, GREY);
    if (paint->buttons[FILE_BUTTON].rect == NULL ||
        paint->buttons[EDIT_BUTTON].rect == NULL ||
        paint->buttons[HELP_BUTTON].rect == NULL
        || init_buttons_file(paint) == false)
        return false;
    return true;
}
