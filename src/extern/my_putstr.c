/*
** EPITECH PROJECT, 2024
** my_putrstr
** File description:
** display a string
*/

#include "my_paint.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
