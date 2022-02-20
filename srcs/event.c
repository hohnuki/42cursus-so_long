#include "../includes/so_long.h"

void	key_hook(int keycode, t_config *info)
{
	if (keycode == 'a' || keycode == 'w' || keycode == 's' || keycode == 'd')
		move_player(info, keycode);
}

void	set_event(t_config *info)
{
	mlx_hook(info->mlx_win, 2, 1L << 0, key_hook, &info);
}