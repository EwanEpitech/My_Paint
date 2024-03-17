/*
** EPITECH PROJECT, 2024
** help_message_func.c
** File description:
** print in terminal help message with all functioannlities
*/

#include "my_paint.h"

void help_message_part_two(void)
{
    my_putstr("Edit:\n");
    my_putstr("- Pencil: Draw with the pencil and chose the form\n"
    "- Choose the color with the color sliders\n");
    my_putstr("- Change the size of the pencil with the size buttons\n");
    my_putstr("- Eraser: Erase the drawing\n\n");
    my_putstr("Rotate: Rotate the drawing with R\n");
    my_putstr("Zoom: Zoom in and out with the mouse wheel\n");
    my_putstr("Resize: Resize the drawing with the window\n");
    my_putstr("Help: Print this message\n");
    my_putstr("Use SPACE to refresh the drawing\n");
    my_putstr("Use CTRL + S to save the drawing\n");
}

void help_message_func(void *data)
{
    paint_t *paint = (paint_t *)data;

    (void)paint;
    my_putstr("Welcome to my_paint\n\n");
    my_putstr("Made by: \n");
    my_putstr("Ewan Tirlemont - ewan.tirlemont@epitech.eu\n");
    my_putstr("Pauline Seret - pauline.seret@epitech.eu\n\n");
    my_putstr("You can use the following functionalities:\n\n");
    my_putstr("File:\n");
    my_putstr("- New: Create a new drawing\n");
    my_putstr("- Open: Open a drawing\n");
    my_putstr("- Save: Save the drawing\n\n");
    help_message_part_two();
}
