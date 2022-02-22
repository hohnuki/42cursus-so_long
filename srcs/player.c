#include "../includes/so_long.h"

void	swap_position(t_config *info, int current_x, int current_y, int next_x, int next_y)
{
	t_list *node = info->map_info.guard_node;
	int 	y_i;

	printf("\x1b[36m[swap_position in]\n\033[m");
	y_i = 0;
	node = node->next;
	while (y_i < current_y)
	{
		node = node->next;
		y_i++;
	}
	node->content[current_x] = '0';

	y_i = 0;
	node = info->map_info.guard_node;
	node = node->next;
	while (y_i < next_y)
	{
		node = node->next;
		y_i++;
	}
	node->content[next_x] = 'P';
}

void	move_player(t_config *info, int keycode)
{
	printf("\x1b[36m[move_player in]\n\033[m");
//	if (keycode == KEY_A)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x - 1, info->player_info.postion_y);
//	else if (keycode == KEY_W)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y - 1);
//	else if (keycode == KEY_D)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x + 1, info->player_info.postion_y);
//	else if (keycode == KEY_S)
//		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y + 1);
	if (keycode == 'a')
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x - 1, info->player_info.postion_y);
	else if (keycode == 'w')
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y - 1);
	else if (keycode == 'd')
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x + 1, info->player_info.postion_y);
	else if (keycode == 's')
		swap_position(info, info->player_info.postion_x, info->player_info.postion_y, info->player_info.postion_x, info->player_info.postion_y + 1);
}