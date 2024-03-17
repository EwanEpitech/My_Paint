/*
** EPITECH PROJECT, 2022
** STRUCT MY_HUNTER
** File description:
** STRUCTURES
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#ifndef MY_PAINT_H
    #define MY_PAINT_H
    #define UNUSED __attribute__((unused))
    #define WIDTH 1280
    #define HEIGHT 720
    #define SCREEN_W paint->screen->width
    #define SCREEN_H paint->screen->height
    #define SCREEN_WNDW paint->screen->window
    #define SCREEN_VIEW paint->screen->view
    #define SCREEN paint->screen
    #define BG_SPRITE_FILE "assets/background/background.png"
    #define DRAWING paint->drawing
    #define SCREEN paint->screen
    #define SFRTGS sfRenderTexture_getSize
    #define CIRCLE_COLOR paint->tools->pencil->circle->color
    #define SQUARE_COLOR paint->tools->pencil->square->color
    #define RAND_COLOR rand() % 255, rand() % 255, rand() % 255, 255
    #define CIRCLE_SIZE paint->tools->pencil->circle->size
    #define SQUARE_SIZE paint->tools->pencil->square->size
    #define ZOOM DRAWING->zoom
    #define GREY sfColor_fromRGBA(200, 200, 200, 255)
    #define HOVER_GREY sfColor_fromRGBA(150, 150, 150, 255)
    #define NAVY sfColor_fromRGBA(0, 0, 128, 255)
    #define LIGHT_BLUE sfColor_fromRGBA(173, 216, 230, 255)
    #define BLUE sfColor_fromRGBA(39, 142, 245, 255)
    #define KEY_PRESSED event->type == sfEvtKeyPressed
    #define KEY_CODE event->key.code
    #define KEYBOARD_PRESSED sfKeyboard_isKeyPressed
    #define REAL_NB_BUTTONS 8
    #define REAL_NB_PENCIL_BUTTONS 4
    #define NB_SLIDERS 3
    #define RED_VALUE paint->slider[RED_].color_value
    #define GREEN_VALUE paint->slider[GREEN_].color_value
    #define BLUE_VALUE paint->slider[BLUE_].color_value
    #define RGB_COLOR sfColor_fromRGB(RED_VALUE, GREEN_VALUE, BLUE_VALUE)
    #define PAINT_NULL_1 paint->screen == NULL || paint->drawing == NULL
    #define PAINT_NULL_2 paint->tools == NULL || paint->cursor == NULL
    #define PAINT_NULL_3 paint->pencil_buttons == NULL
    #define PAINT_NULL_4 paint->color_view_return == NULL

typedef struct rectangle_shape_s {
    sfRectangleShape *rect;
    sfVector2f position;
    sfVector2f size;
    sfColor color;
}rectangle_shape_t;

typedef struct drawing_part_s {
    sfView *view;
    sfSprite *sprite;
    sfRenderTexture *texture;
    sfVector2f center;
    float zoom;
    sfTexture *background_texture;
    sfVector2f view_size;
}drawing_part_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfView *view;
    int width;
    int height;
}window_t;

typedef struct circle_s {
    sfVector2f pos;
    sfColor color;
    int size;
}circle_t;

typedef struct square_s {
    sfVector2f pos;
    sfColor color;
    int size;
}square_t;

typedef struct pencil_s {
    circle_t *circle;
    square_t *square;
}pencil_t;

typedef struct tools_s {
    pencil_t *pencil;
    bool is_eraser;
}tools_t;

typedef struct cursor_s {
    sfTexture *texture;
    sfSprite *sprite;
}cursor_t;

enum button_type {
    FILE_BUTTON,
    EDIT_BUTTON,
    HELP_BUTTON,
    NEW_BUTTON,
    OPEN_BUTTON,
    SAVE_BUTTON,
    PENCIL_BUTTON,
    ERASER_BUTTON,
    HELP_FUNCTION
};

typedef void (*button_func_t)(void *data);

typedef struct button_s {
    bool is_active;
    char *text;
    sfColor color;
    sfVector2f size;
    sfVector2f position;
    button_func_t func;
    sfRectangleShape *rect;
} button_t;

enum pencil_button {
    CIRCLE,
    SQUARE,
    SIZE_PLUS,
    SIZE_MINUS
};
typedef struct pencil_buttons_s {
    button_t buttons[4];
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    bool is_square;
    bool is_circle;
}pencil_buttons_t;


enum slider_color {
    RED_,
    GREEN_,
    BLUE_
};

typedef struct slider_s {
    sfRectangleShape *rect;
    sfVector2f rect_position;
    sfVector2f rect_size;
    sfColor rect_color;
    sfCircleShape *circle;
    sfVector2f circle_pos;
    sfVector2f circle_size;
    sfColor circle_color;
    sfRectangleShape *rect_;
    sfVector2f rect_position_;
    sfVector2f rect_size_;
    sfColor rect_color_;
    int color_value;
}slider_t;

typedef struct paint_s {
    window_t *screen;
    drawing_part_t *drawing;
    tools_t *tools;
    cursor_t *cursor;
    button_t buttons[REAL_NB_BUTTONS];
    pencil_buttons_t *pencil_buttons;
    slider_t slider[NB_SLIDERS];
    rectangle_shape_t *color_view_return;
}paint_t;

// my_paint.c
int my_paint(void);
// create_paint.c
paint_t *create_paint(void);
drawing_part_t *create_drawing_part(void);
tools_t *create_tools(void);
window_t *create_window_struct(int width, int height, char *title);
// destroy_paint.c
void destroy_paint(paint_t *paint);
// create_window.c
sfRenderWindow *create_window(int width, int height, char *title);
// create_view.c
sfView *create_view(void);
// screen_loop.c
int paint_loop(paint_t *paint);
// extern_functions
void my_putstr(char *str);
int my_strlen(char *str);
void *my_calloc(size_t nmemb, size_t size);
char *my_strconcat(char *dest, char *src);
bool my_strcmp(char *str1, char *str2);
bool my_strncmp(char *str1, char *str2, size_t n);
// draw_circle.c
void draw_circle(paint_t *paint);
// draw_square.c
void draw_square(paint_t *paint);
// zoom_dezoom.c
void zoom_dezoom(paint_t *paint);
// save_drawing.c
bool save_drawing(paint_t *paint);
// rotate_view.c
void rotate_drawing(paint_t *paint, int angle);
// zoom_in_out_event.c
void zoom_in_out_event(paint_t *paint, sfEvent *event);
// create_cursor.c
cursor_t *create_cursor(void);
// create_button.c
button_t create_button(char *text, button_func_t func, sfVector2f position);
button_t button_part_two(button_t button, sfVector2f size, sfColor c);
// button_click.c
void button_click(button_t *button, sfVector2i mouse, paint_t *paint, int i);
// window_draw.c
int sf_drawing_part(paint_t *paint);
// button_hover.c
void button_hover(button_t *button, sfVector2i mouse_position, int i);
void button_click_hover(button_t *button, sfVector2i mouse, bool edit_active);
// init_buttons.c
bool init_buttons(paint_t *paint);
// file_func.c
void file_func(void *data);
// edit_func.c
void edit_func(void *data);
// help_func.c
void help_func(void *data);
// is_clicked.c
bool event_button_click(paint_t *p, sfVector2f world);
// event_button.c
bool event_button(paint_t *paint, sfVector2f world, sfEvent *event);
// set_cursor.c
bool set_cursor(paint_t *paint);
// handle_events.c
bool handle_screen_events(paint_t *paint, sfEvent *event);
// new_func.c
void new_func(void *data);
// open_func.c
void open_func(void *data);
char *get_file(void);
void sf_set_functions(paint_t *paint, sfImage *image, sfTexture *texture);
// save_func.c
void save_func(void *data);
// pencil_func.c
void pencil_func(void *data);
// eraser_func.c
void eraser_func(void *data);
// help_message_func.c
void help_message_func(void *data);
// change_state.c
void change_button_state(bool *active_or_not);
// set_color_button.c
void set_color_button(paint_t *paint);
// on_click_circle.c
void on_click_circle(void *data);
// on_click_square.c
void on_click_square(void *data);
// on_click_size_plus.c
void on_click_size_plus(void *data);
// on_click_size_minus.c
void on_click_size_minus(void *data);
// create_pencil_buttons.c
pencil_buttons_t *create_pencil_buttons(void);
// sf_set_funtcions.c
void sf_set_screen(paint_t *paint);
void sf_set_drawing(paint_t *paint);
// create_pencil_buttons.c
pencil_buttons_t *create_pencil_buttons(void);
// resize_event.c
void resize_event(paint_t *paint, sfEvent *event);
// verif_env.c
int verif_env_display(char **envp);
// init_slider.c
bool event_sliders(paint_t *paint, sfVector2f mouse, int i);
// pencil_buttons.c
void update_pencil_circle(paint_t *paint);
void update_pencil_square(paint_t *paint);
// create_color_view_return.c
rectangle_shape_t *create_color_view_return(void);
// display_brush_size
void display_brush_size(paint_t *paint);
#endif /* !MY_PAINT_H */
