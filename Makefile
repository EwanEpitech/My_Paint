##
## EPITECH PROJECT, 2023
## My printf
## File description:
## Makefile
##

SOURCE	=	src/main.c														 \
			src/my_paint.c													 \
			src/button/functions/edit/pencil_functions/on_click_circle.c	 \
			src/button/functions/edit/pencil_functions/on_click_square.c	 \
			src/button/functions/edit/pencil_functions/on_click_size_minus.c \
			src/button/functions/edit/pencil_functions/on_click_size_plus.c	 \
			src/button/functions/edit/pencil_func.c							 \
			src/button/functions/edit/eraser_func.c							 \
			src/button/functions/file/new_func.c							 \
			src/button/functions/file/open_func.c							 \
			src/button/functions/file/save_func.c							 \
			src/button/functions/help/help_message_func.c					 \
			src/button/functions/main/file_func.c							 \
			src/button/functions/main/edit_func.c							 \
			src/button/functions/main/help_func.c							 \
			src/button/change_state.c										 \
			src/button/hover.c												 \
			src/button/is_clicked.c											 \
			src/button/set_color.c											 \
			src/cursor/set_cursor.c											 \
			src/draw/draw_circle.c											 \
			src/draw/draw_square.c											 \
			src/engine/view/create_view.c									 \
			src/engine/view/rotate_view.c									 \
			src/engine/window/create_window.c								 \
			src/engine/zoom/zoom_dezoom.c									 \
			src/env/verif_env.c												 \
			src/events/button/event_button.c								 \
			src/events/button/pencil_button.c								 \
			src/events/mouse_events/zoom_in_out_event.c 					 \
			src/events/resize/resize_event.c								 \
			src/events/save/save_drawing.c									 \
			src/events/sliders/event_sliders.c								 \
			src/events/handle_events.c										 \
			src/extern/my_calloc.c											 \
			src/extern/my_putstr.c											 \
			src/extern/my_strcmp.c											 \
			src/extern/my_strconcat.c										 \
			src/extern/my_strlen.c											 \
			src/loop/screen_loop.c											 \
			src/paint_struct/create/create_button.c							 \
			src/paint_struct/create/create_color_view_return.c				 \
			src/paint_struct/create/create_cursor.c							 \
			src/paint_struct/create/create_drawing_part.c					 \
			src/paint_struct/create/create_paint.c							 \
			src/paint_struct/create/create_pencil_buttons.c					 \
			src/paint_struct/create/create_tools.c							 \
			src/paint_struct/create/create_window_struct.c					 \
			src/paint_struct/create/sf_set_functions.c						 \
			src/paint_struct/destroy/destroy_paint.c						 \
			src/paint_struct/init/init_buttons.c							 \
			src/window_draw/window_draw.c									 \


OBJS	=	$(SOURCE:.c=.o)
OUT		=	my_paint
CC		=	gcc
CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
CFLAGS	+=	-W -Wall -Wextra -I./include -lm -g3
NAME	=	my_paint

all: $(OUT)

$(OUT): $(OBJS)
	@ $(CC) $(SOURCE) -o $(OUT) $(CFLAGS) $(CSFML_FLAGS)
	@ echo -e "\033[1;32m$(OUT) successfully created!\033[0m"

clean:
	@ $(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o *.out
	@ echo -e "\033[1;31mAll cleaned!\033[0m"

fclean: clean
	@ $(RM) $(OUT)
	@ echo -e "\033[1;31m$(OUT) (executable) is removed!\033[0m"

re: fclean all
