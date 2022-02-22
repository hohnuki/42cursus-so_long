#include "../includes/so_long.h"

void	swap_position(t_config *info, int current_x, int current_y, int next_x, int next_y)
{
//	printf("\x1b[36m[swap_position in]\n\033[m");
	info->map_info.map[current_y][current_x] = '0';
	info->map_info.map[next_y][next_x] = 'P';
}

void	move_player(t_config *info, int keycode)
{
//	printf("\x1b[36m[move_player in]\n\033[m");
//	if (keycode == KEY_A)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x - 1, info->player_info.postion_y);
//	else if (keycode == KEY_W)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y - 1);
//	else if (keycode == KEY_D)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x + 1, info->player_info.postion_y);
//	else if (keycode == KEY_S)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y + 1);
	if (keycode == 'a')
	{
		printf("\x1b[36m[put a]\n\033[m");
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x - 1, info->player_info.postion_y);
	}
	else if (keycode == 'w')
	{
		printf("\x1b[36m[put w]\n\033[m");
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y - 1);
	}
	else if (keycode == 'd')
	{
		printf("\x1b[36m[put d]\n\033[m");
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x + 1, info->player_info.postion_y);
	}
	else if (keycode == 's')
	{
		printf("\x1b[36m[put s]\n\033[m");
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y + 1);
	}
}