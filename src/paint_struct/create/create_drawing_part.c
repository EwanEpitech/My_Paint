/*
** EPITECH PROJECT, 2024
** create_paint.c
** File description:
** create struct paint
*/

#include "my_paint.h"

drawing_part_t *return_null_three(drawing_part_t *draw)
{
    sfSprite_destroy(draw->sprite);
    sfRenderTexture_destroy(draw->texture);
    sfView_destroy(draw->view);
    free(draw);
    return NULL;
}

drawing_part_t *return_null_two(drawing_part_t *draw)
{
    sfSprite_destroy(draw->sprite);
    sfRenderTexture_destroy(draw->texture);
    free(draw);
    return NULL;
}

drawing_part_t *return_null(drawing_part_t *draw)
{
    free(draw);
    return NULL;
}

drawing_part_t *create_drawing_part(void)
{
    drawing_part_t *draw = my_calloc(1, sizeof(drawing_part_t) + 1);

    if (draw == NULL)
        return NULL;
    draw->sprite = sfSprite_create();
    if (draw->sprite == NULL)
        return return_null(draw);
    draw->texture = sfRenderTexture_create(WIDTH, HEIGHT, sfTrue);
    if (draw->texture == NULL) {
        sfSprite_destroy(draw->sprite);
        return return_null(draw);
    }
    draw->view = sfView_create();
    if (draw->view == NULL)
        return return_null_two(draw);
    draw->background_texture = sfTexture_createFromFile(BG_SPRITE_FILE, NULL);
    if (draw->background_texture == NULL)
        return return_null_three(draw);
    draw->zoom = 1.0f;
    return draw;
}
