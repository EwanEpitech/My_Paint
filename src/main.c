/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of my_paint project
*/

#include "my_paint.h"

int main(UNUSED int argc, UNUSED char **argv, char **envp)
{
    if (envp[0] == NULL)
        return 84;
    if (verif_env_display(envp) == 84)
        return 84;
    return my_paint();
}
