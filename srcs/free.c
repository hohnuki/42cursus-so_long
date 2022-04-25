#include "../includes/so_long.h"

void	error_message_and_free(char *message, t_config *info)
{
	ft_putendl_fd(message, STDERR_FILENO);
	mlx_free(info);
}

char	**free_array(t_config *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.height)
	{
		free (&(info->map_info.map[i]));
		i++;
	}
	free(info->map_info.map);
	return (NULL);
}

int	mlx_free(t_config *info)
{
	if (info->map_info.guard_node != NULL)
		ft_lstclear(&(info->map_info.guard_node), free);
	if (info->map_info.map != NULL)
		free(info->map_info.map);
	if (info->images.empty != NULL)
		mlx_destroy_image(info->mlx, info->images.empty);
	if (info->images.exit != NULL)
		mlx_destroy_image(info->mlx, info->images.exit);
	if (info->images.collectible != NULL)
		mlx_destroy_image(info->mlx, info->images.collectible);
	if (info->images.player != NULL)
		mlx_destroy_image(info->mlx, info->images.player);
	if (info->images.player2 != NULL)
		mlx_destroy_image(info->mlx, info->images.player2);
	if (info->images.wall != NULL)
		mlx_destroy_image(info->mlx, info->images.wall);
	if (info->mlx_win != NULL)
		mlx_destroy_window(info->mlx, info->mlx_win);
	if (info->mlx != NULL)
	{
		mlx_destroy_display(info->mlx);
		mlx_loop_end(info->mlx);
		free(info->mlx);
	}
	// system("leaks so_long");
	exit (1);
	return (0);
}
