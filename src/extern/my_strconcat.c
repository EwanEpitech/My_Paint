/*
** EPITECH PROJECT, 2024
** my_strconcat
** File description:
** concatenate two strings into one
*/

char *my_strconcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
