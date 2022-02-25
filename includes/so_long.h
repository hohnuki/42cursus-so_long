#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx_mms/mlx.h"

# define PIXEL_SIZE 32

# define IMG_EMPTY			"images/empty.xpm"
# define IMG_WALL			"images/wall.xpm"
# define IMG_COLLECTIBLE	"images/shuriken.xpm"
# define IMG_EXIT			"images/sasuke.xpm"
# define IMG_PLAYER			"images/naruto.xpm"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct s_map
{
	int	width;
	int	height;
	int player_count;
	int collectible_count;
	int exit_count;
	t_list	*guard_node;
	char	**map;
}	t_map;

typedef struct s_player
{
	int postion_x;
	int postion_y;
	int pedometer;
	int collectible_count;
}	t_player;

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*empty;
	int		image_size;
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

/* validate_filename.c */
void	validate_filename(t_config *info, char *filename);
void	validate_map_smooth(t_config *info);

/* map.c */
void	assign_image(t_config *info);
void	ascii_to_xpm(t_config *info, char c, int i, int j);
void	list_to_window(t_config *info);
void	read_map(t_config *info);
void	display_map(t_config *info);

/* map_debug.c */
void	print_map(t_config *info);

/* map_debug_array.c */
void	print_map_array(t_config *info);

/* validate_map.c */
void	validate_map(t_config *info);
void	validate_map_rectangle(t_config *info);
void	validate_map_smooth(t_config *info);
void	validate_characters(t_config *info);
void	validate_enclose_wall(t_config *info);

/* free.c */
int	mlx_free(t_config *info);

/* config_map_info.c */
void	input_player_position(t_config *info);
void	count_collectable(t_config *info);

/* event.c */
int		key_hook(int keycode, t_config *info);
void	set_event(t_config *info);

/* player.c */
void	print_pedometer(t_config *info);
void	swap_position(t_config *info, int current_x, int current_y, int next_x, int next_y);
void	move_player(t_config *info, int keycode);

/* convert.c */
void	list_to_array(t_config **info);

#endif