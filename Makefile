##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		utilities/create_window.c	\
		utilities/analyse_events.c	\
		utilities/create_image.c	\
		utilities/destroy_image.c	\
		utilities/update_image.c	\
		utilities/draw_img.c	\
		utilities/add_images_to_lst.c	\
		utilities/add_images_sheet_to_lst.c	\
		utilities/add_musics.c	\
		utilities/manage_buttons.c	\
		utilities/manage_mouse_move.c	\
		utilities/manage_click.c	\
		utilities/manage_realeased.c	\
		utilities/create_sounds.c	\
		utilities/set_all_img.c	\
		utilities/close_window_in_game.c	\
		set_pos.c	\
		is_clicked.c	\
		launch_robot.c	\
		move_robot.c	\
		launch_game_over.c	\
		update_pos.c	\
		print_help.c	\
		update_music.c	\
		draw_points.c	\
		check_points.c	\
		start_random_music.c	\
		restart.c	\
		fs_get_number_from_first_line.c	\

SRC_LIB	=	lib/my/my_put_nbr.c 	\
			lib/my/my_putchar.c 	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_compute_power_rec.c	\

OBJ	=	$(SRC_LIB:.c=.o)

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

CFLAGS 	=	-I./include/ -L./lib/my/ -lmy -Werror -Wall	\
			-Wextra -l csfml-graphics -l csfml-system -l csfml-audio

NAME	=	my_hunter

all: libmy.a
	gcc -o $(NAME) $(SRC) $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f lib/my/libmy.a

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
