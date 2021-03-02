NAME		=	cub3D

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

INCLUDES	=	./Includes

LIBFT_PATH	=	./Libft

LIBFT		=	./Libft/libft.a

MINILIB		=	libmlx.a mlx.h

SRCS		=	cub3d.c Utils/get_next_line.c Sources/whitespace_skip.c Sources/error_msgs.c Sources/init.c Config/config_parse.c Config/map_treat.c \
				Config/resolution_treat.c Config/color_treat.c Draw/draw_image.c

all : $(NAME)

$(NAME) : $(SRCS)
		@make bonus -C $(LIBFT_PATH)
		@$(CC) -g -o $(NAME) $(CFLAGS) $(SRCS) -I $(INCLUDES) -I $(LIBFT_PATH) $(LIBFT) -lmlx -lm -framework OpenGL -framework AppKit

clean :
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(LIBFT)

fclean : clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re