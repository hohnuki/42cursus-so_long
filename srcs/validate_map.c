#include "../includes/so_long.h"

void	input_player_position(t_config *info)
{
	t_list	*node;
	int		i;
	int		j;

	node = info->map_info.guard_node;
	node = node->next;
	i = 0;
	while (node != NULL)
	{
		j = 0;
		while (node->content[j] != '\0')
		{
			if (node->content[j] == 'P')
			{
				info->player_info.postion_y = i;
				info->player_info.postion_x = j;
				printf("\x1b[36m[player_info.postion_y = %d]\n\033[m", i);
				printf("\x1b[36m[player_info.postion_x = %d]\n\033[m", j);
				return ;
			}
			j++;
		}
		node = node->next;
		i++;
	}
}