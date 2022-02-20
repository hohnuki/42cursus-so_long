#include "../includes/so_long.h"

void	assign_image(t_config *info)
{
	info->images.player = mlx_xpm_file_to_image(info->mlx, IMG_PLAYER, &info->images.image_size, &info->images.image_size);
	info->images.wall = mlx_xpm_file_to_image(info->mlx, IMG_WALL, &info->images.image_size, &info->images.image_size);
	info->images.collectible = mlx_xpm_file_to_image(info->mlx, IMG_COLLECTIBLE, &info->images.image_size, &info->images.image_size);
	info->images.exit = mlx_xpm_file_to_image(info->mlx, IMG_EXIT, &info->images.image_size, &info->images.image_size);
	info->images.empty = mlx_xpm_file_to_image(info->mlx, IMG_EMPTY, &info->images.image_size, &info->images.image_size);
}

void	display_map(t_config *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (info->map_info.width * PIXEL_SIZE), (info->map_info.height * PIXEL_SIZE), "so_long");
	assign_image(info);
	mlx_loop(info->mlx);
}

void	read_map(t_config *info)
{
	t_list	*guard_node;
	size_t	i;
	int fd;

	guard_node = ft_lstnew(NULL);
	info->map_info.guard_node = guard_node;
	i = 0;
	fd = open(info->filename, O_RDONLY);
	while (1)
	{
		char *line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&guard_node, ft_lstnew(line));
		i++;
	}
	close(fd);
	info->map_info.height = i;
	info->map_info.width = ft_strlen(guard_node->next->content);
//	print_map(info);
}