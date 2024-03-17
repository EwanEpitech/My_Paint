/*
** EPITECH PROJECT, 2024
** resize_event.c
** File description:
** handle zoom
*/

#include "my_paint.h"

void swap_zoom(float *zoom, float *tmp, float zoom_value, paint_t *paint)
{
    *tmp = *zoom;
    *zoom = zoom_value;
    zoom_dezoom(paint);
    *zoom = *tmp;
}

void section_resizing_width(paint_t *paint, int diff, float tmp, int diff2)
{
    if (diff < 100 || diff2 < 100)
        swap_zoom(&ZOOM, &tmp, 1.2, paint);
    if ((diff > 100 && diff < 300) || (diff2 > 100 && diff2 < 200))
        swap_zoom(&ZOOM, &tmp, 1.4, paint);
    if ((diff > 200 && diff < 300) || (diff2 > 300 && diff2 < 500))
        swap_zoom(&ZOOM, &tmp, 1.7, paint);
    if ((diff > 500 && diff < 700) || (diff2 > 300 && diff2 < 400))
        swap_zoom(&ZOOM, &tmp, 2.3, paint);
    if ((diff > 700 && diff < 900) || (diff2 > 400 && diff2 < 470))
        swap_zoom(&ZOOM, &tmp, 3, paint);
    if ((diff > 900 && diff < 1100) || (diff2 > 470 && diff2 < 570))
        swap_zoom(&ZOOM, &tmp, 5, paint);
    if ((diff > 1100 && diff < 130) || (diff2 > 570 && diff2 < 600))
        swap_zoom(&ZOOM, &tmp, 6, paint);
    if (diff2 > 600 && diff2 < 630)
        swap_zoom(&ZOOM, &tmp, 8, paint);
    if (diff > 1300 && diff < 1500)
        swap_zoom(&ZOOM, &tmp, 9, paint);
    if (diff > 1500 || (diff2 > 630 && diff2 > 630))
        swap_zoom(&ZOOM, &tmp, 15, paint);
}

void resize_event(paint_t *paint, sfEvent *event)
{
    float tmp = 0;

    if (event->size.width > WIDTH) {
        ZOOM += (event->size.height - WIDTH) / 1000;
        zoom_dezoom(paint);
        ZOOM -= (event->size.height - WIDTH) / 1000;
    }
    if (event->size.height > HEIGHT) {
        ZOOM += (event->size.height - HEIGHT) / 1000;
        zoom_dezoom(paint);
        ZOOM -= (event->size.height - HEIGHT) / 1000;
    }
    if (event->size.width < WIDTH || event->size.height < HEIGHT)
        section_resizing_width(paint, WIDTH - event->size.width, tmp, HEIGHT -
        event->size.height);
}
