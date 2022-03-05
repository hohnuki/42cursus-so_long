#include "../includes/so_long.h"

void	print_pedometer(t_config *info)
{
	printf("pedometer:%d \n", info->player_info.pedometer);
}

void	swap_position(t_config *info, int current_x, int current_y, int next_x, int next_y)
{
//	printf("\x1b[36m[swap_position in]\n\033[m");
//	printf("\x1b[36m[%c]\n\033[m", info->map_info.map[next_y][next_x]);
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
	{
		if (info->map_info.collectible_count == info->player_info.collectible_count)
		{
			info->player_info.pedometer++;
			info->map_info.map[current_y][current_x] = '0';
			info->map_info.map[next_y][next_x] = 'P';
			print_pedometer(info);
			printf("Game clear!\n");
			mlx_free(info);
		}
	}
//	else if (info->map_info.map[next_y][next_y] == 'E')//TODO:Eで真偽判定通らない理由の解明
//	{
//		info->map_info.pedometer++;
//		info->map_info.map[current_y][current_x] = '0';
//		info->map_info.map[next_y][next_x] = 'P';
//		print_pedometer(info);
//		printf("Game clear!\n");
//	}
//	print_map(info);
}

void	move_player(t_config *info, int keycode)
{
//	printf("\x1b[36m[move_player in]\n\033[m");
//	if (keycode == KEY_A)
//	{
//		printf("\x1b[36m[put a]\n\033[m");
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x - 1, info->player_info.postion_y);
//	}
//	else if (keycode == KEY_W)
//	{
//		printf("\x1b[36m[put w]\n\033[m");
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y - 1);
//	}
//	else if (keycode == KEY_D)
//	{
//		printf("\x1b[36m[put d]\n\033[m");
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x + 1, info->player_info.postion_y);
//	}
//	else if (keycode == KEY_S)
//	{
//		printf("\x1b[36m[put s]\n\033[m");
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y + 1);
//	}
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