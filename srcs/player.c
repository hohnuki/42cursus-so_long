#include "../includes/so_long.h"

static void	print_pedometer(t_config *info)
{
	printf("pedometer:%d \n", info->player_info.pedometer);
}

static void	check_goal_condtion(t_config *info)
{
	if (info->map_info.collectible_count == info->player_info.collectible_count)
	{
		info->player_info.pedometer++;
		info->map_info.map[info->player_info.c_y][info->player_info.c_x] = '0';
		info->map_info.map[info->player_info.n_y][info->player_info.n_x] = 'P';
		print_pedometer(info);
		printf("Game clear!\n");
		mlx_free(info);
		system("leaks so_long");
	}
}

static void	swap_position(t_config *info)
{
	if (info->map_info.map[info->player_info.c_y][info->player_info.c_x] == '1')
		return ;
	else if (info->map_info.map[info->player_info.n_y][info->player_info.n_x] \
	== 'C')
	{
		info->player_info.pedometer++;
		info->player_info.collectible_count++;
		info->map_info.map[info->player_info.c_y][info->player_info.c_x] = '0';
		info->map_info.map[info->player_info.n_y][info->player_info.n_x] = 'P';
		print_pedometer(info);
	}
	else if (info->map_info.map[info->player_info.n_y][info->player_info.n_x] \
	== '0')
	{
		info->player_info.pedometer++;
		info->map_info.map[info->player_info.c_y][info->player_info.c_x] = '0';
		info->map_info.map[info->player_info.n_y][info->player_info.n_x] = 'P';
		print_pedometer(info);
	}
	else
		check_goal_condtion(info);
}

void	move_player(t_config *info, int keycode)
{
	if (keycode == 'a')
	{
		info->player_info.c_x = info->player_info.postion_x;
		info->player_info.c_y = info->player_info.postion_y;
		info->player_info.n_x = info->player_info.postion_x - 1;
		info->player_info.n_y = info->player_info.postion_y;
		swap_position(info);
	}
	else if (keycode == 'w')
	{
		info->player_info.c_x = info->player_info.postion_x;
		info->player_info.c_y = info->player_info.postion_y;
		info->player_info.n_x = info->player_info.postion_x;
		info->player_info.n_y = info->player_info.postion_y - 1;
		swap_position(info);
	}
	else if (keycode == 'd')
	{
		info->player_info.c_x = info->player_info.postion_x;
		info->player_info.c_y = info->player_info.postion_y;
		info->player_info.n_x = info->player_info.postion_x + 1;
		info->player_info.n_y = info->player_info.postion_y;
		swap_position(info);
	}
	else if (keycode == 's')
	{
		info->player_info.c_x = info->player_info.postion_x;
		info->player_info.c_y = info->player_info.postion_y;
		info->player_info.n_x = info->player_info.postion_x;
		info->player_info.n_y = info->player_info.postion_y + 1;
		swap_position(info);
	}
}
