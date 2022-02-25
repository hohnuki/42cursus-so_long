#include "../includes/so_long.h"

char	**free_array(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	return (NULL);
}

int		mlx_free(t_config *info)//TODO:listをフリーしていない.
{
	if (info->map_info.map != NULL)
		info->map_info.map = free_array(info->map_info.map);
	if (info->images.empty != NULL)
		mlx_destroy_image(info->mlx_win, info->images.empty);
	if (info->images.exit != NULL)
		mlx_destroy_image(info->mlx_win, info->images.exit);
	if (info->images.collectible != NULL)
		mlx_destroy_image(info->mlx_win, info->images.collectible);
	if (info->images.player != NULL)
		mlx_destroy_image(info->mlx_win, info->images.player);
	if (info->images.wall != NULL)
		mlx_destroy_image(info->mlx_win, info->images.wall);
	if (info->mlx_win != NULL)
		mlx_destroy_image(info->mlx, info->mlx_win);
	if (info->mlx != NULL)
	{
//		mlx_destroy_display(info->mlx);
//		mlx_loop_end(info->mlx);
		free(info->mlx);
	}
	exit (1);
	return (0);
}