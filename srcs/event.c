#include "../includes/so_long.h"

int	key_hook(int keycode, t_config *info)
{
//	printf("\x1b[36m[key_hook in]\n\033[m");
//	printf("\x1b[36m[keycode=%d]\n\033[m", keycode);
//	if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_S || keycode == KEY_D)
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
	mlx_hook(info->mlx_win, 2, 1L << 0, key_hook, info);//TODO:x_event,x_maskにマクロ組む
	mlx_hook(info->mlx_win, 33, 1L << 17, mlx_free, info);
	mlx_hook(info->mlx_win, 12, 1L << 15, expose, info);
}
