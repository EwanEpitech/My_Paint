/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** compare two strings
*/

#include <stdbool.h>
#include <stddef.h>

bool my_strcmp(char *str1, char *str2)
{
    size_t i = 0;

    if (str1 == NULL || str2 == NULL)
        return false;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    if (str1[i] != '\0' || str2[i] != '\0')
        return false;
    return true;
}

bool my_strncmp(char *str1, char *str2, size_t n)
{
    size_t i = 0;

    if (str1 == NULL || str2 == NULL)
        return false;
    for (; str1[i] != '\0' && str2[i] != '\0' && i < n; i++)
        if (str1[i] != str2[i])
            return false;
    if (i < n)
        return false;
    return true;
}
