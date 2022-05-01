CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long
INCLUDES		= 	includes

LIBFT_PATH		= 	./libft/
SRCS_PATH		= 	./srcs/
MLX_PATH		= 	./minilibx_mms_20200219/

SRCS_FILES		= 	event.c get_next_line.c get_next_line_utils.c main.c \
					map.c player.c config_map_info.c \
					convert.c validate_filename.c \
					free.c validate_map.c check_num_elements.c

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_OBJS		= 	$(SRCS:.c=.o)

LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft
MLXMAKE			= 	$(MAKE) -C $(MLX_PATH)
MLXFLAG			=	-lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(MLX_PATH):
				$(GITMLX)

$(NAME):		$(MLX_PATH) $(SRCS_OBJS)
				$(LIBFTMAKE)
				$(MLXMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) $(MLXFLAG) -o $(NAME)

.c.o:
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(MLXMAKE) clean
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(RM) $(MLX_PATH)/libmlx.a
				$(RM) $(NAME) $(SRCS_OBJS)

re:				fclean all

.PHONY:			all clean fclean re