/*
** EPITECH PROJECT, 2024
** verif_env.c
** File description:
** verif if we are in tty ( no display in env)
*/

#include "my_paint.h"

int verif_env_display(char **envp)
{
    for (int i = 0; envp[i] != NULL; i++)
        if (my_strncmp(envp[i], "DISPLAY", 7) == true)
            return 0;
    write(2, "DISPLAY not found\n", 18);
    write(2, "I see you trying to make me crash\n", 34);
    return 84;
}
