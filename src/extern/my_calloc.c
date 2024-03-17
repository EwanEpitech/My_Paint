/*
** EPITECH PROJECT, 2024
** my_calloc.c
** File description:
** alloc + memse
*/

#include <stdlib.h>

void *my_calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr == NULL)
        return NULL;
    for (size_t i = 0; i < nmemb * size; i++)
        ((char *)ptr)[i] = 0;
    return ptr;
}
