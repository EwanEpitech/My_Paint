/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** return the len of a string
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
