#include "../includes/so_long.h"

void	print_pedometer(t_config *info)
{
	printf("pedometer:%d \n", info->player_info.pedometer);
}

void	check_goal_condtion(t_config *info)
{
	if (info->map_info.collectible_count == info->player_info.collectible_count)
	{
		info->player_info.pedometer++;
		info->map_info.map[current_y][current_x] = '0';
		info->map_info.map[next_y][next_x] = 'P';
		print_pedometer(info);
		printf("Game clear!\n");
		mlx_free(info);
		system("leaks so_long");
	}
}

void	swap_position(t_config *info, int current_x, \
int current_y, int next_x, int next_y)
{
	if (info->map_info.map[next_y][next_x] == '1')
		return ;
	else if (info->map_info.map[next_y][next_x] == 'C')
	{
		info->player_info.pedometer++;
		info->player_info.collectible_count++;
		info->map_info.map[current_y][current_x] = '0';
		info->map_info.map[next_y][next_x] = 'P';
		print_pedometer(info);
	}
	else if (info->map_info.map[next_y][next_x] == '0')
	{
		info->player_info.pedometer++;
		info->map_info.map[current_y][current_x] = '0';
		info->map_info.map[next_y][next_x] = 'P';
		print_pedometer(info);
	}
	else
		check_goal_condtion(info);
}

void	move_player(t_config *info, int keycode)
{
//	if (keycode == KEY_A)
//		swap_position(info, info->player_info.postion_x, \
info->player_info.postion_y, \
info->player_info.postion_x - 1, info->player_info.postion_y);
//	else if (keycode == KEY_W)
//		swap_position(info, info->player_info.postion_x, \
info->player_info.postion_y, \
info->player_info.postion_x, info->player_info.postion_y - 1);
//	else if (keycode == KEY_D)
//		swap_position(info, info->player_info.postion_x, \
info->player_info.postion_y, \
info->player_info.postion_x + 1, info->player_info.postion_y);
//	else if (keycode == KEY_S)
//		swap_position(info, info->player_info.postion_x, \
info->player_info.postion_y, \
info->player_info.postion_x, info->player_info.postion_y + 1);
	if (keycode == 'a')
		swap_position(info, info->player_info.postion_x, \
		info->player_info.postion_y, \
		info->player_info.postion_x - 1, info->player_info.postion_y);
	else if (keycode == 'w')
		swap_position(info, info->player_info.postion_x, \
		info->player_info.postion_y, \
		info->player_info.postion_x, info->player_info.postion_y - 1);
	else if (keycode == 'd')
		swap_position(info, info->player_info.postion_x, \
		info->player_info.postion_y, \
		info->player_info.postion_x + 1, info->player_info.postion_y);
	else if (keycode == 's')
		swap_position(info, info->player_info.postion_x, \
		info->player_info.postion_y, \
		info->player_info.postion_x, info->player_info.postion_y + 1);
}
