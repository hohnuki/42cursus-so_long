CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long
INCLUDES		= 	includes

LIBFT_PATH		= 	./libft/
SRCS_PATH		= 	./srcs/
#MLX_PATH		= 	./mlx_linux/

SRCS_FILES    	= 	$(SRCS_PATH)main.c $(SRCS_PATH)map.c $(SRCS_PATH)get_next_line.c $(SRCS_PATH)get_next_line_utils.c \
					$(SRCS_PATH)map_debug.c

SRCS_OBJS		= 	$(SRCS_FILES:.c=.o)

LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft
#MLXMAKE			= 	$(MAKE) -C $(MLX_PATH)
#MLXFLAG			= 	-Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
#GITMLX			= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux

all:			$(NAME)

#$(MLX_PATH):
#				$(GITMLX)

#$(NAME):		$(MLX_PATH) $(SRCS_OBJS)
$(NAME):		$(SRCS_OBJS)
				$(LIBFTMAKE)
				#$(MLXMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) -o $(NAME)
				#$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) $(MLXFLAG) -o $(NAME)

lib:
				$(LIBFTMAKE)

#mlx:
#				$(MLXMAKE)

.c.o:
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
#				$(MLXMAKE) clean
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
#				$(RM) $(MLX_PATH)/libmlx.a
				$(RM) $(NAME) $(SRCS_OBJS)

re:				fclean all

#.PHONY:			all clean fclean lib mlx re
.PHONY:			all clean fclean lib re