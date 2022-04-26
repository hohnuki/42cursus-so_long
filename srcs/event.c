#include "../includes/so_long.h"

int	key_hook(int keycode, t_config *info)
{
	if (keycode == 'a' || keycode == 'w' || keycode == 's' || keycode == 'd')
		move_player(info, keycode);
	input_player_position(info);
	list_to_window(info);
	return (0);
}

int	expose(t_config *info)
{
	list_to_window(info);
	return (0);
}

void	set_event(t_config *info)
{
	mlx_hook(info->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_hook, info);
	mlx_hook(info->mlx_win, EXPOSE_E, EXPOSE_MASK, expose, info);
	mlx_hook(info->mlx_win, CLIENT_MESSAGE, STRUC_NOTFY_MASK, mlx_free, info);
}
