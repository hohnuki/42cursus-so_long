#include "../includes/so_long.h"

void	swap_position(int current_x, int current_y)
{

}

void	move_player(t_config *info, int keycode)
{
	if (keycode == 'a')
		swap_position(info->player_info.postion_x, info->player_info.postion_y);
	else if (keycode == 'w')
		swap_position(info);
	else if (keycode == 'd')
		swap_position(info);
	else if (keycode == 's')
		swap_position(info);
}