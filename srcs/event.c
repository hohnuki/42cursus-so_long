#include "../includes/so_long.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 'a' || keycode == 'w' || keycode == 's' || \
	keycode == 'd')
		move_player(info, keycode);
	else if (keycode == 65307)
		exit (EXIT_FAILURE);
	input_player_position(info);
	list_to_window(info);
	return (0);
}

int	expose(t_info *info)
{
	list_to_window(info);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->mlx_win, KEY_PRESS, 1L << 0, key_hook, info);
	mlx_hook(info->mlx_win, EXPOSE_E, 1L << 15, expose, info);
	mlx_hook(info->mlx_win, DESTROY_NOTIFY, 0L, \
	execute_exit, info);
}
