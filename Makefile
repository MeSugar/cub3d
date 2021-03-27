# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 20:04:32 by gdelta            #+#    #+#              #
#    Updated: 2021/03/27 20:00:41 by gdelta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

INCLUDES	=	./Includes

LIBFT_PATH	=	./Libft

LIBFT		=	./Libft/libft.a

MINILIB		=	./Minilib

SRCS		=	cub3d.c Utils/get_next_line.c Utils/whitespace_skip.c Utils/error_msgs.c Utils/finish_program.c \
				Parsing/config_parse.c Parsing/init.c Parsing/map_treat.c Parsing/map_format_check.c \
				Parsing/texture_treat.c Parsing/resolution_treat.c Parsing/color_treat.c \
				Drawing/create_walls_ceiling_floor.c Drawing/ray_values.c Drawing/create_sprite.c \
				Drawing/sprite_values.c Drawing/draw_screen.c Drawing/create_bitmap.c \
				Buttons/buttons.c Buttons/movements.c Buttons/turns.c

all : $(NAME)

$(NAME) : $(SRCS)
		@make bonus -C $(LIBFT_PATH)
		@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) -I $(INCLUDES) -I $(LIBFT_PATH) -I $(MINILIB) $(LIBFT) -lmlx -lm -framework OpenGL -framework AppKit

clean :
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(LIBFT)

fclean : clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re