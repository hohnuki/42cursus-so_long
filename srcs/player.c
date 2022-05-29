#include "../includes/so_long.h"

static void	print_pedometer(t_info *info)
{
	ft_putstr_fd("pedometer:", STDOUT_FILENO);
	ft_putnbr_fd(info->player_info.pedometer, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	check_goal_condition(t_info *info)
{
	if (info->map_info.collectible_count == info->player_info.collectible_count)
	{
		info->player_info.pedometer++;
		info->map_info.map[info->player_info.c_y][info->player_info.c_x] = '0';
		info->map_info.map[info->player_info.n_y][info->player_info.n_x] = 'P';
		print_pedometer(info);
		ft_putstr_fd("Game clear!\n", STDOUT_FILENO);
		exit (EXIT_SUCCESS);
	}
}

static void	swap_position(t_info *info)
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
	else if (info->map_info.map[info->player_info.n_y][info->player_info.n_x] \
	== 'E')
		check_goal_condition(info);
}

static void	execute_swap_s_or_d(t_info *info, int x, int y)
{
	info->player_info.c_x = info->player_info.postion_x;
	info->player_info.c_y = info->player_info.postion_y;
	info->player_info.n_x = info->player_info.postion_x + x;
	info->player_info.n_y = info->player_info.postion_y + y;
	swap_position(info);
}

void	move_player(t_info *info, int keycode)
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
		execute_swap_s_or_d(info, 1, 0);
	else if (keycode == 's')
		execute_swap_s_or_d(info, 0, 1);
}
