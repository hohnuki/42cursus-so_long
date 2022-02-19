#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_list	*guard_node;
}	t_map;

typedef struct s_player
{
	int test;
}	t_player;

typedef struct s_config
{
	t_map *map_info;
	t_player *player_info;
	char *filename;
}	t_config;

/* main.c */
void	info_init(t_config *info);

/* map.c */
void	read_map(t_config *info);

/* map_debug.c */
void	print_map(t_config *info);

#endif