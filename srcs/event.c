#include "../includes/so_long.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_S || \
	keycode == KEY_D)
		move_player(info, keycode);
	else if (keycode == KEY_ESC)
		mlx_free();
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
	mlx_hook(info->mlx_win, DESTOROY_NOTIFY, NO_EVENT_MASK, \
	mlx_free_ret_int, info);
}
