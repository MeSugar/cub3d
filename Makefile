NAME		=	cub3D

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

LIBFT_PATH	=	./Libft

LIBFT		=	./Libft/libft.a

MINILIB		=	libmlx.a mlx.h

SRCS		=	main.c 

all : $(NAME)

$(NAME) : $(SRCS)
		@make bonus -C $(LIBFT_PATH)
		@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBFT) -lmlx -lm -framework OpenGL -framework AppKit

clean :
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(LIBFT)

fclean : clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re