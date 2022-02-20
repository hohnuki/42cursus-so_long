#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define PIXEL_SIZE 20

# define IMG_EMPTY 			"../images/empty.xpm"
# define IMG_WALL 			"../images/wall.xpm"
# define IMG_COLLECTIBLE	"../images/shuriken.xpm"
# define IMG_EXIT 			"../images/sasuke.xpm"
# define IMG_PLAYER 		"../images/naruto.xpm"

typedef struct s_map
{
	int	width;
	int	height;
	t_list	*guard_node;
}	t_map;

typedef struct s_player
{
	int test;
}	t_player;

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*empty;
}	t_image;

typedef struct s_config
{
	void *mlx;
	void *mlx_win;
	t_map map_info;
	t_player player_info;
	t_image images;
	char *filename;
}	t_config;

/* main.c */
void	info_init(t_config *info);

/* map.c */
void	assign_image(t_config *info);
void	read_map(t_config *info);
void	display_map(t_config *info);

/* map_debug.c */
void	print_map(t_config *info);

#endif