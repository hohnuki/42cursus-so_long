#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define PIXEL_SIZE 32

# define IMG_EMPTY			"images/empty.xpm"
# define IMG_WALL			"images/iMac.xpm"
# define IMG_COLLECTIBLE	"images/class.xpm"
# define IMG_EXIT			"images/python.xpm"
# define IMG_PLAYER			"images/c.xpm"
# define IMG_PLAYER2		"images/c++.xpm"

# define KEY_PRESS 2
# define EXPOSE_E 12
# define DESTROY_NOTIFY 17

# define NO_EVENT_MASK 0L

typedef struct s_map
{
	int		width;
	int		height;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	t_list	*guard_node;
	char	**map;
}	t_map;

typedef struct s_player
{
	int	postion_x;
	int	postion_y;
	int	pedometer;
	int	collectible_count;
	int	c_x;
	int	c_y;
	int	n_x;
	int	n_y;
}	t_player;

typedef struct s_image
{
	void	*player;
	void	*player2;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*empty;
	int		image_size;
}	t_image;

typedef struct s_info
{
	void		*mlx;
	void		*mlx_win;
	t_map		map_info;
	t_player	player_info;
	t_image		images;
	char		*filename;
}	t_info;

/* main.c */

/* validate_filename.c */
void	validate_filename(char *filename);
void	validate_map_smooth(t_info *info);

/* map.c */
void	assign_image(t_info *info);
void	ascii_to_xpm(t_info *info, char c, int i, int j);
void	list_to_window(t_info *info);
void	read_map(t_info *info);
void	display_map(t_info *info);

/* map_debug.c */
void	print_map(t_info *info);

/* map_debug_array.c */
void	print_map_array(t_info *info);

/* validate_map.c */
void	validate_map(t_info *info);
void	validate_map_rectangle(t_info *info);
void	validate_map_smooth(t_info *info);
void	validate_characters(t_info *info);
void	validate_enclose_wall(t_info *info);

/* free.c */
void	error_message_and_exit(char *message);
int		execute_exit(void);

/* config_map_info.c */
void	input_player_position(t_info *info);
void	count_collectable(t_info *info);

/* event.c */
int		key_hook(int keycode, t_info *info);
void	set_event(t_info *info);

/* player.c */
void	move_player(t_info *info, int keycode);

/* convert.c */
void	list_to_array(t_info *info);

/* chechk_num_elements.c */
void	check_num_element(t_info *info);

#endif