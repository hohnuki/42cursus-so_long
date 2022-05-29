#include "../includes/so_long.h"

void	assign_image(t_info *info)
{
	info->images.player = mlx_xpm_file_to_image(info->mlx, \
	IMG_PLAYER, &(info->images.image_size), &(info->images.image_size));
	if (info->images.player == NULL)
		error_message_and_exit("Error\nplayer_image not allocated.");
	info->images.player2 = mlx_xpm_file_to_image(info->mlx, \
	IMG_PLAYER2, &(info->images.image_size), &(info->images.image_size));
	if (info->images.player2 == NULL)
		error_message_and_exit("Error\nplayer2_image not allocated.");
	info->images.wall = mlx_xpm_file_to_image(info->mlx, \
	IMG_WALL, &info->images.image_size, &info->images.image_size);
	if (info->images.wall == NULL)
		error_message_and_exit("Error\nwall_image not allocated.");
	info->images.collectible = mlx_xpm_file_to_image(info->mlx, \
	IMG_COLLECTIBLE, &info->images.image_size, &info->images.image_size);
	if (info->images.collectible == NULL)
		error_message_and_exit("Error\ncollectible_image not allocated.");
	info->images.exit = mlx_xpm_file_to_image(info->mlx, \
	IMG_EXIT, &info->images.image_size, &info->images.image_size);
	if (info->images.exit == NULL)
		error_message_and_exit("Error\nexit_image not allocated.");
	info->images.empty = mlx_xpm_file_to_image(info->mlx, \
	IMG_EMPTY, &info->images.image_size, &info->images.image_size);
	if (info->images.empty == NULL)
		error_message_and_exit("Error\nempty_image not allocated.");
}

void	ascii_to_xpm(t_info *info, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.empty, i * PIXEL_SIZE, j * PIXEL_SIZE);
	else if (c == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.wall, i * PIXEL_SIZE, j * PIXEL_SIZE);
	else if (c == 'P' && info->map_info.collectible_count == \
	info->player_info.collectible_count)
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.player2, i * PIXEL_SIZE, j * PIXEL_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.player, i * PIXEL_SIZE, j * PIXEL_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.collectible, i * PIXEL_SIZE, j * PIXEL_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
		info->images.exit, i * PIXEL_SIZE, j * PIXEL_SIZE);
}

void	list_to_window(t_info *info)
{
	t_list	*node;
	int		i;
	int		j;

	node = info->map_info.guard_node;
	node = node->next;
	j = 0;
	while (node != NULL)
	{
		i = 0;
		while (i < info->map_info.width)
		{
			ascii_to_xpm(info, node->content[i], i, j);
			i++;
		}
		node = node->next;
		j++;
	}
}

void	display_map(t_info *info)
{
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		error_message_and_exit("Error\nmlx not initialized.");
	info->mlx_win = mlx_new_window(info->mlx, \
	(info->map_info.width * PIXEL_SIZE), \
	(info->map_info.height * PIXEL_SIZE), "so_long");
	if (info->mlx_win == NULL)
		error_message_and_exit("Error\nmlx_window not allocated.");
	assign_image(info);
	list_to_window(info);
}

void	read_map(t_info *info)
{
	size_t	i;
	char	*line;
	int		fd;

	info->map_info.guard_node = ft_lstnew(NULL);
	i = 0;
	fd = open(info->filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&info->map_info.guard_node, ft_lstnew(line));
		i++;
	}
	close(fd);
	validate_white_line(info);
	info->map_info.height = (int)i;
	info->map_info.width = \
	(int)ft_strlen(info->map_info.guard_node->next->content);
	input_player_position(info);
}
