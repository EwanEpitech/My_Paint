/*
** EPITECH PROJECT, 2024
** save_drawing.c
** File description:
** function to save the rendertexture !
*/

#include "my_paint.h"

static bool free_name_and_extension(char **name, char **extension)
{
    free(*name);
    free(*extension);
    return false;
}

static bool free_name(char **name)
{
    free(*name);
    return false;
}

bool getline_name_and_extension(char **name, char **extension, size_t *size)
{
    my_putstr("Enter the name of the screenshot: ");
    if (getline(name, size, stdin) == -1)
        return false;
    my_putstr("Enter the extension of the screenshot (png, jpg, bmp, tga): ");
    if (getline(extension, size, stdin) == -1)
        return false;
    if ((*name)[my_strlen((*name)) - 1] == '\n')
        (*name)[my_strlen((*name)) - 1] = '\0';
    if ((*extension)[my_strlen((*extension)) - 1] == '\n')
        (*extension)[my_strlen((*extension)) - 1] = '\0';
    if ((*name) == NULL || (*extension) == NULL || (*name)[0] == '\n'
        || (*extension)[0] == '\n')
        return false;
    if (!my_strcmp(*extension, "png") && !my_strcmp(*extension, "jpg")
        && !my_strcmp(*extension, "bmp") && !my_strcmp(*extension, "tga")) {
        write(2, "Invalid extension\n", 18);
        return false;
    }
    return true;
}

bool concat_verif_path(char **name, char **extension, size_t *size)
{
    *name = my_strconcat(my_strconcat(*name, "."), *extension);
    if (*name == NULL)
        return false;
    (*extension) = NULL;
    my_putstr("You want to save the screenshot as: ");
    my_putstr(*name);
    my_putstr(" ? (y for yes, n for no, default: yes): ");
    if (getline(extension, size, stdin) == -1)
        return false;
    if ((*extension)[my_strlen((*extension)) - 1] == '\n')
        (*extension)[my_strlen((*extension)) - 1] = '\0';
    if (my_strcmp(*extension, "n") == true)
        return free_name(name);
    else if (my_strcmp(*extension, "y") == true)
        my_putstr("Saving screenshot...\n");
    else {
        write(2, "Invalid input\n", 14);
        return free_name_and_extension(name, extension);
    }
    return true;
}

bool save_image(sfImage **image, char *name, const sfTexture *texture)
{
    *image = sfTexture_copyToImage(texture);
    if (*image == NULL)
        return false;
    sfImage_saveToFile(*image, name);
    return true;
}

bool save_drawing(paint_t *paint)
{
    const sfTexture *texture = sfRenderTexture_getTexture(DRAWING->texture);
    sfImage *image = NULL;
    char *name = NULL;
    char *extension = NULL;
    size_t size = 0;

    if (texture == NULL || paint == NULL)
        return true;
    if (getline_name_and_extension(&name, &extension, &size) == false)
        return true;
    if (concat_verif_path(&name, &extension, &size) == false)
        return true;
    if (save_image(&image, name, texture) == false)
        return free_name_and_extension(&name, &extension);
    free_name_and_extension(&name, &extension);
    my_putstr("Screenshot saved\n");
    sfImage_destroy(image);
    return true;
}
