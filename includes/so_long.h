#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"

/* main.c */

/* map.c */
void	read_map(char *file_name);

/* map_debug.c */
void	print_map(t_list *node);

#endif